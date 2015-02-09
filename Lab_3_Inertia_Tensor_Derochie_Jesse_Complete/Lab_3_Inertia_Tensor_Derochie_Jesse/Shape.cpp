#include "Shape.h"


Shape::Shape(void) 
	: depth(0), width(0), height(0), mass(0), radius(0), 
	size(size.Zero()), position(position.Zero()), 
	I11(0), I12(0), I13(0), I21(0), I22(0), I23(0), I31(0), I32(0), I33(0)
{

}

Shape::Shape(PhysicsEngine::Vector3 _position, float _radius, float _height, float _mass)
{
	position = _position;
	radius = _radius;
	height = _height;
	mass = _mass;
}


//  The _size Vector2 in this method will treat the values passed into in the following manner
//	X = radius
//  Y = height
Shape::Shape(PhysicsEngine::Vector3 _position, PhysicsEngine::Vector2 _size, float _mass)
{
	position = _position;
	radius = _size.x;
	height = _size.y;
	mass = _mass;
}

Shape::Shape(PhysicsEngine::Vector3 _position, float _depth, float _width, float _height, float _mass)
{
	position = _position;
	depth = _depth;
	width = _width;
	height = _height;
	mass = _mass;
}


//	The Vector3 _size in this method will be treated as follows
//	X = depth;
//	Y = width;
//	Z = height;
Shape::Shape(PhysicsEngine::Vector3 _position, PhysicsEngine::Vector3 _size, float _mass)
{
	position = _position;
	size = _size;
	depth = _size.x;
	width = _size.y;
	height = _size.z;
	mass = _mass;
}

Shape::~Shape(void)
{
}
