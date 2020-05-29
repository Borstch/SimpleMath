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
		float magnitude, alpha, betha;

		Vector2D(float x, float y);
		~Vector2D();
		Coords2D GetCoords();
		void SetCoords(float new_x, float new_y);
		void normalize();
	private:
		float x, y;

		void ComputeParams();
	};

	class Vector3D
	{
	public:
		float magnitude, alpha, betha, gama;

		Vector3D(float x, float y, float z);
		~Vector3D();
		Coords3D GetCoords();
		void SetCoords(float new_x, float new_y, float new_z);
		void normalize();
	private:
		float x, y, z;

		void ComputeParams();
	};

	Vector2D sum(Vector2D& vector1, Vector2D& vector2);
	Vector2D dot_product(Vector2D& v1, Vector2D& v2);
	float s_product(Vector2D& v1, Vector2D& v2);
	Vector3D sum(Vector3D& v1, Vector3D& v2);
	Vector3D dot_product(Vector3D& v1, Vector3D& v2);
	float s_product(Vector3D& v1, Vector3D& v2);
}