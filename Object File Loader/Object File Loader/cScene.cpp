#include "cScene.h"

using namespace std;

cScene::cScene(cMesh *mesh, size_t *numberOfObjects)
{
	// Delete the content of the old scene text file and save the current scene objects in text file
	ofstream sceneSaver("scene_objects.txt", ios::out | ios::trunc | ios::in);

	// Get the number of the objects in the scene
	numberOfObjectsOnScene = *numberOfObjects;

	// Proceed with each object
	for (size_t i = 0; i < numberOfObjectsOnScene; i++)
	{
		// Save the name of the current object
		sceneSaver << "\n******************************\n" << mesh->getName()
			<< "\n******************************\n";

		// The variables for temporarily storing current position,
		// Rotation and scale of the object
		float *pos = NULL;
		float *rot = NULL;
		float *sca = NULL;

		pos = new float[TRANSFORM_COORDINATES_NUMBER];
		rot = new float[TRANSFORM_COORDINATES_NUMBER];
		sca = new float[TRANSFORM_COORDINATES_NUMBER];

		// Get the object's position
		for (int j = 0; j < TRANSFORM_COORDINATES_NUMBER; j++)
		{
			pos[j] = mesh->getPos(j);
			rot[j] = mesh->getRot(j);
			sca[j] = mesh->getSca(j);
		}

		saveTransformPosition(sceneSaver, pos, rot, sca);

		// Save the vertices data
		saveVertices(sceneSaver, mesh);

		// Save texture coordinates data
		saveTextureCoordinates(sceneSaver, mesh);

		// Save faces data
		saveFaces(sceneSaver, mesh);

		// Save edges data
		saveEdges(sceneSaver, mesh);

		mesh++;
	}

	sceneSaver.close();
}

void cScene::saveTransformPosition(std::ofstream &sceneSaver, float * pos, float * rot, float * sca)
{
	sceneSaver << "\t\t\tTransform Position\n";
	sceneSaver << "\t\tX\t\tY\t\tZ \n";

	// Save the object's position, rotation and scale
	sceneSaver << "Position: ";
	for (int j = 0; j < TRANSFORM_COORDINATES_NUMBER; j++)
	{
		sceneSaver << "\t" << fixed << setprecision(2) << pos[j] << "\t";
	}

	// Clear memory
	delete[] pos;

	sceneSaver << "\n";

	sceneSaver << "Rotation: ";
	for (int j = 0; j < TRANSFORM_COORDINATES_NUMBER; j++)
	{
		sceneSaver << "\t" << fixed << setprecision(2) << rot[j] << "\t";
	}

	// Clear memory
	delete[] rot;

	sceneSaver << "\n";

	sceneSaver << "Scale:   ";
	for (int j = 0; j < TRANSFORM_COORDINATES_NUMBER; j++)
	{
		sceneSaver << "\t" << fixed << setprecision(2) << sca[j] << "\t";
	}

	// Clear memory
	delete[] sca;
}

void cScene::saveVertices(std::ofstream &sceneSaver, cMesh * mesh)
{
	sceneSaver << "\n\n";

	sceneSaver << "******************************" << " Vertices " << "******************************\n\n";

	sceneSaver << "Number of vertices: " << mesh->getVerticesElements() / VERTEX_COORDINATES_NUMBER << "\n\n";

	sceneSaver << "(v):";

	for (int j = 0; j < (mesh->getVerticesElements()); j++)
	{
		float vertex = mesh->getVertex(j);

		if (j % 3 == 0 && j != 0)
		{
			sceneSaver << "\n";
			sceneSaver << "(v):";
		}

		sceneSaver << "  " << fixed << setprecision(6) << vertex << "  ";

	}
}

void cScene::saveTextureCoordinates(std::ofstream &sceneSaver, cMesh * mesh)
{
	sceneSaver << "\n\n";

	sceneSaver << "******************************" << " Texture Coordinates " << "******************************\n\n";

	sceneSaver << "Number of texture coordinates: " << mesh->getTextureCoordinatesElements() / TEXTURE_COORDINATES_NUMBER << "\n\n";

	sceneSaver << "(vt):";

	for (int j = 0; j < (mesh->getTextureCoordinatesElements()); j++)
	{

		float txtCoordinates = mesh->getTxtCoords(j);

		if (j % 2 == 0 && j != 0)
		{
			sceneSaver << "\n";
			sceneSaver << "(vt):";
		}

		sceneSaver << "  " << fixed << setprecision(6) << txtCoordinates << "  ";

	}
}

void cScene::saveFaces(std::ofstream &sceneSaver, cMesh * mesh)
{
	sceneSaver << "\n\n";

	sceneSaver << "******************************" << " Faces " << "******************************\n\n";

	sceneSaver << "Number of faces: " << mesh->getFacesElements() / FACE_COORDINATES_NUMBER << "\n\n";

	sceneSaver << "(f):";

	for (int j = 0; j < (mesh->getFacesElements()); j++)
	{
		int faceNumb = mesh->getFace(j);

		if (j % 3 == 0)
		{
			if (j % 12 == 0 && j != 0)
			{
				sceneSaver << "\n";
				sceneSaver << "(f):";
			}

			sceneSaver << " ";
		}

		sceneSaver << faceNumb << "/";
	}
}

void cScene::saveEdges(std::ofstream &sceneSaver, cMesh * mesh)
{
	sceneSaver << "\n\n";

	// Save the edges

	sceneSaver << "******************************" << " Edges " << "******************************\n\n";

	sceneSaver << "Number of edges: " << mesh->getEdges() << "\n\n";
}

cScene::~cScene()
{
}
