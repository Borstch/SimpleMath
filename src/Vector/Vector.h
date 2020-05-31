#pragma once

namespace Vector
{
	struct Coords2D
	{
		float x;
		float y;
	};

	struct Coords3D
	{
		float x;
		float y;
		float z;
	};

	class Vector2D
	{
	public:
		float m_Magnitude, m_Alpha, m_Betha;

		Vector2D(float x, float y);
		~Vector2D();
		Vector2D add(const Vector2D& v);
		Vector2D sub(const Vector2D& v);
		Coords2D GetCoords() const;
		float dot(const Vector2D& v);
		void SetCoords(float new_x, float new_y);
		void normalize();
		void scale(float scaler);
	private:
		float x, y;

		void ComputeParams();
	};

	class Vector3D
	{
	public:
		float m_Magnitude, m_Alpha, m_Betha, m_Gama;

		Vector3D(float x, float y, float z);
		~Vector3D();
		Vector3D add(const Vector3D& v);
		Vector3D sub(const Vector3D& v);
		Vector3D cross(const Vector3D& v);
		Coords3D GetCoords() const;
		float dot(const Vector3D& v);
		void SetCoords(float new_x, float new_y, float new_z);
		void normalize();
		void scale(float scaler);
	private:
		float x, y, z;

		void ComputeParams();
	};
	Vector2D operator -(const Vector2D& vector);
	Vector2D operator +(const Vector2D& v1, const Vector2D& v2);
	Vector2D operator -(const Vector2D& v1, const Vector2D& v2);
	Vector2D operator *(float scaler, const Vector2D& vector);
	Vector3D operator -(const Vector3D& vector);
	Vector3D operator +(const Vector3D& v1, const Vector3D& v2);
	Vector3D operator -(const Vector3D& v1, const Vector3D& v2);
	Vector3D operator *(float scaler, const Vector3D& vector);
	Vector3D cross(const Vector3D& v1, const Vector3D& v2);
	float operator *(const Vector2D& v1, const Vector2D& v2);
	float operator *(const Vector3D& v1, const Vector3D& v2);
}