#include <iostream>
#include <string>
#include <cmath>

#include "Vector.h"

using namespace Vector;

Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{
	ComputeParams();
}

Vector2D::~Vector2D()
{
	std::cout << "Destroyed: " << x << " " << y << std::endl;
}

Coords2D Vector2D::GetCoords()
{
	return { x, y };
}

void Vector2D::SetCoords(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
	ComputeParams();
}

void Vector2D::ComputeParams()
{
	magnitude = sqrt(x * x + y * y);
	alpha = x / magnitude;
	betha = y / magnitude;
}

Vector2D Vector::sum(Vector2D& vector1, Vector2D& vector2)
{
	Coords2D c1 = vector1.GetCoords();
	Coords2D c2 = vector2.GetCoords();
	return Vector2D(c1.x + c2.x, c1.y + c2.y);
}

float Vector::s_product(Vector2D& v1, Vector2D& v2)
{
	Coords2D c1 = v1.GetCoords();
	Coords2D c2 = v2.GetCoords();
	return c1.x * c2.x + c1.y * c2.y;
}

void Vector2D::normalize()
{
	this->SetCoords(x / magnitude, y / magnitude);
	this->ComputeParams();
}

Vector3D::Vector3D(float x, float y, float z)
	: x(x), y(y), z(z)
{
	ComputeParams();
}

Vector3D::~Vector3D()
{
	std::cout << "Destroyed: " << x << " " << y << " " << z << std::endl;
}

Coords3D Vector3D::GetCoords()
{
	return { x, y, z };
}

void Vector3D::SetCoords(float new_x, float new_y, float new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

void Vector::Vector3D::normalize()
{
	this->SetCoords(x / magnitude, y / magnitude, z / magnitude);
	this->ComputeParams();
}

void Vector3D::ComputeParams()
{
	magnitude = sqrt(x * x + y * y + z * z);
	alpha = x / magnitude;
	betha = y / magnitude;
	gama = z / magnitude;
}

Vector3D Vector::sum(Vector3D& v1, Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return Vector3D(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
}

float Vector::s_product(Vector3D& v1, Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
}