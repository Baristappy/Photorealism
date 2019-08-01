#include "Sphere.h"
#include "Hit.h"


bool Sphere::intersect(const Ray& ray, Hit* hit) const{
	Vector<double> origin = ray.m_Origin;
	Vector<double> direction = ray.m_Direction;
	Vector<double> originToCenter = origin - m_Center;

	double paramB = direction.innerProduct(originToCenter);
	double paramC = originToCenter.lengthPower() - (m_Radius * m_Radius);
	double paramD = paramB * paramB - paramC;

	if ( paramD < 0 ) {
		return false;
	}

	double t1 = -paramB - std::sqrt(paramD);
	double t2 = -paramB + std::sqrt(paramD);

	if (t1 > 10000 or t2 < 0) return false;

	double t = t1;

	if ( t < 0 ) {
		t = t2;
		if ( t > 10000 ) return false;
	}

	hit->m_Sphere = this;
	hit->m_HitPos = origin + t * direction;
	hit->m_HitDistance = t;
	hit->m_HitNormal = ( hit->m_HitPos - m_Center ).normalization();

	return true;
}