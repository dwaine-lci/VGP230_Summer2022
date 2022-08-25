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

	_health = 100;
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
	_removeCollider = false;
}
void Player::Update(float deltaTime)
{
	if (_health <= 0)
	{
		if (_removeCollider)
		{
			CollisionManager::Get()->RemoveCollidable(this);
			_removeCollider = false;
		}
		return;
	}

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
	if (_health > 0)
	{
		X::DrawSprite(_image, _position);
	}

	std::string screenText = "HEALTH: " + std::to_string(_health);
	X::DrawScreenText(screenText.c_str(), 4.0f, 4.0f, 20.0f, X::Colors::Yellow);
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
	if (collidable->GetType() == (int)EntityType::Enemy)
	{
		_health -= 10;
	}
	else if (collidable->GetType() == (int)EntityType::PickUp)
	{
		_health += 5;
	}

	_health = X::Math::Clamp(_health, 0, 100);
	if (_health <= 0)
	{
		_removeCollider = true;
	}
}
const X::Math::Vector2& Player::GetPosition() const
{
	return _position;
}