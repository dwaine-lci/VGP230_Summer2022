#include "AnimSpriteSheet.h"

AnimSpriteSheet::AnimSpriteSheet()
{
}

AnimSpriteSheet::~AnimSpriteSheet()
{
}

void AnimSpriteSheet::SetActive(const X::Math::Vector2& position, bool loop)
{
	_position = position;
	_isLooping = loop;
	_currentIndex = 0;
	_currentFrameTime = 0.0f;
}

bool AnimSpriteSheet::IsActive()
{
	return _isLooping || _currentIndex >= 0;
}

void AnimSpriteSheet::Load()
{
	_spriteSheet = X::LoadTexture("explosion_anim.png");
	_spriteRect.right = 100.0f;
	_spriteRect.bottom = 100.0f;
	_maxFrames = 81;
	_rows = 9;
	_columns = 9;
	_frameRate = 1.0f / 120.0f;
	_isLooping = false;
	_currentIndex = -1;
}
void AnimSpriteSheet::Update(float deltaTime)
{
	if (IsActive())
	{
		_currentFrameTime += deltaTime;
		while (_currentFrameTime > _frameRate)
		{
			_currentFrameTime -= _frameRate;
			++_currentIndex;
		}
		if (_currentIndex >= _maxFrames)
		{
			if (_isLooping)
			{
				_currentIndex -= _maxFrames;
			}
			else
			{
				_currentIndex = -1;
			}
		}

		const float rectWidth = 100.0f;
		const float rectHeight = 100.0f;
		_spriteRect.left = (_currentIndex % _columns) * rectWidth;
		_spriteRect.top = (_currentIndex / _columns) * rectHeight;
		_spriteRect.right = _spriteRect.left + rectWidth;
		_spriteRect.bottom = _spriteRect.top + rectHeight;
	}
}

void AnimSpriteSheet::Render()
{
	if (IsActive())
	{
		X::DrawSprite(_spriteSheet, _spriteRect, _position);
	}
}

void AnimSpriteSheet::Unload()
{
}