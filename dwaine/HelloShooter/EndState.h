#pragma once
#include "GameState.h"

class EndState : public GameState
{
public:
	EndState();
	virtual ~EndState();

	// abstract functions
	virtual void Load() override;
	virtual State Update(float deltaTime) override;
	virtual void Render() override;
	virtual void Unload() override;
};
