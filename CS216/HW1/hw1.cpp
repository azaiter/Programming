// hw1.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW1 // DUE DATE: 1-27-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//  a program in C++ to compute the volume of an 3-dimensional box.
//*******************************************************************

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

//*****************************************
//************ Class Definition ***********
//*****************************************

class Box
{
	public:
		Box();
		//*********************************************
		// Purpose: Initializes private data to default values.
		// Input: None.
		// Pre: None.
		// Output: none.
		// Post: Private data initialized to default values.
		// Note: none.
		//*********************************************
		void readFile(ifstream& inFile);
		//*********************************************
		// Purpose: Initializes private data to default values.
		// Input: inFile.
		// Pre: inFile is opened & ok.
		// Output: none.
		// Post: Box dimensions data is stored.
		// Note: none.
		//*********************************************
		float computeVolume();
		//*********************************************
		// Purpose: Calculate the volume of the box and returns it.
		// Input: none.
		// Pre: private variables have valid values.
		// Output: none.
		// Post: The volume of the box is returned.
		// Note: none.
		//*********************************************
	private:
		float height, width, length;
};

//*****************************************
//********* Class Implementation **********
//*****************************************

Box::Box()
//*********************************************
// Purpose: Initializes private data to default values.
// Input: None.
// Pre: None.
// Output: none.
// Post: Private data initialized to default values.
// Note: none.
//*********************************************
{
	height = -1;
	width = -2;
	length = -3;
}

void Box::readFile(ifstream& inFile)
//*********************************************
// Purpose: Initializes private data to default values.
// Input: inFile.
// Pre: inFile is opened & ok.
// Output: none.
// Post: Box dimensions data is stored.
// Note: none.
//*********************************************
{
	inFile >> height >> width >> length;
}

float Box::computeVolume()
//*********************************************
// Purpose: Calculate the volume of the box and returns it.
// Input: none.
// Pre: private variables have valid values.
// Output: none.
// Post: The volume of the box is returned.
// Note: none.
//*********************************************
{
	return (height*width*length);
}

//*****************************************
//************ Client Code ****************
//*****************************************

bool filesCheck(ifstream& inFile);
//*********************************************
// Purpose: Checks if either input file exists.
// Input: inFile.
// Pre: Declaration input stream before calling this function.
// Output: bool.
// Post: return true if file is loaded successfully, false if not.
// Note: none.
//*********************************************


int main()
{
	//defining streams and opening files
	ifstream inFile;
	inFile.open("in.txt");
	
	//file checks
	if (!filesCheck(inFile))
		return 1;//endif
	
	//declaring box object.
	Box boxObject;
	
	//intialize data from file
	boxObject.readFile(inFile);
	
	//loop that does the output on file.
	int rdCounter = 0;
	while(inFile)
	{
		rdCounter = rdCounter + 1;
		cout << "Box " << rdCounter << " Volume: " <<  boxObject.computeVolume() << endl;
		boxObject.readFile(inFile);
	}//end while
	
	//closing input file
	getch();
	inFile.close();
	//indicate successful execution.
	return 0;
}

bool filesCheck(ifstream& inFile)
//*********************************************
// Purpose: Checks if either input file exists.
// Input: inFile.
// Pre: Declaration input stream before calling this function.
// Output: bool.
// Post: return true if file is loaded successfully, false if not.
// Note: none.
//*********************************************

{
	if (inFile.fail())
	{
		cout << "Check your input file !!" << endl;
		getch();
		return 0;
	}
	else
		return 1;//end if
}//end function