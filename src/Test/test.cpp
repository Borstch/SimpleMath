#include <iostream>

#include "../Vector/Vector.h"

int main()
{
	// Just testing part(will be deleted later)

	Vector::Vector3D vector1(1, 2, 3);
	Vector::Vector3D vector2(4, 5, 6);

	std::cout << "X: " << vector1.on_X() << " Y: " << vector1.on_Y() << " Z: " << vector1.on_Z() << std::endl;
}