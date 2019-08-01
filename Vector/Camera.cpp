#include "Camera.h"

Camera::Camera(const Vector<double>& pos, const Vector<double>& forward) : m_Pos(pos), m_Forward(forward) {
	orthonormalBasic(&m_Forward, &m_Right, &m_Up);

	std::cout << "m_Pos : " << m_Pos << std::endl
		<< "m_Forward : " << m_Forward << std::endl
		<< "m_Right : " << m_Right << std::endl
		<< "m_Up : " << m_Up << std::endl;
}

Camera::~Camera() {

}
