#pragma once
#pragma once
#include "PickUp.h"
#include <vector>

class PickUpManager : public Entity
{
public:
	virtual ~PickUpManager();
	static PickUpManager* Get();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void SpawnPickUps(int count);
private:
	PickUpManager();
	static PickUpManager* _instance;
	std::vector<PickUp*> _pickups;

	int _nextAvailablePickUp;
};