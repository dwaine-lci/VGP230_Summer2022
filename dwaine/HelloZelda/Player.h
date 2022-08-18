#pragma once
#include <XEngine.h>
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	X::TextureId _image;
	X::Math::Vector2 _position;
};
