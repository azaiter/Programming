// prog8.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #8
//
// DUE DATE: 10-29-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//  a program that reads records of name, id, and exams data from an input file and
//  it calculates the average of exams data, determining if they pass or not. and writes
//  data on a well aligned output file using functions.
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

bool filesCheck(ofstream& outFile, ifstream& inFile);
//*********************************************
// Purpose: Checks if either input or output files exists.
//
// Input: none.
//
// Pre: Declaration of both input and output streams before calling this function.
//
// Output: bool.
//
// Post: return true if files are loaded successfully, false if not.
//
// Note: none.
//*********************************************

void setPrecision(ofstream& outFile, int data);
//*********************************************
// Purpose: Changes quantity of numbers after decimal point.
//
// Input: data.
//
// Pre: outFile is opened & ok, data has valid value.
//
// Output: outFile.
//
// Post: Changes the quantity of numbers after decimal point to the given data in call.
//
// Note: none.
//*********************************************

void printHeading(ofstream& outFile);
//*********************************************
// Purpose: Print heading for output file.
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: Heading is printed in outFile.
//
// Note: none.
//*********************************************

void readRd(ifstream& inFile, string& studName, int& studId, float& exam1, float& exam2, float& exam3);
//*********************************************
// Purpose: Reads exams data from input file.
//
// Input: inFile.
//
// Pre: inFile is opened & ok. studName, studId, exam1, exam2, exam3 have values.
//
// Output: studName, studId, exam1, exam2, exam3.
//
// Post: studName, studId, exam1, exam2, exam3 are stored to their variables via inFile.
//
// Note: none.
//*********************************************

