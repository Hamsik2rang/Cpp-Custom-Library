#include "Vector3D.h"

Vector3D::Vector3D()
	:x(0), y(0), z(0)
{}

Vector3D::Vector3D(const float& x, const float& y, const float& z)
	: x(x), y(y), z(z)
{}

Vector3D::Vector3D(const Vector3D& v)
	: x(v.x), y(v.y), z(v.z)
{}

Vector3D Vector3D::Normalize() const
{
	Scalar size = this->Magnitude();
	return Vector3D(x / size, y / size, z / size);
}

Scalar Vector3D::Magnitude() const
{
	Scalar size = sqrt(x * x + y * y + z * z);
	return size;
}

Scalar Vector3D::MagnitudeWithoutSqrt() const
{
	Scalar size = x * x + y * y + z * z;
	return size;
}

Vector3D& Vector3D::operator=(const Vector3D& right)
{
	if (*this != right)
	{
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
	}
	return *this;
}

const Vector3D Vector3D::operator+() const
{
	Vector3D temp = Vector3D(x, y, z);
	return temp;
}

const Vector3D Vector3D::operator-() const
{
	Vector3D temp = Vector3D(-x, -y, -z);
	return temp;
}

Vector3D Vector3D::operator*(const int& scalar)	const
{
	Scalar tempScalar = static_cast<Scalar>(scalar);
	Vector3D temp = Vector3D(tempScalar * x, tempScalar * y, tempScalar * z);
	return temp;
}

Vector3D Vector3D::operator*(const float& scalar) const
{
	Vector3D temp = Vector3D(scalar * x, scalar * y, scalar * z);
	return temp;
}

const float Vector3D::operator[](int index) const
{
	switch (index)
	{
	case X:
		return x;
	case Y:
		return y;
	case Z:
		return z;
	default:
		throw std::out_of_range("벡터의 성분 수가 올바르지 않습니다. (0~n-1)");
	}
}

float& Vector3D::operator[](int index)
{
	switch (index)
	{
	case X:
		return x;
	case Y:
		return y;
	case Z:
		return z;
	default:
		throw std::out_of_range("벡터의 성분 수가 올바르지 않습니다. (0~n-1)");
	}
}

const Vector3D operator+(const Vector3D& left, const Vector3D& right)
{
	Vector3D temp(left.x + right.x, left.y + right.y, left.z + right.z);
	return temp;
}

const Vector3D operator-(const Vector3D& left, const Vector3D& right)
{
	Vector3D temp(left.x - right.x, left.y - right.y, left.z - right.z);
	return temp;
}

const Vector3D operator*(const int& left, const Vector3D& right)
{
	Scalar tempScalar = static_cast<Scalar>(left);
	Vector3D temp(tempScalar * right.x, tempScalar * right.y, tempScalar * right.z);
	return temp;
}

const Vector3D operator*(const float& left, const Vector3D& right)
{
	Vector3D temp(left * right.x, left * right.y, left * right.z);
	return temp;
}

// Cross Product
const Vector3D operator*(const Vector3D& left, const Vector3D& right)
{
	Vector3D temp(left.y * right.z - left.z * right.y, left.z * right.x - left.x * right.z, left.x * right.y - left.y * right.x);
	return temp;
}
// Dot Product
const Scalar operator/(const Vector3D& left, const Vector3D& right)
{
	Scalar temp = left.x * right.x + left.y * right.y + left.z * right.z;
	return temp;
}

const Vector3D& Vector3D::operator+=(const Vector3D& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;

	return *this;
}

const Vector3D& Vector3D::operator-=(const Vector3D& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;

	return *this;
}

const Vector3D& Vector3D::operator*=(const int& right)
{
	this->x *= right;
	this->y *= right;
	this->z *= right;

	return *this;
}

const Vector3D& Vector3D::operator*=(const float& right)
{
	this->x *= right;
	this->y *= right;
	this->z *= right;

	return *this;
}

const Vector3D& Vector3D::operator*=(const Vector3D& right)
{
	this->x = this->y * right.z - this->z * right.y;
	this->y = this->z * right.x - this->x * right.z;
	this->z = this->x * right.y - this->y * right.x;

	return *this;
}

bool operator==(const Vector3D& left, const Vector3D& right)
{
	return (
		(left.x / right.x == left.y / right.y && left.y / right.y == left.z / right.z) &&
		(left.Magnitude() == right.Magnitude())
		);
}

bool operator!=(const Vector3D& left, const Vector3D& right)
{
	return (!(left.x / right.x == left.y / right.y && left.y / right.y == left.z / right.z)
			|| !(left.Magnitude() == right.Magnitude()));
}

bool operator<(const Vector3D& left, const Vector3D& right)
{
	return (left.Magnitude() < right.Magnitude());
}

bool operator>(const Vector3D& left, const Vector3D& right)
{
	return (left.Magnitude() > right.Magnitude());
}

bool operator<=(const Vector3D& left, const Vector3D& right)
{
	return (left.Magnitude() <= right.Magnitude());
}

bool operator>=(const Vector3D& left, const Vector3D& right)
{
	return (left.Magnitude() >= right.Magnitude());
}

std::ostream& operator<<(std::ostream& left, const Vector3D& right)
{
	left << "(" << right.x << ", " << right.y << ", " << right.z << ")";
	return left;
}

std::istream& operator>>(std::istream& left, Vector3D& right)
{
	left >> right.x >> right.y >> right.z;
	return left;
}