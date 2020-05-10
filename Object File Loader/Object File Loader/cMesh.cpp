#include "cMesh.h"

// Set the original object's name
cMesh::cMesh()
{
	objectName = getName();
}

// Functions for operation on vertices
void cMesh::setVertex(int counter, float *ver)
{
	// Add value to the vector at given position
	vertices.push_back(*ver);

	numbOfVerticesCoordinates += counter;
}
float cMesh::getVertex(int counter)
{
	return vertices.at(counter);
}
int cMesh::getVerticesElements()
{
	return(numbOfVerticesCoordinates);
}

// Functions for operation on texture coordinates
void cMesh::setTextureCoordinates(int counter, float *txtC)
{
	// Add value to the vector at given position
	textureCoordinates.push_back(*txtC);

	numbOfTextureCoordinates += counter;
}
float cMesh::getTxtCoords(int counter)
{
	return textureCoordinates.at(counter);
}
int cMesh::getTextureCoordinatesElements()
{
	return (numbOfTextureCoordinates);
}

// Functions for operation on faces
void cMesh::setFace(int counter, int *f)
{
	// Add value to the vector at given position
	faces.push_back(*f);

	numbOfFacesCoordinates += counter;
}
int cMesh::getFace(int counter)
{
	return faces.at(counter);
}
int cMesh::getFacesElements()
{
	return (numbOfFacesCoordinates);
}

// Get the number of edges
int cMesh::getEdges()
{
	// Temporary store the number of vertices and faces
	int ver = getVerticesElements()/VERTEX_COORDINATES_NUMBER;
	int fac = getFacesElements()/FACE_COORDINATES_NUMBER;

	// Euler's polyhedron formula for finding the number of edges
	int numberOfEdges = ver + fac - 2;

	return numberOfEdges;
}

// Set the given name to the object
void cMesh::setName(string *name)
{
	objectName = *name;
}

string cMesh::getName()
{
	return objectName;
}


cMesh::~cMesh()
{
}



