#include "Vector3.h"

const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);
const Vector3 Vector3:: ONE = Vector3(1.0f, 1.0f, 1.0f);


Vector3::Vector3()
	: x(0.0f)
	, y(0.0f)
	, z(0.0f)
{}

Vector3::Vector3(const Vector3 & v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
{}

Vector3::Vector3(float vx, float vy, float vz)
	: x(vx)
	, y(vy)
	, z(vz)
{}


Vector3::~Vector3()
{}

bool Vector3::zero() const
{
	return x == 0.0f && y == 0.0f && z == 0.0f;
}

void Vector3::negate() 
{
	x = -x;
	y = -y;
	z = -z;
}

void Vector3::scale(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
}

void Vector3::scale(const Vector3 & scale)
{
	x *= scale.x;
	y *= scale.y;
	z *= scale.z;
}
// 模长
float Vector3::length() const
{
	return std::sqrt(x*x + y*y + z*z);
}
float Vector3::lengthSquared() const
{
	return x*x + y*y + z*z;
}

// 两向量之间的距离
float Vector3::distance(const Vector3 & v) const
{
	float dx = x - v.x;
	float dy = y - v.y;
	float dz = z - v.z;
	return std::sqrt(dx*dx + dy*dy + dz*dz);
}
float Vector3::distanceSquared(const Vector3 & v) const
{
	float dx = x - v.x;
	float dy = y - v.y;
	float dz = z - v.z;
	return x*dx + dy*dy + dz*dz;
}

// 标准化向量 Vector3
void Vector3::nomalaize()
{
	float normalaize = x*x + y*y + z*z;
	if (0.0f != normalaize)
	{
		float OneOverNormalaize = 1.0f / std::sqrt(normalaize);
		x *= OneOverNormalaize;
		y *= OneOverNormalaize;
		z *= OneOverNormalaize;
	}
	return;
}


Vector3 Vector3::crossProduct(const Vector3 & right) const
{
	return Vector3(
		y*right.z - z*right.y,
		z*right.x - x*right.z,
		x*right.y - y*right.x
		);
}

bool Vector3:: operator==(const Vector3 & v) const
{
	return x == v.x && y == v.y && z == v.z;
}
bool Vector3:: operator!=(const Vector3 & v) const
{
	return x != v.x || y != v.y || z != v.z;
}


const Vector3 Vector3:: operator+(const Vector3 & v) const
{
	return Vector3(x+v.x,y+v.y,z+v.z);
}
Vector3 & Vector3:: operator+=(const Vector3 & v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

const Vector3 Vector3:: operator-(const Vector3 & v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 & Vector3:: operator-=(const Vector3 & v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
const Vector3  Vector3::operator*(const float scale) const
{
	return Vector3(x*scale, y*scale, z*scale);
}
Vector3 & Vector3::operator *= (const float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}
float Vector3:: operator*(const Vector3 & v) const
{
	return x*v.x + y*v.y + z*v.z;
}