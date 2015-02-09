#pragma once
#include <string>
#include "PhysicsEngine.h"

class Calculator
{
public:
	Calculator(void);
	~Calculator(void);

	float calcTotalMass(float M1, float M2);
	float calcTotalMass(float M1, float M2, float M3);
	float calcTotalMass(float M1, float M2, float M3, float M4);

	PhysicsEngine::Vector3 calc_COM(PhysicsEngine::Vector3 posi_1, PhysicsEngine::Vector3 posi_2, float _mass1, float _mass2);
	PhysicsEngine::Vector3 calc_COM(PhysicsEngine::Vector3 posi_1, PhysicsEngine::Vector3 posi_2, PhysicsEngine::Vector3 posi_3, float _mass1, float _mass2, float _mass3);
	PhysicsEngine::Vector3 calc_COM(PhysicsEngine::Vector3 posi_1, PhysicsEngine::Vector3 posi_2, PhysicsEngine::Vector3 posi_3, PhysicsEngine::Vector3 posi_4, float _mass1, float _mass2, float _mass3, float _mass4);

	PhysicsEngine::Vector3 FindDistance(PhysicsEngine::Vector3 _position, PhysicsEngine::Vector3 _centerOfMass);
	void SolidCuboid_I_Tensor(PhysicsEngine::Vector3 _size, PhysicsEngine::Vector3 _distanceToCOM, float _mass);
	void SolidCylinder_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float radius, float height, float _mass);
	void HollowCylinder_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius1, float _radius2, float _height, float _mass);
	void SolidSphere_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass);
	void HollowSphere_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass);
	void Right_Circular_Cone_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _radius, float _height, float _mass);
	void Rod_End_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _length, float _mass);
	void Rod_Center_I_Tensor(PhysicsEngine::Vector3 _distanceToCOM, float _length, float _mass);
	PhysicsEngine::Matrix3x3 WorldInertiaTensor(PhysicsEngine::Matrix3x3 InertiaTensor, PhysicsEngine::Matrix3x3 OrientationMatrix);


	float totalMass;
	PhysicsEngine::Matrix3x3 inertiaTensor;
	float parallelAxis;
	PhysicsEngine::Vector3 centerOfMass;
	PhysicsEngine::Vector3 distanceToCOM;

	void PrintToScreen(PhysicsEngine::Matrix3x3, std::string);

	PhysicsEngine::Matrix3x3 I_Tensor;

};

