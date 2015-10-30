#pragma once
#include <iostream>
class Vector3 {

public: 
	Vector3();
	Vector3(const Vector3 & v);
	explicit Vector3(float vx, float vy, float vz);
	~Vector3();

	bool zero() const;
	void negate();
	void scale(const float scale);
	void scale(const Vector3 & scale);
	void scale(const float scalex, const float scaley,const float scalez);

	// ģ��
	float length() const;
	float lengthSquared() const;

	// ������֮��ľ���
	float distance(const Vector3 & v) const;
	float distanceSquared(const Vector3 & v) const;

	// ��׼������
	void nomalaize();

	Vector3  crossProduct(const Vector3 & right) const;

public:
	bool  operator==(const Vector3 & v) const;
	bool  operator!=(const Vector3 & v) const;

	const Vector3  operator+(const Vector3 & v) const;
	Vector3 & operator+=(const Vector3 & v);
    const Vector3  operator-(const Vector3 & v) const;
	Vector3 & operator-=(const Vector3 & v);
	const Vector3  operator*(const float scale) const;
	Vector3 & operator*=(const float scale);
	float  operator*(const Vector3 & v) const;
public:
	float x;
	float y;
	float z;

	static const Vector3 ZERO ;
	static const Vector3  ONE ;
};
#include "Vector3.inl"

