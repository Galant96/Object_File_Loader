# Object_File_Loader
 
 
# CONSOLE APPLICATION : Object File Loader Project

Programming Language: C++

IDE: Microsoft Visual Studio Community 2017 v15.9.18

This project is responsible for retrieving data from 3D files and loading the given assets into a scene.
The data for a single .obj file is saved to object.txt file, which is created to store all loaded objects. 
Therefore the results can be compared to the final scene objects.
However, the objects aggregated into the scene are saved to scene_objects.txt file.


# HOW TO USE THE PROGRAM

1. The application is opend in the console window and it displays the main menu.
2. User may input 1 to provide a number of objects to load or 2 to exit the application.
3. If input was 1 then user provides a number of objects to load.
4. The objects menu is displayed and user must choose an object to load. 
   For demonstration purpose some .obj files are already contained in the main folder of the project and user may choose between them.
5. User sets a transform position for a particular object.
6. All provided objects are loaded into the scene and saved to scene_objects.txt file.
7. To get the results of the program operations, the user must find scene_objects.txt file in the main folder of the application.


# CLASSES AND THEIR FUNCTIONS

main.cpp

This is the main project source file. It proceeds with the application, displays the menu to users,
loads objects and obtains the most important data form them and pass them to the scene.

float readNumber(string text) - The function reads the user input and checks that it is a number.
int readIntValue(int minValue, int maxValue, string text) - Read integer values. The passed min and max values allow to set up the function.
void proceesOperation(int userChoice) - Proceed with the menu options.
void displayObjectsMenu() - Display the object's menu and get an object to load.
void loadObjectFile(string *filesNamesData, cMesh* mesh) - Load the passed file and set its mesh object.
void chooseMeshToRender(int userChoice) - Choose mesh to get the final objects to the scene.

=====================================================================
cTransform.h
cTransform.cpp

This is the class for keeping a transform position of the object in a Cartesian coordinate system.

float cTransform::getPos(int counter)
float cTransform::getRot(int counter)
float cTransform::getSca(int counter)
 - return a particular atrribute of a transform position.

void cTransform::setTransformPos(string *name) - Set a given position for the object.

=====================================================================

cMesh.h
cMesh.cpp

This class is a blueprint for a mesh object. It inherits features from cTransform.

void cMesh::setName(string *name) - Set the name for a mesh.
string cMesh::getName() - Get the name of the mesh.

void cMesh::setVertex(int counter, float *ver)
void cMesh::setTextureCoordinates(int counter, float *txtC)
void cMesh::setFace(int counter, int *f)
- Set required values for a 3D object.

float cMesh::getVertex(int counter)
float cMesh::getTxtCoords(int counter)
int cMesh::getFace(int counter)
int cMesh::getEdges()
- Get required values for a 3D object.

int cMesh::getVerticesElements()
int cMesh::getTextureCoordinatesElements()
int cMesh::getFacesElements()
int cMesh::getEdges()
- Get the number of elments which makes of vertices, texture coordinates, faces or edges.

=====================================================================

cScene.h
cScene.cpp

This is the class for aggregating all loaded meshes into one scene and saving the results.

void cScene::saveTransformPosition(std::ofstream &sceneSaver, float * pos, float * rot, float * sca)
void cScene::saveVertices(std::ofstream &sceneSaver, cMesh * mesh)
void cScene::saveTextureCoordinates(std::ofstream &sceneSaver, cMesh * mesh)
void cScene::saveFaces(std::ofstream &sceneSaver, cMesh * mesh)
void cScene::saveEdges(std::ofstream &sceneSaver, cMesh * mesh)
- Functions which save the given meshes data loaded by the scene.
