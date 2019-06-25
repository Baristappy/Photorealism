#pragma once
#include <iostream>

template<class TYPE> class Vector {
public:
	TYPE x;
	TYPE y;
	TYPE z;

	Vector();
	Vector(TYPE nx, TYPE ny, TYPE nz);
	~Vector();
	Vector operator+(const Vector& vec);
	Vector operator-(const Vector& vec);
	Vector operator*(const Vector& vec);
	Vector operator/(const Vector& vec);
	Vector operator=(const Vector& vec);

	Vector operator+(const TYPE val);
	Vector operator-(const TYPE val);
	Vector operator*(const TYPE val);
	Vector operator/(const TYPE val);

	Vector reverse(void);

	TYPE length(void);
	TYPE lengthPower(void);

	TYPE innerProduct(const Vector& vec);
	Vector crossProduct(const Vector& vec);

	Vector normalization(void);

	void print(void);
};

template<class TYPE> std::ostream& operator<<(std::ostream& out, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator+(TYPE val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator-(TYPE val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator*(TYPE val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator/(TYPE val, const Vector<TYPE>& vec);
