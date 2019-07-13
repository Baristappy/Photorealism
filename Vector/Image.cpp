#include "Image.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

Image::Image(unsigned int width, unsigned int height) : m_Height(width), m_Width(height)
{
	m_Data = new Vector<double>[m_Width * m_Height];
	if (m_Data == NULL) {
		std::cout << "Memmory Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Image::Image(const char* filename) {
	std::ifstream file;
	std::string str;

	file.open(filename, std::ios::in);
	if (file.is_open() == false) {
		std::cout << "Load Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	//P3
	file >> str;
	if (str != "P3") {
		std::cout << "Mode Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	//‰¡•
	file >> str;
	m_Width = atoi(str.c_str());
	//c•
	file >> str;
	m_Height = atoi(str.c_str());
	//æ~’²
	file >> str;
	m_Shade = atoi(str.c_str());

	m_Data = new Vector<double>[m_Width * m_Height];
	if (m_Data == NULL) {
		std::cout << "Memmory Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	for (unsigned int y = 0; y < m_Height; y++) {
		for (unsigned int x = 0; x < m_Width; x++) {
			file >> str;
			m_Data[y * m_Width + x].x = atoi(str.c_str());
			file >> str;
			m_Data[y * m_Width + x].y = atoi(str.c_str());
			file >> str;
			m_Data[y * m_Width + x].z = atoi(str.c_str());
		}
	}
}

Image::~Image()
{
	delete[] m_Data;
	m_Data = 0;
}

void Image::SetPixel(unsigned int x, unsigned int y, const Vector<double>& col) {
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

Vector<double> Image::GetPixel(unsigned int x, unsigned int y) const{
	Vector<double> temp;
	
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
			Vector<double> temp = m_Data[y * m_Width + x];
			m_Data[y * m_Width + x].x = std::pow(gamma, temp.x);
			m_Data[y * m_Width + x].y = std::pow(gamma, temp.y);
			m_Data[y * m_Width + x].z = std::pow(gamma, temp.z);
		}
	}
}

void Image::OutputPpm(std::ofstream* file){
	file->seekp(std::ios::beg);

	*file << "P3" << std::endl;
	*file << m_Width << " " << m_Height << std::endl;
	*file << m_Shade << std::endl;

	for (unsigned int y = 0; y < m_Height; y++) {
		for (unsigned int x = 0; x < m_Width; x++) {
			Vector<double> temp = (GetPixel(x, y) * 255.0);
			*file << static_cast<unsigned int>(clamp(temp.x, 0.0, 255.0)) << " " 
				<< static_cast<unsigned int>(clamp(temp.y, 0.0, 255.0)) << " "
				<< static_cast<unsigned int>(clamp(temp.z, 0.0, 255.0)) << std::endl;
		}
	}

	file->close();

}