bool validData(int studId, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Checks if exam and student id are valid.
//
// Input: studId, exam1, exam2, exam3.
//
// Pre: studId, exam1, exam2, exam3 have values.
//
// Output: bool.
//
// Post: Returns True if data are valid, false is not.
//
// Note: none.
//*********************************************

void printRd(ofstream& outFile, string studName, int studId, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Print intial row of student and exams data.
//
// Input: studName, studId, exam1, exam2, exam3.
//
// Pre: outFile is opened & ok. studName, studId, exam1, exam2, exam3 have values.
//
// Output: outFile.
//
// Post: Student name, id, exam 1, exam 2, exam3 are printed in outFile.
//
// Note: none.
//*********************************************

float avg(float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Calculates avg of 3 exams.
//
// Input: exam1, exam2, exam3.
//
// Pre: exam1, exam2, exam3 are valid and have data.
//
// Output: float.
//
// Post: The avg of 3 exams is returned.
//
// Note: none.
//*********************************************

void printAvgPassedOrFailed(ofstream& outFile, float examAvg);
//*********************************************
// Purpose: Prints student Fail or Pass data.
//
// Input: examAvg.
//
// Pre: outFile is opened & ok. examAvg is valid and have data.
//
// Output: outFile.
//
// Post: PASSED is printed if student has passing score, otherwise FAILED if has a failing score.
//
// Note: none.
//*********************************************

float meanOfAvg(float examAvgSum ,int examCount);
//*********************************************
// Purpose: Calculates the mean of avg of the given exam average sum and exams count.
//
// Input: examAvgSum ,examCount.
//
// Pre: examAvgSum , examCount are valid and have data, examCount is greater than zero.
//
// Output: float.
//
// Post: The mean of avg is returned.
//
// Note: none.
//*********************************************

void printMeanOfAvg(ofstream& outFile, float avgMean);
//*********************************************
// Purpose: Prints mean of the avg line.
//
// Input: avgMean.
//
// Pre: outFile is opened & ok. avgMean is valid and have data and examCount is greater than zero.
//
// Output: outFile.
//
// Post: Mean of the avg line is printed in outFile.
//
// Note: none.
//*********************************************

void printInvalidDataMsg(ofstream& outFile);
//*********************************************
// Purpose: Prints invalid data line.
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: "~~ Invalid data~~" line is printed in outFile.
//
// Note: none.
//*********************************************

void printNoValidMeanMsg(ofstream& outFile); **HERE
//*********************************************
// Purpose: Prints invalid mean of avg line .
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: Invalid mean of avg line is printed in outFile.
//
// Note: none.
//*********************************************

int main()
{
  //defining streams and opening files
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");

  //file checks
  if (!filesCheck(outFile, inFile))
    return 1;

  //setting numbers after decimal point to 2
  setPrecision(outFile, 2);

  //declaring variables
  int studId;
  int examCount = 0;
  float exam1,exam2,exam3,examAvg,avgMean;
  float examAvgSum = 0.00;
  string studName;

  //outputting intial aligned heading
  printHeading(outFile);

  //inputing data from file and do the loop
  readRd(inFile, studName, studId, exam1, exam2, exam3);
  while (inFile)
  {
    //print intial data
    printRd(outFile, studName, studId, exam1, exam2, exam3);
    //this if statment well determine the validity of student id, and exams.
    //if not, it will show invalid data error
    if(validData(studId, exam1, exam2, exam3))
    {
      //calcualting the average
      examAvg = avg(exam1, exam2, exam3);
      //adding it to count
      examCount = examCount + 1;
      //adding to sum
      examAvgSum = examAvgSum + examAvg;
      //outputting Passed Failed data
      printAvgPassedOrFailed(outFile, examAvg);
    }
    else
      printInvalidDataMsg(outFile);

    //re-reading the input data
    readRd(inFile, studName, studId, exam1, exam2, exam3);
  }

  if (examCount > 0)
  {
    avgMean = meanOfAvg(examAvgSum ,examCount);
    printMeanOfAvg(outFile, avgMean);
  }
  else
    printNoValidMeanMsg(outFile);

  outFile << endl << "*< end >*" << endl;

  //closing input and output files
  inFile.close();
  outFile.close();

  return 0;
}


bool filesCheck(ofstream& outFile, ifstream& inFile)
//*********************************************
// Purpose: Checks if either input or output files exists.
//
// Input: none.
//
// Pre: Declaration of both input and output streams before calling this function.
//
// Output: bool.
//
// Post: return true if files are loaded successfully, false if not.
//
// Note: none.
//*********************************************

{
  if (inFile.fail() || outFile.fail())
  {
    cout << "Check your input and/or output file !!" << endl;
    return 0;
  }
  else
    return 1;
}

void setPrecision(ofstream& outFile, int data)
//*********************************************
// Purpose: Changes quantity of numbers after decimal point.
//
// Input: data.
//
// Pre: outFile is opened & ok, data has valid value.
//
// Output: outFile.
//
// Post: Changes the quantity of numbers after decimal point to the given data in call.
//
// Note: none.
//*********************************************

{
  outFile.setf(ios::fixed);
  outFile.precision(data);
}

void printHeading(ofstream& outFile)
//*********************************************
// Purpose: Print heading for output file.
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: Heading is printed in outFile.
//
// Note: none.
//*********************************************

{
  outFile << "*~~< Stud Exam Report >~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Passed/Failed" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-------------" << endl;
}

void readRd(ifstream& inFile, string& studName, int& studId, float& exam1, float& exam2, float& exam3)
//*********************************************
// Purpose: Reads exams data from input file.
//
// Input: inFile.
//
// Pre: inFile is opened & ok. studName, studId, exam1, exam2, exam3 have values.
//
// Output: studName, studId, exam1, exam2, exam3.
//
// Post: studName, studId, exam1, exam2, exam3 are stored to their variables via inFile.
//
// Note: none.
//*********************************************

{
  inFile >> studName >> studId >> exam1 >> exam2 >> exam3;
}

bool validData(int studId, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Checks if exam and student id are valid.
//
// Input: studId, exam1, exam2, exam3.
//
// Pre: studId, exam1, exam2, exam3 have values.
//
// Output: bool.
//
// Post: Returns True if data are valid, false is not.
//
// Note: none.
//*********************************************

{
  if((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX) &&
     (exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX))
    return 1;
  else
    return 0;
}

void printRd(ofstream& outFile, string studName, int studId, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Print intial row of student and exams data.
//
// Input: studName, studId, exam1, exam2, exam3.
//
// Pre: outFile is opened & ok. studName, studId, exam1, exam2, exam3 have values.
//
// Output: outFile.
//
// Post: Student name, id, exam 1, exam 2, exam3 are printed in outFile.
//
// Note: none.
//*********************************************

{
  outFile << left << setw(20) <<  studName << setw(10) << studId << setw(10)
          << exam1 << setw(10) << exam2 << setw(15) << exam3  << setw(15);
}

float avg(float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Calculates avg of 3 exams.
//
// Input: exam1, exam2, exam3.
//
// Pre: exam1, exam2, exam3 are valid and have data.
//
// Output: float.
//
// Post: The avg of 3 exams is returned.
//
// Note: none.
//*********************************************

{
  return ((exam1+exam2+exam3)/3);
}

void printAvgPassedOrFailed(ofstream& outFile, float examAvg)
//*********************************************
// Purpose: Prints student Fail or Pass data.
//
// Input: examAvg.
//
// Pre: outFile is opened & ok. examAvg is valid and have data.
//
// Output: outFile.
//
// Post: PASSED is printed if student has passing score, otherwise FAILED if has a failing score.
//
// Note: none.
//*********************************************

{
  if (examAvg >= PASS_SCORE)
    outFile << examAvg << "PASSED" << endl;
  else
    outFile << examAvg << "FAILED" << endl;
}

float meanOfAvg(float examAvgSum ,int examCount)
//*********************************************
//*********************************************
// Purpose: Calculates the mean of avg of the given exam average sum and exams count.
//
// Input: examAvgSum ,examCount.
//
// Pre: examAvgSum , examCount are valid and have data, examCount is greater than zero.
//
// Output: float.
//
// Post: The mean of avg is returned.
//
// Note: none.
//*********************************************

{
  return(examAvgSum / examCount);
}

void printMeanOfAvg(ofstream& outFile, float avgMean)
//*********************************************
// Purpose: Prints mean of the avg line.
//
// Input: avgMean.
//
// Pre: outFile is opened & ok. avgMean is valid and have data and examCount is greater than zero.
//
// Output: outFile.
//
// Post: Mean of the avg line is printed in outFile.
//
// Note: none.
//*********************************************

{
  outFile << endl << "Mean of AVG = " << avgMean << endl << endl;
}

void printInvalidDataMsg(ofstream& outFile)
//*********************************************
// Purpose: Prints invalid data line.
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: "~~ Invalid data~~" line is printed in outFile.
//
// Note: none.
//*********************************************

{
  outFile << "~~ Invalid data~~" << endl;
}

void printNoValidMeanMsg(ofstream& outFile)
//*********************************************
// Purpose: Prints invalid mean of avg line .
//
// Input: none.
//
// Pre: outFile is opened & ok.
//
// Output: outFile.
//
// Post: Invalid mean of avg line is printed in outFile.
//
// Note: none.
//*********************************************

{
  outFile << endl << "There is no valid data to calculate the Mean of the AVG for it !" << endl << endl;
}