#pragma once

#include "Matrix3x3.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct Vector3
{
public:
	public:
	//Constructors and deconstructors
	Vector3(void);
	Vector3(float, float, float);
	Vector3(Vector3, Vector3);
	~Vector3(void);

	//Operator modifier
	Vector3 operator + (Vector3);
	Vector3 operator += (Vector3);
	Vector3 operator + (float);
	Vector3 operator += (float);
	Vector3 operator - (Vector3);
	Vector3 operator -= (Vector3);
	Vector3 operator * (Vector3);
	Vector3 operator *= (Vector3);
	Vector3 operator * (float);
	Vector3 operator *= (float);
	Vector3 operator * (Matrix3x3);
	Vector3 operator / (float);

	bool operator == (Vector3);
	bool operator != (Vector3);
	bool operator < (Vector3);
	bool operator > (Vector3);
	//Vector function
	Vector3 Zero();
	Vector3 Normalize();
	float Length();
	//Feilds
	float x, y, z;
};

