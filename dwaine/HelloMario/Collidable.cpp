#include <XEngine.h>
#include "Collidable.h"

Collidable::Collidable()
	: _collisionFilter(-1)
{

}
Collidable::~Collidable()
{

}

void Collidable::SetCollisionFilter(int filter)
{
	_collisionFilter = filter;
}

int Collidable::GetCollisionFilter() const
{
	return _collisionFilter;
}
void Collidable::SetRect(const X::Math::Rect& rect)
{
	_rect = rect;
}
const X::Math::Rect& Collidable::GetRect() const
{
	return _rect;
}
bool Collidable::DidCollide(const Collidable* collidable) const
{
	bool didCollide = false;
	if (collidable != nullptr)
	{
		int collidableFilter = collidable->GetCollisionFilter();
		int collisionFilter = GetCollisionFilter();
		if (collidableFilter != 0 && collisionFilter != 0)
		{
			if (collidableFilter < 0 || collisionFilter < 0 || (collidableFilter & GetType()) > 0)
			{
				didCollide = X::Math::Intersect(_rect, collidable->GetRect());
			}
		}
	}

	return didCollide;
}