#pragma once
#pragma once
#include "Enemy.h"
#include <vector>

class EnemyManager : public Entity
{
public:
	virtual ~EnemyManager();
	static EnemyManager* Get();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void SpawnEnemies(int count);
private:
	EnemyManager();
	static EnemyManager* _instance;
	std::vector<Enemy*> _enemies;

	int _nextAvailableEnemy;
};
