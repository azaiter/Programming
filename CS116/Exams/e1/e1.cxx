#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int EXAM_MAX = 100;
const int EXAM_MIN = 0;
const int PASS_SCORE = 70;
const int ID_MAX = 999;
const int ID_MIN = 111;

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

	//declaring variables
	int studId;
	int exam;

	//outputting intial aligned output
	outFile << "<* Exam Report *>" << endl;

	//inputing data from file
    inFile >> studId >> exam;

	//printint intialized input data
	outFile << left << setw(6) << studId << setw(6) << exam << setw(6);

	if((exam >= EXAM_MIN && exam <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX))
    {
		if (exam >= 70)
			outFile << "PASSED";
		else
			outFile << "FAILED";
	}
	else
	{
		if (!(exam >= EXAM_MIN && exam <= EXAM_MAX) && !(studId >= ID_MIN && studId <= ID_MAX))
			outFile << "Invalid Id & Exam";
		else if (!(exam >= EXAM_MIN && exam <= EXAM_MAX))
			outFile << "Invalid Exam";
		else if (!(studId >= ID_MIN && studId <= ID_MAX))
			outFile << "Invalid Id";
	}


	outFile << endl << endl << "<* end *>" << endl;

	//closing input and output files
	inFile.close();
	outFile.close();

    return 0;
}
