#include "Matrix3x3.h"

#pragma region Constructors & Deconstructors

Matrix3x3::Matrix3x3(void)
{
}

	/*	
	This Constructor takes the supplied Vector3's and creates a Matrix3x3 from them.
	If you want your Matrix Represented from Left to Right and top to bottom;
	ie. |one	two		three|
		|four	five	six	 |
		|seven  eight	nine |
	*/
Matrix3x3::Matrix3x3(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine)
{
	I11 = one;		I12 = two;		I13 = three;
	I21 = four;		I22 = five;		I23 = six;
	I31 = seven;	I32 = eight;	I33 = nine;
}

	/*	
	This Constructor takes the supplied Vector3's and creates a Matrix3x3 from them.
	If you want your Matrix Represented from Left to Right make the LeftToRight Bool
	true, otherwise make it false.
	*/
Matrix3x3::Matrix3x3(Vector3 paramOne, Vector3 paramTwo, Vector3 paramThree, bool LeftToRight)
{
	Matrix3x3 temp;
	if(LeftToRight)
	{
		temp.I11 = paramOne.x;		temp.I12 = paramOne.y;		temp.I13 = paramOne.z;
		temp.I21 = paramTwo.x;		temp.I22 = paramTwo.y;		temp.I23 = paramTwo.z;
		temp.I31 = paramThree.x;	temp.I32 = paramThree.y;	temp.I33 = paramThree.z;
	}
	else
	{
		temp.I11 = paramOne.x;		temp.I12 = paramTwo.x;		temp.I13 = paramThree.x;
		temp.I21 = paramOne.y;		temp.I22 = paramTwo.y;		temp.I23 = paramThree.y;
		temp.I31 = paramOne.z;		temp.I32 = paramTwo.z;		temp.I33 = paramThree.z;
	}
}

Matrix3x3::~Matrix3x3(void)
{
}
#pragma endregion

#pragma region Operators
Matrix3x3 Matrix3x3::operator + (Matrix3x3 param)
{
	Matrix3x3 temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator += (Matrix3x3 param)
{
	Matrix3x3 temp;
	temp.I11 = I11 += param.I11;		temp.I12 = I12 += param.I12;		temp.I13 = I13 += param.I13;
	temp.I21 = I21 += param.I21;		temp.I22 = I22 += param.I22;		temp.I23 = I23 += param.I23;
	temp.I31 = I31 += param.I31;		temp.I32 = I32 += param.I32;		temp.I33 = I33 += param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator - (Matrix3x3 param)
{
	Matrix3x3 temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator -= (Matrix3x3 param)
{
	Matrix3x3 temp;
	temp.I11 = I11 -= param.I11;		temp.I12 = I12 -= param.I12;		temp.I13 = I13 -= param.I13;
	temp.I21 = I21 -= param.I21;		temp.I22 = I22 -= param.I22;		temp.I23 = I23 -= param.I23;
	temp.I31 = I31 -= param.I31;		temp.I32 = I32 -= param.I32;		temp.I33 = I33 -= param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator * (Matrix3x3 param)
{
	Matrix3x3 temp;
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33);

	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33);

	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33);

	return temp;
}

Matrix3x3 Matrix3x3::operator * (float param)
{
	Matrix3x3 temp;

	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;

	return temp;
}

Matrix3x3 Matrix3x3::operator / (float param)
{
	Matrix3x3 temp;
	if(param > 0 || param < 0)
	{
		temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;
		temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;
		temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;
	}
	return temp;
}

bool Matrix3x3::operator == (Matrix3x3 param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return true;
	else return false;
}

bool Matrix3x3::operator != (Matrix3x3 param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return false;
	else return true;
}
#pragma endregion