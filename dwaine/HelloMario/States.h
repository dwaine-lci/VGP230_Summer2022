#pragma once
#include <XEngine.h>
#include "Enums.h"

class Player;

class State
{
public:
	State(Player* player) : _player(player) {};
	virtual ~State() {}

	virtual void OnEnterState() = 0;
	virtual MovementState Update(float deltaTime) = 0;
	virtual void OnExitState() = 0;

protected:
	Player* _player;
};

class IdleState : public State
{
public:
	IdleState(Player* player);
	virtual ~IdleState();

	virtual void OnEnterState() override;
	virtual MovementState Update(float deltaTime) override;
	virtual void OnExitState() override;
};
class WalkState : public State
{
public:
	WalkState(Player* player);
	virtual ~WalkState();

	virtual void OnEnterState() override;
	virtual MovementState Update(float deltaTime) override;
	virtual void OnExitState() override;
private:
	X::Math::Vector2 _velocity;
};
class JumpState : public State
{
public:
	JumpState(Player* player);
	virtual ~JumpState();

	virtual void OnEnterState() override;
	virtual MovementState Update(float deltaTime) override;
	virtual void OnExitState() override;
private:
	X::Math::Vector2 _velocity;
};
class FallState : public State
{
public:
	FallState(Player* player);
	virtual ~FallState();

	virtual void OnEnterState() override;
	virtual MovementState Update(float deltaTime) override;
	virtual void OnExitState() override;
private:
	X::Math::Vector2 _velocity;
};