#include "Vector3.h"

#pragma region Constructors & Deconstructors

Vector3::Vector3(void)
{}
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
Vector3::Vector3(Vector3 _paramOne, Vector3 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
Vector3::~Vector3(void)
{}

#pragma endregion

#pragma region Operators
Vector3 Vector3::operator+(Vector3 param)
{
	Vector3 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	temp.z = z + param.z;
	return temp;
}
Vector3 Vector3::operator+=(Vector3 param)
{
	Vector3 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	temp.z = z += param.z;
	return temp;
}
Vector3 Vector3::operator+(float param)
{
	Vector3 temp;
	temp.x = x + param;
	temp.y = y + param;
	temp.z = z + param;
	return temp;
}
Vector3 Vector3::operator+=(float param)
{
	Vector3 temp;
	temp.x = x += param;
	temp.y = y += param;
	temp.z = z += param;
	return temp;
}
Vector3 Vector3::operator-(Vector3 param)
{
	Vector3 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	temp.z = z - param.z;
	return temp;
}
Vector3 Vector3::operator-=(Vector3 param)
{
	Vector3 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	temp.z = z -= param.z;
	return temp;
}
Vector3 Vector3::operator*(Vector3 param)
{
	Vector3 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	temp.z = z * param.z;
	return temp;
}
Vector3 Vector3::operator*=(Vector3 param)
{
	Vector3 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	temp.z = z *= param.z;
	return temp;
}

Vector3 Vector3::operator*(Matrix3x3 param)
{
	Vector3 temp;
	temp.x = (x * param.I11) + (y * param.I21) + (z * param.I31);
	temp.y = (x * param.I12) + (y * param.I22) + (z * param.I32);
	temp.z = (x * param.I13) + (y * param.I23) + (z * param.I33);
	return temp;
}

Vector3 Vector3::operator*(float param)
{
	Vector3 temp;
	temp.x = x * param;
	temp.y = y * param;
	temp.z = z * param;
	return temp;
}
Vector3 Vector3::operator*=(float param)
{
	Vector3 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	temp.z = z *= param;
	return temp;
}
Vector3 Vector3::operator/(float param)
{
	Vector3 temp;
	temp.x = x / param;
	temp.y = y / param;
	temp.z = z / param;
	return temp;
}

bool Vector3::operator==(Vector3 param)
{
	if (x == param.x && y == param.y && z == param.z) return true;
	else return false;
}
bool Vector3::operator!=(Vector3 param)
{
	if (x == param.x && y == param.y && z == param.z) return false;
	else return true;
}
bool Vector3::operator<(Vector3 param)
{
	if (abs(x) < abs(param.x) && abs(y) < abs(param.y) && abs(z) < abs(param.z)) return true;
	else return true;
}
bool Vector3::operator>(Vector3 param)
{
	if (abs(x) > abs(param.x) && abs(y) > abs(param.y)  && abs(z) > abs(param.z)) return true;
	else return true;
}
#pragma endregion

Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::Normalize()
{
	float magnitude = ::sqrt((x * x) + (y * y) + (z * z));
	Vector3 normal(x / magnitude, y / magnitude, z / magnitude);
	return normal;
}

float Vector3::Length()
{
	return ::sqrtf(x * x + y * y + z * z);
}
