#include <iostream>

#include "Vector.h"

int main()
{
	Vector::Vector3D vector1(1, 2, 3);
	Vector::Vector3D vector2(4, 5, 6);
	Vector::Vector3D vector3 = Vector::sum(vector1, vector2);

	std::cout << "Scalar Product: " << Vector::s_product(vector1, vector2) << std::endl;
	Vector::Coords3D c = vector1.GetCoords();
	std::cout << "Coords of v1: " << c.x << " " << c.y << " " << c.z << std::endl;
	vector1.normalize();
	c = vector1.GetCoords();
	std::cout << "After normalization: " << c.x << " " << c.y << " " << c.z << std::endl;
	std::cout << vector1.magnitude << std::endl;
}