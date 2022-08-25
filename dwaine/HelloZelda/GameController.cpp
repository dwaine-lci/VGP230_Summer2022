#include "GameController.h"
#include "TileMap.h"
#include "PickUpManager.h"
#include "CollisionManager.h"

GameController* GameController::_instance = nullptr;
GameController::GameController()
{
}
GameController::~GameController()
{
}
GameController* GameController::Get()
{
	if (_instance == nullptr)
	{
		_instance = new GameController();
	}

	return _instance;
}

void GameController::Load()
{
	CollisionManager::Get()->Load();
	TileMap::Get()->Load();
	_player.Load();
	PickUpManager::Get()->Load();

	PickUpManager::Get()->SpawnPickUps(10);
}
void GameController::Update(float deltaTime)
{
	TileMap::Get()->Update(deltaTime);
	_player.Update(deltaTime);
	PickUpManager::Get()->Update(deltaTime);
	CollisionManager::Get()->Update(deltaTime);
}
void GameController::Render()
{
	TileMap::Get()->Render();
	PickUpManager::Get()->Render();
	_player.Render();
}
void GameController::Unload()
{
	CollisionManager::Get()->Unload();
	TileMap::Get()->Unload();
	PickUpManager::Get()->Unload();
	_player.Unload();
}