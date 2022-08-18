#include "Player.h"
#include "TileMap.h"

Player::Player()
{
}
Player::~Player()
{
}
void Player::Load()
{
	_image = X::LoadTexture("stone.png");

	const Tile* safeTile = TileMap::Get()->GetFirstWalkableTile();
	_position = safeTile->GetPosition();
}
void Player::Update(float deltaTime)
{
	const float speed = 100.0f;
	X::Math::Vector2 direction;
	X::Math::Vector2 displacement;
	if (X::IsKeyDown(X::Keys::W))
	{
		direction.y = -1.0f;
	}
	else if (X::IsKeyDown(X::Keys::S))
	{
		direction.y = 1.0f;
	}
	if (X::IsKeyDown(X::Keys::A))
	{
		direction.x = -1.0f;
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		direction.x = 1.0f;
	}
	if (X::Math::MagnitudeSqr(direction) > 0.0f)
	{
		direction = X::Math::Normalize(direction);
		displacement = _position + direction * speed * deltaTime;
		float halfPlayerWidth = X::GetSpriteWidth(_image) * 0.5f;
		float halfPlayerHeight = X::GetSpriteHeight(_image) * 0.5f;
		X::Math::Rect displacementRect(displacement.x - halfPlayerWidth, displacement.y - halfPlayerHeight,
										displacement.x + halfPlayerWidth, displacement.y + halfPlayerHeight);
		if (!TileMap::Get()->HasCollision(displacementRect))
		{
			_position = displacement;
		}
	}
}
void Player::Render()
{
	X::DrawSprite(_image, _position);
	float halfPlayerWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfPlayerHeight = X::GetSpriteHeight(_image) * 0.5f;
	X::Math::Rect displacementRect(_position.x - halfPlayerWidth, _position.y - halfPlayerHeight,
		_position.x + halfPlayerWidth, _position.y + halfPlayerHeight);
	X::DrawScreenRect(displacementRect, X::Colors::Teal);
}
void Player::Unload()
{

}