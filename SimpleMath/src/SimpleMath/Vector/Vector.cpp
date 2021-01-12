#include "Simplepch.h"
#include "SimpleMath/Core/Log.h"
#include "Vector.h"

namespace SimpleMath
{
	namespace Linalg
	{
		namespace Vector
		{

			Vector2D::Vector2D()
				: x(0), y(0)
			{
				SM_CORE_TRACE("Vector created: 0 0");
				computeParams(true);
			}

			Vector2D::Vector2D(const Vector2D& other)
				: x(other.x), y(other.y), m_Magnitude(other.m_Magnitude),
				m_Alpha(other.m_Alpha), m_Betha(other.m_Betha)
			{
				SM_CORE_TRACE("Vector copied: {0} {1}", x, y);
			}

			Vector2D::Vector2D(float x, float y)
				: x(x), y(y)
			{
				SM_CORE_TRACE("Vector created: {0} {1}", x, y);
				computeParams(true);
			}

			Vector2D::Vector2D(float all)
				: x(all), y(all)
			{
				SM_CORE_TRACE("Vector created: {0} {1}", x, y);
				computeParams(true);
			}

			Vector2D::~Vector2D()
			{
				SM_CORE_TRACE("Vector destroyed: {0} {1}", x, y);
			}

			Vector2D* Vector2D::add(const Vector2D& v)
			{
				Coords2D coords = v.getCoords();
				x += coords.x;
				y += coords.y;
				computeParams();
				return this; // modifies current vector
			}

			Vector2D* Vector2D::sub(const Vector2D& v)
			{
				Coords2D coords = v.getCoords();
				x -= coords.x;
				y -= coords.y;
				computeParams();
				return this;
			}

			Coords2D Vector2D::getCoords() const
			{
				return { x, y };
			}

			float Vector2D::getX() const
			{
				return x;
			}

			float Vector2D::getY() const
			{
				return y;
			}

			float Vector2D::dot(const Vector2D& v)
			{
				Coords2D coords = v.getCoords();
				return x * coords.x + y * coords.y;
			}

			bool Vector2D::is_point() const
			{
				return !m_Magnitude;
			}

			bool Vector2D::is_collinear_with(const Vector2D& vector) const
			{
				if (this->is_point() || vector.is_point())
					return true;
				return (x / vector.x) == (y / vector.y);
			}

			void Vector2D::setCoords(float new_x, float new_y)
			{
				x = new_x;
				y = new_y;
				computeParams();
			}

			void Vector2D::computeParams(bool first)
			{
				if (!first)
					SM_CORE_INFO("Vector updated: {0} {1}", x, y);
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
				setCoords(x / m_Magnitude, y / m_Magnitude);
				computeParams();
			}

			void Vector2D::scale(float scaler)
			{
				x *= scaler;
				y *= scaler;
				computeParams();
			}

			void Vector2D::print() const
			{
				std::cout << "Coords: " << x << " " << y << "\nMagnitude: " << m_Magnitude <<
					"\nCos Alpha: " << m_Alpha << " " << "Cos Betha: " << m_Betha << std::endl;
			}

			Vector2D Vector::add(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return Vector2D(c1.x + c2.x, c1.y + c2.y);
			}

			Vector2D Vector::sub(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return Vector2D(c1.x - c2.x, c1.y - c2.y);
			}

			float Vector::dot(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return c1.x * c2.x + c1.y * c2.y;
			}

			bool Vector::is_collinear(const Vector2D& v1, const Vector2D& v2)
			{
				if (v1.is_point() || v2.is_point())
					return true;
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return (c1.x / c2.x) == (c1.y / c2.y);
			}

			Vector3D::Vector3D()
				: x(0), y(0), z(0)
			{
				SM_CORE_TRACE("Vector created: 0 0 0");
				computeParams(true);
			}

			Vector3D::Vector3D(const Vector3D& other)
				: x(other.x), y(other.y), z(other.z), m_Magnitude(other.m_Magnitude),
				m_Alpha(other.m_Alpha), m_Betha(other.m_Betha), m_Gama(other.m_Gama)
			{
				SM_CORE_TRACE("Vector copied: {0} {1} {2}", x, y, z);
			}

			Vector3D::Vector3D(float x, float y, float z)
				: x(x), y(y), z(z)
			{
				SM_CORE_TRACE("Vector created: {0} {1} {2}", x, y, z);
				computeParams(true);
			}

			Vector3D::Vector3D(float all)
				: x(all), y(all), z(all)
			{
				SM_CORE_TRACE("Vector created: {0} {1} {2}", x, y, z);
				computeParams(true);
			}

			Vector3D::~Vector3D()
			{
				SM_CORE_TRACE("Vector destroyed: {0} {1} {2}", x, y, z);
			}

			Vector3D* Vector3D::add(const Vector3D& v)
			{
				Coords3D coords = v.getCoords();
				x += coords.x;
				y += coords.y;
				z += coords.z;
				computeParams();
				return this;
			}

