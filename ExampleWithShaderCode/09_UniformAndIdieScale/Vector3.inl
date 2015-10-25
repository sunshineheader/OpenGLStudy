#include "Vector3.h"

// == !=
inline bool operator!=(const Vector3 & left, const Vector3 & right)
{
	return left.x != right.x || left.y != right.y || left.z != right.z;
}
inline bool operator==(const Vector3 & left, const Vector3 & right)
{
	return left.x == right.x && left.y == right.y && left.z == right.z;
}
// + -
inline Vector3  operator+(const Vector3 & left ,const Vector3 & right )
{
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}
inline Vector3  operator-(const Vector3 & left , const Vector3 & right)
{
	return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

// 实现 左乘
inline Vector3  operator*(float scale, Vector3 & right)
{
	return Vector3(scale*right.x, scale* right.y, scale*right.z);
}
// 向量 叉乘
inline Vector3  crossProduct (const Vector3 & left, const Vector3 & right)
{
	return Vector3( 
		   left.y*right.z-left.z*right.y,
		   left.z*right.x-left.x*right.z,
		   left.x*right.y-left.y*right.x
		 );
}

// 向量 点乘
inline float operator*(const Vector3 & left, const Vector3 & right)
{
	return left.x*right.x + left.y*right.y + left.z*right.z;
}

// 模长
inline float length(const Vector3 & v)
{
	return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
// 模长平方
inline float lengthSquared(const Vector3 & v)
{
	return v.x*v.x + v.y*v.y + v.z *v.z;
}

// 求两向量的距离
inline float distance(const Vector3 & left, const Vector3 & right)
{
	float dx = left.x - right.x;
	float dy = left.y - right.y;
	float dz = left.z - right.z;
	return std::sqrt(dx*dx + dy*dy + dz*dz);
}

// 求两向量的距离的平方
inline float distanceSquared(const Vector3 & left, const Vector3 & right)
{
	float dx = left.x - right.x;
	float dy = left.y - right.y;
	float dz = left.z - right.z;
	return dx*dx + dy*dy + dz*dz;
}

// 重载 输出流
inline std::ostream & operator<<(std::ostream & os, const Vector3 vec3)
{
	os << "Vector3.x is " << vec3.x << "\n" << "Vector3.y is " << vec3.y << "\n" << "Vector3.z is " << vec3.z << std::endl;
	return os;
}
