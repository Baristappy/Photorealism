#pragma once
#include "Sphere.h"
#include "Hit.h"
#include <memory>
#include <vector>

class Aggregate{
private:
	std::vector<std::shared_ptr<Sphere>> m_Spheres;

public:
	void add(const std::shared_ptr<Sphere>& sphere);
	bool intersect(const Ray& ray, Hit* hit) const;
};