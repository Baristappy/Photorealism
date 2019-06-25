#include "Image.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


Image::Image(unsigned int width, unsigned int height) : m_Height(width), m_Width(height)
{
	m_Data = new Vector<unsigned int>[m_Width * m_Height];
	if (m_Data == NULL) {
		std::cout << "Memmory Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


Image::~Image()
{
	delete[] m_Data;
	m_Data = 0;
}

void Image::SetPixel(unsigned int x, unsigned int y, const Vector<unsigned int>& col) {
	if ( x < 0 || x >= m_Width ) {
		return;
	}
	if ( y < 0 || y >= m_Height ) {
		return;
	}
	if (m_Data == NULL ) {
		return;
	}

	m_Data[y * m_Width + x] = col;
}

Vector<unsigned int> Image::GetPixel(unsigned int x, unsigned int y) const{
	Vector<unsigned int> temp;
	
	if (x < 0 || x >= m_Width) {
		return temp;
	}
	if (y < 0 || y >= m_Height) {
		return temp;
	}
	if (m_Data == NULL) {
		return temp;
	}

	temp = m_Data[y * m_Width + x];
	return temp;
}

void Image::DividePixel(const double div) {
	for ( unsigned int y = 0; y < m_Height; y++ ) {
		for ( unsigned int x = 0; x < m_Width; x++ ) {
			m_Data[y * m_Width + x] = m_Data[y * m_Width + x] / div;
		}
	}
}

void Image::GammaCorrection(double gamma) {
	for (unsigned int y = 0; y < m_Height; y++) {
		for (unsigned int x = 0; x < m_Width; x++) {
			m_Data[y * m_Width + x].x = std::pow(gamma, m_Data[y * m_Width + x].x);
			m_Data[y * m_Width + x].y = std::pow(gamma, m_Data[y * m_Width + x].y);
			m_Data[y * m_Width + x].z = std::pow(gamma, m_Data[y * m_Width + x].z);
		}
	}
}

void Image::OutputPpm(const std::ofstream& file) const{
}