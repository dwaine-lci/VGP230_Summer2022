#pragma once
#include "GameState.h"

class StartState : public GameState
{
public:
	StartState();
	virtual ~StartState();

	// abstract functions
	virtual void Load() override;
	virtual State Update(float deltaTime) override;
	virtual void Render() override;
	virtual void Unload() override;
};