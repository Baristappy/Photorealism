#pragma once
#include <iostream>

template<class TYPE> class Vector {
public:
	TYPE x;
	TYPE y;
	TYPE z;

	Vector();
	Vector(const Vector& vec);
	Vector(TYPE nx, TYPE ny, TYPE nz);
	~Vector();
	Vector operator+(const Vector& vec)const;
	Vector operator-(const Vector& vec)const;
	Vector operator*(const Vector& vec)const;
	Vector operator/(const Vector& vec)const;
	void operator=(const Vector& vec);

	Vector operator+(double val)const;
	Vector operator-(double val)const;
	Vector operator*(double val)const;
	Vector operator/(double val)const;

	Vector reverse(void);

	TYPE length(void);
	TYPE lengthPower(void);

	TYPE innerProduct(const Vector& vec);
	Vector crossProduct(const Vector& vec);

	Vector normalization(void);

	void print(void);
};

template<class TYPE> std::ostream& operator<<(std::ostream& out, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator+(double val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator-(double val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator*(double val, const Vector<TYPE>& vec);
template<class TYPE> Vector<TYPE> operator/(double val, const Vector<TYPE>& vec);
template<class TYPE> void orthonormalBasic(Vector<TYPE>* v1, Vector<TYPE>* v2, Vector<TYPE>* v3);

template <class TYPE> Vector<TYPE>::Vector() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

template <class TYPE> Vector<TYPE>::Vector(TYPE nx, TYPE ny, TYPE nz) {
	x = nx;
	y = ny;
	z = nz;
}

template <class TYPE> Vector<TYPE>::Vector(const Vector& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

template <class TYPE> Vector<TYPE>::~Vector() {

}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator+(const Vector<TYPE>& vec) const {
	Vector<TYPE> tmp;

	tmp.x = this->x + vec.x;
	tmp.y = this->y + vec.y;
	tmp.z = this->z + vec.z;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator-(const Vector<TYPE>& vec) const {
	Vector<TYPE> tmp;

	tmp.x = this->x - vec.x;
	tmp.y = this->y - vec.y;
	tmp.z = this->z - vec.z;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator*(const Vector<TYPE>& vec) const {
	Vector<TYPE> tmp;

	tmp.x = this->x * vec.x;
	tmp.y = this->y * vec.y;
	tmp.z = this->z * vec.z;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator/(const Vector<TYPE>& vec) const {
	Vector<TYPE> tmp;

	if (vec.x != 0) {
		tmp.x = this->x / vec.x;
	}

	if (vec.y != 0) {
		tmp.y = this->y / vec.y;
	}

	if (vec.z != 0) {
		tmp.z = this->z / vec.z;
	}

	return tmp;
}

template <class TYPE> void Vector<TYPE>::operator=(const Vector<TYPE>& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator+(double val) const {
	Vector<TYPE> tmp;

	tmp.x = this->x + val;
	tmp.y = this->y + val;
	tmp.z = this->z + val;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator-(double val) const {
	Vector<TYPE> tmp;

	tmp.x = this->x - val;
	tmp.y = this->y - val;
	tmp.z = this->z - val;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator*(double val) const {
	Vector<TYPE> tmp;

	tmp.x = this->x * val;
	tmp.y = this->y * val;
	tmp.z = this->z * val;

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::operator/(double val) const {
	Vector<TYPE> tmp;

	if (val != 0) {
		tmp.x = this->x / val;
		tmp.y = this->y / val;
		tmp.z = this->z / val;
	}

	return tmp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::reverse(void) {
	Vector<TYPE> tmp;

	tmp.x = -x;
	tmp.y = -y;
	tmp.z = -z;

	return tmp;
}

template <class TYPE> TYPE Vector<TYPE>::length(void) {
	TYPE length = std::sqrt(lengthPower());
	return length;
}

template <class TYPE> TYPE Vector<TYPE>::lengthPower(void) {
	TYPE length = x * x + y * y + z * z;
	return length;
}

template <class TYPE> TYPE Vector<TYPE>::innerProduct(const Vector<TYPE>& vec) {
	TYPE ans = x * vec.x + y * vec.y + z * vec.z;
	return ans;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::crossProduct(const Vector<TYPE>& vec) {
	Vector<TYPE> temp;

	temp.x = y * vec.z - vec.y * z;
	temp.y = z * vec.x - vec.z * x;
	temp.z = x * vec.y - vec.x * y;

	return temp;
}

template <class TYPE> Vector<TYPE> Vector<TYPE>::normalization(void) {
	TYPE len = length();
	Vector<TYPE> temp;

	temp.x = x / len;
	temp.y = y / len;
	temp.z = z / len;

	return temp;
}

template <class TYPE> void Vector<TYPE>::print() {
	std::cout << x << "," << y << "," << z << std::endl;
}

template <class TYPE> std::ostream& operator<<(std::ostream& out, const Vector<TYPE>& vec) {
	out << vec.x << "," << vec.y << "," << vec.z;
	return out;
}

template <class TYPE> Vector<TYPE> operator+(double val, const Vector<TYPE>& vec) {
	Vector<TYPE> temp;

	temp.x = val + vec.x;
	temp.y = val + vec.y;
	temp.z = val + vec.z;

	return temp;
}

template <class TYPE> Vector<TYPE> operator-(double val, const Vector<TYPE>& vec) {
	Vector<TYPE> temp;

	temp.x = val - vec.x;
	temp.y = val - vec.y;
	temp.z = val - vec.z;

	return temp;

}

template <class TYPE> Vector<TYPE> operator*(double val, const Vector<TYPE>& vec) {
	Vector<TYPE> temp;

	temp.x = val * vec.x;
	temp.y = val * vec.y;
	temp.z = val * vec.z;

	return temp;

}

template <class TYPE> Vector<TYPE> operator/(double val, const Vector<TYPE>& vec) {
	Vector<TYPE> temp;

	temp.x = val / vec.x;
	temp.y = val / vec.y;
	temp.z = val / vec.z;

	return temp;

}

template <class TYPE> void orthonormalBasic(Vector<TYPE>* v1, Vector<TYPE>* v2, Vector<TYPE>* v3) {
	if (v1 != NULL) {
		v1->normalization();
	}
	if (v2 != NULL) {
		if (v1->x >= 1.0) *v2 = Vector<TYPE>(0, 1, 0);
		else *v2 = Vector<TYPE>(1, 0, 0);

		*v2 = *v2 - v1->innerProduct(static_cast<const Vector<double>>(*v2)) * (*v1);
	}
	if (v3 != NULL) {
		*v3 = v1->crossProduct(static_cast<const Vector<double>>(*v2));
	}
}
