#include "Matrix4x4.h"
using std::cout;
using std::endl;

Matrix4x4::Matrix4x4()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(const Matrix4x4 & mcopy)
{
	matrix[0][0] = mcopy.matrix[0][0]; matrix[0][1] = mcopy.matrix[0][1]; matrix[0][2] = mcopy.matrix[0][2]; matrix[0][3] = mcopy.matrix[0][3];
	matrix[1][0] = mcopy.matrix[1][0]; matrix[1][1] = mcopy.matrix[1][1]; matrix[1][2] = mcopy.matrix[1][2]; matrix[1][3] = mcopy.matrix[1][3];
	matrix[2][0] = mcopy.matrix[2][0]; matrix[2][1] = mcopy.matrix[2][1]; matrix[2][2] = mcopy.matrix[2][2]; matrix[2][3] = mcopy.matrix[2][3];
	matrix[3][0] = mcopy.matrix[3][0]; matrix[3][1] = mcopy.matrix[3][1]; matrix[3][2] = mcopy.matrix[3][2]; matrix[3][3] = mcopy.matrix[3][3];
}

Matrix4x4::Matrix4x4 (
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44
	)
{
	matrix[0][0] = m11; matrix[0][1] = m12; matrix[0][2] = m13; matrix[0][3] = m14;
	matrix[1][0] = m21; matrix[1][1] = m22; matrix[1][2] = m23; matrix[1][3] = m24;
	matrix[2][0] = m31; matrix[2][1] = m32; matrix[2][2] = m33; matrix[2][3] = m34;
	matrix[3][0] = m41; matrix[3][1] = m42; matrix[3][2] = m43; matrix[3][3] = m44;
}

Matrix4x4::~Matrix4x4()
{}

void Matrix4x4:: identity()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
}

const bool Matrix4x4:: operator==(const Matrix4x4 & right) const
{
	return matrix[0][0] == right.matrix[0][0] && matrix[0][1] == right.matrix[0][1] && matrix[0][2] == right.matrix[0][2] && matrix[0][3] == right.matrix[0][3]
		&& matrix[1][0] == right.matrix[1][0] && matrix[1][1] == right.matrix[1][1] && matrix[1][2] == right.matrix[1][2] && matrix[1][3] == right.matrix[1][3]
		&& matrix[2][0] == right.matrix[2][0] && matrix[2][1] == right.matrix[2][1] && matrix[2][2] == right.matrix[2][2] && matrix[2][3] == right.matrix[2][3]
		&& matrix[3][0] == right.matrix[3][0] && matrix[3][1] == right.matrix[3][1] && matrix[3][2] == right.matrix[3][2] && matrix[3][3] == right.matrix[3][3];
																			 
}

const bool Matrix4x4::operator != (const Matrix4x4 & right) const
{
	return matrix[0][0] != right.matrix[0][0] || matrix[0][1] != right.matrix[0][1] || matrix[0][2] != right.matrix[0][2] || matrix[0][3] != right.matrix[0][3]
		|| matrix[1][0] != right.matrix[1][0] || matrix[1][1] != right.matrix[1][1] || matrix[1][2] != right.matrix[1][2] || matrix[1][3] != right.matrix[1][3]
		|| matrix[2][0] != right.matrix[2][0] || matrix[2][1] != right.matrix[2][1] || matrix[2][2] != right.matrix[2][2] || matrix[2][3] != right.matrix[2][3]
		|| matrix[3][0] != right.matrix[3][0] || matrix[3][1] != right.matrix[3][1] || matrix[3][2] != right.matrix[3][2] || matrix[3][3] != right.matrix[3][3];
}


const Matrix4x4 Matrix4x4:: operator+ (const Matrix4x4 & right) const
{
	return Matrix4x4(
		matrix[0][0] + right.matrix[0][0] , matrix[0][1] + right.matrix[0][1] , matrix[0][2] + right.matrix[0][2] , matrix[0][3] + right.matrix[0][3],
	    matrix[1][0] + right.matrix[1][0] , matrix[1][1] + right.matrix[1][1] , matrix[1][2] + right.matrix[1][2] , matrix[1][3] + right.matrix[1][3],
	    matrix[2][0] + right.matrix[2][0] , matrix[2][1] + right.matrix[2][1] , matrix[2][2] + right.matrix[2][2] , matrix[2][3] + right.matrix[2][3],
	    matrix[3][0] + right.matrix[3][0] , matrix[3][1] + right.matrix[3][1] , matrix[3][2] + right.matrix[3][2] , matrix[3][3] + right.matrix[3][3]
	);
}

