#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const float NUM_MAX = 100.00;
const float NUM_MIN = 0.00;


int main()
{
	//defining streams and opening files
	ofstream outFile;
	ifstream inFile;
	outFile.open("out.data");
	inFile.open("in.data");

	//file checks
	if (inFile.fail() || outFile.fail())
	{
		outFile << "Check your input and/or output file !!" << endl;
		return 1;
	}

	//setting numbers after decimal point to 2
	outFile.setf(ios::fixed);
	outFile.precision(2);

	//declaring variables
	int numOne,numTwo;
	float numAvg;
	
		//inputing data from file
    inFile >> numOne >> numTwo;
	

	//outputting intial aligned output
	outFile << "<* Numberrs Report *>" << endl << endl;
	outFile << "Num1: " << numOne << endl << "Num2: " << numTwo << endl << endl;



	//this if statment well determine the validity of student id, and exams.
	//if not, it will show invalid data error
	if((numOne >= NUM_MIN && numOne <= NUM_MAX) && (numTwo >= NUM_MIN && numTwo <= NUM_MAX))
    {
		//calcualting the average
		numAvg = (numOne+numTwo)/2;

		if (numOne == numTwo)
			outFile << "~~~ Two Numbers are Equal !" << endl << "MAX = MIN = AVG = " << numOne << endl;
		else if (numOne >= numTwo)
			outFile << "MIN: " << numTwo << endl << "MAX: " << numOne << endl << "AVG: " << numAvg << endl << endl;
		else
			outFile << "MIN: " << numOne << endl << "MAX: " << numTwo << endl << "AVG: " << numAvg << endl << endl;

	}
	else
		outFile << "~~~ Invalid Numbers." << endl << endl;


	outFile << "*< end >*" << endl;

	//closing input and output files
	inFile.close();
	outFile.close();

    return 0;
}


