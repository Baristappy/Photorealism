#pragma once
#include "Vector.h"

class Ray
{
public:
	Ray();
	Ray(const Vector& origin, const Vector& direction) : m_Origin(origin), m_Direction(direction){};
	~Ray();
	
	const Vector& GetOrigin(void) const;
	const Vector& GetDirection(void) const;
	Vector operator()(double point);

private:
	Vector m_Origin;
	Vector m_Direction;
};

std::ostream& operator<<(std::ostream& out, const Ray& ray);