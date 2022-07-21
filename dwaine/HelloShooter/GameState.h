#pragma once
#include "Enums.h"

class GameState
{
public:
	GameState(State state) : _state(state) {}
	virtual ~GameState() {}

	State GetState() const { return _state; }

	// abstract functions
	virtual void Load() = 0;
	virtual State Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Unload() = 0;

private:
	State _state;
};