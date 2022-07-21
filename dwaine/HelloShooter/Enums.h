#pragma once

enum class EntityType : int
{
	Ship			= 1 << 0,
	Bullet_Player	= 1 << 1,
	Bullet_Enemy	= 1 << 2,
	Enemy			= 1 << 3
};

enum class State : int
{
	Start,
	RunGame,
	End
};