#pragma once
#include "cMesh.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

class cScene
{
private:
	// Store the number of objects in the scene
	size_t numberOfObjectsOnScene = 0;
public:
	// Get the objects and their amount and set up the scene
	cScene(cMesh*, size_t*);

	// Functions responsible for saving scene data
	void saveTransformPosition(std::ofstream &sceneSaver, float * pos, float * rot, float * sca);
	void saveVertices(std::ofstream &sceneSaver, cMesh * mesh);
	void saveTextureCoordinates(std::ofstream &sceneSaver, cMesh * mesh);
	void saveFaces(std::ofstream &sceneSaver, cMesh * mesh);
	void saveEdges(std::ofstream &sceneSaver, cMesh * mesh);

	~cScene();
};

