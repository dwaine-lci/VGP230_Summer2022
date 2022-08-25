#pragma once
#include <XEngine.h>
#include "Entity.h"
#include "Collidable.h"

class PickUp : public Entity, public Collidable
{
public:
	PickUp();
	virtual ~PickUp();

	void Load() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Unload() override;

	bool IsActive() const;
	void SetActive(const X::Math::Vector2& position);
	virtual int GetType() const override;
	virtual void OnCollision(Collidable* collidable) override;
	const X::Math::Vector2& GetPosition() const override;
private:
	bool _isActive;
	bool _removeCollision;
	X::TextureId _image;
	X::Math::Vector2 _position;
};

