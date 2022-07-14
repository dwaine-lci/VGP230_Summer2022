#pragma once
#include <XEngine.h>
#include "Entity.h"

class BulletPool;

class Ship : public Entity
{
public:
	Ship();
	virtual ~Ship();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	void ShootBullet();

	BulletPool* _bulletPool;
	X::TextureId _shipTextureId;
	X::Math::Vector2 _position;
	float _rotation;
};