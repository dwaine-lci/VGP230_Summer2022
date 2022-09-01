#include "States.h"
#include "Player.h"
#include "TileMap.h"

const float cWalkSpeed = 200.0f;
const float cJumpSpeed = 300.0f;
const float cFrictionAccel = 600.0f;
const float cFallAccel = 300.0f;
const float cMaxWalkSpeed = 300.0f;
const float cMaxFallSpeed = 300.0f;
IdleState::IdleState(Player* player)
	: State(player)
{

}
IdleState::~IdleState()
{

}
void IdleState::OnEnterState()
{

}
MovementState IdleState::Update(float deltaTime)
{
	if (X::IsKeyDown(X::Keys::A) || X::IsKeyDown(X::Keys::D))
	{
		return MovementState::Walk;
	}
	if (X::IsKeyDown(X::Keys::W))
	{
		return MovementState::Jump;
	}
	return MovementState::Idle;
}
void IdleState::OnExitState()
{

}


WalkState::WalkState(Player* player)
	: State(player)
{

}
WalkState::~WalkState()
{

}
void WalkState::OnEnterState()
{
	_velocity = _player->GetVelocity();
}
MovementState WalkState::Update(float deltaTime)
{
	X::Math::Vector2 displacement;
	if (X::IsKeyDown(X::Keys::W))
	{
		return MovementState::Jump;
	}
	if (X::IsKeyDown(X::Keys::A))
	{
		if (_velocity.x > 0.0f)
		{
			_velocity.x -= 2.0f * (cWalkSpeed + cFrictionAccel) * deltaTime;
		}
		else
		{
			_velocity.x -= cWalkSpeed * deltaTime;
		}
		_velocity.x = X::Math::Max(_velocity.x, -cMaxWalkSpeed);
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		if (_velocity.x < 0.0f)
		{
			_velocity.x += 2.0f * (cWalkSpeed + cFrictionAccel) * deltaTime;
		}
		else
		{
			_velocity.x += cWalkSpeed * deltaTime;
		}
		_velocity.x = X::Math::Min(_velocity.x, cMaxWalkSpeed);
	}
	else
	{
		if (_velocity.x < 0.0f)
		{
			_velocity.x += cFrictionAccel * deltaTime;
		}
		else
		{
			_velocity.x -= cFrictionAccel * deltaTime;
		}
		if (abs(_velocity.x) < 0.01f)
		{
			_velocity.x = 0.0f;
		}
	}
	displacement.x = _velocity.x * deltaTime;
	displacement.y = cWalkSpeed * deltaTime;
	X::Math::Vector2 position = _player->GetPosition();
	X::Math::Vector2 maxDisplacement = displacement;
	if (TileMap::Get()->HasCollision(_player->GetRect(), maxDisplacement, displacement))
	{
		position += displacement;
	}
	else
	{
		position += displacement;
	}
	_player->SetVelocity(_velocity);
	_player->SetPosition(position);

	if (displacement.y > 0.0f)
	{
		return MovementState::Fall;
	}
	return MovementState::Walk;
}
void WalkState::OnExitState()
{

}


JumpState::JumpState(Player* player)
	: State(player)
{

}
JumpState::~JumpState()
{

}
void JumpState::OnEnterState()
{
	_velocity = _player->GetVelocity();
	_velocity.y = -cJumpSpeed;
}
MovementState JumpState::Update(float deltaTime)
{
	X::Math::Vector2 displacement;
	if (X::IsKeyDown(X::Keys::A))
	{
		_velocity.x -= cWalkSpeed * deltaTime;
		_velocity.x = X::Math::Max(_velocity.x, -cMaxWalkSpeed);
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		_velocity.x += cWalkSpeed * deltaTime;
		_velocity.x = X::Math::Min(_velocity.x, cMaxWalkSpeed);
	}
	else
	{
		if (_velocity.x < 0.0f)
		{
			_velocity.x += cFrictionAccel * 0.5f * deltaTime;
		}
		else
		{
			_velocity.x -= cFrictionAccel * 0.5f * deltaTime;
		}
		if (abs(_velocity.x) < 0.01f)
		{
			_velocity.x = 0.0f;
		}
	}
	displacement.x = _velocity.x * deltaTime;
	displacement.y += _velocity.y * deltaTime;
	_velocity.y += cFallAccel * deltaTime;
	X::Math::Vector2 position = _player->GetPosition();
	X::Math::Vector2 maxDisplacement = displacement;
	if (TileMap::Get()->HasCollision(_player->GetRect(), maxDisplacement, displacement))
	{
		position += displacement;
	}
	else
	{
		position += displacement;
	}
	_player->SetVelocity(_velocity);
	_player->SetPosition(position);

	if (_velocity.y >= 0.0f)
	{
		return MovementState::Fall;
	}
	return MovementState::Jump;
}
void JumpState::OnExitState()
{

}


FallState::FallState(Player* player)
	: State(player)
{

}
FallState::~FallState()
{

}
void FallState::OnEnterState()
{
	_velocity = _player->GetVelocity();
}
MovementState FallState::Update(float deltaTime)
{
	X::Math::Vector2 displacement;
	if (X::IsKeyDown(X::Keys::A))
	{
		_velocity.x -= cWalkSpeed * deltaTime;
		_velocity.x = X::Math::Max(_velocity.x, -cMaxWalkSpeed);
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		_velocity.x += cWalkSpeed * deltaTime;
		_velocity.x = X::Math::Min(_velocity.x, cMaxWalkSpeed);
	}
	else
	{
		if (_velocity.x < 0.0f)
		{
			_velocity.x += cFrictionAccel * 0.75f * deltaTime;
		}
		else
		{
			_velocity.x -= cFrictionAccel * 0.75f * deltaTime;
		}
		if (abs(_velocity.x) < 0.01f)
		{
			_velocity.x = 0.0f;
		}
	}
	displacement.x = _velocity.x * deltaTime;
	_velocity.y += cFallAccel * deltaTime;
	_velocity.y = X::Math::Min(_velocity.y, cMaxFallSpeed);
	displacement.y = _velocity.y * deltaTime;

	X::Math::Vector2 position = _player->GetPosition();
	X::Math::Vector2 maxDisplacement = displacement;
	if (TileMap::Get()->HasCollision(_player->GetRect(), maxDisplacement, displacement))
	{
		position += displacement;
	}
	else
	{
		position += displacement;
	}
	_player->SetPosition(position);

	if (displacement.y < maxDisplacement.y)
	{
		if (abs(displacement.x) > 0.0f)
		{
			return MovementState::Walk;
		}
		return MovementState::Idle;
	}
	return MovementState::Fall;
}
void FallState::OnExitState()
{

}