#pragma once
#include "Vector.h"

class Ray
{
public:
	Vector<double> m_Origin;
	Vector<double> m_Direction;

	Ray(const Vector<double>& origin, const Vector<double>& direction);
	~Ray();
	
	Vector<double> operator()(double point);
};

std::ostream& operator<<(std::ostream& out, const Ray& ray);