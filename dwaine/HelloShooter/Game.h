#pragma once
#include "Entity.h"
#include "Collidable.h"
#include <vector>

class Ship;
class Enemy;
class BulletPool;
class ProgressBar;

class Game : public Entity
{
public:
	Game();
	virtual ~Game();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void AddCollidable(Collidable* collidable);

	bool IsGameOver();
	
private:
	Ship* _ship;
	BulletPool* _bulletPool;
	ProgressBar* _healthBar;
	std::vector<Enemy*> _enemies;
	std::vector<Collidable*> _collidables;
};