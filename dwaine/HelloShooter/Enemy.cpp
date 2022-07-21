#include "Enemy.h"
#include "BulletPool.h"
#include "Bullet.h"
#include "Enums.h"

Enemy::Enemy()
	: Entity()
	, Collidable(30.0f)
	, _shipTextureId(0)
	, _position(0.0f, 0.0f)
	, _rotation(0.0f)
	, _health(0)
{
}
Enemy::~Enemy()
{
}
void Enemy::Load()
{
	_shipTextureId = X::LoadTexture("carrier_01.png");
	XASSERT(_shipTextureId != 0, "Enemy texture did not load");

	_position.x = 0.0f;
	_position.y = 0.0f;
	_rotation = 0.0f;

	_health = 100;
	SetCollisionFilter((int)EntityType::Ship | (int)EntityType::Bullet_Player);
}
void Enemy::Update(float deltaTime)
{
	if (IsAlive())
	{
		//const float speed = 100.0f;
		//const float rotationSpeed = X::Math::kPiByTwo;
	}
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
}
void Enemy::Unload()
{

}
void Enemy::SetBulletPool(BulletPool* bulletPool)
{
	_bulletPool = bulletPool;
}
void Enemy::SetPosition(const X::Math::Vector2& position)
{
	_position = position;
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
		}
	}
}

bool Enemy::IsAlive()
{
	return _health > 0;
}

