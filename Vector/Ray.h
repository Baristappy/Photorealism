#pragma once
#include "Vector.h"

class Ray
{
public:
	Ray();
	Ray(const Vector<double>& origin, const Vector<double>& direction) : m_Origin(origin), m_Direction(direction){};
	~Ray();
	
	const Vector<double>& GetOrigin(void) const;
	const Vector<double>& GetDirection(void) const;
	Vector<double> operator()(double point);

private:
	Vector<double> m_Origin;
	Vector<double> m_Direction;
};

std::ostream& operator<<(std::ostream& out, const Ray& ray);