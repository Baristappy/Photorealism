#pragma once
#include "Vector.h"
#include "Ray.h"

class Camera {
public:
	Vector<double> m_Pos;
	Vector<double> m_Forward;
	Vector<double> m_Right;
	Vector<double> m_Up;

	Camera(const Vector<double>& pos, const Vector<double>& forward);
	~Camera();

	virtual Ray getRay(double u, double v) const = 0;
};