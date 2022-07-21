#include "Bullet.h"

Bullet::Bullet()
	: Entity()
	, Collidable(10.0f)
	, _textureId(0)
	, _position(0.0f, 0.0f)
	, _rotation(0.0f)
	, _lifeTime(0.0f)
{
}
Bullet::~Bullet()
{
}
void Bullet::SetActive(const X::Math::Vector2& position, const float& rotation, EntityType bulletType, float lifeTime)
{
	_lifeTime = lifeTime;
	_position = position;
	_rotation = rotation;
	_bulletType = bulletType;

	if (bulletType == EntityType::Bullet_Player)
	{
		SetCollisionFilter((int)EntityType::Enemy | (int)EntityType::Bullet_Enemy);
	}
	else if (bulletType == EntityType::Bullet_Enemy)
	{
		SetCollisionFilter((int)EntityType::Ship | (int)EntityType::Bullet_Player);
	}
	else
	{
		SetCollisionFilter(0);
	}
}
bool Bullet::IsActive()
{
	return _lifeTime > 0.0f;
}

void Bullet::Load()
{
	_textureId = X::LoadTexture("bullet1.png");
	_lifeTime = 0.0f;
	_position = X::Math::Vector2::Zero();
	_rotation = 0.0f;
}
void Bullet::Update(float deltaTime)
{
	if (IsActive())
	{
		const float speed = 200.0f;
		_position += X::Math::Vector2::Forward(_rotation) * speed * deltaTime;
		_lifeTime -= deltaTime;
		if (!IsActive())
		{
			SetCollisionFilter(0);
		}
	}
}
void Bullet::Render()
{
	if (IsActive())
	{
		X::DrawSprite(_textureId, _position, _rotation);
		X::DrawScreenCircle(_position, GetRadius(), X::Colors::Red);
	}
}
void Bullet::Unload()
{
}
int Bullet::GetType() const
{
	return (int)_bulletType;
}
const X::Math::Vector2& Bullet::GetPosition() const
{
	return _position;
}
void Bullet::OnCollision(Collidable* collidable)
{
	_lifeTime = 0.0f;
	SetCollisionFilter(0);
}
