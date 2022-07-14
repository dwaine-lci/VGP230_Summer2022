#include "Game.h"
#include "Ship.h"

Game::Game()
	: Entity()
	, _ship(nullptr)
{

}
Game::~Game()
{

}

void Game::Load()
{
	_ship = new Ship();
	_ship->Load();
}
void Game::Update(float deltaTime)
{
	XASSERT(_ship != nullptr, "Ship was not created");
	_ship->Update(deltaTime);
}
void Game::Render()
{
	_ship->Render();
}
void Game::Unload()
{
	_ship->Unload();
	delete _ship;
	_ship = nullptr;
}