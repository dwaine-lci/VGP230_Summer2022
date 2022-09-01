#include "TileMap.h"

TileMap* TileMap::_instance = nullptr;
TileMap::TileMap()
{
}
TileMap::~TileMap()
{
}
TileMap* TileMap::Get()
{
	if (_instance == nullptr)
	{
		_instance = new TileMap();
	}

	return _instance;
}

void TileMap::Load()
{
	ReloadMap();
}
void TileMap::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::ENTER))
	{
		ReloadMap();
	}
	for (int i = 0; i < _tiles.size(); ++i)
	{
		_tiles[i]->Update(deltaTime);
	}
}
void TileMap::Render()
{
	for (int i = 0; i < _tiles.size(); ++i)
	{
		_tiles[i]->Render();
	}
}
void TileMap::Unload()
{
	for (int i = 0; i < _tiles.size(); ++i)
	{
		_tiles[i]->Unload();
		delete _tiles[i];
		_tiles[i] = nullptr;
	}
	_tiles.clear();
}

void TileMap::ReloadMap()
{
	const char fileName[255] = "./level.lvl";
	std::fstream inputStream;
	inputStream.open(fileName);

	inputStream >> _columns;
	inputStream >> _rows;

	X::TextureId dummyTile = X::LoadTexture("white.jpg");
	_tiles.clear();
	float tileWidth = X::GetSpriteWidth(dummyTile);
	float tileHeight = X::GetSpriteHeight(dummyTile);
	X::Math::Vector2 offset(tileWidth * 0.5f, tileHeight * 0.5f);
	int dataType = 0;
	int tileIndex = 0;
	int x = 0;
	int y = 0;
	while (inputStream >> dataType)
	{
		TileData newData;
		newData.Type = (TileType)dataType;
		x = tileIndex % _columns;
		y = tileIndex / _columns;
		newData.Position.x = tileWidth * x + offset.x;
		newData.Position.y = tileHeight * y + offset.y;

		Tile* newTile = new Tile(newData);
		newTile->Load();
		_tiles.push_back(newTile);
		++tileIndex;
	}
}

const Tile* TileMap::GetFirstWalkableTile()
{
	Tile* tile = nullptr;

	for (int i = 0; i < _tiles.size(); ++i)
	{
		if (!_tiles[i]->IsCollidable())
		{
			tile = _tiles[i];
			break;
		}
	}

	return tile;
}
void TileMap::GetAllWalkableTiles(std::vector<Tile*>& outWalkableTiles)
{
	for (int i = 0; i < _tiles.size(); ++i)
	{
		if (!_tiles[i]->IsCollidable())
		{
			outWalkableTiles.push_back(_tiles[i]);
		}
	}
}
bool TileMap::HasCollision(const X::Math::Rect& objRect, const X::Math::Vector2& maxDisplacement, X::Math::Vector2& outDisplacement) const
{
	// AABB
	// left/right x axis
	// top/bott y axis

	bool hasCollision = false;
	const float offset = 0.5f;
	for (int d = 0; d < 2; ++d)
	{
		X::Math::Rect targetRect(objRect);
		X::Math::Vector2 testDirection = X::Math::Vector2::Zero();
		if (d == 0)
		{
			testDirection.x = maxDisplacement.x;
		}
		else
		{
			testDirection.y = maxDisplacement.y;
		}
		targetRect.min += testDirection;
		targetRect.max += testDirection;
		for (int i = 0; i < _tiles.size(); ++i)
		{
			if (_tiles[i]->IsCollidable() && _tiles[i]->HasCollision(targetRect))
			{
				hasCollision = true;
				const X::Math::Rect& tileRect = _tiles[i]->GetRect();
				if (d == 0)
				{
					if (maxDisplacement.x > 0.0f && targetRect.right > tileRect.left)
					{
						outDisplacement.x = X::Math::Min(maxDisplacement.x - (targetRect.right - tileRect.left) - offset, outDisplacement.x);
						outDisplacement.x = X::Math::Max(outDisplacement.x, 0.0f);
					}
					else if (maxDisplacement.x < 0.0f && targetRect.left < tileRect.right)
					{
						outDisplacement.x = X::Math::Max(maxDisplacement.x + (tileRect.right - targetRect.left) + offset, outDisplacement.x);
						outDisplacement.x = X::Math::Min(outDisplacement.x, 0.0f);
					}
				}
				else
				{
					if (maxDisplacement.y < 0.0f && targetRect.top < tileRect.bottom)
					{
						outDisplacement.y = X::Math::Max(maxDisplacement.y + (tileRect.bottom - targetRect.top) + offset, outDisplacement.y);
						outDisplacement.y = X::Math::Min(outDisplacement.y, 0.0f);
					}
					else if (maxDisplacement.y > 0.0f && targetRect.bottom > tileRect.top)
					{
						outDisplacement.y = X::Math::Min(maxDisplacement.y - (targetRect.bottom - tileRect.top) - offset, outDisplacement.y);
						outDisplacement.y = X::Math::Max(outDisplacement.y, 0.0f);
					}
				}
			}
		}
	}

	return hasCollision;
}