#pragma once
#include <XEngine.h>
#include "Entity.h"

class AnimSpriteSheet : public Entity
{
public:
	AnimSpriteSheet();
	virtual ~AnimSpriteSheet();

	void SetActive(const X::Math::Vector2& position, bool loop = false);
	bool IsActive();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	X::TextureId _spriteSheet;
	X::Math::Rect _spriteRect;
	X::Math::Vector2 _position;
	float _frameRate;
	float _currentFrameTime;
	int _rows;
	int _columns;
	int _maxFrames;
	int _currentIndex;
	bool _isLooping;
};