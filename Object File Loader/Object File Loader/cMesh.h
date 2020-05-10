#pragma once
#include "cTransform.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define VERTEX_COORDINATES_NUMBER 3 // Store how many numbers is stored by vertex
#define TEXTURE_COORDINATES_NUMBER 2 // Store how many numbers is stored by texture coordinates
#define FACE_COORDINATES_NUMBER 12 // Store how many numbers is stored by face

using namespace std;

// cMesh class inherits from cTransform class
class cMesh : public cTransform
{
private:
	// Variables for storing values for vertices, texture coordinates and faces
	vector <float> vertices = { 0 };
	vector <float> textureCoordinates = { 0 };
	vector <int> faces = { 0 };

	// Variables for storing number of every singular passed value for vertices, texture coordinates, edges and faces
	int numbOfVerticesCoordinates = 0;
	int numbOfFacesCoordinates = 0;
	int numbOfTextureCoordinates = 0;
	int numbOfEdges = 0;

public:
	// Store the object's name
	string objectName = "";

	//The constructor sets the default name for the object 
	cMesh();
	~cMesh();

	// Set a vertex value and add it to the vector
	// Count the number of added elements
	void setVertex(int = 0, float * = NULL);

	// Return required vertex
	float getVertex(int counter);

	// Return the number of elements from the vector
	int getVerticesElements();


	// Set a texture coordinates value and add them to the texture coordinates
	// Count the number of added elements
	void setTextureCoordinates(int = 0, float * = NULL);

	// Return required texture coordinates
	float getTxtCoords(int counter);
	// Return the number of elements from the vector
	int getTextureCoordinatesElements();

	// Set a face value and add it to the faces
	// Count the number of added elements
	void setFace(int = 0, int * = NULL);
	// Return required face
	int getFace(int counter);
	// Return the number of elements from the vector
	int getFacesElements();

	// Calculate and return the number of edges
	int getEdges();

	// Set name for the object
	void setName(string* = NULL);

	// Get the name of the object
	string getName();

};


