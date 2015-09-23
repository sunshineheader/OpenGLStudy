#include "Matrix3x3.h"
using std::cout;
using std::endl;

Matrix3x3::Matrix3x3()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f;
}

Matrix3x3::Matrix3x3(const Matrix3x3 & mcopy)
{
	matrix[0][0] = mcopy.matrix[0][0]; matrix[0][1] = mcopy.matrix[0][1]; matrix[0][2] = mcopy.matrix[0][2];
	matrix[1][0] = mcopy.matrix[1][0]; matrix[1][1] = mcopy.matrix[1][1]; matrix[1][2] = mcopy.matrix[1][2];
	matrix[2][0] = mcopy.matrix[2][0]; matrix[2][1] = mcopy.matrix[2][1]; matrix[2][2] = mcopy.matrix[2][2];
}

Matrix3x3::Matrix3x3(
	float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33
	)
{
	matrix[0][0] = m11; matrix[0][1] = m12; matrix[0][2] = m13;
	matrix[1][0] = m21; matrix[1][1] = m22; matrix[1][2] = m23;
	matrix[2][0] = m31; matrix[2][1] = m32; matrix[2][2] = m33;
}
Matrix3x3::~Matrix3x3()
{}

void Matrix3x3::identity()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f;
}

bool Matrix3x3:: operator== (const Matrix3x3 & right) const
{
	return matrix[0][0] == right.matrix[0][0] && matrix[0][1] == right.matrix[0][1] && matrix[0][2] == right.matrix[0][2]
        && matrix[1][0] == right.matrix[1][0] && matrix[1][1] == right.matrix[1][1] && matrix[1][2] == right.matrix[1][2]
		&& matrix[2][0] == right.matrix[2][0] && matrix[2][1] == right.matrix[2][1] && matrix[2][2] == right.matrix[2][2];

}
bool Matrix3x3:: operator!= (const Matrix3x3 & right) const
{
	return matrix[0][0] != right.matrix[0][0] || matrix[0][1] != right.matrix[0][1] || matrix[0][2] != right.matrix[0][2]
		|| matrix[1][0] != right.matrix[1][0] || matrix[1][1] != right.matrix[1][1] || matrix[1][2] != right.matrix[1][2]
		|| matrix[2][0] != right.matrix[2][0] || matrix[2][1] != right.matrix[2][1] || matrix[2][2] != right.matrix[2][2];
}

const Matrix3x3 Matrix3x3::operator+ (const Matrix3x3 & right) const
{
	return Matrix3x3 (
		matrix[0][0] + right.matrix[0][0], matrix[0][1] + right.matrix[0][1], matrix[0][2] + right.matrix[0][2],
		matrix[1][0] + right.matrix[1][0], matrix[1][1] + right.matrix[1][1], matrix[1][2] + right.matrix[1][2],
		matrix[2][0] + right.matrix[2][0], matrix[2][1] + right.matrix[2][1], matrix[2][2] + right.matrix[2][2]
		);
}
const Matrix3x3 Matrix3x3::operator- (const Matrix3x3 & right) const
{
	return Matrix3x3 (
		matrix[0][0] - right.matrix[0][0], matrix[0][1] - right.matrix[0][1], matrix[0][2] - right.matrix[0][2],
		matrix[1][0] - right.matrix[1][0], matrix[1][1] - right.matrix[1][1], matrix[1][2] - right.matrix[1][2],
		matrix[2][0] - right.matrix[2][0], matrix[2][1] - right.matrix[2][1], matrix[2][2] - right.matrix[2][2]
		);
}
const Matrix3x3 Matrix3x3::operator* (const Matrix3x3 & right) const
{
	return Matrix3x3 (
	    matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0] + matrix[0][2] * right.matrix[2][0],
	    matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1] + matrix[0][2] * right.matrix[2][1],
	    matrix[0][0] * right.matrix[0][2] + matrix[0][1] * right.matrix[1][2] + matrix[0][2] * right.matrix[2][2],
	   																										  
	    matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0] + matrix[1][2] * right.matrix[2][0],
	    matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1] + matrix[1][2] * right.matrix[2][1],
	    matrix[1][0] * right.matrix[0][2] + matrix[1][1] * right.matrix[1][2] + matrix[1][2] * right.matrix[2][2],
	   																										  
	    matrix[2][0] * right.matrix[0][0] + matrix[2][1] * right.matrix[1][0] + matrix[2][2] * right.matrix[2][0],
	    matrix[2][0] * right.matrix[0][1] + matrix[2][1] * right.matrix[1][1] + matrix[2][2] * right.matrix[2][1],
	    matrix[2][0] * right.matrix[0][2] + matrix[2][1] * right.matrix[1][2] + matrix[2][2] * right.matrix[2][2]
	  );
	
}


void Matrix3x3::printMatrix() const
{
	const size_t wide = 3;
	for (size_t i = 0; i < wide; i++)
	{
		cout << "i is " << i << endl;
		for (size_t j = 0; j < wide; j++)
		{
			cout << "Matrix3x3[" << i << "][" << j << "] is " << matrix[i][j] << endl;
		}
	}
}