#include "Ray.h"

Ray::Ray()
{
}

Ray::~Ray()
{
}

const Vector& Ray::GetOrigin(void) const {
	return m_Origin;
}

const Vector& Ray::GetDirection(void) const {
	return m_Direction;
}

Vector Ray::operator()(double point) {
	return m_Origin + point * m_Direction;
}

std::ostream& operator<<(std::ostream& out, const Ray& ray) {
	out << "origin : " << ray.GetOrigin() << "   " << "direction : " << ray.GetDirection();
	return out;
}
