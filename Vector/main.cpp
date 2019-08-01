#include "Vector.h"
#include "Ray.h"
#include "Image.h"
#include "Sphere.h"
#include "Hit.h"
#include "Camera.h"
#include "PinholeCamera.h"
#include "Aggregate.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>

int main() {

	Vector<double> cameraPos(0, 0, 0);
	Vector<double> cameraForward(0, 0, -1);
	double dist = 1;

	PinholeCamera camera(cameraPos, cameraForward, dist);

	Vector<double> center(0, 0, -3);
	Sphere sphere(center, 1.0);

	Vector<double> floorCenter(0,-10001,0);
	Sphere floor(floorCenter, 10000);

	Vector<double> sunDir(1, 1, 1);
	sunDir = sunDir.normalization();

	Aggregate aggrate;

	aggrate.add(std::make_shared<Sphere>(sphere));
	aggrate.add(std::make_shared<Sphere>(floor));

	unsigned int width = 512;
	unsigned int height = 512;
	Image image(width, height);

	for (unsigned int j = 0; j < height; j++) {
		for (unsigned int i = 0; i < width; i++) {
			double u = (2 * i - static_cast<double>(width)) / static_cast<double>(height);
			double v = (2 * j - static_cast<double>(height)) / static_cast<double>(height);

			Ray ray = camera.getRay(-u, -v);

			Hit hit;
			Vector<double> col(0, 0, 0);
//			Vector<double> maxcol(1, 1, 1);

			if (aggrate.intersect(ray, &hit) == true ){
				//0.0Å`1.0ÇÃä‘Ç…ä€ÇﬂçûÇﬁ
				col = (hit.m_HitNormal + 1.0) / 2.0;

				Ray sunDirRay(hit.m_HitPos + (hit.m_HitNormal * 0.001), sunDir);
				Hit sunHit;

				double bright = 0.0;
				if (aggrate.intersect(sunDirRay, &sunHit) == false) {
					bright = hit.m_HitNormal.innerProduct(sunDir);
					bright = std::max(bright, 0.0);
				}

				col = col * bright;
			}

			image.SetPixel(i, j, col);
		}
	}

	std::ofstream file;

	file.open("aggrate_tracing_shadow_color.ppm", std::ios::out);
	if (file.is_open() == false) {
		std::cout << "output fileopen error!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	image.OutputPpm(&file);

	return 0;

	//Vector<double> pos(0, 0, 0);
	//Vector<double> forward(1, 0, 0);
	//Camera cam(pos, forward);

	//Sphere s(Vector<double>(0,0,0), 1);
	//Ray ray(Vector<double>(0, 0, -3), Vector<double>(0, 0, 1));
	//Hit res;

	//if (s.intersect(ray, &res)) {
	//	std::cout << res.m_HitPos << std::endl;
	//}

	//std::ofstream file;
	//file.open("output.ppm", std::ios::out);
	//if (file.is_open() == false) {
	//	std::cout << "Output FileOpen Error!" << std::endl;
	//	std::exit(EXIT_FAILURE);
	//}

	//unsigned int width = 512;
	//unsigned int height = 512;

	//Image image(width, height);

	//for (unsigned int y = 0; y < height; y++) {
	//	for (unsigned int x = 0; x < width; x++) {
	//		double r = static_cast<double>(y) / static_cast<double>(height);
	//		double g = static_cast<double>(x) / static_cast<double>(width);
	//		double b = 1.0;

	//		Vector<double> col(r, g, b);
	//		image.SetPixel(x, y, col);
	//	}
	//}

	//image.OutputPpm(&file);
}
