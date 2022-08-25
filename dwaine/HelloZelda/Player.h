#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"

class Player : public Entity, public Collidable
{
public:
	Player();
	virtual ~Player();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	virtual int GetType() const override;
	virtual void OnCollision(Collidable* collidable) override;
	const X::Math::Vector2& GetPosition() const override;

private:
	X::TextureId _image;
	X::Math::Vector2 _position;
	X::Math::Rect _playerRect;
	int _health;
	bool _removeCollider;
};
