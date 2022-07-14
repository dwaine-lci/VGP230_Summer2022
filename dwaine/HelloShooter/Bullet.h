#pragma once
#include <XEngine.h>
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	void SetActive(const X::Math::Vector2& position, const float& rotation, float lifeTime = 2.0f);
	bool IsActive();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

private:
	X::TextureId _textureId;
	X::Math::Vector2 _position;
	float _rotation;
	float _lifeTime;
};