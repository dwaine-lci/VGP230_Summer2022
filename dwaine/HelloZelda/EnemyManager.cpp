#include "EnemyManager.h"
#include "TileMap.h"

EnemyManager* EnemyManager::_instance = nullptr;
EnemyManager::EnemyManager()
{
}
EnemyManager::~EnemyManager()
{
}
EnemyManager* EnemyManager::Get()
{
	if (_instance == nullptr)
	{
		_instance = new EnemyManager();
	}

	return _instance;
}

void EnemyManager::Load()
{
	const int maxEnemies = 100;
	for (int i = 0; i < maxEnemies; ++i)
	{
		Enemy* newEnemy = new Enemy();
		newEnemy->Load();

		_enemies.push_back(newEnemy);
	}

	_nextAvailableEnemy = 0;
}
void EnemyManager::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::ENTER))
	{
		SpawnEnemies(3);
	}

	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Update(deltaTime);
	}
}
void EnemyManager::Render()
{
	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Render();
	}
}
void EnemyManager::Unload()
{
	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Unload();
		delete _enemies[i];
		_enemies[i] = nullptr;
	}
	_enemies.clear();
}

void EnemyManager::SpawnEnemies(int count)
{
	std::vector<Tile*> walkableTiles;
	TileMap::Get()->GetAllWalkableTiles(walkableTiles);
	for (int p = 0; p < _enemies.size(); ++p)
	{
		if (_enemies[p]->IsActive())
		{
			for (int i = 0; i < walkableTiles.size(); ++i)
			{
				if (walkableTiles[i]->HasCollision(_enemies[p]->GetRect()))
				{
					if (i < walkableTiles.size() - 1)
					{
						Tile* tmp = walkableTiles[walkableTiles.size() - 1];
						walkableTiles[walkableTiles.size() - 1] = walkableTiles[i];
						walkableTiles[i] = tmp;
					}
					walkableTiles.pop_back();
					break;
				}
			}
		}
	}
	int prevAvailablePickup = 0;
	for (int i = 0; i < count; ++i)
	{
		prevAvailablePickup = _nextAvailableEnemy - 1;
		if (prevAvailablePickup < 0)
		{
			prevAvailablePickup = _enemies.size() - 1;
		}
		while (_nextAvailableEnemy != prevAvailablePickup)
		{
			Enemy* enemy = _enemies[_nextAvailableEnemy];
			_nextAvailableEnemy = (_nextAvailableEnemy + 1) % (int)_enemies.size();
			if (!enemy->IsActive())
			{
				int randomIndex = (int)floor(X::RandomFloat() * (float)walkableTiles.size());
				Tile* randomTile = walkableTiles[randomIndex];
				enemy->SetActive(randomTile->GetPosition(), 10);

				if (randomIndex < walkableTiles.size() - 1)
				{
					Tile* tmp = walkableTiles[walkableTiles.size() - 1];
					walkableTiles[walkableTiles.size() - 1] = walkableTiles[randomIndex];
					walkableTiles[randomIndex] = tmp;
				}
				walkableTiles.pop_back();

				break;
			}
		}
	}
}