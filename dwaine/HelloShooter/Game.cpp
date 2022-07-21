#include "Game.h"
#include "Ship.h"
#include "BulletPool.h"
#include "Bullet.h"

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
	_bulletPool->Render();
}
void Game::Unload()
{
	_ship->Unload();
	delete _ship;
	_ship = nullptr;

	_bulletPool->Unload();
	delete _bulletPool;
	_bulletPool = nullptr;

	_collidables.clear();
}

void Game::AddCollidable(Collidable* collidable)
{
	_collidables.push_back(collidable);
}