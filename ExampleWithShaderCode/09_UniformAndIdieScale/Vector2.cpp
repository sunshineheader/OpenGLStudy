#include "Vector2.h"



const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
const Vector2 Vector2:: ONE = Vector2(1.0f, 1.0f);

Vector2::Vector2() 
	: x(0.0f)
	, y(0.0f)
{}

Vector2::Vector2(const Vector2 & vcopy)
	: x(vcopy.x)
	, y(vcopy.y)
{}

Vector2::Vector2(float vx, float vy)
	: x(vx)
	, y(vy)
{}

Vector2::~Vector2()
{}

bool Vector2::zero()const
{
	return x == 0.0f && y == 0.0f;
}

bool Vector2::one() const
{
	return x == 1.0f && y == 1.0f;
}

void Vector2::negate()
{
	x = -x;
	y = -y;
}

void Vector2:: scale(const float scale)
{
	this->scale(scale, scale);
}
void Vector2::scale(const Vector2 & scale)
{
	this->scale(scale.x, scale.y);
}

void Vector2::scale(const float scalex, float scaley)
{
	x *= scalex;
	y *= scaley;
}
void Vector2::rotate(const Vector2 & point, float angle)
{
	double sinAngle = std::sin(angle);
	double cosAngle = std::cos(angle);
	// 如果旋转点是（0.0）点
	if (point.zero())
	{
		float x1 = x * cosAngle - y * sinAngle;
		y = y * cosAngle + x * sinAngle;
		x = x1;
	} else // 如果旋转点不是（0.0）点
	{
		float dx = x - point.x;
		float dy = y - point.y;
		x = dx * cosAngle - dy * sinAngle + point.x;
		y = dy * cosAngle + dx * sinAngle + point.y;
	}
}

float Vector2::length() const
{
	return std::sqrt(x*x + y*y);
}

float Vector2::lengthSquared() const
{
	return x*x + y*y;
}

float Vector2::distance(const Vector2 & v) const
{
	float dx = x - v.x;
	float dy = y - v.y;
	return std::sqrt(dx*dx + dy*dy);
}

float Vector2::distanceSquared(const Vector2 & v) const
{
	float dx = x - v.x;
	float dy = y - v.y;
	return dx*dx + dy*dy;
}

void Vector2::normalize()
{
	float normalaize = x*x + y*y ;
	if (0.0f != normalaize)
	{
		float OneOverNormalaize = 1.0f / std::sqrt(normalaize);
		x *= OneOverNormalaize;
		y *= OneOverNormalaize;
	}
	return;
}

bool Vector2:: operator==(const Vector2 & v) const
{
	return x == v.x && y ==v.y;
}

bool Vector2:: operator!=(const Vector2 & v) const
{
	return x != v.x || y != v.y;
}

const Vector2 Vector2:: operator+(const Vector2 & v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 & Vector2::operator += (const Vector2 & v)
{
	x += v.x;
	y += v.y;
	return *this;
}

const Vector2 Vector2:: operator-(const Vector2 & v) const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 & Vector2::operator -= (const Vector2 & v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
const Vector2  Vector2:: operator*(const float scale) const
{
	return Vector2(x*scale, y*scale);
}
Vector2 & Vector2:: operator*=(const float scale)
{
	x *= scale;
	y *= scale;
	return *this;
}
float Vector2::operator*(const Vector2 & v) const
{
	return x*v.x + y*v.y;
}

