#include "BulletPool.h"
#include "Bullet.h"

BulletPool::BulletPool()
	: Entity()
	, _nextAvailableIndex(0)
{
}
BulletPool::~BulletPool()
{
}

Bullet* BulletPool::GetBullet()
{
	Bullet* bullet = _bullets[_nextAvailableIndex];
	if (bullet->IsActive())
	{
		return nullptr;
	}
	_nextAvailableIndex = (_nextAvailableIndex + 1) % (int)_bullets.size();

	return bullet;
}

void BulletPool::Load()
{
	_nextAvailableIndex = 0;
	const int maxBullets = 30;
	for (int i = 0; i < maxBullets; ++i)
	{
		Bullet* newBullet = new Bullet();
		newBullet->Load();
		_bullets.push_back(newBullet);
	}
}
void BulletPool::Update(float deltaTime)
{
	for (int i = 0; i < _bullets.size(); ++i)
	{
		_bullets[i]->Update(deltaTime);
	}
}
void BulletPool::Render()
{
	for (int i = 0; i < _bullets.size(); ++i)
	{
		_bullets[i]->Render();
	}
}
void BulletPool::Unload()
{
	for (int i = 0; i < _bullets.size(); ++i)
	{
		delete _bullets[i];
		_bullets[i] = nullptr;
	}

	_bullets.clear();
}
