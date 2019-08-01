#pragma once
#include "Camera.h"

class PinholeCamera : public Camera {
public:
	double m_PinholeDist;

	PinholeCamera(const Vector<double>& pos, const Vector<double>& forward, double pinholeDist);
	~PinholeCamera();

	Ray getRay(double u, double v) const;
};
