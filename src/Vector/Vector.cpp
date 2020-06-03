#include <iostream>
#include <string>
#include <cmath>

#include "Vector.h"

using namespace Vector;

Vector2D::Vector2D()
	: x(0), y(0)
{
	std::cout << "Created 0 0!\n";
	ComputeParams();
}

Vector2D::Vector2D(const Vector2D& other)
	: x(other.x), y(other.y), m_Magnitude(other.m_Magnitude),
	m_Alpha(other.m_Alpha), m_Betha(other.m_Betha)
{
	std::cout << "Copied " << x << " " << y << "!\n";
}

Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{
	std::cout << "Created " << x << " " << y << "!\n";
	ComputeParams();
}

Vector2D::Vector2D(float all)
	: x(all), y(all)
{
	std::cout << "Created " << x << " " << y << "!\n";
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
	return *this; // modifies current vector
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
	if ((x == 0) && (y == 0))
	{
		m_Magnitude = 0;
		m_Alpha = 0;
		m_Betha = 0;
	}
	else
	{
		m_Magnitude = sqrt(x * x + y * y);
		m_Alpha = x / m_Magnitude;
		m_Betha = y / m_Magnitude;
	}
}

void Vector2D::normalize()
{
	SetCoords(x / m_Magnitude, y / m_Magnitude);
	ComputeParams();
}

void Vector2D::scale(float scaler)
{
	x *= scaler;
	y *= scaler;
}

Vector3D::Vector3D()
	: x(0), y(0), z(0)
{
	std::cout << "Created 0 0 0 !\n";
	ComputeParams();
}

Vector3D::Vector3D(const Vector3D& other)
	: x(other.x), y(other.y), z(other.z), m_Magnitude(other.m_Magnitude),
	m_Alpha(other.m_Alpha), m_Betha(other.m_Betha), m_Gama(other.m_Gama)
{
	std::cout << "Copied " << x << " " << y << " " << z << "!\n";
}

Vector3D::Vector3D(float x, float y, float z)
	: x(x), y(y), z(z)
{
	std::cout << "Created " << x << " " << y << " " << z << "!\n";
	ComputeParams();
}

Vector3D::Vector3D(float all)
	: x(all), y(all), z(all)
{
	std::cout << "Created " << x << " " << y << " " << z << "!\n";
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
	float new_x = y * coords.z - z * coords.y; // formula for cross product
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
	SetCoords(x / m_Magnitude, y / m_Magnitude, z / m_Magnitude);
	ComputeParams();
}

void Vector3D::scale(float scaler)
{
	x *= scaler;
	y *= scaler;
	z *= scaler;
}

void Vector3D::ComputeParams()
{
	if ((x == 0) && (y == 0) & (z == 0))
	{
		m_Magnitude = 0;
		m_Alpha = 0;
		m_Betha = 0;
		m_Gama = 0;
	}
	else
	{
		m_Magnitude = sqrt(x * x + y * y + z * z);
		m_Alpha = x / m_Magnitude;
		m_Betha = y / m_Magnitude;
		m_Gama = z / m_Magnitude;
	}
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

bool Vector::operator ==(const Vector2D& v1, const Vector2D& v2)
{
	Coords2D c1 = v1.GetCoords();
	Coords2D c2 = v2.GetCoords();
	return (c1.x == c2.x) && (c1.y == c2.y);
}

bool Vector::operator ==(const Vector3D& v1, const Vector3D& v2)
{
	Coords3D c1 = v1.GetCoords();
	Coords3D c2 = v2.GetCoords();
	return (c1.x == c2.x) && (c1.y == c2.y) && (c1.z == c2.z);
}