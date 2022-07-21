#include "RunGameState.h"
#include "Game.h"
#include <XEngine.h>

RunGameState::RunGameState()
	: GameState(State::RunGame)
	, _game(nullptr)
{

}
RunGameState::~RunGameState()
{

}

void RunGameState::Load()
{
	_game = new Game();
	_game->Load();
}
State RunGameState::Update(float deltaTime)
{
	if (_game->IsGameOver())
	{
		return State::End;
	}

	_game->Update(deltaTime);
	return State::RunGame;
}
void RunGameState::Render()
{
	_game->Render();
}
void RunGameState::Unload()
{
	if (_game != nullptr)
	{
		_game->Unload();
		delete _game;
		_game = nullptr;
	}
}
