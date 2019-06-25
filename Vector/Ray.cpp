#include "Ray.h"

Ray::Ray()
{
}

Ray::~Ray()
{
}

const Vector<double>& Ray::GetOrigin(void) const {
	return m_Origin;
}

const Vector<double>& Ray::GetDirection(void) const {
	return m_Direction;
}

Vector<double> Ray::operator()(double point) {
	return m_Origin + point * m_Direction;
}

std::ostream& operator<<(std::ostream& out, const Ray& ray) {
	out << "origin : " << ray.GetOrigin() << "   " << "direction : " << ray.GetDirection();
	return out;
}
