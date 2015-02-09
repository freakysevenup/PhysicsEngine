#include <iostream>
#include "Calculator.h"


Calculator::Calculator(void) : totalMass(0), parallelAxis(0), centerOfMass(centerOfMass.Zero()), distanceToCOM(distanceToCOM.Zero())
{
}


Calculator::~Calculator(void)
{
}

float Calculator::calcTotalMass(float M1, float M2)
{
	totalMass = M1 + M2;
	return M1 + M2;
}

float Calculator::calcTotalMass(float M1, float M2, float M3)
{
	totalMass = M1 + M2 + M3;
	return M1 + M2 + M3;
}

float Calculator::calcTotalMass(float M1, float M2, float M3, float M4)
{
	totalMass = M1 + M2 + M3 + M4;
	return M1 + M2 + M3 + M4;
}

PhysicsEngine::Vector3 Calculator::calc_COM(PhysicsEngine::Vector3 _posi_1, PhysicsEngine::Vector3 _posi_2, float _mass1, float _mass2)
{
	PhysicsEngine::Vector3 temp;

	centerOfMass.x = temp.x = ((_mass1 * _posi_1.x) + (_mass2 * _posi_2.x)) / totalMass;
	centerOfMass.y = temp.y = ((_mass1 * _posi_1.y) + (_mass2 * _posi_2.y)) / totalMass;
	centerOfMass.z = temp.z = ((_mass1 * _posi_1.z) + (_mass2 * _posi_2.z)) / totalMass;

	return temp;
}

PhysicsEngine::Vector3 Calculator::calc_COM(PhysicsEngine::Vector3 _posi_1, PhysicsEngine::Vector3 _posi_2, PhysicsEngine::Vector3 _posi_3, float _mass1, float _mass2, float _mass3)
{
	PhysicsEngine::Vector3 temp;

	centerOfMass.x = temp.x = ((_mass1 * _posi_1.x) + (_mass2 * _posi_2.x) + (_mass3 * _posi_3.x)) / totalMass;
	centerOfMass.y = temp.y = ((_mass1 * _posi_1.y) + (_mass2 * _posi_2.y) + (_mass3 * _posi_3.y)) / totalMass;
	centerOfMass.z = temp.z = ((_mass1 * _posi_1.z) + (_mass2 * _posi_2.z) + (_mass3 * _posi_3.z)) / totalMass;

	return temp;
}

PhysicsEngine::Vector3 Calculator::calc_COM(PhysicsEngine::Vector3 _posi_1, PhysicsEngine::Vector3 _posi_2, PhysicsEngine::Vector3 _posi_3, PhysicsEngine::Vector3 _posi_4, float _mass1, float _mass2, float _mass3, float _mass4)
{
	PhysicsEngine::Vector3 temp;

	centerOfMass.x = temp.x = ((_mass1 * _posi_1.x) + (_mass2 * _posi_2.x) + (_mass3 * _posi_3.x) + (_mass4 * _posi_4.x)) / totalMass;
	centerOfMass.y = temp.y = ((_mass1 * _posi_1.y) + (_mass2 * _posi_2.y) + (_mass3 * _posi_3.y) + (_mass4 * _posi_4.y)) / totalMass;
	centerOfMass.z = temp.z = ((_mass1 * _posi_1.z) + (_mass2 * _posi_2.z) + (_mass3 * _posi_3.z) + (_mass4 * _posi_4.z)) / totalMass;

	return temp;
}

PhysicsEngine::Vector3 Calculator::FindDistance(PhysicsEngine::Vector3 _position, PhysicsEngine::Vector3 _centerOfMass)
{
	distanceToCOM = _centerOfMass - _position;
	return _centerOfMass - _position;
}

