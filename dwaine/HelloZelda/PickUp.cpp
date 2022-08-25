#include "PickUp.h"
#include "CollisionManager.h"

PickUp::PickUp()
{

}
PickUp::~PickUp()
{

}

void PickUp::Load()
{
	_image = X::LoadTexture("qmark.png");
	_isActive = false;
	_removeCollision = false;
}
void PickUp::Update(float deltaTime)
{
	if (_removeCollision)
	{
		CollisionManager::Get()->RemoveCollidable(this);
		_removeCollision = false;
	}
}
void PickUp::Render()
{
	if (_isActive)
	{
		X::DrawSprite(_image, _position);
	}
}
void PickUp::Unload()
{

}

bool PickUp::IsActive() const
{
	return _isActive;
}

void PickUp::SetActive(const X::Math::Vector2& position)
{
	_isActive = true;
	_position = position;
	float halfPickUpWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfPickUpHeight = X::GetSpriteHeight(_image) * 0.5f;
	X::Math::Rect newRect;
	newRect.left = position.x - halfPickUpWidth;
	newRect.right = position.x + halfPickUpWidth;
	newRect.top = position.y - halfPickUpHeight;
	newRect.bottom = position.y + halfPickUpHeight;

	SetRect(newRect);
	SetCollisionFilter((int)EntityType::Player);

	CollisionManager::Get()->AddCollidable(this);
}

const X::Math::Vector2& PickUp::GetPosition() const
{
	return _position;
}
int PickUp::GetType() const
{
	return _isActive ? (int)EntityType::PickUp : 0;
}
void PickUp::OnCollision(Collidable* collidable)
{
	if (_isActive)
	{
		_isActive = false;
		_removeCollision = true;
	}
}