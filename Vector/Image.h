#pragma once
#include "Vector.h"

class Image
{
public:
	Image(unsigned int width, unsigned int height);
	Image(const char* filename);
	~Image();
	void SetPixel(unsigned int x, unsigned int y, const Vector<double>& col);
	Vector<double> GetPixel(unsigned int x, unsigned int y) const;
	void DividePixel(const double div);
	void GammaCorrection(double gamma);
	void OutputPpm(std::ofstream* file);

private:
	Vector<double>* m_Data;
	unsigned int m_Width;
	unsigned int m_Height;
	unsigned int m_Shade = 255;
};

