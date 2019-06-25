#pragma once
#include "Vector.h"

class Image
{
public:
	Image(unsigned int width, unsigned int height);
	~Image();
	void SetPixel(unsigned int x, unsigned int y, const Vector<unsigned int>& col);
	Vector<unsigned int> GetPixel(unsigned int x, unsigned int y) const;
	void DividePixel(const double div);
	void GammaCorrection(double gamma);
	void OutputPpm(const std::ofstream& file) const;

private:
	Vector<unsigned int>* m_Data;
	const unsigned int m_Width;
	const unsigned int m_Height;
};

