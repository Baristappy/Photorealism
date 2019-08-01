#include "PinholeCamera.h"
#include "Vector.h"

PinholeCamera::PinholeCamera(const Vector<double>& pos, const Vector<double>& forward, double pinholeDist) : Camera(pos, forward),m_PinholeDist(pinholeDist){

}

PinholeCamera::~PinholeCamera() {

}

Ray PinholeCamera::getRay(double u, double v) const{
	Vector<double> pinhole = m_Pos + ( m_Forward * m_PinholeDist );
	Vector<double> imagePos = m_Pos + ( u * m_Right) + ( v * m_Up );
	Vector<double> direction = pinhole - imagePos;

	Ray ray(imagePos, direction.normalization());
	return ray;
}