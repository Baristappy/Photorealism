#include "Vector.h"
#include <iostream>

Vector::Vector(){
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(double nx, double ny, double nz) {
	x = nx;
	y = ny;
	z = nz;
}

Vector::~Vector() {

}

Vector Vector::operator+(const Vector& vec) {
	Vector tmp;

	tmp.x = this->x + vec.x;
	tmp.y = this->y + vec.y;
	tmp.z = this->z + vec.z;

	return tmp;
}

Vector Vector::operator-(const Vector& vec) {
	Vector tmp;

	tmp.x = this->x - vec.x;
	tmp.y = this->y - vec.y;
	tmp.z = this->z - vec.z;

	return tmp;
}

Vector Vector::operator*(const Vector& vec) {
	Vector tmp;

	tmp.x = this->x * vec.x;
	tmp.y = this->y * vec.y;
	tmp.z = this->z * vec.z;

	return tmp;
}

Vector Vector::operator/(const Vector& vec) {
	Vector tmp;

	if ( vec.x != 0 ) {
		tmp.x = this->x / vec.x;
	}

	if ( vec.y != 0 ) {
		tmp.y = this->y / vec.y;
	}

	if ( vec.z != 0 ) {
		tmp.z = this->z / vec.z;
	}

	return tmp;
}

Vector Vector::operator+(const double val) {
	Vector tmp;

	tmp.x = this->x + val;
	tmp.y = this->y + val;
	tmp.z = this->z + val;

	return tmp;
}

Vector Vector::operator-(const double val) {
	Vector tmp;

	tmp.x = this->x - val;
	tmp.y = this->y - val;
	tmp.z = this->z - val;

	return tmp;
}

Vector Vector::operator*(const double val) {
	Vector tmp;

	tmp.x = this->x * val;
	tmp.y = this->y * val;
	tmp.z = this->z * val;

	return tmp;
}

Vector Vector::operator/(const double val) {
	Vector tmp;

	if (val != 0) {
		tmp.x = this->x / val;
		tmp.y = this->y / val;
		tmp.z = this->z / val;
	}

	return tmp;
}

Vector Vector::reverse(void) {
	Vector tmp;

	tmp.x = -x;
	tmp.y = -y;
	tmp.z = -z;

	return tmp;
}

double Vector::length(void) {
	double length = std::sqrt(lengthPower());
	return length;
}

double Vector::lengthPower(void) {
	double length = x * x + y * y + z * z;
	return length;
}

double Vector::innerProduct(const Vector& vec) {
	double ans = x * vec.x + y * vec.y + z * vec.z;
	return ans;
}

Vector Vector::crossProduct(const Vector& vec) {
	Vector temp;

	temp.x = y * vec.z - vec.y * z;
	temp.y = z * vec.x - vec.z * x;
	temp.z = x * vec.y - vec.x * y;

	return temp;
}

Vector Vector::normalization(void) {
	double len = length();
	Vector temp;

	temp.x = x / len;
	temp.y = y / len;
	temp.z = z / len;

	return temp;
}

void Vector::print() {
	std::cout << x << "," << y << "," << z << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	out << vec.x << "," << vec.y << "," << vec.z;
	return out;
}

Vector operator+(double val, const Vector& vec) {
	Vector temp;

	temp.x = val + vec.x;
	temp.y = val + vec.y;
	temp.z = val + vec.z;

	return temp;
}

Vector operator-(double val, const Vector& vec) {
	Vector temp;

	temp.x = val - vec.x;
	temp.y = val - vec.y;
	temp.z = val - vec.z;

	return temp;

}

Vector operator*(double val, const Vector& vec) {
	Vector temp;

	temp.x = val * vec.x;
	temp.y = val * vec.y;
	temp.z = val * vec.z;

	return temp;

}

Vector operator/(double val, const Vector& vec) {
	Vector temp;

	temp.x = val / vec.x;
	temp.y = val / vec.y;
	temp.z = val / vec.z;

	return temp;

}
