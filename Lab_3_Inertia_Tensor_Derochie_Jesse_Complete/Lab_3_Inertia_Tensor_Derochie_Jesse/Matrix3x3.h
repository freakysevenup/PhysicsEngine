#pragma once
#include "Vector3.h"

class Matrix3x3
{
public:
	//Constructors and deconstructors
	Matrix3x3(void);
	Matrix3x3(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine);
	Matrix3x3(Vector3, Vector3, Vector3, bool);
	~Matrix3x3(void);

	Matrix3x3 operator + (Matrix3x3);
	Matrix3x3 operator += (Matrix3x3);
	Matrix3x3 operator - (Matrix3x3);
	Matrix3x3 operator -= (Matrix3x3);
	Matrix3x3 operator * (Matrix3x3);
	Matrix3x3 operator * (float);
	Matrix3x3 operator / (float);

	bool operator == (Matrix3x3);
	bool operator != (Matrix3x3);

	float I11, I12, I13, I21, I22, I23, I31, I32, I33;
};

