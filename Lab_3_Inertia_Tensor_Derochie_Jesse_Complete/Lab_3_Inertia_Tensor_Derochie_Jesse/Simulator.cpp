#include "Simulator.h"


Simulator::Simulator(void)
{
}


Simulator::~Simulator(void)
{
}

void Simulator::Run_InertiaTensor_Test()
{
//CREATE RIGID BODIES
	Shape warpDrive1(PhysicsEngine::Vector3(150.0f, 75.0f, 100.0f), PhysicsEngine::Vector3(250.0f, 50.0f, 50.0f), 150000.0f);
	Shape warpDrive2(PhysicsEngine::Vector3(-150.0f, 75.0f, 100.0f), PhysicsEngine::Vector3(250.0f, 50.0f, 50.0f), 150000.0f);
	Shape engineRoom(PhysicsEngine::Vector3(0.0f, 0.0f, 0.0f), PhysicsEngine::Vector3(150.0f, 50.0f, 100.0f), 400000.0f);
	Shape bridge(PhysicsEngine::Vector3(0.0f, 50.0f, -300.0f), 150.0f, 50.0f, 300000.0f);

//INSTANTIATE CALCULATOR
	Calculator calc;

//CALCULATE TOTAL MASS AND CENTER OF MASS
	calc.calcTotalMass(warpDrive1.mass, warpDrive2.mass, engineRoom.mass, bridge.mass);
	calc.calc_COM(warpDrive1.position, warpDrive2.position, engineRoom.position, bridge.position, warpDrive1.mass, warpDrive2.mass, engineRoom.mass, bridge.mass);

//WARP DRIVE 1
	calc.FindDistance(warpDrive1.position, calc.centerOfMass);
	calc.SolidCuboid_I_Tensor(warpDrive1.size, calc.distanceToCOM, warpDrive1.mass);

	warpDrive1.I11 = calc.I_Tensor.I11;
	warpDrive1.I22 = calc.I_Tensor.I22;
	warpDrive1.I33 = calc.I_Tensor.I33;

//WARP DRIVE 2
	calc.FindDistance(warpDrive2.position, calc.centerOfMass);
	calc.SolidCuboid_I_Tensor(warpDrive2.size, calc.distanceToCOM, warpDrive2.mass);

	warpDrive2.I11 = calc.I_Tensor.I11;
	warpDrive2.I22 = calc.I_Tensor.I22;
	warpDrive2.I33 = calc.I_Tensor.I33;

//ENGINE ROOM
	calc.FindDistance(engineRoom.position, calc.centerOfMass);
	calc.SolidCuboid_I_Tensor(engineRoom.size, calc.distanceToCOM, engineRoom.mass);

	engineRoom.I11 = calc.I_Tensor.I11;
	engineRoom.I22 = calc.I_Tensor.I22;
	engineRoom.I33 = calc.I_Tensor.I33;

//BRIDGE
	calc.FindDistance(bridge.position, calc.centerOfMass);
	calc.SolidCylinder_I_Tensor(calc.distanceToCOM, bridge.radius, bridge.height, bridge.mass);

	bridge.I11 = calc.I_Tensor.I11;
	bridge.I22 = calc.I_Tensor.I22;
	bridge.I33 = calc.I_Tensor.I33;

//STORE DATA IN MATRICES
	float IXX = warpDrive1.I11 + warpDrive2.I11 + engineRoom.I11 + bridge.I11;
	float IYY = warpDrive1.I22 + warpDrive2.I22 + engineRoom.I22 + bridge.I22;
	float IZZ = warpDrive1.I33 + warpDrive2.I33 + engineRoom.I33 + bridge.I33;

	PhysicsEngine::Matrix3x3 InertiaTensor;
	PhysicsEngine::Matrix3x3 InverseInertiaTensor;

	InertiaTensor.I11 = IXX, InertiaTensor.I22 = IYY, InertiaTensor.I33 = IZZ;
	InertiaTensor.I12 = InertiaTensor.I13 = InertiaTensor.I21 = InertiaTensor.I23 = InertiaTensor.I31 = InertiaTensor.I32 = 0.0f;

	InverseInertiaTensor = InertiaTensor.InvertMatrix();

//CALCULATE ORIENTATION MATRIX
	PhysicsEngine::Matrix3x3 OrientationMatrix;
	OrientationMatrix = OrientationMatrix.RotateMatrix(30, 'x');

//CALCULATE WORLD INERTIA TENSOR

	PhysicsEngine::Matrix3x3 WorldInertiaTensor;
	PhysicsEngine::Matrix3x3 Transpose_OrientationMatrix;
	Transpose_OrientationMatrix = OrientationMatrix.TransposeMatrix();
	WorldInertiaTensor = OrientationMatrix * InertiaTensor * Transpose_OrientationMatrix;

	PhysicsEngine::Matrix3x3 Inverse_World_I_Tensor;
	Inverse_World_I_Tensor = WorldInertiaTensor.InvertMatrix();

	//Inverse_World_I_Tensor = Inverse_World_I_Tensor.GetAdjunct();

//PRINT DATA TO THE SCREEN USING THE MATRICES
	calc.PrintToScreen(InertiaTensor, "Local Inertia Tensor");
	calc.PrintToScreen(InverseInertiaTensor, "Local Inverse Inertia Tensor");
	calc.PrintToScreen(OrientationMatrix, "Orientation Matrix");
	calc.PrintToScreen(WorldInertiaTensor, "World Inertia Tensor");
	calc.PrintToScreen(Inverse_World_I_Tensor, "Inverse World Inertia Tensor");
}