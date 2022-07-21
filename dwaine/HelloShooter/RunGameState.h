#pragma once
#include "GameState.h"

class Game;

class RunGameState : public GameState
{
public:
	RunGameState();
	virtual ~RunGameState();

	// abstract functions
	virtual void Load() override;
	virtual State Update(float deltaTime) override;
	virtual void Render() override;
	virtual void Unload() override;
private:
	Game* _game;
};