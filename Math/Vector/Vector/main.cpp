#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
using namespace std;


void main()
{
	double angle = std::cos(90);
	float s = 10;
	Vector2 v =  Vector2(1.0f, 1.0f);
	Vector2 v1 = Vector2(4.0f, 3.0f);
	Vector2 v2 = Vector2(0.0f, 3.0f);
	cout << v;

	Vector3 v3;
	Vector3 v4 = Vector3(0.1f, 0.1f, 0.1f);
	Vector3 v5 = Vector3(3.0f, 2.0f, 2.0f);
	v4.scale(v5);
	cout << v4;

	Matrix2x2 m23 = Matrix2x2(2.0f,0.0f,0.0f,2.0f);
	Matrix2x2 m24 = Matrix2x2(10.0f, 5.0f, 5.0f, 10.0f);
	Matrix2x2 m25 = m23*m24;
	m25.printMatrix();

	Matrix3x3 m3 = Matrix3x3(2.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 2.0f);
	Matrix3x3 m4 = Matrix3x3(m3);
	Matrix3x3 m5 = m3+m4;
	m4.printMatrix();

	system("PAUSE");
}