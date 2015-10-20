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

// µ•ŒªªØ æÿ’Û
void Matrix2x2::identity()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f;
}

void Matrix2x2::initlaizeScaleMatrix(const float scalex, const float scaley)
{
	matrix[0][0] = scalex;  matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f;    matrix[1][1] = scaley;
}
void Matrix2x2::iniitlaizeRotationMatrix(const float rotatex, const float rotatey)
{
	matrix[0][0] = rotatex;  matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f;     matrix[1][1] = rotatey;
}
void Matrix2x2::initlaizeTransformMatrix(const float transformx, const float transformy)
{
	matrix[0][0] = transformx;  matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f;        matrix[1][1] = transformy;
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
// æÿ’Û º”∑®
const Matrix2x2 Matrix2x2:: operator+(const Matrix2x2 & right) const
{
	return Matrix2x2(
	    matrix[0][0] + right.matrix[0][0],
	    matrix[0][1] + right.matrix[0][1],
	    matrix[1][0] + right.matrix[1][0],
	    matrix[1][1] + right.matrix[1][1]
		 );
}

// æÿ’Û ºı∑®
const Matrix2x2 Matrix2x2:: operator-(const Matrix2x2 & right) const
{
	return Matrix2x2(
		matrix[0][0] - right.matrix[0][0],
		matrix[0][1] - right.matrix[0][1],
		matrix[1][0] - right.matrix[1][0],
		matrix[1][1] - right.matrix[1][1]
		);			 
}

// æÿ’Û ≥À∑®
const Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & right) const
{
   return Matrix2x2 (
   	   matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0],
   	   matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1],
   	   matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0],
   	   matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1]
   	 );
}

//  ‰≥ˆ æÿ’Û
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
