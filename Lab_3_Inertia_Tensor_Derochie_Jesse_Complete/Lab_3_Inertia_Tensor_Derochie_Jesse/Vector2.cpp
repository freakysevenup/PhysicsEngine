#include "Vector2.h"

#pragma region Constructors & Deconstructors

Vector2::Vector2(void)
{}
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
Vector2::Vector2(Vector2 _paramOne, Vector2 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
Vector2::~Vector2(void)
{}

#pragma endregion

#pragma region Operators
Vector2 Vector2::operator+(Vector2 param)
{
	Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}
Vector2 Vector2::operator+=(Vector2 param)
{
	Vector2 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	return temp;
}
Vector2 Vector2::operator+(float param)
{
	Vector2 temp;
	temp.x = x + param;
	temp.y = y + param;
	return temp;
}
Vector2 Vector2::operator+=(float param)
{
	Vector2 temp;
	temp.x = x += param;
	temp.y = y += param;
	return temp;
}
Vector2 Vector2::operator-(Vector2 param)
{
	Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}
Vector2 Vector2::operator-=(Vector2 param)
{
	Vector2 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	return temp;
}
Vector2 Vector2::operator*(Vector2 param)
{
	Vector2 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	return temp;
}
Vector2 Vector2::operator*=(Vector2 param)
{
	Vector2 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	return temp;
}
Vector2 Vector2::operator*(float param)
{
	Vector2 temp;
	temp.x = x * param;
	temp.y = y * param;
	return temp;
}
Vector2 Vector2::operator*=(float param)
{
	Vector2 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	return temp;
}
Vector2 Vector2::operator/(float param)
{
	Vector2 temp;
	temp.x = x / param;
	temp.y = y / param;
	return temp;
}

bool Vector2::operator==(Vector2 param)
{
	if (x == param.x && y == param.y) return true;
	else return false;
}
bool Vector2::operator!=(Vector2 param)
{
	if (x == param.x && y == param.y) return false;
	else return true;
}
bool Vector2::operator<(Vector2 param)
{
	if (abs(x) < abs(param.x) && abs(y) < abs(param.y)) return true;
	else return true;
}
bool Vector2::operator>(Vector2 param)
{
	if (abs(x) > abs(param.x) && abs(y) > abs(param.y)) return true;
	else return true;
}
#pragma endregion

Vector2 Vector2::Zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::Normalize()
{
	float magnitude = ::sqrt((x * x) + (y * y));
	Vector2 normal(x / magnitude, y / magnitude);
	return normal;
}

void Vector2::rotateVector(float _angle)
{
	float tempX = x;
	float tempY = y;
	x = tempX * ::cos(_angle) - tempY * ::sin(_angle);
	y = tempX * ::sin(_angle) + tempY * ::cos(_angle);
}

float Vector2::Length()
{
	return ::sqrtf(x * x + y * y);
}
