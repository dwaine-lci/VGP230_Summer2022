#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"
#include "Enums.h"

class Bullet : public Entity, public Collidable
{
public:
	Bullet();
	virtual ~Bullet();

	void SetActive(const X::Math::Vector2& position, const float& rotation, EntityType bulletType, float lifeTime = 2.0f);
	bool IsActive();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	int GetType() const override;
	const X::Math::Vector2& GetPosition() const override;
	void OnCollision(Collidable* collidable) override;

private:
	X::TextureId _textureId;
	X::Math::Vector2 _position;
	float _rotation;
	float _lifeTime;
	EntityType _bulletType;
};