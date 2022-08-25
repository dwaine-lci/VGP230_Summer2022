#include "PickUpManager.h"
#include "TileMap.h"

PickUpManager* PickUpManager::_instance = nullptr;
PickUpManager::PickUpManager()
{
}
PickUpManager::~PickUpManager()
{
}
PickUpManager* PickUpManager::Get()
{
	if (_instance == nullptr)
	{
		_instance = new PickUpManager();
	}

	return _instance;
}

void PickUpManager::Load()
{
	const int maxPickUps = 100;
	for (int i = 0; i < maxPickUps; ++i)
	{
		PickUp* newPickUp = new PickUp();
		newPickUp->Load();

		_pickups.push_back(newPickUp);
	}

	_nextAvailablePickUp = 0;
}
void PickUpManager::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::RSHIFT))
	{
		SpawnPickUps(10);
	}

	for (int i = 0; i < _pickups.size(); ++i)
	{
		_pickups[i]->Update(deltaTime);
	}
}
void PickUpManager::Render()
{
	for (int i = 0; i < _pickups.size(); ++i)
	{
		_pickups[i]->Render();
	}
}
void PickUpManager::Unload()
{
	for (int i = 0; i < _pickups.size(); ++i)
	{
		_pickups[i]->Unload();
		delete _pickups[i];
		_pickups[i] = nullptr;
	}
	_pickups.clear();
}

void PickUpManager::SpawnPickUps(int count)
{
	std::vector<Tile*> walkableTiles;
	TileMap::Get()->GetAllWalkableTiles(walkableTiles);
	for (int p = 0; p < _pickups.size(); ++p)
	{
		if (_pickups[p]->IsActive())
		{
			for (int i = 0; i < walkableTiles.size(); ++i)
			{
				if (walkableTiles[i]->HasCollision(_pickups[p]->GetRect()))
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
		prevAvailablePickup = _nextAvailablePickUp - 1;
		if (prevAvailablePickup < 0)
		{
			prevAvailablePickup = _pickups.size() - 1;
		}
		while (_nextAvailablePickUp != prevAvailablePickup)
		{
			PickUp* pickUp = _pickups[_nextAvailablePickUp];
			_nextAvailablePickUp = (_nextAvailablePickUp + 1) % (int)_pickups.size();
			if (!pickUp->IsActive())
			{
				int randomIndex = (int)floor(X::RandomFloat() * (float)walkableTiles.size());
				Tile* randomTile = walkableTiles[randomIndex];
				pickUp->SetActive(randomTile->GetPosition());

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