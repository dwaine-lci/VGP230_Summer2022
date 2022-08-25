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
	void GetAllWalkableTiles(std::vector<Tile*>& outWalkableTiles);
	bool HasCollision(const X::Math::Rect& objRect, const X::Math::Vector2& maxDisplacement, X::Math::Vector2& outDisplacement) const;
private:
	void ReloadMap();
	TileMap();
	static TileMap* _instance;
	std::vector<Tile*> _tiles;
	int _columns;
	int _rows;
};