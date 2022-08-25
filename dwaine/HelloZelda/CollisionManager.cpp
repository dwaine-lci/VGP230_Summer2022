#include "CollisionManager.h"
#include "Collidable.h"

CollisionManager* CollisionManager::_instance = nullptr;
CollisionManager::CollisionManager()
{
}
CollisionManager::~CollisionManager()
{
}
CollisionManager* CollisionManager::Get()
{
	if (_instance == nullptr)
	{
		_instance = new CollisionManager();
	}

	return _instance;
}

void CollisionManager::AddCollidable(Collidable* collidable)
{
	if (std::find(_collidables.begin(), _collidables.end(), collidable) == _collidables.end())
	{
		_collidables.push_back(collidable);
	}
}
void CollisionManager::RemoveCollidable(Collidable* collidable)
{
	(void)std::remove(_collidables.begin(), _collidables.end(), collidable);
}

void CollisionManager::Load()
{

}
void CollisionManager::Update(float deltaTime)
{
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
void CollisionManager::Render()
{
}
void CollisionManager::Unload()
{
	_collidables.clear();
}