//	Size Vector3 is used as follows
//	X = depth;
//	Y = width;
//	Z = height;
void Calculator::SolidCuboid_I_Tensor(PhysicsEngine::Vector3 _size, PhysicsEngine::Vector3 _distanceToCOM, float _mass)
{
	I_Tensor.I11 = (((_mass / 12) * ((_size.z * _size.z) + (_size.x * _size.x))) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I22 = (((_mass / 12) * ((_size.y * _size.y) + (_size.x * _size.x))) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I33 = (((_mass / 12) * ((_size.y * _size.y) + (_size.z * _size.z))) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));
}

void Calculator::SolidCylinder_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass)
{
	I_Tensor.I11 = ((_mass / 12) * ((3 * (_radius * _radius)) + (_height * _height)) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I22 = (((_mass / 2) * (_radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I33 = ((_mass / 12) * ((3 * (_radius * _radius)) + (_height * _height)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));

}

//Thick Walled Cylindrical tube (inner radius, outer radius, length, mass)
void Calculator::HollowCylinder_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius1, float _radius2, float _height, float _mass)
{
	I_Tensor.I11 = ((_mass / 12) * (3 * (((_radius1 * _radius1) + (_radius2 * _radius2)) + (_height * _height))) + (((_height * _height)) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z)))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I21 = ((_mass / 12) * (3 * (((_radius1 * _radius1) + (_radius2 * _radius2)) + (_height * _height))) + (((_height * _height)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z)))));
	I_Tensor.I31 = ((_mass / 2) * (((_radius1 * _radius1) + (_radius2 * _radius2))) + (((_height * _height)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y)))));
}

//SolidSphere
void Calculator::SolidSphere_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass)
{
	I_Tensor.I11 = ((( 2 / 5 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z)));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I22 = (((( 2 / 5 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I33 = (((( 2 / 5 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));
}

//HollowSphere I_Tensor
void Calculator::HollowSphere_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass)
{
	I_Tensor.I11 = (((( 2 / 3 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I22 = (((( 2 / 3 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I33 = (((( 2 / 3 ) * _mass) * ( _radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));
}

//Right Circular Cone
void Calculator::Right_Circular_Cone_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass)
{
	I_Tensor.I11 = (((( 3 / 5 ) * _mass) * (_height * _height)) + ((( 3 / 20 ) * _mass) * (_radius * _radius)) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I22 = (((( 3 / 5 ) * _mass) * (_height * _height)) + ((( 3 / 20 ) * _mass) * (_radius * _radius)) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I33 = (((( 3 / 10 ) * _mass) * (_radius * _radius))) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y)));
}

//Slender Rod (y axis lengtth and mass about one end)
void Calculator::Rod_End_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _length, float _mass)
{
	I_Tensor.I11 = ((( _mass / 3 ) * ( _length * _length )) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I22 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I33 = ((( _mass / 3 ) * ( _length * _length )) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));
}

//Slender rod y axis length and mass about center
void Calculator::Rod_Center_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _length, float _mass)
{
	I_Tensor.I11 = ((( _mass / 12 ) * ( _length * _length )) + (_mass * ((_distanceToCOM.y * _distanceToCOM.y) + (_distanceToCOM.z * _distanceToCOM.z))));
	I_Tensor.I12 = I_Tensor.I13 = I_Tensor.I21 = I_Tensor.I22 = I_Tensor.I23 = I_Tensor.I31 = I_Tensor.I32 = 0.0f;
	I_Tensor.I33 = ((( _mass / 12 ) * ( _length * _length )) + (_mass * ((_distanceToCOM.x * _distanceToCOM.x) + (_distanceToCOM.y * _distanceToCOM.y))));
}


void Calculator::PrintToScreen(PhysicsEngine::Matrix3x3 _printMatrix, std::string _title)
{
	std::cout << "       ---" << _title << "---" << std::endl;
	std::cout << std::endl;

	if (_printMatrix.I11 == 1)
	{
		std::cout << _printMatrix.I11 << "		           " << _printMatrix.I12 << "	        	   " << _printMatrix.I13 << std::endl;
	}
	else
	{
		std::cout << _printMatrix.I11 << "		   " << _printMatrix.I12 << "		           " << _printMatrix.I13 << std::endl;
	}

	std::cout << _printMatrix.I21 << "    		           " << _printMatrix.I22 << "             " << _printMatrix.I23 << std::endl;

	if (_printMatrix.I32 == 0.5)
	{
		std::cout << _printMatrix.I31 << "    		           " << _printMatrix.I32 << "                  " << _printMatrix.I33 << std::endl;
	}
	else if (_printMatrix.I32 == 0)
	{
		std::cout << _printMatrix.I31 << "    		           " << _printMatrix.I32 << "                       " << _printMatrix.I33 << std::endl;
	}
	else
	{
		std::cout << _printMatrix.I31 << "    		           " << _printMatrix.I32 << "             " << _printMatrix.I33 << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

}
