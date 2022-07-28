#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Load()
{
	_backgroundTexture = X::LoadTexture("bar_empty.png");
	_foregroundTexture = X::LoadTexture("bar_red.png");
	_barRect.right = X::GetSpriteWidth(_foregroundTexture);
	_barRect.bottom = X::GetSpriteHeight(_foregroundTexture);

	_barFullWidth = _barRect.right;
	_position.x = (X::GetScreenWidth() - _barFullWidth) * 0.5f;
	_position.y = 20.0f;
}

void ProgressBar::Update(float deltaTime)
{
	// check health
}

void ProgressBar::Render()
{
	X::DrawSprite(_backgroundTexture, _position, X::Pivot::Left);
	X::DrawSprite(_foregroundTexture, _barRect, _position, X::Pivot::Left);
}

void ProgressBar::Unload()
{
}

void ProgressBar::SetBarValue(int current, int max)
{
	_barRect.right = X::Math::Clamp((float)current / (float)max, 0.0f, 1.0f) * _barFullWidth;
}