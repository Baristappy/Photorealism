#include "Ray.h"

Ray::Ray(const Vector<double>& origin, const Vector<double>& direction) : m_Origin(origin), m_Direction(direction)
{
}

Ray::~Ray()
{
}

Vector<double> Ray::operator()(double point) {
	return m_Origin + point * m_Direction;
}

std::ostream& operator<<(std::ostream& out, const Ray& ray) {
	out << "origin : " << ray.m_Origin << "   " << "direction : " << ray.m_Direction;
	return out;
}
