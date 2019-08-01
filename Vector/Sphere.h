#pragma once
#include "Vector.h"
#include "Ray.h"

class Hit;

class Sphere {
public:
	Vector<double> m_Center;
	double m_Radius;

	bool intersect(const Ray& ray, Hit* res) const;

	Sphere(const Vector<double>& center, double radius) : m_Center(center), m_Radius(radius) { } ;
	~Sphere() {};
};