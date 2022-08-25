#pragma once
#include "Enums.h"

namespace X {
	namespace Math {
		class Vector2;
		class Rect;
	};
};

class Collidable
{
public:
	Collidable();
	virtual ~Collidable();

	virtual int GetType() const = 0;
	virtual const X::Math::Vector2& GetPosition() const = 0;
	virtual void OnCollision(Collidable* collidable) = 0;

	virtual void SetCollisionFilter(int filter);
	virtual int GetCollisionFilter() const;
	virtual void SetRect(const X::Math::Rect& rect);
	virtual const X::Math::Rect& GetRect() const;
	virtual bool DidCollide(const Collidable* collidable) const;
private:
	X::Math::Rect _rect;
	int _collisionFilter;
};