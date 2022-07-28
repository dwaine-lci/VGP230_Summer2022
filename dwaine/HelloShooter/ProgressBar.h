#pragma once
#include <XEngine.h>
#include "Entity.h"

class ProgressBar : public Entity
{
public:
	ProgressBar();
	virtual ~ProgressBar();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	void SetBarValue(int current, int max);

private:
	X::TextureId _backgroundTexture;
	X::TextureId _foregroundTexture;
	X::Math::Rect _barRect;
	X::Math::Vector2 _position;
	float _barFullWidth;
};