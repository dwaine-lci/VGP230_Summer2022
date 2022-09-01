#include "Player.h"
#include "TileMap.h"
#include "CollisionManager.h"

Player::Player()
{
}
Player::~Player()
{
}
void Player::Load()
{
	_image = X::LoadTexture("stone.png");

	_health = 100;
	float halfPlayerWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfPlayerHeight = X::GetSpriteHeight(_image) * 0.5f;
	_playerRect.left = -halfPlayerWidth;
	_playerRect.right = halfPlayerWidth;
	_playerRect.top = -halfPlayerHeight;
	_playerRect.bottom = halfPlayerHeight;

	_velocity = X::Math::Vector2::Zero();
	SetRect(_playerRect);
	const Tile* safeTile = TileMap::Get()->GetFirstWalkableTile();
	SetPosition(safeTile->GetPosition());

	SetCollisionFilter((int)EntityType::PickUp | (int)EntityType::Enemy);
	CollisionManager::Get()->AddCollidable(this);
	_removeCollider = false;

	_stateMachine.Cleanup();
	_stateMachine.AddState(MovementState::Idle, new IdleState(this));
	_stateMachine.AddState(MovementState::Walk, new WalkState(this));
	_stateMachine.AddState(MovementState::Jump, new JumpState(this));
	_stateMachine.AddState(MovementState::Fall , new FallState(this));
	_stateMachine.SetState(MovementState::Fall);
}
void Player::Update(float deltaTime)
{
	if (_health <= 0)
	{
		if (_removeCollider)
		{
			CollisionManager::Get()->RemoveCollidable(this);
			_removeCollider = false;
		}
		return;
	}

	_stateMachine.Update(deltaTime);
}
void Player::Render()
{
	if (_health > 0)
	{
		X::DrawSprite(_image, _position);
	}

	std::string screenText = "HEALTH: " + std::to_string(_health);
	X::DrawScreenText(screenText.c_str(), 4.0f, 4.0f, 20.0f, X::Colors::Yellow);
}
void Player::Unload()
{
	_stateMachine.Cleanup();
}

int Player::GetType() const
{
	return (int)EntityType::Player;
}
void Player::OnCollision(Collidable* collidable)
{
	// depends on object
	if (collidable->GetType() == (int)EntityType::Enemy)
	{
		_health -= 10;
	}
	else if (collidable->GetType() == (int)EntityType::PickUp)
	{
		_health += 5;
	}

	_health = X::Math::Clamp(_health, 0, 100);
	if (_health <= 0)
	{
		_removeCollider = true;
	}
}
void Player::SetPosition(const X::Math::Vector2& position)
{
	_position = position;
	X::Math::Rect currentRect = X::Math::Rect(_playerRect);
	currentRect.min += _position;
	currentRect.max += _position;
	SetRect(currentRect);
}
const X::Math::Vector2& Player::GetPosition() const
{
	return _position;
}
void Player::SetVelocity(const X::Math::Vector2& velocity)
{
	_velocity = velocity;
}
const X::Math::Vector2& Player::GetVelocity() const
{
	return _velocity;
}