const Matrix4x4 Matrix4x4:: operator- (const Matrix4x4 & right) const
{
	return Matrix4x4(
		matrix[0][0] - right.matrix[0][0], matrix[0][1] - right.matrix[0][1], matrix[0][2] - right.matrix[0][2], matrix[0][3] - right.matrix[0][3],
		matrix[1][0] - right.matrix[1][0], matrix[1][1] - right.matrix[1][1], matrix[1][2] - right.matrix[1][2], matrix[1][3] - right.matrix[1][3],
		matrix[2][0] - right.matrix[2][0], matrix[2][1] - right.matrix[2][1], matrix[2][2] - right.matrix[2][2], matrix[2][3] - right.matrix[2][3],
		matrix[3][0] - right.matrix[3][0], matrix[3][1] - right.matrix[3][1], matrix[3][2] - right.matrix[3][2], matrix[3][3] - right.matrix[3][3]
		);
}
const Matrix4x4 Matrix4x4:: operator* (const Matrix4x4 & right) const
{
	return Matrix4x4(

		matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0] + matrix[0][2] * right.matrix[2][0] + matrix[0][3] * right.matrix[3][0],
		matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1] + matrix[0][2] * right.matrix[2][1] + matrix[0][3] * right.matrix[3][1],
		matrix[0][0] * right.matrix[0][2] + matrix[0][1] * right.matrix[1][2] + matrix[0][2] * right.matrix[2][2] + matrix[0][3] * right.matrix[3][2],
		matrix[0][0] * right.matrix[0][3] + matrix[0][1] * right.matrix[1][3] + matrix[0][2] * right.matrix[2][3] + matrix[0][3] * right.matrix[3][3],

		matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0] + matrix[1][2] * right.matrix[2][0] + matrix[1][3] * right.matrix[3][0],
		matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1] + matrix[1][2] * right.matrix[2][1] + matrix[1][3] * right.matrix[3][1],
		matrix[1][0] * right.matrix[0][2] + matrix[1][1] * right.matrix[1][2] + matrix[1][2] * right.matrix[2][2] + matrix[1][3] * right.matrix[3][2],
		matrix[1][0] * right.matrix[0][3] + matrix[1][1] * right.matrix[1][3] + matrix[1][2] * right.matrix[2][3] + matrix[1][3] * right.matrix[3][3],

		matrix[2][0] * right.matrix[0][0] + matrix[2][1] * right.matrix[1][0] + matrix[2][2] * right.matrix[2][0] + matrix[2][3] * right.matrix[3][0],
		matrix[2][0] * right.matrix[0][1] + matrix[2][1] * right.matrix[1][1] + matrix[2][2] * right.matrix[2][1] + matrix[2][3] * right.matrix[3][1],
		matrix[2][0] * right.matrix[0][2] + matrix[2][1] * right.matrix[1][2] + matrix[2][2] * right.matrix[2][2] + matrix[2][3] * right.matrix[3][2],
		matrix[2][0] * right.matrix[0][3] + matrix[2][1] * right.matrix[1][3] + matrix[2][2] * right.matrix[2][3] + matrix[2][3] * right.matrix[3][3],

		matrix[3][0] * right.matrix[0][0] + matrix[3][1] * right.matrix[1][0] + matrix[3][2] * right.matrix[2][0] + matrix[3][3] * right.matrix[3][0],
		matrix[3][0] * right.matrix[0][1] + matrix[3][1] * right.matrix[1][1] + matrix[3][2] * right.matrix[2][1] + matrix[3][3] * right.matrix[3][1],
		matrix[3][0] * right.matrix[0][2] + matrix[3][1] * right.matrix[1][2] + matrix[3][2] * right.matrix[2][2] + matrix[3][3] * right.matrix[3][2],
		matrix[3][0] * right.matrix[0][3] + matrix[3][1] * right.matrix[1][3] + matrix[3][2] * right.matrix[2][3] + matrix[3][3] * right.matrix[3][3]
		);
}


void Matrix4x4::printMatrix() const
{
	const size_t wide = 4;
	for (size_t i = 0; i < wide; i++)
	{
		cout << "i is " << i << endl;
		for (size_t j = 0; j < wide; j++)
		{
			cout << "Matrix4x4[" << i << "][" << j << "] is " << matrix[i][j] << endl;
		}
	}
}