			Vector3D* Vector3D::sub(const Vector3D& v)
			{
				Coords3D coords = v.getCoords();
				x -= coords.x;
				y -= coords.y;
				z -= coords.z;
				computeParams();
				return this;
			}

			Vector3D* Vector3D::cross(const Vector3D& v)
			{
				Coords3D coords = v.getCoords();
				float new_x = y * coords.z - z * coords.y; // formula for cross product
				float new_y = z * coords.x - x * coords.z;
				float new_z = x * coords.y - coords.x * y;
				x = new_x;
				y = new_y;
				z = new_z;
				computeParams();
				return this;
			}

			Coords3D Vector3D::getCoords() const
			{
				return { x, y, z };
			}

			float Vector3D::getX() const
			{
				return x;
			}

			float Vector3D::getY() const
			{
				return y;
			}

			float Vector3D::getZ() const
			{
				return z;
			}

			float Vector3D::dot(const Vector3D& v)
			{
				Coords3D coords = v.getCoords();
				return x * coords.x + y * coords.y + z * coords.z;
			}

			bool Vector3D::is_point() const
			{
				return !m_Magnitude; // if magnitude is not zero then vector isn't a point
			}

			bool Vector3D::is_collinear_with(const Vector3D& vector) const
			{
				return Vector::cross(*this, vector) == 0;
			}

			void Vector3D::setCoords(float new_x, float new_y, float new_z)
			{
				x = new_x;
				y = new_y;
				z = new_z;
				computeParams();
			}

			void Vector::Vector3D::normalize()
			{
				setCoords(x / m_Magnitude, y / m_Magnitude, z / m_Magnitude);
				computeParams();
			}

			void Vector3D::scale(float scaler)
			{
				x *= scaler;
				y *= scaler;
				z *= scaler;
				computeParams();
			}

			void Vector3D::computeParams(bool first)
			{
				if (!first)
					SM_CORE_INFO("Vector updated: {0} {1} {2}", x, y, z);
				if ((x == 0) && (y == 0) && (z == 0))
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

			void Vector3D::print() const
			{
				std::cout << "Coords: " << x << " " << y << " " << z << "\nMagnitude: " <<
					m_Magnitude << "\nCos Alpha: " << m_Alpha << " " << " Cos Betha: " <<
					m_Betha << " Cos Gama: " << m_Gama << std::endl;
			}

			Vector3D Vector::cross(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				float x = c1.y * c2.z - c1.z * c2.y;
				float y = c1.z * c2.x - c1.x * c2.z;
				float z = c1.x * c2.y - c2.x * c1.y;
				return Vector3D(x, y, z);
			}

			Vector3D Vector::add(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return Vector3D(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
			}

			Vector3D Vector::sub(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return Vector3D(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
			}

			float Vector::dot(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
			}

			bool Vector::is_collinear(const Vector3D& v1, const Vector3D& v2)
			{
				return cross(v1, v2) == 0;
			}

			Vector2D Vector::operator-(const Vector2D& vector)
			{
				Coords2D coords = vector.getCoords();
				return Vector2D(-coords.x, -coords.y);
			}

			Vector2D Vector::operator+(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return Vector2D(c1.x + c2.x, c1.y + c2.y);
			}

			Vector2D Vector::operator -(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return Vector2D(c1.x - c2.x, c1.y - c2.y);
			}

			Vector2D Vector::operator *(float scaler, const Vector2D& vector)
			{
				Coords2D coords = vector.getCoords();
				return Vector2D(scaler * coords.x, scaler * coords.y);
			}

			Vector3D Vector::operator-(const Vector3D& vector)
			{
				Coords3D coords = vector.getCoords();
				return Vector3D(-coords.x, -coords.y, -coords.z);
			}

			Vector3D Vector::operator +(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return Vector3D(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
			}

			Vector3D Vector::operator -(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return Vector3D(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
			}

			Vector3D Vector::operator *(float scaler, const Vector3D& vector)
			{
				Coords3D coords = vector.getCoords();
				return Vector3D(scaler * coords.x, scaler * coords.y, scaler * coords.z);
			}

			float Vector::operator *(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return c1.x * c2.x + c1.y * c2.y;
			}

			float Vector::operator *(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
			}

			bool Vector::operator ==(const Vector2D& v1, const Vector2D& v2)
			{
				Coords2D c1 = v1.getCoords();
				Coords2D c2 = v2.getCoords();
				return (c1.x == c2.x) && (c1.y == c2.y);
			}

			bool Vector::operator ==(const Vector3D& v1, const Vector3D& v2)
			{
				Coords3D c1 = v1.getCoords();
				Coords3D c2 = v2.getCoords();
				return (c1.x == c2.x) && (c1.y == c2.y) && (c1.z == c2.z);
			}

		}
	}
}