#include "Aggregate.h"

void Aggregate::add(const std::shared_ptr<Sphere>& sphere) {
	if (sphere) {
		m_Spheres.push_back(sphere);
	}
}

bool Aggregate::intersect(const Ray& ray, Hit* hit)const {

	bool result = false;
	int num = m_Spheres.size();

	for (int i = 0; i < num; i++) {
		Hit res;
		if (m_Spheres[i]->intersect(ray, &res)) {
			if (res.m_HitDistance < hit->m_HitDistance) {
				*hit = res;
				result = true;
			}
		}
	}

	return result;
}