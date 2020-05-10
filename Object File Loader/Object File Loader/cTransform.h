#pragma once
#include <iostream>
#include <string>

#define TRANSFORM_COORDINATES_NUMBER 3 // Define the number of transform coordinates
using namespace std;

class cTransform
{
private:

	// Variables for storing position, rotation and scale of the object
	float position[TRANSFORM_COORDINATES_NUMBER] = { 0, 0, 0 };
	float rotation[TRANSFORM_COORDINATES_NUMBER] = { 0, 0, 0 };
	float scale[TRANSFORM_COORDINATES_NUMBER] = { 0, 0, 0 };
	
public:
	// Constructor sets the original transform position to (0, 0, 0)
	cTransform();

	// Get a required coordinates
	float getPos(int);
	float getRot(int);
	float getSca(int);

	// Set transform position for the object
	void setTransformPos(string *);

	~cTransform();

};

