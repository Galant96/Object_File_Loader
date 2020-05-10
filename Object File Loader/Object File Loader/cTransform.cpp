#include "cTransform.h"

cTransform::cTransform()
{
	// Set the original transform position
	for (int i = 0; i < TRANSFORM_COORDINATES_NUMBER; i++)
	{
		position[i] = 0;
		rotation[i] = 0;
		scale[i] = 0;
	}
}

// Get position of the object
float cTransform::getPos(int counter)
{
	return position[counter];
}

// Get rotation of the object
float cTransform::getRot(int counter)
{
	return rotation[counter];
}

// Get scale of the object
float cTransform::getSca(int counter)
{
	return scale[counter];
}

// Set a given position for the object
void cTransform::setTransformPos(string *name)
{
	// Variables for temporary storing of new coordinates
	float pos[TRANSFORM_COORDINATES_NUMBER] = { 0 };
	float rot[TRANSFORM_COORDINATES_NUMBER] = { 0 };
	float sca[TRANSFORM_COORDINATES_NUMBER] = { 0 };

	// Ask user to provide new coordinates
	cout << "Set the transform position for the " << *name << endl;
	cout << "TRANSFORM" << endl;
	cout << "Position x: ";
	cin >> position[0];
	cout << "Position y: ";
	cin >> position[1];
	cout << "Position z: ";
	cin >> position[2];

	cout << endl;
	cout << "Rotation x: ";
	cin >> rotation[0];
	cout << "Rotation y: ";
	cin >> rotation[1];
	cout << "Rotation z: ";
	cin >> rotation[2];

	cout << endl;
	cout << "Scale x: ";
	cin >> scale[0];
	cout << "Scale y: ";
	cin >> scale[1];
	cout << "Scale z: ";
	cin >> scale[2];

}


cTransform::~cTransform()
{
}
