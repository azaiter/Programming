// prog6.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #6
//
// DUE DATE: 10-15-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
//      a program that reads records of name, id, and exams data from an input file and 
//      it calculates the average of exams data, determining if they pass or not. and writes data on a well aligned output file.
//
//*******************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const float EXAM_MAX = 100.00;
const float EXAM_MIN = 0.00;
const int ID_MAX = 9999;
const int ID_MIN = 1111;
const float PASS_SCORE = 70.00;

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
	int studId;
	int examCount = 0;
	float exam1,exam2,exam3,examAvg,avgMean;
	float examAvgSum = 0.00;
	string studName,passingString;

	//outputting intial aligned output
	outFile << "*~~< Stud Exam Report >~~*" << endl;
	outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
					<< setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Passed/Failed" << endl;
	outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "------" << setw(10) << "------"
					<< setw(15) << "------"  << setw(15) << "------------"  << "-------------" << endl;

	//inputing data from file
    inFile >> studName >> studId >> exam1 >> exam2 >> exam3;

	//doing the main loop till the end of the file
	while (inFile)
	{

		//this if statment well determine the validity of student id, and exams.
		//if not, it will show invalid data error
		if((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX)	&&
			(exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX))
		{
			//calcualting the average
			examAvg = (exam1+exam2+exam3)/3;
			//adding it to count
			examCount = examCount + 1;
			//adding to sum
			examAvgSum = examAvgSum + examAvg;
			//detenmining the output string that depends on studend's grade
			if (examAvg >= PASS_SCORE)
				passingString = "PASSED";
			else
				passingString = "FAILED";

			//outputting main data
			outFile << left << setw(20) <<  studName << setw(10) << studId << setw(10) << exam1 << setw(10) << exam2
					<< setw(15) << exam3  << setw(15) << examAvg  << passingString << endl;

		}
		else
			outFile << left << setw(20) << studName << setw(10) << studId << setw(10) << exam1 << setw(10) << exam2 <<
			setw(15) << exam3 << setw(15)  << "~~ Invalid data~~" << endl;

		//re-reading the input data
		inFile >> studName >> studId >> exam1 >> exam2 >> exam3;

	}

	if (examCount > 0)
	{
		avgMean = examAvgSum / examCount;
		outFile << endl << "Mean of AVG = " << avgMean << endl << endl;
	}
	else
		outFile << endl << "There is no valid data to calculate the Mean of the AVG for it !" << endl << endl;

	outFile << endl << "*< end >*" << endl;

	//closing input and output files
	inFile.close();
	outFile.close();

    return 0;
}


