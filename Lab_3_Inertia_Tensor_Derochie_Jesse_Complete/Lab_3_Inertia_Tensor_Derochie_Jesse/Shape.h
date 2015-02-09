#pragma once
#include "PhysicsEngine.h"

struct Shape
{
public:
	Shape::Shape(void);
	Shape::Shape(PhysicsEngine::Vector3 position, float radius, float height, float mass);
	Shape::Shape(PhysicsEngine::Vector3 position, PhysicsEngine::Vector2 size, float mass);
	Shape::Shape(PhysicsEngine::Vector3 position, float depth, float width, float height, float mass);
	Shape::Shape(PhysicsEngine::Vector3 position, PhysicsEngine::Vector3 size, float mass);

	Shape::~Shape(void);

	PhysicsEngine::Vector3 position;
	/*
		The Size variable that follows will be treated as follows
		X = depth;
		Y = width;
		Z = height;
	*/
	PhysicsEngine::Vector3 size;

	float depth, width, height, mass, radius;
	float I11, I12, I13, I21, I22, I23, I31, I32, I33;

};

