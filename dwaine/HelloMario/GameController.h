#pragma once
#include "Entity.h"
#include "Player.h"

class GameController : public Entity
{
public:
	virtual ~GameController();
	static GameController* Get();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;
private:
	GameController();
	static GameController* _instance;
	Player _player;
};