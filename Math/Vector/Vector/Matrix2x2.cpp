#include "Matrix2x2.h"
using std::cout;
using std::endl;

Matrix2x2::Matrix2x2()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f;
}

Matrix2x2::Matrix2x2(const Matrix2x2 & mcopy)
{
	matrix[0][0] = mcopy.matrix[0][0]; matrix[0][1] = mcopy.matrix[0][1];
	matrix[1][0] = mcopy.matrix[1][0]; matrix[1][1] = mcopy.matrix[1][1];
}

Matrix2x2::Matrix2x2(float m11, float m12, float m21, float m22)
{
	matrix[0][0] = m11; matrix[0][1] = m12;
	matrix[1][0] = m21; matrix[1][1] = m22;
}

Matrix2x2::~Matrix2x2()
{}

// 单位化 矩阵
void Matrix2x2::identity()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f;
}

bool Matrix2x2:: operator==(const Matrix2x2 & right) const
{
	return matrix[0][0] == right.matrix[0][0]
		&& matrix[0][1] == right.matrix[0][1]
		&& matrix[1][0] == right.matrix[1][0]
		&& matrix[1][1] == right.matrix[1][1];
}
bool Matrix2x2:: operator!=(const Matrix2x2 & right) const
{
	return matrix[0][0] != right.matrix[0][0]
		|| matrix[0][1] != right.matrix[0][1]
		|| matrix[1][0] != right.matrix[1][0]
		|| matrix[1][1] != right.matrix[1][1];
}
// 矩阵 加法
const Matrix2x2 Matrix2x2:: operator+(const Matrix2x2 & right) const
{
	return Matrix2x2(
	    matrix[0][0] + right.matrix[0][0],
	    matrix[0][1] + right.matrix[0][1],
	    matrix[1][0] + right.matrix[1][0],
	    matrix[1][1] + right.matrix[1][1]
		 );
}

// 矩阵 减法
const Matrix2x2 Matrix2x2:: operator-(const Matrix2x2 & right) const
{
	return Matrix2x2(
		matrix[0][0] - right.matrix[0][0],
		matrix[0][1] - right.matrix[0][1],
		matrix[1][0] - right.matrix[1][0],
		matrix[1][1] - right.matrix[1][1]
		);			 
}

// 矩阵 乘法
const Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & right) const
{
   return Matrix2x2 (
   	   matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0],
   	   matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1],
   	   matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0],
   	   matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1]
   	 );
}

// 输出 矩阵
void Matrix2x2::printMatrix() const
{
	const size_t wide = 2;
	for (size_t i = 0; i < wide; i++)
	{
		cout << "i is " << i << endl;
		for (size_t j = 0; j < wide; j++)
		{
			cout << "Matrix2x2[" << i << "][" << j << "] is " << matrix[i][j] << endl;
		}
	}
}
