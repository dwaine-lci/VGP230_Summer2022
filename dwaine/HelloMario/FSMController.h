#pragma once
#include "Enums.h"
#include "States.h"
#include <map>

class FSMController
{
public:
	FSMController();
	virtual ~FSMController();

	void AddState(MovementState moveState, State* state);
	void SetState(MovementState newState);
	void Update(float deltaTime);
	void Cleanup();

private:
	MovementState _currentState;
	std::map<MovementState, State*> _states;
};