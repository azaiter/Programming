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
// ASSIGNMENT NUMBER: #4
//
// DUE DATE: 09-24-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
//      a program that reads records of name, id, sex and exams data from an input file and 
//      it calculates the average of exams data. and writes data on output file.
//
//*******************************************************************
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
//defining streams and opening files
ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

//file checks
if (inFile.fail() || outFile.fail())
{
outFile << "Check your input and/or output file !!" << endl;
return 1;
}

//setting numbers after decimal point to 2
outFile.setf(ios::fixed);
outFile.precision(2);

//declaring identifiers
int studentId;
float examFirst, examSecond, examThird, examAvg;
string studentName;
char studentSex;

//inputing data from file
inFile >> studentId >> studentName >> studentSex >> examFirst >> examSecond >> examThird;

//calculating average
examAvg = (examFirst + examSecond + examThird)/3;

//outputting data to file
outFile << "~*< Exam AVG Report >*~" << endl << endl;
outFile << "Name: " << studentName << "     Id: " << studentId << "  Sex: " << studentSex << endl << endl;
outFile << "Exam1 = " << examFirst << endl;
outFile << "Exam2 = " << examSecond << endl;
outFile << "Exam3 = " << examThird << endl << endl;
outFile << "AVG of Three Exams= " << examAvg  << endl << endl;
outFile << "~ end ~ " << endl;

//closing input and output files
inFile.close();
outFile.close();

return 0;
}
