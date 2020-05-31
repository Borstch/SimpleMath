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

Vector2D Vector2D::add(const Vector2D& v)
{
	Coords2D coords = v.GetCoords();
	x += coords.x;
	y += coords.y;
	return *this;
}

Vector2D Vector2D::sub(const Vector2D& v)
{
	Coords2D coords = v.GetCoords();
	x -= coords.x;
	y -= coords.y;
	return *this;
}

Coords2D Vector2D::GetCoords() const
{
	return { x, y };
}

float Vector2D::dot(const Vector2D& v)
{
	Coords2D coords = v.GetCoords();
	return x * coords.x + y * coords.y;
}

void Vector2D::SetCoords(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
	ComputeParams();
}

void Vector2D::ComputeParams()
{
	m_Magnitude = sqrt(x * x + y * y);
	m_Alpha = x / m_Magnitude;
	m_Betha = y / m_Magnitude;
}

void Vector2D::normalize()
{
	this->SetCoords(x / m_Magnitude, y / m_Magnitude);
	this->ComputeParams();
}

void Vector2D::scale(float scaler)
{
	x *= scaler;
	y *= scaler;
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

Vector3D Vector3D::add(const Vector3D& v)
{
	Coords3D coords = v.GetCoords();
	x += coords.x;
	y += coords.y;
	z += coords.z;
	return *this;
}

Vector3D Vector3D::sub(const Vector3D& v)
{
	Coords3D coords = v.GetCoords();
	x -= coords.x;
	y -= coords.y;
	z -= coords.z;
	return *this;
}

Vector3D Vector3D::cross(const Vector3D& v)
{
	Coords3D coords = v.GetCoords();
	float new_x = y * coords.z - z * coords.y;
	float new_y = z * coords.x - x * coords.z;
	float new_z = x * coords.y - coords.x * y;
	x = new_x;
	y = new_y;
	z = new_z;
	return *this;
}

Coords3D Vector3D::GetCoords() const
{
	return { x, y, z };
}

float Vector3D::dot(const Vector3D& v)
{
	Coords3D coords = v.GetCoords();
	return x * coords.x + y * coords.y + z * coords.z;
}

void Vector3D::SetCoords(float new_x, float new_y, float new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

void Vector::Vector3D::normalize()
{
	this->SetCoords(x / m_Magnitude, y / m_Magnitude, z / m_Magnitude);
	this->ComputeParams();
}

void Vector3D::scale(float scaler)
{
	x *= scaler;
	y *= scaler;
	z *= scaler;
}

void Vector3D::ComputeParams()
{
	m_Magnitude = sqrt(x * x + y * y + z * z);
	m_Alpha = x / m_Magnitude;
	m_Betha = y / m_Magnitude;
	m_Gama = z / m_Magnitude;
}

Vector2D Vector::operator-(const Vector2D& vector)
{
	Coords2D coords = vector.GetCoords();
	return Vector2D(-coords.x, -coords.y);
}

Vector2D Vector::operator+(const Vector2D& v1, const Vector2D& v2)
{
	Coords2D c1 = v1.GetCoords();
	Coords2D c2 = v2.GetCoords();
	return Vector2D(c1.x + c2.x, c1.y + c2.y);
}

Vector2D Vector::operator -(const Vector2D& v1, const Vector2D& v2)
{
	Coords2D c1 = v1.GetCoords();
	Coords2D c2 = v2.GetCoords();
	return Vector2D(c1.x - c2.x, c1.y - c2.y);
}

Vector2D Vector::operator *(float scaler, const Vector2D& vector)
{
	Coords2D coords = vector.GetCoords();
	return Vector2D(scaler * coords.x, scaler * coords.y);
}

Vector3D Vector::operator-(const Vector3D& vector)
{
	Coords3D coords = vector.GetCoords();
	return Vector3D(-coords.x, -coords.y, -coords.z);
}

Vector3D Vector::operator +(const Vector3D& v1, const Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return Vector3D(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
}

Vector3D Vector::operator -(const Vector3D& v1, const Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return Vector3D(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
}

Vector3D Vector::operator *(float scaler, const Vector3D& vector)
{
	Coords3D coords = vector.GetCoords();
	return Vector3D(scaler * coords.x, scaler * coords.y, scaler * coords.z);
}

Vector3D Vector::cross(const Vector3D& v1, const Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	float x = c1.y * c2.z - c1.z * c2.y;
	float y = c1.z * c2.x - c1.x * c2.z;
	float z = c1.x * c2.y - c2.x * c1.y;
	return Vector3D(x, y, z);
}

float Vector::operator *(const Vector2D& v1, const Vector2D& v2)
{
	Coords2D c1 = v1.GetCoords();
	Coords2D c2 = v2.GetCoords();
	return c1.x * c2.x + c1.y * c2.y;
}

float Vector::operator *(const Vector3D& v1, const Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
}