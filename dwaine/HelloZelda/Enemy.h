#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"

class Enemy : public Entity, public Collidable
{
public:
	Enemy();
	virtual ~Enemy();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	bool IsActive() const;
	void SetActive(const X::Math::Vector2& position, int health);
	int GetType() const override;
	const X::Math::Vector2& GetPosition() const override;
	void OnCollision(Collidable* collidable) override;

private:
	X::TextureId _image;
	X::Math::Vector2 _position;
	X::Math::Vector2 _centerPoint;
	X::Math::Vector2 _targetPosition;
	X::Math::Rect _enemyRect;
	float _targetPositionUpdate;
	int _health;
	bool _removeCollider;
};
