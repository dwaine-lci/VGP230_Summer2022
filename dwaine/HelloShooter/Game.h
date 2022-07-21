#pragma once
#include "Entity.h"
#include "Collidable.h"
#include <vector>

class Ship;
class BulletPool;

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
	
private:
	Ship* _ship;
	BulletPool* _bulletPool;
	std::vector<Collidable*> _collidables;
};