#pragma once

namespace SimpleMath
{

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

		public:
			Vector2D();
			Vector2D(const Vector2D& other);
			Vector2D(float x, float y);
			Vector2D(float all);
			~Vector2D();

		public:
			Vector2D* add(const Vector2D& v);
			Vector2D* sub(const Vector2D& v);
			Coords2D getCoords() const;
			float getX() const;
			float getY() const;
			float dot(const Vector2D& v);
			bool is_point() const;
			bool is_collinear_with(const Vector2D& vector) const;
			void setCoords(float new_x, float new_y);
			void normalize();
			void scale(float scaler);
			void print() const;
		private:
			float x, y;

		private:
			void computeParams(bool first = false);
		};

		Vector2D add(const Vector2D& v1, const Vector2D& v2);
		Vector2D sub(const Vector2D& v1, const Vector2D& v2);
		float dot(const Vector2D& v1, const Vector2D& v2);
		float angle_between(const Vector2D& v1, const Vector2D& v2, const char* mode = "rad");
		bool is_collinear(const Vector2D& v1, const Vector2D& v2);

		class Vector3D
		{
		public:
			float m_Magnitude, m_Alpha, m_Betha, m_Gama;

		public:
			Vector3D();
			Vector3D(const Vector3D& other);
			Vector3D(float x, float y, float z);
			Vector3D(float all);
			~Vector3D();

		public:
			Vector3D* add(const Vector3D& v);
			Vector3D* sub(const Vector3D& v);
			Vector3D* cross(const Vector3D& v);
			Coords3D getCoords() const;
			float getX() const;
			float getY() const;
			float getZ() const;
			float dot(const Vector3D& v);
			bool is_point() const;
			bool is_collinear_with(const Vector3D& vector) const;
			void setCoords(float new_x, float new_y, float new_z);
			void normalize();
			void scale(float scaler);
			void print() const;
		private:
			float x, y, z;

		private:
			void computeParams(bool first = false);
		};
		Vector3D cross(const Vector3D& v1, const Vector3D& v2);
		Vector3D add(const Vector3D& v1, const Vector3D& v2);
		Vector3D sub(const Vector3D& v1, const Vector3D& v2);
		float dot(const Vector3D& v1, const Vector3D& v2);
		float angle_between(const Vector3D& v1, const Vector3D& v2, const char* mode = "rad");
		bool is_collinear(const Vector3D& v1, const Vector3D& v2);

		Vector2D operator -(const Vector2D& vector);
		Vector2D operator +(const Vector2D& v1, const Vector2D& v2);
		Vector2D operator -(const Vector2D& v1, const Vector2D& v2);
		Vector2D operator *(float scaler, const Vector2D& vector);
		Vector3D operator -(const Vector3D& vector);
		Vector3D operator +(const Vector3D& v1, const Vector3D& v2);
		Vector3D operator -(const Vector3D& v1, const Vector3D& v2);
		Vector3D operator *(float scaler, const Vector3D& vector);
		float operator *(const Vector2D& v1, const Vector2D& v2);
		float operator *(const Vector3D& v1, const Vector3D& v2);
		bool operator ==(const Vector2D& v1, const Vector2D& v2);
		bool operator ==(const Vector3D& v1, const Vector3D& v2);

	}

}