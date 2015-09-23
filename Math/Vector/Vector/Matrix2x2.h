#pragma once
#include <iostream>
/*Matrix2x2   m11 m12
			  m21 m22
*/
class Matrix2x2 {

public:
	float matrix[2][2];
public:
	Matrix2x2();
	Matrix2x2(const Matrix2x2 & mcopy);
	explicit Matrix2x2(float m11, float m12, float m21, float m22);
	~Matrix2x2();
	void identity();
public:
	bool operator==(const Matrix2x2 & right) const ;
	bool operator!=(const Matrix2x2 & right) const ;

	const Matrix2x2 operator+(const Matrix2x2 & right) const ;
	const Matrix2x2 operator-(const Matrix2x2 & right) const ;
	const Matrix2x2 operator*(const Matrix2x2 & right) const ;
	void printMatrix() const;
};



