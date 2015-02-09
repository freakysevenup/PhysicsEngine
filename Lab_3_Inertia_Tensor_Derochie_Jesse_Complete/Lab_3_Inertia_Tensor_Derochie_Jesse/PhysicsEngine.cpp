#include "PhysicsEngine.h"
#include "Error.h"


#pragma region PhysicsEngine::Vector2

#pragma region Constructors & Deconstructors

PhysicsEngine::Vector2::Vector2(void)
{}

PhysicsEngine::Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
PhysicsEngine::Vector2::Vector2(Vector2 _paramOne, Vector2 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
PhysicsEngine::Vector2::~Vector2(void)
{}

#pragma endregion

#pragma region Operators
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator+(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator+=(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator+(float param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x + param;
	temp.y = y + param;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator+=(float param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x += param;
	temp.y = y += param;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator-(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator-=(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator*(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator*=(PhysicsEngine::Vector2 param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator*(float param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x * param;
	temp.y = y * param;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator*=(float param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	return temp;
}
PhysicsEngine::Vector2 PhysicsEngine::Vector2::operator/(float param)
{
	PhysicsEngine::Vector2 temp;
	temp.x = x / param;
	temp.y = y / param;
	return temp;
}

bool PhysicsEngine::Vector2::operator==(PhysicsEngine::Vector2 param)
{
	if (x == param.x && y == param.y) return true;
	else return false;
}
bool PhysicsEngine::Vector2::operator!=(PhysicsEngine::Vector2 param)
{
	if (x == param.x && y == param.y) return false;
	else return true;
}
bool PhysicsEngine::Vector2::operator<(PhysicsEngine::Vector2 param)
{
	if (abs(x) < abs(param.x) && abs(y) < abs(param.y)) return true;
	else return true;
}
bool PhysicsEngine::Vector2::operator>(PhysicsEngine::Vector2 param)
{
	if (abs(x) > abs(param.x) && abs(y) > abs(param.y)) return true;
	else return true;
}
#pragma endregion

#pragma region Methods
PhysicsEngine::Vector2 PhysicsEngine::Vector2::Zero()
{
	return PhysicsEngine::Vector2(0.0f, 0.0f);
}

PhysicsEngine::Vector2 PhysicsEngine::Vector2::Normalize()
{
	PhysicsEngine::Vector2 temp;
	float magnitude = ::sqrt((x * x) + (y * y));
	if(magnitude != 0)
	{
		PhysicsEngine::Vector2 normal(x / magnitude, y / magnitude);
		temp = normal;
	}
	else
	{
		fatalError("While trying to normalize magnitude was calculated to be zero, \n operation aborted.");
	}
	return temp;
}

void PhysicsEngine::Vector2::rotateVector(float _angle)
{
	float tempX = x;
	float tempY = y;
	x = tempX * ::cos(_angle) - tempY * ::sin(_angle);
	y = tempX * ::sin(_angle) + tempY * ::cos(_angle);
}

float PhysicsEngine::Vector2::Dot(PhysicsEngine::Vector2 _passed1, PhysicsEngine::Vector2 _passed2)
{
	return ((_passed1.x * _passed2.x) + (_passed1.y * _passed2.y));
}

float PhysicsEngine::Vector2::Length()
{
	return ::sqrtf(x * x + y * y);
}

#pragma endregion

#pragma endregion

#pragma region PhysicsEngine::Vector3


#pragma region Constructors & Deconstructors

PhysicsEngine::Vector3::Vector3(void)
{}
PhysicsEngine::Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
PhysicsEngine::Vector3::Vector3(PhysicsEngine::Vector3 _paramOne, PhysicsEngine::Vector3 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
PhysicsEngine::Vector3::~Vector3(void)
{}

#pragma endregion

#pragma region Operators
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator + (PhysicsEngine::Vector3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	temp.z = z + param.z;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator += (PhysicsEngine::Vector3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	temp.z = z += param.z;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator + (float param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x + param;
	temp.y = y + param;
	temp.z = z + param;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator += (float param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x += param;
	temp.y = y += param;
	temp.z = z += param;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator - (PhysicsEngine::Vector3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	temp.z = z - param.z;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator -= (PhysicsEngine::Vector3 param)
{
	Vector3 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	temp.z = z -= param.z;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator * (PhysicsEngine::Vector3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	temp.z = z * param.z;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator *= (PhysicsEngine::Vector3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	temp.z = z *= param.z;
	return temp;
}

PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator * (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = (x * param.I11) + (y * param.I21) + (z * param.I31);
	temp.y = (x * param.I12) + (y * param.I22) + (z * param.I32);
	temp.z = (x * param.I13) + (y * param.I23) + (z * param.I33);
	return temp;
}

PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator * (float param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x * param;
	temp.y = y * param;
	temp.z = z * param;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator *= (float param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	temp.z = z *= param;
	return temp;
}
PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator / (float param)
{
	PhysicsEngine::Vector3 temp;
	temp.x = x / param;
	temp.y = y / param;
	temp.z = z / param;
	return temp;
}

PhysicsEngine::Vector3 PhysicsEngine::Vector3::operator /= (float param)
{
	PhysicsEngine::Vector3 temp;
	temp = temp / param;
	return temp ;
}

bool PhysicsEngine::Vector3::operator==(PhysicsEngine::Vector3 param)
{
	if (x == param.x && y == param.y && z == param.z) return true;
	else return false;
}
bool PhysicsEngine::Vector3::operator!=(PhysicsEngine::Vector3 param)
{
	if (x == param.x && y == param.y && z == param.z) return false;
	else return true;
}
bool PhysicsEngine::Vector3::operator<(PhysicsEngine::Vector3 param)
{
	if (abs(x) < abs(param.x) && abs(y) < abs(param.y) && abs(z) < abs(param.z)) return true;
	else return true;
}
bool PhysicsEngine::Vector3::operator>(PhysicsEngine::Vector3 param)
{
	if (abs(x) > abs(param.x) && abs(y) > abs(param.y)  && abs(z) > abs(param.z)) return true;
	else return true;
}
#pragma endregion

#pragma region Methods
PhysicsEngine::Vector3 PhysicsEngine::Vector3::Zero()
{
	return PhysicsEngine::Vector3(0.0f, 0.0f, 0.0f);
}

PhysicsEngine::Vector3 PhysicsEngine::Vector3::Normalize()
{
	PhysicsEngine::Vector3 temp;
	float magnitude = ::sqrt((x * x) + (y * y) + (z * z));

	if(magnitude != 0)
	{
		PhysicsEngine::Vector3 normal(x / magnitude, y / magnitude, z / magnitude);
		temp = normal;
	}
	else
	{
		fatalError("While trying to normalize magnitude was calculated to be zero, \n operation aborted \n Line 324 PhysicsEngine::Vector3 - Methods.");
	}
	return temp;
}

PhysicsEngine::Vector3 PhysicsEngine::Vector3::Cross(PhysicsEngine::Vector3 _passed)
{
	PhysicsEngine::Vector3 temp;

	temp.x = ((y * _passed.z) - (z * _passed.y));
	temp.y = ((z * _passed.x) - (x * _passed.z));
	temp.z = ((x * _passed.y) - (y * _passed.x));

	return temp;
}


float PhysicsEngine::Vector3::Length()
{
	return ::sqrtf(x * x + y * y + z * z);
}

float PhysicsEngine::Vector3::Dot(PhysicsEngine::Vector3 _passed1, PhysicsEngine::Vector3 _passed2)
{
	return ((_passed1.x * _passed2.x) + (_passed1.y * _passed2.y) + (_passed1.z * _passed2.z));
}




#pragma endregion

#pragma endregion

#pragma region PhysicsEngine::Vector4

PhysicsEngine::Vector4::Vector4(void)
{

}

PhysicsEngine::Vector4::Vector4(float xx, float yy, float zz, float ww)
{
	x = xx; 
	y = yy; 
	z = zz; 
	w = ww;
}

PhysicsEngine::Vector4::~Vector4(void)
{
}

void PhysicsEngine::Vector4::operator () (float xx, float yy, float zz, float ww)	
{
	x = xx; 
	y = yy; 
	z = zz; 
	w = ww;
}

bool PhysicsEngine::Vector4::operator == (PhysicsEngine::Vector4 &param)
{
	return (x == param.x && y == param.y && z == param.z && w == param.w);
}

bool PhysicsEngine::Vector4::operator != (PhysicsEngine::Vector4 &param)
{
	return (x != param.x || y != param.y || z != param.z || w != param.w);
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator = (PhysicsEngine::Vector4 &param)
{
	x = param.x; 
	y = param.y;	
	z = param.z;	
	w = param.w;	
	return *this;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator - (void)
{
	return PhysicsEngine::Vector4(-x, -y, -z, w);
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator + (PhysicsEngine::Vector4 &param)
{
	return PhysicsEngine::Vector4(x + param.x, y + param.y, z + param.z, w);
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator - (PhysicsEngine::Vector4 &param)
{
	return PhysicsEngine::Vector4(x - param.x, y - param.y, z - param.z, 0);
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator * (float param)
{
	PhysicsEngine::Vector4 temp(*this);			
	return temp *= param;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator / (float param)
{
	PhysicsEngine::Vector4 temp(*this);			
	return temp /= param;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator += (PhysicsEngine::Vector4 &param)
{
	x += param.x;
	y += param.y;
	z += param.z;	
	return *this;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator -= (PhysicsEngine::Vector4 &param)
{
	x -= param.x;
	y -= param.y;
	z -= param.z;	
	return *this;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator *= (float  param)
{
	x *= param;
	y *= param;
	z *= param;
	w *= param;
	return *this;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator /= (float  param)
{
	x /= param; 
	y /= param; 
	z /= param;	
	w /= param;								
	return *this;
}

float PhysicsEngine::Vector4::operator * (PhysicsEngine::Vector4 &param)
{
	return x * param.x + y * param.y + z * param.z;
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::operator % (PhysicsEngine::Vector4 &param)
{
	PhysicsEngine::Vector4 temp(y * param.z - z * param.y, z * param.x - x * param.z, x * param.y - y * param.x, 0);
	return temp;
}

float PhysicsEngine::Vector4::Length_Squared()
{
	return (float)(*this * *this);
}

float PhysicsEngine::Vector4::Length()
{
	return (float)::sqrt(*this * *this);
}

void PhysicsEngine::Vector4::Normalize()
{
	*this /= Length();
}

void PhysicsEngine::Vector4::Reflect(PhysicsEngine::Vector4 &param)
{
	PhysicsEngine::Vector4 original(*this);
	Project(param);
	*this = *this * 2 - original;
}

void PhysicsEngine::Vector4::Project(PhysicsEngine::Vector4 &param)
{
	*this = param * (*this * param) / (param * param);
}

PhysicsEngine::Vector4 PhysicsEngine::Vector4::Projected(PhysicsEngine::Vector4 &param)
{
	return param * (*this * param) / (param * param);
}


#pragma endregion

#pragma region PhysicsEngine::Matrix3x3

#pragma region Constructors & Deconstructors

PhysicsEngine::Matrix3x3::Matrix3x3(void)
{
}


PhysicsEngine::Matrix3x3::Matrix3x3(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine)
{
	I11 = one;		I12 = two;		I13 = three;
	I21 = four;		I22 = five;		I23 = six;
	I31 = seven;	I32 = eight;	I33 = nine;
}

PhysicsEngine::Matrix3x3::Matrix3x3(PhysicsEngine::Vector3 paramOne, PhysicsEngine::Vector3 paramTwo, PhysicsEngine::Vector3 paramThree)
{
	I11 = paramOne.x;		I12 = paramOne.y;		I13 = paramOne.z;
	I21 = paramTwo.x;		I22 = paramTwo.y;		I23 = paramTwo.z;
	I31 = paramThree.x;		I32 = paramThree.y;		I33 = paramThree.z;
}

PhysicsEngine::Matrix3x3::~Matrix3x3(void)
{
}
#pragma endregion

#pragma region Operators
PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator + (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;
	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator += (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp;

	return temp = temp + param;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator - (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;
	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator -= (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp;
	temp.I11 = I11 -= param.I11;		temp.I12 = I12 -= param.I12;		temp.I13 = I13 -= param.I13;
	temp.I21 = I21 -= param.I21;		temp.I22 = I22 -= param.I22;		temp.I23 = I23 -= param.I23;
	temp.I31 = I31 -= param.I31;		temp.I32 = I32 -= param.I32;		temp.I33 = I33 -= param.I33;
	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator * (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp;
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

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator *= (PhysicsEngine::Matrix3x3 param)
{
	PhysicsEngine::Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp * param;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator * (float param)
{
	PhysicsEngine::Matrix3x3 temp;

	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;

	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator *= (float param)
{
	PhysicsEngine::Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp * param;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator / (float param)
{
	PhysicsEngine::Matrix3x3 temp;
	if(param > 0.0f || param < 0.0f)
	{
		temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;
		temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;
		temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;
	}
	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::operator /= (float param)
{
	PhysicsEngine::Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp / param;
}

bool PhysicsEngine::Matrix3x3::operator == (PhysicsEngine::Matrix3x3 param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return true;
	else return false;
}

bool PhysicsEngine::Matrix3x3::operator != (PhysicsEngine::Matrix3x3 param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return false;
	else return true;
}

#pragma endregion

#pragma region Methods

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::TransposeMatrix()
{
	PhysicsEngine::Matrix3x3 transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;

	return transpose;
}

float PhysicsEngine::Matrix3x3::Get3x3Determinant(float I11, float D11, float I12, float D12, float I13, float D13)
{
	return ((I11 * D11) + (I12 * D12) + (I13 * D13));
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::GetAdjunct()
{
	PhysicsEngine::Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	temp.I12 != 0.0f ? temp.I12 *= -1 : temp.I12;		temp.I21 != 0.0f ? temp.I21 *= -1 : temp.I21;
	temp.I23 != 0.0f ? temp.I23 *= -1 : temp.I23;		temp.I32 != 0.0f ? temp.I32 *= -1 : temp.I32;


	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::InvertMatrix()
{
	PhysicsEngine::Matrix3x3 temp;
	float determinant;

	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	temp.I21 = D21 = (I12 * I33) - (I32 * I13);		temp.I22 = D22 = (I11 * I33) - (I31 * I13);		temp.I23 = D23 = (I11 * I32) - (I31 * I12);
	temp.I31 = D31 = (I12 * I23) - (I22 * I13);		temp.I32 = D32 = (I11 * I23) - (I21 * I13);		temp.I33 = D33 = (I11 * I22) - (I21 * I12);

	temp = temp.GetAdjunct();

	temp.TransposeMatrix();

	determinant = Get3x3Determinant(I11, D11, I12, D12, I13, D13);

	temp = temp / determinant;

	return temp;
}

PhysicsEngine::Matrix3x3 PhysicsEngine::Matrix3x3::RotateMatrix(float _angle, char axis)
{
	PhysicsEngine::Matrix3x3 temp;

	if(axis == 'x' || axis == 'X')
	{
		//Rotate about the X axis when axis is equal to 1
		PhysicsEngine::Matrix3x3 rotateByFloat( 1.0f, 0.0f, 0.0f, 0.0f, ::cos((_angle * 3.141592653589793) / 180), -::sin((_angle * 3.141592653589793) / 180), 0.0f, ::sin((_angle * 3.141592653589793) / 180), ::cos((_angle * 3.141592653589793) / 180));
		temp = rotateByFloat;
	}

	if(axis == 'y' || axis == 'Y')
	{
		//Rotate about the Y axis when axis is equal to 2
		PhysicsEngine::Matrix3x3 rotateByFloat( ::cos((_angle * 3.141592653589793) / 180), -::sin((_angle * 3.141592653589793) / 180), 0.0f, ::sin((_angle * 3.141592653589793) / 180), ::cos((_angle * 3.141592653589793) / 180), 0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
	}

	if(axis == 'z' || axis == 'Z')
	{
		//Rotate about the Z axis when axis is equal to 3
		PhysicsEngine::Matrix3x3 rotateByFloat( ::cos((_angle * 3.141592653589793) / 180), 0.0f, ::sin((_angle * 3.141592653589793) / 180), 0.0f, 1.0f, 0.0f, -::sin((_angle * 3.141592653589793) / 180), 0.0f, ::cos((_angle * 3.141592653589793) / 180));
		temp = rotateByFloat;
	}
	return temp;
}


#pragma endregion

#pragma endregion

#pragma region PhysicsEngine::Matrix4x4

PhysicsEngine::Matrix4x4::Matrix4x4(void)
{
}

PhysicsEngine::Matrix4x4::Matrix4x4(float a_One, float a_Two, float a_Three, float a_Four, 
									float b_One, float b_Two, float b_Three, float b_Four, 
									float c_One, float c_Two, float c_Three, float c_Four, 
									float d_One, float d_Two, float d_Three, float d_Four)
{
	I11 = a_One;		I12 = a_Two;		I13 = a_Three;		I14 = a_Four;
	I21 = b_One;		I22 = b_Two;		I23 = b_Three;		I24 = b_Four;
	I31 = c_One;		I32 = c_Two;		I33 = c_Three;		I34 = c_Four;
	I41 = d_One;		I42 = d_Two;		I43 = d_Three;		I44 = d_Four;
}

PhysicsEngine::Matrix4x4::Matrix4x4(Vector4 row1, Vector4 row2, Vector4 row3, Vector4 row4)
{
	I11 = row1.x;		I12 = row1.y;		I13 = row1.z;		I14 = row1.w;
	I21 = row2.x;		I22 = row2.y;		I23 = row2.z;		I24 = row2.w;
	I31 = row3.x;		I32 = row3.y;		I33 = row3.z;		I34 = row3.w;
	I41 = row4.x;		I42 = row4.y;		I43 = row4.z;		I44 = row4.w;
}

PhysicsEngine::Matrix4x4::~Matrix4x4(void)
{
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator + (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;		temp.I14 = I14 + param.I14;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;		temp.I24 = I24 + param.I24;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;		temp.I34 = I34 + param.I34;
	temp.I41 = I41 + param.I41;		temp.I42 = I42 + param.I42;		temp.I43 = I43 + param.I43;		temp.I44 = I44 + param.I44;
	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator += (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	return temp = temp + param;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator - (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;		temp.I14 = I14 - param.I14;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;		temp.I24 = I24 - param.I24;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;		temp.I34 = I34 - param.I34;
	temp.I41 = I41 - param.I41;		temp.I42 = I42 - param.I42;		temp.I43 = I43 - param.I43;		temp.I44 = I44 - param.I44;
	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator -= (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	return temp = temp - param;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator * (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	//ROW 1
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31) + (I14 * param.I41);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32) + (I14 * param.I42);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33) + (I14 * param.I43);
	temp.I14 = (I11 * param.I14) + (I12 * param.I24) + (I13 * param.I34) + (I14 * param.I44);

	//ROW 2
	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31) + (I24 * param.I41);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32) + (I24 * param.I42);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33) + (I24 * param.I43);
	temp.I24 = (I21 * param.I14) + (I22 * param.I24) + (I23 * param.I34) + (I24 * param.I44);

	//ROW 3
	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31) + (I34 * param.I41);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32) + (I34 * param.I42);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33) + (I34 * param.I43);
	temp.I34 = (I31 * param.I14) + (I32 * param.I24) + (I33 * param.I34) + (I34 * param.I44);

	//ROW 4
	temp.I41 = (I41 * param.I11) + (I42 * param.I21) + (I43 * param.I31) + (I44 * param.I41);
	temp.I42 = (I41 * param.I12) + (I42 * param.I22) + (I43 * param.I32) + (I44 * param.I42);
	temp.I43 = (I41 * param.I13) + (I42 * param.I23) + (I43 * param.I33) + (I44 * param.I43);
	temp.I44 = (I41 * param.I14) + (I42 * param.I24) + (I43 * param.I34) + (I44 * param.I44);

	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator *= (Matrix4x4 param)
{
	PhysicsEngine::Matrix4x4 temp;
	return temp = temp * param;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator * (float param)
{
	PhysicsEngine::Matrix4x4 temp;
	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;		temp.I14 = I14 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;		temp.I24 = I24 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;		temp.I34 = I34 * param;
	temp.I41 = I41 * param;		temp.I42 = I42 * param;		temp.I43 = I43 * param;		temp.I44 = I44 * param;
	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator *= (float param)
{
	PhysicsEngine::Matrix4x4 temp;
	return temp = temp * param;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator / (float param)
{
	PhysicsEngine::Matrix4x4 temp;
	temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;		temp.I14 = I14 / param;
	temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;		temp.I24 = I24 / param;
	temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;		temp.I34 = I34 / param;
	temp.I41 = I41 / param;		temp.I42 = I42 / param;		temp.I43 = I43 / param;		temp.I44 = I44 / param;
	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::operator /= (float param)
{
	PhysicsEngine::Matrix4x4 temp;
	return temp = temp / param;
}

bool PhysicsEngine::Matrix4x4::operator == (Matrix4x4 param)
{
	if(I11 == param.I11 && I12 == param.I12	&& I13 == param.I13	&& I14 == param.I14	&& 
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 && I24 == param.I24 && 
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33 && I34 == param.I34 && 
		I41 == param.I41 && I42 == param.I42 && I43 == param.I43 && I44 == param.I44) return true;
	else return false;
}

bool PhysicsEngine::Matrix4x4::operator != (Matrix4x4 param)
{
		if(I11 != param.I11 || I12 != param.I12	|| I13 != param.I13	|| I14 != param.I14	|| 
		I21 != param.I21 || I22 != param.I22 || I23 != param.I23 || I24 != param.I24 || 
		I31 != param.I31 || I32 != param.I32 || I33 != param.I33 || I34 != param.I34 || 
		I41 != param.I41 || I42 != param.I42 || I43 != param.I43 || I44 != param.I44) return true;
	else return false;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::TransposeMatrix()
{
	PhysicsEngine::Matrix4x4 transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;		transpose.I14 = I41;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;		transpose.I24 = I42;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;		transpose.I34 = I43;
	transpose.I41 = I14;		transpose.I42 = I24;		transpose.I43 = I34;		transpose.I44 = I44;

	return transpose;
}

float PhysicsEngine::Matrix4x4::Get3x3Determinant(float aI, float aD, float bI, float bD, float cI, float cD)
{
	return ((aI * aD) + (bI * bD) + (cI * cD));
}


PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::GetAdjunct()
{
	PhysicsEngine::Matrix4x4 temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	temp.I12 != 0.0f ? temp.I12 *= -1 : temp.I12;		temp.I14 != 0.0f ? temp.I14 *= -1 : temp.I14;		temp.I21 != 0.0f ? temp.I21 *= -1 : temp.I21;
	temp.I23 != 0.0f ? temp.I23 *= -1 : temp.I23;		temp.I32 != 0.0f ? temp.I32 *= -1 : temp.I32;		temp.I34 != 0.0f ? temp.I34 *= -1 : temp.I34;
	temp.I41 != 0.0f ? temp.I41 *= -1 : temp.I41;		temp.I43 != 0.0f ? temp.I43 *= -1 : temp.I43;

	return temp;
}

PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::RotateMatrix(float _angle, char axis)
{
	PhysicsEngine::Matrix4x4 temp;

	if(axis == 'x' || axis == 'X')
	{
		//Rotate about the X axis when axis is equal to 1
		PhysicsEngine::Matrix4x4 rotateByFloat( 1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, (float)::cos((-_angle * 3.141592653589793) / 180), (float)-::sin((-_angle * 3.141592653589793) / 180), 0.0f, 
			0.0f, (float)::sin((-_angle * 3.141592653589793) / 180), (float)::cos((-_angle * 3.141592653589793) / 180), 0.0f, 
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
	}

	if(axis == 'y' || axis == 'Y')
	{
		//Rotate about the Y axis when axis is equal to 2
		PhysicsEngine::Matrix4x4 rotateByFloat((float)::cos((-_angle * 3.141592653589793) / 180), 0.0f, (float)::sin((-_angle * 3.141592653589793) / 180), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			(float)-::sin((-_angle * 3.141592653589793) / 180), 0.0f, (float)::cos((-_angle * 3.141592653589793) / 180), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
	}

	if(axis == 'z' || axis == 'Z')
	{
		//Rotate about the Z axis when axis is equal to 3
		PhysicsEngine::Matrix4x4 rotateByFloat((float)::cos((-_angle * 3.141592653589793) / 180), (float)-::sin((-_angle * 3.141592653589793) / 180), 0.0f, 0.0f,
			(float)::sin((_angle * 3.141592653589793) / 180), (float)::cos((_angle * 3.141592653589793) / 180), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
	}
	return temp;
}




PhysicsEngine::Matrix4x4 PhysicsEngine::Matrix4x4::InvertMatrix()
{
	PhysicsEngine::Matrix4x4 returnMatrix(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	float Determinant = 0.0f;
	PhysicsEngine::Matrix3x3 temp(I22, I23, I24, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I21, I23, I24, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I21, I22, I24, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I21, I22, I23, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I12, I13, I14, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I13, I14, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I14, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I13, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I12, I13, I14, I22, I23, I24, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I13, I14, I21, I23, I24, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I14, I21, I22, I24, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I13, I21, I22, I23, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I12, I13, I14, I22, I23, I24, I32, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I13, I14, I21, I23, I24, I31, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I14, I21, I22, I24, I31, I32, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = PhysicsEngine::Matrix3x3(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	returnMatrix = returnMatrix.GetAdjunct();

	returnMatrix.TransposeMatrix();

	returnMatrix = returnMatrix / Determinant;

	return returnMatrix;

}
#pragma endregion

#pragma region PhysicsEngine::Quaternion

/****************************************
 * Quaternion class
 * By Will Perone (will.perone@gmail.com)
 * Original: 12-09-2003  
 * Revised:  27-09-2003
 *           22-11-2003
 *           10-12-2003
 *           15-01-2004
 *           16-04-2004
 *           07-29-2011    added corrections from website
 *           22-12-2011    added correction to *= operator, thanks Steve Rogers
 *           22-10-2012    fixed ctor from euler angles & added non windows platform fixes, thanks to Art Golf
 *   
 * Dependancies: My 4x4 matrix class
 * 
 * © 2003, This code is provided "as is" and you can use it freely as long as 
 * credit is given to Will Perone in the application it is used in
 *
 * Notes:  
 * if |q|=1 then q is a unit quaternion
 * if q=(0,v) then q is a pure quaternion 
 * if |q|=1 then q conjugate = q inverse
 * if |q|=1 then q= [cos(angle), u*sin(angle)] where u is a unit vector 
 * q and -q represent the same rotation 
 * q*q.conjugate = (q.length_squared, 0) 
 * ln(cos(theta),sin(theta)*v)= ln(e^(theta*v))= (0, theta*v)

Jesse Derochie (jesse.a.derochie@gmail.com)
Revised:  08-FEB-2015

Places I found this code online as of February 7th 2015
	http://www.willperone.net/Code/quaternion.php
	https://github.com/MegaManSE/willperone/tree/master/Math

****************************************/


PhysicsEngine::Quaternion::Quaternion(void)
{

}

PhysicsEngine::Quaternion::Quaternion(float _w, Vector3 _v)
{
	s = _w;
	v = _v;
}

PhysicsEngine::Quaternion::Quaternion(Vector4 _v)
{
	s = _v.w;
	v.x = _v.x;
	v.y = _v.y;
	v.z = _v.z;
}


PhysicsEngine::Quaternion::Quaternion(float _w, float _x, float _y, float _z)
{
	s = _w;
	v.x = _x;
	v.y = _y;
	v.z = _z;
}

PhysicsEngine::Quaternion::~Quaternion(void)
{
}

void PhysicsEngine::Quaternion::QuaternionFromEulerAngles(float theta_z, float theta_y, float theta_x)
{
		float cos_z_2 = ::cosf(0.5 * theta_z);
		float cos_y_2 = ::cosf(0.5 * theta_y);
		float cos_x_2 = ::cosf(0.5 * theta_x);

		float sin_z_2 = ::sinf(0.5 * theta_z);
		float sin_y_2 = ::sinf(0.5 * theta_y);
		float sin_x_2 = ::sinf(0.5 * theta_x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;
}

void PhysicsEngine::Quaternion::QuaternionFromEulerAngles(const PhysicsEngine::Vector3 &angles)
	{	
		float cos_z_2 = ::cosf(0.5 * angles.z);
		float cos_y_2 = ::cosf(0.5 * angles.y);
		float cos_x_2 = ::cosf(0.5 * angles.x);

		float sin_z_2 = ::sinf(0.5 * angles.z);
		float sin_y_2 = ::sinf(0.5 * angles.y);
		float sin_x_2 = ::sinf(0.5 * angles.x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;		
	} 

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator = (PhysicsEngine::Quaternion q)		
{ 
	s = q.s; 
	v = q.v; 
	return *this; 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator + (PhysicsEngine::Quaternion q)	
{ 
	return PhysicsEngine::Quaternion(s + q.s, v + q.v); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator - (PhysicsEngine::Quaternion q)	
{ 
	return PhysicsEngine::Quaternion(s-q.s, v-q.v); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator * (PhysicsEngine::Quaternion q)
{	
	return PhysicsEngine::Quaternion(s*q.s - v.x * q.v.x + v.y * q.v.y + v.z * q.v.z,
				  v.y*q.v.z - v.z*q.v.y + s*q.v.x + v.x*q.s,
				  v.z*q.v.x - v.x*q.v.z + s*q.v.y + v.y*q.s,
				  v.x*q.v.y - v.y*q.v.x + s*q.v.z + v.z*q.s);
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator / (const PhysicsEngine::Quaternion q)
{
	PhysicsEngine::Quaternion p(q); 
	p.Invert(); 
	return *this * p;
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator * (float scale)
{ 
	return PhysicsEngine::Quaternion(s*scale,v*scale); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator / (float scale)
{ 
	return PhysicsEngine::Quaternion(s/scale,v/scale); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator - ()
{ 
	return PhysicsEngine::Quaternion(-s, v * -1.0f); 
}
	
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator += (PhysicsEngine::Quaternion q)		
{ 
	v += q.v; 
	s += q.s; 
	return *this; 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator -= (PhysicsEngine::Quaternion q)		
{ 
	v -= q.v; 
	s -= q.s; 
	return *this; 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator *= (PhysicsEngine::Quaternion q)		
{			
	float x = v.x;
	float y = v.y;
	float z = v.z;
	float sn = (s * q.s) - (v.x * q.v.x + v.y * q.v.y + v.z * q.v.z);

	v.x = y * q.v.z - z * q.v.y + s * q.v.x + x * q.s;
	v.y = z * q.v.x - x * q.v.z + s * q.v.y + y * q.s;
	v.z = x * q.v.y - y * q.v.x + s * q.v.z + z * q.s;
	s = sn;
	return *this;
}
	
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator *= (float scale)			
{ 
	v *= scale; 
	s *= scale; 
	return *this; 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::operator /= (float scale)			
{ 
	v /= scale; 
	s /= scale; 
	return *this; 
}


float PhysicsEngine::Quaternion::Length()
{ 
	return (float)::sqrt(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}


float PhysicsEngine::Quaternion::Length_Squared()
{ 
	return (float)(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}


void PhysicsEngine::Quaternion::Normalize()
{ 
	*this /= Length(); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Normalized()
{ 
	return  *this / Length(); 
}

void PhysicsEngine::Quaternion::Conjugate()
{ 
	v = v * -1.0f;
}

void PhysicsEngine::Quaternion::Invert()
{ 
	Conjugate(); 
	*this /= Length_Squared(); 
}
	
// returns the logarithm of a quaternion = v*a where q = [cos(a),v*sin(a)]
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Log()
{
	float a = (float)::acos(s);
	float sinOfA = (float)::sin(a);
	PhysicsEngine::Quaternion quatReturn;

	quatReturn.s = 0;
	if (sinOfA > 0)
	{
		quatReturn.v.x = a * v.x/sinOfA;
		quatReturn.v.y = a * v.y/sinOfA;
		quatReturn.v.z = a * v.z/sinOfA;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0;
	}
	return quatReturn;
}

// returns e^quaternion = exp(v*a) = [cos(a),vsin(a)]
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Exp()
{
	float a = (float)v.Length();
	float sinOfA = (float)::sin(a);
	float cosOfA = (float)::cos(a);
	PhysicsEngine::Quaternion quatReturn;

	quatReturn.s = cosOfA;
	if (a > 0)
	{
		quatReturn.v.x = sinOfA * v.x / a;
		quatReturn.v.y = sinOfA * v.y / a;
		quatReturn.v.z = sinOfA * v.z / a;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0;
	}
	return quatReturn;
}

float PhysicsEngine::Quaternion::Dot(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2) 
{ 
	float fTemp;
	fTemp = q1.v.Dot(q1.v, q2.v);
	return  fTemp + q1.s * q2.s; 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Lerp(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t) 
{ 
	return (q1 * (1 - t) + q2 * t).Normalized(); 
}

PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Slerp(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t) 
{
	PhysicsEngine::Quaternion q3;
	float dot = PhysicsEngine::Quaternion::Dot(q1, q2);

	/*	dot = cos(theta)
		if (dot < 0), q1 and q2 are more than 90 degrees apart,
		so we can invert one to reduce spinning	*/
	if (dot < 0)
	{
		dot = -dot;
		q3 = -q2;
	} else q3 = q2;
	
	if (dot < 0.95f)
	{
		float angle = ::acosf(dot);
		return (q1 * ::sinf(angle * (1 - t)) + q3 * ::sinf(angle * t)) / ::sinf(angle);
	} else // if the angle is small, use linear interpolation								
		return Lerp(q1,q3,t);			
}

	//! This version of slerp, used by squad, does not check for theta > 90.
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::SlerpNoInvert(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t) 
{
	float dot = PhysicsEngine::Quaternion::Dot(q1, q2);
	if (dot > -0.95f && dot < 0.95f)
	{
		float angle = ::acosf(dot);			
		return (q1 * ::sinf(angle * (1 - t)) + q2 * ::sinf(angle * t)) / ::sinf(angle);
	} else  // if the angle is small, use linear interpolation								
		return Lerp(q1,q2,t);				
}

	//! spherical cubic interpolation
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Squad(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, PhysicsEngine::Quaternion a, PhysicsEngine::Quaternion b, float t)
{
	PhysicsEngine::Quaternion c = SlerpNoInvert(q1, q2, t), d = SlerpNoInvert(a, b, t);		
	return SlerpNoInvert(c, d, 2 * t * (1 - t));
}

	//! Shoemake-Bezier interpolation using De Castlejau algorithm
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Bezier(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, PhysicsEngine::Quaternion a, PhysicsEngine::Quaternion b, float t)
{

	PhysicsEngine::Quaternion q11 = SlerpNoInvert(q1, a, t), q12 = SlerpNoInvert(a, b, t), q13 = SlerpNoInvert(b, q2, t);		

	return SlerpNoInvert(SlerpNoInvert(q11, q12, t), SlerpNoInvert(q12, q13, t), t);
}

	//! Given 3 quaternions, qn-1,qn and qn+1, calculate a control point to be used in spline interpolation
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::Spline(PhysicsEngine::Quaternion qnm1, PhysicsEngine::Quaternion qn, PhysicsEngine::Quaternion qnp1)
{
	PhysicsEngine::Quaternion qni(qn.s, qn.v * -1.0f);	
	return qn * (( (qni * qnm1).Log() + (qni * qnp1).Log() ) / -4).Exp();	
}

	//! converts from a normalized axis - angle pair rotation to a quaternion
PhysicsEngine::Quaternion PhysicsEngine::Quaternion::From_Axis_Angle(PhysicsEngine::Vector3 axis, float angle)
{ 
	return PhysicsEngine::Quaternion(::cosf(angle / 2), axis * ::sinf(angle / 2)); 
}

	//! returns the axis and angle of this unit quaternion
void PhysicsEngine::Quaternion::To_Axis_Angle(PhysicsEngine::Vector3 axis, float angle)
{
	angle = ::acosf(s);

	// pre-compute to save time
	float sinf_theta_inv = 1.0 / ::sinf(angle);

	// now the vector
	axis.x = v.x * sinf_theta_inv;
	axis.y = v.y * sinf_theta_inv;
	axis.z = v.z * sinf_theta_inv;

	// multiply by 2
	angle *= 2;
}

	//! rotates v by this quaternion (quaternion must be unit)
PhysicsEngine::Vector3 PhysicsEngine::Quaternion::Rotate(PhysicsEngine::Vector3 v)
{   
	PhysicsEngine::Quaternion V(0, v);
	PhysicsEngine::Quaternion conjugate(*this);
	conjugate.Conjugate();
	return (*this * V * conjugate).v;
}

	//! returns the euler angles from a rotation quaternion
PhysicsEngine::Vector3 PhysicsEngine::Quaternion::Euler_Angles(bool homogenous)
	{
		float sqw = s * s;    
		float sqx = v.x * v.x;    
		float sqy = v.y * v.y;    
		float sqz = v.z * v.z;    

		PhysicsEngine::Vector3 euler;
		if (homogenous) {
			euler.x = ::atan2f(2.f * (v.x * v.y + v.z * s), sqx - sqy - sqz + sqw);    		
			euler.y = ::asinf(-2.f * (v.x * v.z - v.y * s));
			euler.z = ::atan2f(2.f * (v.y * v.z + v.x * s), -sqx - sqy + sqz + sqw);    
		} else {
			euler.x = ::atan2f(2.f * (v.z * v.y + v.x * s), 1 - 2 * (sqx + sqy));
			euler.y = ::asinf(-2.f * (v.x * v.z - v.y * s));
			euler.z = ::atan2f(2.f * (v.x * v.y + v.z * s), 1 - 2 * (sqy + sqz));
		}
		return euler;
	}

#pragma endregion