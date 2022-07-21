#include "Game.h"
#include "Ship.h"
#include "BulletPool.h"
#include "Bullet.h"
#include "Enemy.h"

Game::Game()
	: Entity()
	, _ship(nullptr)
	, _bulletPool(nullptr)
{

}
Game::~Game()
{

}

void Game::Load()
{
	_ship = new Ship();
	_ship->Load();
	AddCollidable(_ship);

	X::Math::Vector2 spawnPosition = X::Math::Vector2::Zero();
	X::Math::Vector2 spawnDirection = X::Math::Vector2::Zero();
	X::Math::Vector2 center(X::GetScreenWidth() * 0.5f, X::GetScreenHeight() * 0.5f);
	const float minOffset = 100.0f;
	const float maxOffset = X::GetScreenHeight() * 0.5f;
	const int numEnemies = 10;
	for (int i = 0; i < numEnemies; ++i)
	{
		spawnDirection = X::RandomUnitCircle();
		spawnPosition = center + (spawnDirection * X::RandomFloat(minOffset, maxOffset));

		Enemy* newEnemy = new Enemy();
		newEnemy->Load();
		newEnemy->SetPosition(spawnPosition);
		AddCollidable(newEnemy);
		_enemies.push_back(newEnemy);
	}

	_bulletPool = new BulletPool();
	_bulletPool->Load();

	std::vector<Bullet*>& bullets = _bulletPool->GetBullets();
	for (int i = 0; i < bullets.size(); ++i)
	{
		AddCollidable(bullets[i]);
	}

	_ship->SetBulletPool(_bulletPool);
}
void Game::Update(float deltaTime)
{
	XASSERT(_ship != nullptr, "Ship was not created");
	_ship->Update(deltaTime);
	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Update(deltaTime);
	}

	_bulletPool->Update(deltaTime);

	int numCollidables = _collidables.size();
	for (int i = 0; i < numCollidables; ++i)
	{
		for (int n = i + 1; n < numCollidables; ++n)
		{
			if (_collidables[i]->DidCollide(_collidables[n]))
			{
				_collidables[i]->OnCollision(_collidables[n]);
				_collidables[n]->OnCollision(_collidables[i]);
			}
		}
	}
}
void Game::Render()
{
	_ship->Render();
	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Render();
	}
	_bulletPool->Render();
}
void Game::Unload()
{
	_ship->Unload();
	delete _ship;
	_ship = nullptr;

	for (int i = 0; i < _enemies.size(); ++i)
	{
		_enemies[i]->Unload();
		delete _enemies[i];
		_enemies[i] = nullptr;
	}
	_enemies.clear();

	_bulletPool->Unload();
	delete _bulletPool;
	_bulletPool = nullptr;

	_collidables.clear();
}

void Game::AddCollidable(Collidable* collidable)
{
	_collidables.push_back(collidable);
}

bool Game::IsGameOver()
{
	return _ship == nullptr || !_ship->IsAlive();
}
