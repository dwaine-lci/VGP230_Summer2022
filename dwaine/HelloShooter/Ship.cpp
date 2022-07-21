#include "Ship.h"
#include "BulletPool.h"
#include "Bullet.h"
#include "Enums.h"

Ship::Ship()
	: Entity()
	, Collidable(30.0f)
	, _shipTextureId(0)
	, _position(0.0f, 0.0f)
	, _rotation(0.0f)
	, _health(0)
{
}
Ship::~Ship()
{
}
void Ship::Load()
{
	_shipTextureId = X::LoadTexture("fighter.png");
	XASSERT(_shipTextureId != 0, "Ship texture did not load");

	_position.x = X::GetScreenWidth() * 0.5f;
	_position.y = X::GetScreenHeight() * 0.5f;
	_rotation = 0.0f;

	_health = 100;
	SetCollisionFilter((int)EntityType::Enemy | (int)EntityType::Bullet_Enemy);
}
void Ship::Update(float deltaTime)
{
	const float speed = 100.0f;
	const float rotationSpeed = X::Math::kPiByTwo;
	if (X::IsKeyDown(X::Keys::W))
	{
		_position += X::Math::Vector2::Forward(_rotation) * speed * deltaTime;
	}
	else if (X::IsKeyDown(X::Keys::S))
	{
		_position -= X::Math::Vector2::Forward(_rotation) * speed * deltaTime;
	}
	if (X::IsKeyDown(X::Keys::A))
	{
		_rotation -= rotationSpeed * deltaTime;
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		_rotation += rotationSpeed * deltaTime;
	}

	if (X::IsKeyPressed(X::Keys::SPACE))
	{
		ShootBullet();
	}
}
void Ship::ShootBullet()
{
	Bullet* bullet = _bulletPool->GetBullet();
	if (bullet != nullptr)
	{
		X::Math::Vector2 offset = X::Math::Vector2::Forward(_rotation) * 50.0f;
		bullet->SetActive(_position + offset, _rotation, EntityType::Bullet_Player);
	}
}
void Ship::Render()
{
	X::DrawSprite(_shipTextureId, _position, _rotation);
	X::DrawScreenCircle(_position, GetRadius(), X::Colors::HotPink);
}
void Ship::Unload()
{

}
void Ship::SetBulletPool(BulletPool* bulletPool)
{
	_bulletPool = bulletPool;
}
int Ship::GetType() const
{
	return (int)EntityType::Ship;
}
const X::Math::Vector2& Ship::GetPosition() const
{
	return _position;
}
void Ship::OnCollision(Collidable* collidable)
{
	if (_health > 0)
	{
		_health -= 10;
	}

	XLOG("HIT SOMETHING");
}
