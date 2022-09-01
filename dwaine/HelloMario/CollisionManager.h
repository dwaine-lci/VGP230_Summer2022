#pragma once
#include "Entity.h"
#include "Player.h"

class Collidable;

class CollisionManager : public Entity
{
public:
	virtual ~CollisionManager();
	static CollisionManager* Get();

	void AddCollidable(Collidable* collidable);
	void RemoveCollidable(Collidable* collidable);

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;
private:
	CollisionManager();
	static CollisionManager* _instance;
	std::vector<Collidable*> _collidables;
};
