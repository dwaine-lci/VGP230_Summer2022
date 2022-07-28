#include "AnimSpriteArray.h"

AnimSpriteArray::AnimSpriteArray()
{
}

AnimSpriteArray::~AnimSpriteArray()
{
}

void AnimSpriteArray::SetActive(const X::Math::Vector2& position, bool loop)
{
	_position = position;
	_isLooping = loop;
	_currentIndex = 0;
	_currentFrameTime = 0.0f;
}

bool AnimSpriteArray::IsActive()
{
	return _isLooping || _currentIndex >= 0;
}

void AnimSpriteArray::Load()
{
	const int frameCount = 32;
	std::string textureName;
	for (int i = 0; i < frameCount; ++i)
	{
		if(i < 9)
		{
			textureName = "carrier_0";
		}
		else
		{
			textureName = "carrier_";
		}
		textureName += std::to_string(i + 1);
		textureName += ".png";
		X::TextureId imageId = X::LoadTexture(textureName.c_str());
		_sprites.push_back(imageId);
	}

	_frameRate = 1.0f / 30.0f;
	_isLooping = false;
	_currentIndex = -1;
}
void AnimSpriteArray::Update(float deltaTime)
{
	if (IsActive())
	{
		_currentFrameTime += deltaTime;
		while (_currentFrameTime > _frameRate)
		{
			_currentFrameTime -= _frameRate;
			++_currentIndex;
		}
		if (_currentIndex >= _sprites.size())
		{
			if (_isLooping)
			{
				_currentIndex -= _sprites.size();
			}
			else
			{
				_currentIndex = -1;
			}
		}
	}
}

void AnimSpriteArray::Render()
{
	if (IsActive())
	{
		X::DrawSprite(_sprites[_currentIndex], _position);
	}
}

void AnimSpriteArray::Unload()
{
}