#include <XEngine.h>
#include "Collidable.h"

Collidable::Collidable(float radius)
	: _radius(radius)
	, _collisionFilter(-1)
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
float Collidable::GetRadius() const
{
	return _radius;
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
				float distanceSqr = X::Math::Vector2::SqrMagnitude((collidable->GetPosition() - GetPosition()));
				float radiusSqr = X::Math::Sqr(collidable->GetRadius() + GetRadius());
				didCollide = distanceSqr <= radiusSqr;
			}
		}
	}

	return didCollide;
}