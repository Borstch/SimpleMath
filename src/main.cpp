#include <iostream>

#include "Vector/Vector.h"

int main()
{
	Vector::Vector3D vector1(1, 2, 3);
	Vector::Vector3D vector2(4, 5, 6);
	
	Vector::Coords3D coords = vector1.cross(vector2).GetCoords();
	std::cout << "Cross product:\nX: " << coords.x << " Y: " << coords.y << " Z: " << coords.z << std::endl;
}