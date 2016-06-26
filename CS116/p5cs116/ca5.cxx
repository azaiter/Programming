// prog4.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #5
//
// DUE DATE: 10-05-2015
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
	float exam1,exam2,exam3,examAvg;
	string studName,passingString;
	
	//outputting intial aligned output
	outFile << "*~~< Stud Exam Report >~~*" << endl << endl;
	outFile << "Name" << setw(30) << "Stud Id" << setw(10) << "Exam1" <<  setw(10) << "Exam2"
	<<  setw(10) << "Exam3" <<  setw(10) << "AVG" <<  setw(20) << "Passed/Failed" << endl;
	outFile << "----" << setw(30) << "-------" << setw(10) << "-----" << setw(10) << "-----"  << setw(10)
	<< "-----"  << setw(10) << "---"  << setw(20) << "-----------" << endl;

	//inputing data from file
    inFile >> studName >> studId >> exam1 >> exam2 >> exam3;
	
	//this if statment well determine the validity of student id, and exams. 
	//if not, it will show invalid data error
if((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX)	&&
 (exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX))
    {
		//calcualting the average
		examAvg = (exam1+exam2+exam3)/3;
	
		//detenmining the output string that depends on studend's grade
		if (examAvg >= 97.00)
			passingString = "PASSED / TOP";
		else if (examAvg >= 70.00)
			passingString = "PASSED";
		else
			passingString = "FAILED";
       
		//outputting main data
		outFile << studName << setw(30) << studId << setw(10) << exam1 << setw(10) << exam2  
		<< setw(10) << exam3  << setw(10) << examAvg  << setw(20) << passingString << endl << endl;

     }
     else
		outFile << setw(50) << "~~ Invalid data~~" << endl << endl;

     outFile << endl << "*< end >*" << endl;

	
    return 0;
}
