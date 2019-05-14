#pragma once
#include <iostream>

class Vector {
public:
	double x;
	double y;
	double z;

	Vector();
	Vector(double nx, double ny, double nz);
	~Vector();
	Vector operator+(const Vector& vec);
	Vector operator-(const Vector& vec);
	Vector operator*(const Vector& vec);
	Vector operator/(const Vector& vec);

	Vector operator+(const double val);
	Vector operator-(const double val);
	Vector operator*(const double val);
	Vector operator/(const double val);

	Vector reverse(void);

	double length(void);
	double lengthPower(void);

	double innerProduct(const Vector& vec);
	Vector crossProduct(const Vector& vec);

	Vector normalization(void);

	void print(void);
};

std::ostream& operator<<(std::ostream& out, const Vector& vec);
Vector operator+(double val, const Vector& vec);
Vector operator-(double val, const Vector& vec);
Vector operator*(double val, const Vector& vec);
Vector operator/(double val, const Vector& vec);
