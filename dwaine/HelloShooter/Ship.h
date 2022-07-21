#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"

class BulletPool;

class Ship : public Entity, public Collidable
{
public:
	Ship();
	virtual ~Ship();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void SetBulletPool(BulletPool* bulletPool);

	int GetType() const override;
	const X::Math::Vector2& GetPosition() const override;
	void OnCollision(Collidable* collidable) override;

private:
	void ShootBullet();

	BulletPool* _bulletPool;
	X::TextureId _shipTextureId;
	X::Math::Vector2 _position;
	float _rotation;
	int _health;
};