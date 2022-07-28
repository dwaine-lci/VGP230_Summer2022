#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"
#include "AnimSpriteSheet.h"

class BulletPool;
class Ship;

class Enemy : public Entity, public Collidable
{
public:
	Enemy();
	virtual ~Enemy();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void SetBulletPool(BulletPool* bulletPool);
	void SetPosition(const X::Math::Vector2& position);
	void SetRotation(float rotation);
	void SetPlayerShip(Ship* ship);

	int GetType() const override;
	const X::Math::Vector2& GetPosition() const override;
	void OnCollision(Collidable* collidable) override;

	bool IsAlive();

private:
	void ShootBullet();

	BulletPool* _bulletPool;
	Ship* _ship;
	AnimSpriteSheet _explosionAnim;
	X::TextureId _shipTextureId;
	X::Math::Vector2 _position;

	X::Math::Vector2 _centerPoint;
	X::Math::Vector2 _targetPosition;
	float _targetPositionUpdate;

	float _fireRate = 0.0f;

	float _rotation;
	int _health;
};
