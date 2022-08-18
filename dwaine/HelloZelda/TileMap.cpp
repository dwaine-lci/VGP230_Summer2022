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
bool TileMap::HasCollision(const X::Math::Rect& objRect) const
{
	bool hasCollision = false;
	for (int i = 0; i < _tiles.size(); ++i)
	{
		if (_tiles[i]->IsCollidable() && _tiles[i]->HasCollision(objRect))
		{
			hasCollision = true;
			break;
		}
	}

	return hasCollision;
}