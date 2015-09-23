#pragma once
#include <iostream>

class Matrix3x3 {
	 
public:
	float matrix[3][3];
public:
	Matrix3x3();
	Matrix3x3(const Matrix3x3 & mcopy);
	explicit Matrix3x3(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
		);
	~Matrix3x3();

	void identity();

public:
	bool operator==(const Matrix3x3 & right) const;
	bool operator!=(const Matrix3x3 & right) const;

	const Matrix3x3 operator+ (const Matrix3x3 & right) const;
	const Matrix3x3 operator- (const Matrix3x3 & right) const;
	const Matrix3x3 operator* (const Matrix3x3 & right) const;

	void printMatrix() const;
};

