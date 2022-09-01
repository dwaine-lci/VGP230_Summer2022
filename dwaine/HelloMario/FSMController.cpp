#include "FSMController.h"
#include <XEngine.h>


FSMController::FSMController()
{
	_currentState = MovementState::None;
}
FSMController::~FSMController()
{

}

void FSMController::AddState(MovementState moveState, State* state)
{
	XASSERT(_states[moveState] == nullptr, "should not have multiple states of the same type");
	_states[moveState] = state;
}
void FSMController::SetState(MovementState newState)
{
	if (_currentState != newState)
	{
		if (_states[_currentState] != nullptr)
		{
			_states[_currentState]->OnExitState();
		}
		if (_states[newState] != nullptr)
		{
			_states[newState]->OnEnterState();
		}
	}
	_currentState = newState;
}
void FSMController::Update(float deltaTime)
{
	if (_states[_currentState] != nullptr)
	{
		MovementState nextState = _states[_currentState]->Update(deltaTime);
		SetState(nextState);
	}
}
void FSMController::Cleanup()
{
	for (auto state : _states)
	{
		delete state.second;
		state.second = nullptr;
	}

	_states.clear();
}