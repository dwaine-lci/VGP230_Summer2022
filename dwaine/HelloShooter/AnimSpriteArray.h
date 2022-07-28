#pragma once
#include <XEngine.h>
#include "Entity.h"

class AnimSpriteArray : public Entity
{
public:
	AnimSpriteArray();
	virtual ~AnimSpriteArray();

	void SetActive(const X::Math::Vector2& position, bool loop = false);
	bool IsActive();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	std::vector<X::TextureId> _sprites;
	X::Math::Vector2 _position;
	float _frameRate;
	float _currentFrameTime;
	int _currentIndex;
	bool _isLooping;
};