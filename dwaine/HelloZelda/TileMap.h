#pragma once
#include "Tile.h"
#include <vector>

class TileMap : public Entity
{
public:
	virtual ~TileMap();
	static TileMap* Get();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	const Tile* GetFirstWalkableTile();
	bool HasCollision(const X::Math::Rect& objRect) const;
private:
	void ReloadMap();
	TileMap();
	static TileMap* _instance;
	std::vector<Tile*> _tiles;
	int _columns;
	int _rows;
};