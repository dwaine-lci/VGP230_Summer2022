#pragma once
#include "Entity.h"

class Ship;

class Game : public Entity
{
public:
	Game();
	virtual ~Game();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;
	
private:
	Ship* _ship;
};