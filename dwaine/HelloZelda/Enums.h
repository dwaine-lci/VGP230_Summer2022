#pragma once

enum class EntityType : int
{
	Player			= 1 << 0,
	Tile			= 1 << 1,
	Enemy			= 1 << 2
};

enum class TileType : int
{
	None = -1,
	Ground,
	Wall
};