#include <iostream>

#include "../Vector/Vector.h"

int main()
{
	// Just testing part(will be deleted later)

	Vector::Vector3D vector1(1, 2, 3);
	Vector::Vector3D vector2(4, 5, 6);

	std::cout << (vector1 == vector2) << std::endl << (vector1 == vector1) << std::endl;
	
	vector1.cross(vector2);
	Vector::Coords3D coords = vector1.GetCoords();
	std::cout << "Coords:\nX: " << coords.x << " Y: " << coords.y << " Z: " << coords.z << std::endl;
}