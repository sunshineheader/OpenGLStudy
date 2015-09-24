#pragma once
#include <iostream>
/*
Matrix3x3   m11 m12 m13 m14
            m21 m22 m23	m24
            m31 m32 m33	m34
			m41 m42 m43 m44
*/
class Matrix4x4 {

public:
	float matrix[4][4];

public:
	Matrix4x4();
	Matrix4x4(const Matrix4x4 & mcopy);
	explicit Matrix4x4(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
		);
	~Matrix4x4();
	void identity();
public:
	const bool operator==(const Matrix4x4 & right) const;
	const bool operator!=(const Matrix4x4 & right) const;

	const Matrix4x4 operator+ (const Matrix4x4 & right) const;
	const Matrix4x4 operator- (const Matrix4x4 & right) const;
	const Matrix4x4 operator* (const Matrix4x4 & right) const;

	void printMatrix() const;
};

