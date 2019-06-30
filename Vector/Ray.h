#pragma once
#include "Vector.h"

class Ray
{
public:
	Ray(const Vector<double>& origin, const Vector<double>& direction);
	~Ray();
	
	const Vector<double>& GetOrigin(void) const;
	const Vector<double>& GetDirection(void) const;
	Vector<double> operator()(double point);

private:
	Vector<double> m_Origin;
	Vector<double> m_Direction;
};

std::ostream& operator<<(std::ostream& out, const Ray& ray);