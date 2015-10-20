#pragma once
#include <ostream>

class Vector2 {

public:
	float x;
	float y;
public:
	Vector2();
	Vector2(const Vector2 & vcopy);
	explicit Vector2(float vx, float vy);
	~Vector2();

	bool zero()const;
	bool one()const;
	void negate();
	void scale(const float scale);
	void scale(const Vector2 & scale);
	void scale(const float scalex,const float scaley);
	void rotate(const Vector2 & point,float angle);

	// 模长
	float length() const;
	float lengthSquared() const;

	// 两向量之间的距离
	float distance(const Vector2 & v) const;
	float distanceSquared(const Vector2 & v) const;

	// 标准化向量
	void normalize();

public:
	// 重置 比较 运算符 == !=
	bool  operator==(const Vector2 & v) const;
	bool  operator!=(const Vector2 & v) const;

	// 重载 一元 运算符  + +=
	const Vector2  operator+(const Vector2 & v) const;
	Vector2 & operator+=(const Vector2 & v);

	// 重载 一元 运算符  - -=
	const Vector2  operator-(const Vector2 & v) const;
	Vector2 & operator-=(const Vector2 & v);

	// 重载 一元 运算符  * *=
	const Vector2  operator*(const float scale) const;
	Vector2 & operator*=(const float scale);

	// 向量的数量积
	float  operator*(const Vector2 & v) const;

public:
	static const Vector2 ZERO;
	static const Vector2  ONE;
};

#include "Vector2.inl"

