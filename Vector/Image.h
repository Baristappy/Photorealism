#pragma once
#include "Vector.h"

class Image
{
public:
	Image();
	~Image();
	void SetPixel(int x, int y, const Vector& col);
	Vector GetPixel(int x, int y);
	void DividePixel(double div);
	void GammaCorrection(void);
	void OutputPpm(const std::ofstream& file);

};

