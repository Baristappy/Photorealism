#include "Vector.h"
#include "Ray.h"
#include "Image.h"
#include <iostream>
#include <iostream>
#include <fstream>

int main() {
	std::ofstream file;
	file.open("output.ppm", std::ios::out);
	if (file.is_open() == false) {
		std::cout << "Output FileOpen Error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	unsigned int width = 512;
	unsigned int height = 512;

	Image image(width, height);

	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			double r = static_cast<double>(y) / static_cast<double>(height);
			double g = static_cast<double>(x) / static_cast<double>(width);
			double b = 1.0;

			Vector<double> col(r, g, b);
			image.SetPixel(x, y, col);
		}
	}

	image.OutputPpm(&file);
}
