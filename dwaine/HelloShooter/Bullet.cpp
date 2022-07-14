#include "Bullet.h"

Bullet::Bullet()
	: Entity()
	, _textureId(0)
	, _position(0.0f, 0.0f)
	, _rotation(0.0f)
	, _lifeTime(0.0f)
{
}
Bullet::~Bullet()
{
}
void Bullet::SetActive(const X::Math::Vector2& position, const float& rotation, float lifeTime)
{
	_lifeTime = lifeTime;
	_position = position;
	_rotation = rotation;
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
	}
}
void Bullet::Render()
{
	if (IsActive())
	{
		X::DrawSprite(_textureId, _position, _rotation);
	}
}
void Bullet::Unload()
{
}
