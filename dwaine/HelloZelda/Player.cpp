#include "Player.h"
#include "TileMap.h"
#include "CollisionManager.h"

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
	float halfPlayerWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfPlayerHeight = X::GetSpriteHeight(_image) * 0.5f;
	_playerRect.left = -halfPlayerWidth;
	_playerRect.right = halfPlayerWidth;
	_playerRect.top = -halfPlayerHeight;
	_playerRect.bottom = halfPlayerHeight;

	SetRect(_playerRect);
	SetCollisionFilter((int)EntityType::PickUp | (int)EntityType::Enemy);
	CollisionManager::Get()->AddCollidable(this);
}
void Player::Update(float deltaTime)
{
	const float speed = 1000.0f;
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
		displacement = direction * speed * deltaTime;
		X::Math::Vector2 maxDisplacement = displacement;
		X::Math::Rect currentRect(_playerRect);
		currentRect.min += _position;
		currentRect.max += _position;
		if (TileMap::Get()->HasCollision(currentRect, maxDisplacement, displacement))
		{
			_position += displacement;
		}
		else
		{
			_position += displacement;
		}
		currentRect = X::Math::Rect(_playerRect);
		currentRect.min += _position;
		currentRect.max += _position;
		SetRect(currentRect);
	}
}
void Player::Render()
{
	X::DrawSprite(_image, _position);
}
void Player::Unload()
{

}

int Player::GetType() const
{
	return (int)EntityType::Player;
}
void Player::OnCollision(Collidable* collidable)
{
	// depends on object
}
const X::Math::Vector2& Player::GetPosition() const
{
	return _position;
}