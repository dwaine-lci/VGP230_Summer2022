#include "Enemy.h"
#include "BulletPool.h"
#include "Bullet.h"
#include "Ship.h"
#include "Enums.h"

Enemy::Enemy()
	: Entity()
	, Collidable(30.0f)
	, _shipTextureId(0)
	, _position(0.0f, 0.0f)
	, _rotation(0.0f)
	, _health(0)
	, _bulletPool(nullptr)
	, _ship(nullptr)
{
}
Enemy::~Enemy()
{
}
void Enemy::Load()
{
	_shipTextureId = X::LoadTexture("carrier_01.png");
	XASSERT(_shipTextureId != 0, "Enemy texture did not load");

	_rotation = 0.0f;
	_targetPositionUpdate = 0.0f;
	_fireRate = 5.0f;

	_health = 100;
	SetCollisionFilter((int)EntityType::Ship | (int)EntityType::Bullet_Player);

	_explosionAnim.Load();
}
void Enemy::Update(float deltaTime)
{
	if (IsAlive())
	{
		const float speed = 70.0f;
		const float rotationSpeed = X::Math::kPiByTwo;
		const float offsetDistance = 200.0f;

		_targetPositionUpdate -= deltaTime;
		if (_targetPositionUpdate <= 0.0f || X::Math::Vector2::SqrMagnitude(_targetPosition - _position) <= 100.0f)
		{
			_targetPosition = _centerPoint + (X::RandomUnitCircle() * offsetDistance);
			_targetPositionUpdate = 5.0f;
		}

		X::Math::Vector2 direction = X::Math::Normalize(_targetPosition - _position);
		_position += direction * speed * deltaTime;

		if (_ship != nullptr && _ship->IsAlive())
		{
			direction = X::Math::Normalize(_ship->GetPosition() - _position);
			float targetRotation = atan2(direction.x, -direction.y);
			_rotation = targetRotation;

			_fireRate -= deltaTime;
			if (_fireRate <= 0.0f)
			{
				ShootBullet();
				_fireRate = X::RandomFloat(1.0f, 3.0f);
			}
		}
	}
	_explosionAnim.Update(deltaTime);
}
void Enemy::ShootBullet()
{
	Bullet* bullet = _bulletPool->GetBullet();
	if (bullet != nullptr)
	{
		X::Math::Vector2 offset = X::Math::Vector2::Forward(_rotation) * 50.0f;
		bullet->SetActive(_position + offset, _rotation, EntityType::Bullet_Enemy);
	}
}
void Enemy::Render()
{
	if (IsAlive())
	{
		X::DrawSprite(_shipTextureId, _position, _rotation);
		X::DrawScreenCircle(_position, GetRadius(), X::Colors::HotPink);
	}
	_explosionAnim.Render();
}
void Enemy::Unload()
{
	_explosionAnim.Unload();
}
void Enemy::SetBulletPool(BulletPool* bulletPool)
{
	_bulletPool = bulletPool;
}
void Enemy::SetPlayerShip(Ship* ship)
{
	_ship = ship;
}
void Enemy::SetPosition(const X::Math::Vector2& position)
{
	_position = position;
	_centerPoint = position;
	_targetPosition = position;
	_targetPositionUpdate = 0.0f;
}
void Enemy::SetRotation(float rotation)
{
	_rotation = rotation;
}
int Enemy::GetType() const
{
	return (int)EntityType::Enemy;
}
const X::Math::Vector2& Enemy::GetPosition() const
{
	return _position;
}
void Enemy::OnCollision(Collidable* collidable)
{
	if (_health > 0)
	{
		if (collidable->GetType() == (int)EntityType::Ship)
		{
			_health -= _health;
		}
		else
		{
			_health -= 10;
		}
		if (!IsAlive())
		{
			SetCollisionFilter(0);
			_explosionAnim.SetActive(_position);
		}
	}
}

bool Enemy::IsAlive()
{
	return _health > 0;
}

