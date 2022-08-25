#include "Enemy.h"
#include "Enums.h"
#include "TileMap.h"
#include "CollisionManager.h"

Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
void Enemy::Load()
{
	_image = X::LoadTexture("mushroom.png");
	_targetPositionUpdate = 0.0f;

	_health = -1;
	_removeCollider = false;
}
void Enemy::Update(float deltaTime)
{
	if (_health > 0)
	{
		const float speed = 70.0f;
		const float rotationSpeed = X::Math::kPiByTwo;
		const float offsetDistance = 200.0f;

		_targetPositionUpdate -= deltaTime;
		if (_targetPositionUpdate <= 0.0f || X::Math::Vector2::SqrMagnitude(_targetPosition - _position) <= 100.0f)
		{
			_targetPosition = _centerPoint + (X::RandomUnitCircle() * offsetDistance);
			_targetPositionUpdate = (X::RandomFloat() * 4.0f) + 1.0f;
		}

		X::Math::Vector2 direction = X::Math::Normalize(_targetPosition - _position);
		if (X::Math::MagnitudeSqr(direction) > 0.0f)
		{
			X::Math::Vector2 displacement = direction * speed * deltaTime;
			X::Math::Vector2 maxDisplacement = displacement;
			X::Math::Rect currentRect(_enemyRect);
			currentRect.min += _position;
			currentRect.max += _position;
			if (TileMap::Get()->HasCollision(currentRect, maxDisplacement, displacement))
			{
				_position += displacement;
				if (X::Math::MagnitudeSqr(displacement) <= 0.0f)
				{
					_targetPositionUpdate = 0.0f;
				}
			}
			else
			{
				_position += displacement;
			}
			currentRect = X::Math::Rect(_enemyRect);
			currentRect.min += _position;
			currentRect.max += _position;
			SetRect(currentRect);
		}
	}
	else if (_removeCollider)
	{
		_removeCollider = false;
		CollisionManager::Get()->RemoveCollidable(this);
	}
}
void Enemy::Render()
{
	if (_health > 0)
	{
		X::DrawSprite(_image, _position);
	}
}
void Enemy::Unload()
{

}
bool Enemy::IsActive() const
{
	return _health > 0;
}
void Enemy::SetActive(const X::Math::Vector2& position, int health)
{
	_position = position;
	_centerPoint = position;
	_targetPosition = position;
	_targetPositionUpdate = 0.0f;
	_health = health;

	float halfPlayerWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfPlayerHeight = X::GetSpriteHeight(_image) * 0.5f;
	_enemyRect.left = -halfPlayerWidth;
	_enemyRect.right = halfPlayerWidth;
	_enemyRect.top = -halfPlayerHeight;
	_enemyRect.bottom = halfPlayerHeight;
	SetRect(_enemyRect);
	SetCollisionFilter((int)EntityType::Player);

	CollisionManager::Get()->AddCollidable(this);
	_removeCollider = false;
}
int Enemy::GetType() const
{
	return _health > 0 ? (int)EntityType::Enemy : 0;
}
const X::Math::Vector2& Enemy::GetPosition() const
{
	return _position;
}
void Enemy::OnCollision(Collidable* collidable)
{
	if (_health > 0)
	{
		if (collidable->GetType() == (int)EntityType::Player)
		{
			_health -= _health;
		}
		if (_health <= 0)
		{
			_removeCollider = true;
		}
	}
}

