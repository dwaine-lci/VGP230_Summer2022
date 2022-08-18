#include "Tile.h"

Tile::Tile(const TileData& data)
	: _data(data)
{

}
Tile::~Tile()
{

}

void Tile::Load()
{
	switch (_data.Type)
	{
	case TileType::Ground: _image = X::LoadTexture("green.jpg"); break;
	case TileType::Wall: _image = X::LoadTexture("red.jpg"); break;
	default:
		XASSERT(false, "NO PROPER TILE");
		break;
	}

	float halfTileWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfTileHeight = X::GetSpriteHeight(_image) * 0.5f;
	_rect.left = _data.Position.x - halfTileWidth;
	_rect.right = _data.Position.x + halfTileWidth;
	_rect.top = _data.Position.y - halfTileHeight;
	_rect.bottom = _data.Position.y + halfTileHeight;
}
void Tile::Update(float deltaTime)
{

}
void Tile::Render()
{
	X::DrawSprite(_image, _data.Position);
	X::DrawScreenRect(_rect, X::Colors::Yellow);
}
void Tile::Unload()
{

}

const X::Math::Vector2& Tile::GetPosition() const
{
	return _data.Position;
}
bool Tile::IsCollidable() const
{
	return _data.Type == TileType::Wall;
}
bool Tile::HasCollision(const X::Math::Rect& objRect) const
{
	return X::Math::Intersect(_rect, objRect);
}