#include "Vector2.h"



inline bool operator==(Vector2 & left, Vector2 & right)
{
	return left.x == right.x&&left.y == right.y;
}

inline bool  operator!=(Vector2 & left, Vector2 & right)
{
	return left.x != right.x || left.y != right.y;
}


inline Vector2  operator+(Vector2 & left, Vector2 & right) 
{
	return Vector2(left.x + right.x, left.y + right.y);
}

inline Vector2  operator-(Vector2 & left, Vector2 & right)
{
	return Vector2 (left.x - right.x, left.y - right.y);
}

// ÊµÏÖ ×ó³Ë
inline Vector2  operator*(float scale, Vector2 & right)
{
	return Vector2(scale*right.x, scale* right.y);
}

inline float operator*(Vector2 & left, Vector2 & right)
{
	return left.x * right.x && left.y * right.y;
}


inline std:: ostream & operator<<(std::ostream & os, const Vector2 vec2)
{
	os << "Vector2.x is " << vec2.x << "\n" << "Vector2.y is " << vec2.y << std::endl;
	return os;
}
