#pragma once
#include "Vector.h"

class Sphere;

class Hit {
public:
	double m_HitDistance = 10000;
	Vector<double> m_HitPos;
	Vector<double> m_HitNormal;
	const Sphere* m_Sphere;
};