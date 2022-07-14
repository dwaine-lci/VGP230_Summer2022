#pragma once
#include <XEngine.h>
#include "Entity.h"

class Bullet;

class BulletPool : public Entity
{
public:
	BulletPool();
	virtual ~BulletPool();

	Bullet* GetBullet();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	int _nextAvailableIndex;
	std::vector<Bullet*> _bullets;
};