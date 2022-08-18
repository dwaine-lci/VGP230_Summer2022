#pragma once
#include <XEngine.h>
#include "Enums.h"
#include "Entity.h"

struct TileData
{
	TileType Type;
	X::Math::Vector2 Position;
};
class Tile : public Entity
{
public:
	Tile(const TileData& data);
	virtual ~Tile();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	const X::Math::Vector2& GetPosition() const;
	bool IsCollidable() const;
	bool HasCollision(const X::Math::Rect& objRect) const;
private:
	TileData _data;
	X::TextureId _image;
	X::Math::Rect _rect;
};