#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

struct Vector2
{
public:
	//Constructors and deconstructors
	Vector2(void);
	Vector2(float, float);
	Vector2(Vector2, Vector2);
	~Vector2(void);
	//Operator modifier
	Vector2 operator + (Vector2);
	Vector2 operator += (Vector2);
	Vector2 operator + (float);
	Vector2 operator += (float);
	Vector2 operator - (Vector2);
	Vector2 operator -= (Vector2);
	Vector2 operator * (Vector2);
	Vector2 operator *= (Vector2);
	Vector2 operator * (float);
	Vector2 operator *= (float);
	Vector2 operator / (float);

	bool operator == (Vector2);
	bool operator != (Vector2);
	bool operator < (Vector2);
	bool operator > (Vector2);
	//Vector function
	Vector2 Zero();
	Vector2 Normalize();
	void rotateVector(float);
	float Length();
	//Feilds
	float x, y;
};

