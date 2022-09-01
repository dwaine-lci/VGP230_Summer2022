#pragma once

enum class EntityType : int
{
	Player			= 1 << 0,
	Tile			= 1 << 1,
	Enemy			= 1 << 2,
	PickUp			= 1 << 3
};

enum class TileType : int
{
	None = -1,
	Ground,
	Wall
};

enum class MovementState : int
{
	None = -1,
	Idle,
	Walk,
	Jump,
	Fall
};