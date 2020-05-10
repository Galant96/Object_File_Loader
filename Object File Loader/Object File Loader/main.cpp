#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


#include "cTransform.h"
#include "cMesh.h"
#include "cScene.h"

#define TRANSFORM_COORDINATES_NUMBER 3

int readIntValue(int minValue, int maxValue, string text);
float readNumber(string text);
void proceesOperation(int userChoice);
void displayObjectsMenu();
void chooseMeshToLoad(int userChoice);
void loadObjectFile(string *filesNamesData, cMesh *mesh);

// Store the names of files to read
vector <string> objectFilesNames(0);
// Store the number of objects
size_t numberOfObjects = 0;

using namespace std;

int main(void)
{
	// Store user choice
	int userChoice = 0;

	// Display the menu of the program in the console windows
	do
	{
		cout << "\n" << "************************************************" << "\n" << "************************************************" << endl;
		cout << "Welcome in file loader menu!" << endl;
		cout << "MENU:" << endl;
		cout << "1. Enter the number of objects you want to render." << endl;
		cout << "2. Exit the application." << endl;

		// Get user input
		userChoice = readIntValue(1, 2, "");
		// Proceed wuth a choosen operation
		proceesOperation(userChoice);

	} while (userChoice != 2);

	return 0;
}

// The function reads the user input and checks that it is a number
float readNumber(string text)
{
	float value = 0;
	string input = "";
	stringstream stream{};

	cout << text;
	getline(cin, input);
	// Empty the contents
	stream.str(input); 
	// Empty the bits flags
	stream.clear();

	while ((stream >> value && stream.eof()) == false)
	{
		cout << text;
		stream.clear();
		getline(cin, input);
		stream.str(input);
	}

	// Convert a string into a integer value
	stream >> value; 

	return value;
}

// Reading integer values
// Passing min and max value allows for setting the function
int readIntValue(int minValue, int maxValue, string text)
{
	float userChoice = 0;

	// Avoiding confusion when a user enters decimal values
	do
	{
		userChoice = readNumber(text);

		// Checking that the chosen value is not a decimal number
	} while ((userChoice - int(userChoice) > 0) || (userChoice < minValue || userChoice > maxValue));

	// Casting float into int
	int userIntChoice = static_cast <int> (userChoice);

	return userIntChoice;
}


// Proceed the menu options
void proceesOperation(int userChoice)
{

	switch (userChoice)
	{
		// Load objects files and save their features
		case 1:
		{
			// Display the availiable objects to read
			displayObjectsMenu();

			// Set the pointer to the very first element of the vector
			string *fileName = NULL;
			fileName = &objectFilesNames.at(0);

			// Initialise mesh objects
			cMesh *mesh = NULL;
			mesh = new cMesh[numberOfObjects];

			// Load and procced with each mesh object
			for (size_t i = 0; i < numberOfObjects; i++)
			{
				loadObjectFile(fileName, &mesh[i]);
				// Go to the next element of the vector
				fileName++;
			}

			// Initialise a scene and pass the mesh objects
			cScene *scene = NULL;
     		scene = new cScene(mesh, &numberOfObjects);

			// Release the memory
			delete[] mesh;
			delete scene;
			break;
		}
		// Exit the application
		case 2:	
			cout << endl;
			cout << "Exitting the application...";
			exit(0);
			break;
		default:
			cout << "Error: Invalid input!" << endl;
			exit(0);
	}
}

// Load and proceed with an object file
void loadObjectFile(string *filesNamesData, cMesh* mesh)
{
	// Set and store a name of the object
	mesh->setName(filesNamesData);
	string name = mesh->getName();

	// Set transform position for the object
	mesh->setTransformPos(&name);

	// Load the object's file
	ifstream objectFileLoader(*filesNamesData);

	// Exit the program if there is not a file to prevent errors
	if (objectFileLoader.good() == false)
	{
		cout << "\nThe file does not exist!" << endl;
		exit(0);
	}

	// Save the important data of the object and save it into text file
	// This file helps to check if the objects from the scene have the same attributes
	ofstream saver("object.txt", ios::trunc);

	// Write the name of the original file to the text file
	saver << "\n******************************\n" << name << "\n******************************\n";

	// Proceed with the file
	while (!objectFileLoader.eof())
	{
		// Initialise a buffer for storing the data
		string buffer = "";
		getline(objectFileLoader, buffer);

		// Split string around spaces
		istringstream iss(buffer);
		string firstWord;
		iss >> firstWord;

		// Variable for storing float values from the file
		float value;

		// Recognise values and pass them to relevant variables
		if (firstWord == "v") // Store verticles
		{
			while (iss >> value)
			{
				// Push the value to the vector and add one element
				mesh->setVertex(1, &value);
			}

			saver << buffer << "\n";

		}
		else if (firstWord == "vt") // Store texture coordinates
		{
			while (iss >> value)
			{
				// Push the value to the vector and add one element
				mesh->setTextureCoordinates(1, &value);
			}

			saver << buffer << "\n";

		}
		else if (firstWord == "f") // Store faces
		{
			// Faces are more tricky to read by the program

			// Initialise variables for manipulating face data
			string word = "";
			char searchChar = '/';
			char replacement = ' ';
			size_t length = 0;

			// Intialising a new string for storing a modified "word" variable
			string newState = "";

			// Proceed with word string
			while (iss >> word)
			{
				// Get the length of a string
				length = word.length();

				// Check and replace the '/' character with the ' '
				for (size_t i = 0; i < length; i++)
				{
					if (word[i] == searchChar)
					{
						word[i] = replacement;
					}

					// Add checked word's element to the new string
					newState += word[i];
				}

				newState += '\n';

			}

			// Reset word variable
			word = "";

			// Split string around spaces for newState
			istringstream newIss(newState);

			// Get just a numbers without special characters like '/'
			while (newIss >> word)
			{
				// Push the value to the vector and add one element
				int number = stoi(word);
				mesh->setFace(1, &number);
			}

			saver << buffer << "\n";
		}
		else
		{
			continue;
		}

	}

	// Close unused files
	objectFileLoader.close();
	saver.close();
}

void displayObjectsMenu()
{
	// Get the number of objects to load from user
	numberOfObjects = static_cast <int> (readNumber("Number of objects to render: "));

	cout << "Choose the object to load:" << endl;
	for (size_t i = 0; i < numberOfObjects; i++)
	{
		cout << "Choose " << i + 1 << " mesh to render: ";
		cout << endl;
		cout << "1. cube.obj" << endl;
		cout << "2. sphere.obj" << endl;
		cout << "3. cone.obj" << endl;
		cout << "4. cylinder.obj" << endl;
		cout << "5. doughnut.obj" << endl;

		// Pick a particular mesh to render
		chooseMeshToLoad(readIntValue(1, 5, """"));
	}
}

// Choose mesh to get the final objects to the scene
void chooseMeshToLoad(int userChoice)
{
	string fileName = "";

	switch (userChoice)
	{

	case 1:
		{
			fileName = "cube.obj";
			objectFilesNames.push_back(fileName);

			break;
		}
		case 2:
		{
			fileName = "sphere.obj";
			objectFilesNames.push_back(fileName);
			break;
		}
		case 3:
		{
			fileName = "cone.obj";
			objectFilesNames.push_back(fileName);
			break;
		}
		case 4:
		{
			fileName = "cylinder.obj";
			objectFilesNames.push_back(fileName);
			break;
		}
		case 5:
		{
			fileName = "doughnut.obj";
			objectFilesNames.push_back(fileName);
			break;
		}
		default:
			cout << "Error: Invalid input!" << endl;
			exit(0);
	}

}
