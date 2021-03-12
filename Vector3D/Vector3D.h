#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

#define X 0
#define Y 1
#define Z 2

using Scalar = float;

class Vector3D
{
public:
	Vector3D();
	Vector3D(const float& x, const float& y, const float& z);
	Vector3D(const Vector3D& v);
	// Get Unit Vector.
	Vector3D					Normalize() const;
	// Get Size of Vector. 
	Scalar						Magnitude() const;
	// Get Product of all squared elements.
	Scalar						MagnitudeWithoutSqrt() const;

	/////////////////////////
	//Operators Overloaded.//
	/////////////////////////

	// Unary Operator
	Vector3D& operator=(const Vector3D& right);
	const Vector3D				operator+() const;
	const Vector3D				operator-() const;
	// Return Element. Index is X, Y and Z.
	const float					operator[](int index) const;
	float& operator[](int index);

	// Binary Operator
	// Scalar Product - Vector * Scalar.
	Vector3D					operator*(const int& scalar) const;
	Vector3D					operator*(const float& scalar) const;

	friend const Vector3D		operator+(const Vector3D& left, const Vector3D& right);
	friend const Vector3D		operator-(const Vector3D& left, const Vector3D& right);
	// Scalar Product - Scalar * Vector.
	friend const Vector3D		operator*(const int& left, const Vector3D& right);
	friend const Vector3D		operator*(const float& left, const Vector3D& right);
	// Cross Product
	friend const Vector3D		operator*(const Vector3D& left, const Vector3D& right);
	// Dot Product
	friend const Scalar			operator/(const Vector3D& left, const Vector3D& right);

	const Vector3D&				operator+=(const Vector3D& right);
	const Vector3D&				operator-=(const Vector3D& right);
	const Vector3D&				operator*=(const int& right);
	const Vector3D&				operator*=(const float& right);
	const Vector3D&				operator*=(const Vector3D& right);

	friend bool					operator==(const Vector3D& left, const Vector3D& right);
	friend bool					operator!=(const Vector3D& left, const Vector3D& right);
	friend bool					operator<(const Vector3D& left, const Vector3D& right);
	friend bool					operator>(const Vector3D& left, const Vector3D& right);
	friend bool					operator<=(const Vector3D& left, const Vector3D& right);
	friend bool					operator>=(const Vector3D& left, const Vector3D& right);

	friend std::ostream&		operator<<(std::ostream& left, const Vector3D& right);
	friend std::istream&		operator>>(std::istream& left, Vector3D& right);

private:
	float x;
	float y;
	float z;
};