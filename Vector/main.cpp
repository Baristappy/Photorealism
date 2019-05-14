#include <iostream>
#include "Vector.h"
#include "Ray.h"

int main() {
	/*
	Vector vec1(1, 2, 3);
	Vector vec2(4, 5, 6);

	std::cout << vec1 + vec2 << std::endl;
	std::cout << vec1 - vec2 << std::endl;
	std::cout << vec1 * vec2 << std::endl;
	std::cout << vec1 / vec2 << std::endl;

	std::cout << vec1 + 1 << std::endl;
	std::cout << vec1 - 1 << std::endl;
	std::cout << vec1 * 2 << std::endl;
	std::cout << vec1 / 2 << std::endl;

	std::cout << vec1.innerProduct(vec2) << std::endl;
	std::cout << vec1.crossProduct(vec2) << std::endl;

	std::cout << vec1.length() << std::endl;
	*/

	Vector vec1(0, 0, 0);
	Vector vec2(0, 0, 1);
	Ray ray(vec1, vec2);

	std::cout << ray << std::endl;
	std::cout << ray(10) << std::endl;
}
