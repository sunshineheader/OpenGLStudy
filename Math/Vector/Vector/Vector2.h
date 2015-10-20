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

	// ģ��
	float length() const;
	float lengthSquared() const;

	// ������֮��ľ���
	float distance(const Vector2 & v) const;
	float distanceSquared(const Vector2 & v) const;

	// ��׼������
	void normalize();

public:
	// ���� �Ƚ� ����� == !=
	bool  operator==(const Vector2 & v) const;
	bool  operator!=(const Vector2 & v) const;

	// ���� һԪ �����  + +=
	const Vector2  operator+(const Vector2 & v) const;
	Vector2 & operator+=(const Vector2 & v);

	// ���� һԪ �����  - -=
	const Vector2  operator-(const Vector2 & v) const;
	Vector2 & operator-=(const Vector2 & v);

	// ���� һԪ �����  * *=
	const Vector2  operator*(const float scale) const;
	Vector2 & operator*=(const float scale);

	// ������������
	float  operator*(const Vector2 & v) const;

public:
	static const Vector2 ZERO;
	static const Vector2  ONE;
};

#include "Vector2.inl"

