// prog10.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #10
//
// DUE DATE: 11-12-2015
//
// POSSIBLE POINTS: 40 Points
//
// PURPOSE:
//  a program that reads records of name, id, male or female and exams data from an input file and
//  it calculates the average of exams data, determining if they pass or not, calculates the percentage
//  of male and females, and the destrubution of students, top exam performance and writes
//  data on a well aligned output file using functions.
//*******************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const float EXAM_MAX = 100.00;
const float EXAM_MIN = 0.00;
const int ID_MAX = 9999;
const int ID_MIN = 1111;
const int EXCELLENT_MAX = 100;
const int EXCELLENT_MIN = 90;
const int GOOD_MAX = 89;
const int GOOD_MIN = 80;
const int OK_MAX = 79;
const int OK_MIN = 70;
const int WEAK_MAX = 69;
const int WEAK_MIN = 60;
const int FAILING_MAX = 59;
const int FAILING_MIN = 0;

enum Grades{EXCELLENT, GOOD, OK, WEAK, FAILING};

bool filesCheck(ofstream& outFile, ifstream& inFile);
//*********************************************
// Purpose: Checks if either input or output files exists.
// Input: inFile, outFile.
// Pre: Declaration of both input and output streams before calling this function.
// Output: bool.
// Post: return true if files are loaded successfully, false if not.
// Note: none.
//*********************************************

void setPrecision(ofstream& outFile, int data);
//*********************************************
// Purpose: Changes quantity of numbers after decimal point.
// Input: data.
// Pre: outFile is opened & ok, data has valid value.
// Output: outFile.
// Post: Changes the quantity of numbers after decimal point to the given data in call.
// Note: none.
//*********************************************

void printHeading(ofstream& outFile);
//*********************************************
// Purpose: Print heading for output file.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile.
// Note: none.
//*********************************************

void readRd(ifstream& inFile, string& studName, int& studId, char& sex, float& exam1, float& exam2, float& exam3);
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: studName, studId, exam1, exam2, exam3.
// Post: studName, studId, sex, exam1, exam2, exam3 are stored to their variables via inFile.
// Note: none.
//*********************************************

bool validData(int studId, char sex, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Checks if exam and student id are valid.
// Input: studId, sex, exam1, exam2, exam3.
// Pre: studId, sex, exam1, exam2, exam3 have values.
// Output: bool.
// Post: Returns True if data are valid, false is not.
// Note: none.
//*********************************************

void printRd(ofstream& outFile, string studName, int studId, char sex, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studName, studId, sex, exam1, exam2, exam3.
// Pre: outFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3 are printed in outFile.
// Note: none.
//*********************************************

int avg(float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Calculates avg of 3 exams converted to the next integer.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2, exam3 are valid and have data.
// Output: int.
// Post: The avg of 3 exams converted to the next integer is returned.
// Note: none.
//*********************************************

void printAvgAndGrade(ofstream& outFile, int examAvg, Grades studGrade);
//*********************************************
// Purpose: Prints student avg and grade data.
// Input: examAvg, studGrade.
// Pre: outFile is opened & ok. examAvg, studGrade are valid and have data, datatype Grades is valid.
// Output: outFile.
// Post: Avg and grade are printed to outFile.
// Note: none.
//*********************************************

Grades grade(int examAvg);
//*********************************************
// Purpose: Returns the exams avg to Grades datatype.
// Input: examAvg.
// Pre: examAvg is valid and have data, datatype Grades is valid.
// Output: Grades.
// Post: Returns enum value of Grades that matches exams Avg.
// Note: none.
//*********************************************

void printInvalidDataMsg(ofstream& outFile);
//*********************************************
// Purpose: Prints invalid data line.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: "~~ Invalid data ~~" line is printed in outFile.
// Note: none.
//*********************************************

void countGrades(Grades studGrade, int& cntExcellent, int& cntGood, int& cntOk, int& cntWeak, int& cntFailing);
//*********************************************
// Purpose: Depending on the input, grade count is increased by one.
// Input: studGrade.
// Pre: studGrade has value and valid grade, cntcntExcellent, cntGood, cntOk,
//      cntWeak, cntFailing has valid values. datatype Grades is valid
// Output: cntExcellent, cntGood, cntOk, cntWeak, cntFailing.
// Post: Count of one of the grades cnt variables is ancreased by one, depending on the input.
// Note: none.
//*********************************************

void printBarChart(ofstream& outFile, int studCnt, int cntExcellent, int cntGood, int cntOk, int cntWeak, int cntFailing);
//*********************************************
// Purpose: Prints Grade Destitution Bar Chart.
// Input: studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing.
// Pre: outFile is opened & ok. studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing have values.
// Output: outFile.
// Post: grade performance bar chart is printed to outFile.
// Note: none.
//*********************************************

void printNoValidData(ofstream& outFile);
//*********************************************
// Purpose: Prints an error message if there is no valid exam records.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: the meaning of "no valid student data, no bar chart and mean of all avg printed" is printed to outFile.
// Note: none.
//*********************************************

void printMeanOfAllAvg(ofstream& outFile, int examAvgSum, int studCnt);
//*********************************************
// Purpose: Prints the mean of all avg's.
// Input: examAvgSum, studCnt.
// Pre: outFile is opened & ok, examAvgSum, studCnt have values.
// Output: outFile.
// Post: the mean of all exams AVG's is printed to outFile.
// Note: none.
//*********************************************

void printValidInvalidPerc(ofstream& outFile, int invalidCnt, int studCnt);
//*********************************************
// Purpose: Prints valid and invalid records percentage.
// Input: invalidCnt, studCnt.
// Pre: outFile is opened & ok, invalidCnt, studCnt have values.
// Output: outFile.
// Post: the percentage of valid and invalid records are printed in outFile.
// Note: none.
//*********************************************

int main()
{
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");

  if (!filesCheck(outFile, inFile))
    return 1;//endif

  //setting numbers after decimal point to 2
  setPrecision(outFile, 2);

  //declaring variables
  int studId,invalidCnt,examAvgSum;
  int studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing, examAvg;
  studCnt = cntExcellent = cntGood = cntOk = cntWeak = cntFailing = examAvgSum = invalidCnt = 0;
  float exam1,exam2,exam3;
  string studName;
  char sex;

  //outputting intial aligned heading
  printHeading(outFile);

  //inputing data from file and do the loop
  readRd(inFile, studName, studId, sex, exam1, exam2, exam3);
  
  while (inFile)
  {
    Grades studGrade;
    //print intial data
    printRd(outFile, studName, studId, sex, exam1, exam2, exam3);
    //this if statment well determine the validity of student id, sex, and exams.
    //if not, it will show invalid data error
    if(validData(studId, sex, exam1, exam2, exam3))
    {
      //calcualting the average
      examAvg = avg(exam1, exam2, exam3);
      studCnt++;
      studGrade = grade(examAvg);
      countGrades(studGrade, cntExcellent, cntGood, cntOk, cntWeak, cntFailing);
      examAvgSum = examAvgSum + examAvg;
      //outputting Passed Failed data
      printAvgAndGrade(outFile, examAvg, studGrade);
    }
    else
    {
      printInvalidDataMsg(outFile);
      invalidCnt = invalidCnt + 1;
    }//end if

    //re-reading the input data
    readRd(inFile, studName, studId, sex, exam1, exam2, exam3);
  }//end While

  if (studCnt > 0)
  {
     printBarChart(outFile, studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing);
     printMeanOfAllAvg(outFile, examAvgSum, studCnt);
     printValidInvalidPerc(outFile, invalidCnt, studCnt);
  }
  else
  {
    printNoValidData(outFile);
    printValidInvalidPerc(outFile, invalidCnt, studCnt);
  }

  outFile << endl << "*< end >*" << endl;

  //closing input and output files
  inFile.close();
  outFile.close();

  return 0;
}//end function


bool filesCheck(ofstream& outFile, ifstream& inFile)
//*********************************************
// Purpose: Checks if either input or output files exists.
// Input: inFile, outFile.
// Pre: Declaration of both input and output streams before calling this function.
// Output: bool.
// Post: return true if files are loaded successfully, false if not.
// Note: none.
//*********************************************

{
  if (inFile.fail() || outFile.fail())
  {
    cout << "Check your input and/or output file !!" << endl;
    return 0;
  }
  else
    return 1;//end if
}//end function

void setPrecision(ofstream& outFile, int data)
//*********************************************
// Purpose: Changes quantity of numbers after decimal point.
// Input: data.
// Pre: outFile is opened & ok, data has valid value.
// Output: outFile.
// Post: Changes the quantity of numbers after decimal point to the given data in call.
// Note: none.
//*********************************************

{
  outFile.setf(ios::fixed);
  outFile.precision(data);
}//end function

void printHeading(ofstream& outFile)
//*********************************************
// Purpose: Print heading for output file.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile.
// Note: none.
//*********************************************

{
  outFile << "*~~< Stud Exam Report >~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Sex" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Grade" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "---" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-----" << endl;
}//end function

void readRd(ifstream& inFile, string& studName, int& studId, char& sex, float& exam1, float& exam2, float& exam3)
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: studName, studId, exam1, exam2, exam3.
// Post: studName, studId, sex, exam1, exam2, exam3 are stored to their variables via inFile.
// Note: none.
//*********************************************

{
  inFile >> studName >> studId >> sex >> exam1 >> exam2 >> exam3;
}//end function

bool validData(int studId, char sex, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Checks if exam and student id are valid.
// Input: studId, sex, exam1, exam2, exam3.
// Pre: studId, sex, exam1, exam2, exam3 have values.
// Output: bool.
// Post: Returns True if data are valid, false is not.
// Note: none.
//*********************************************

{
  if((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX) &&
     (exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX) &&
     (sex == 'M' || sex == 'F'))
    return 1;
  else
    return 0;//end if
}//end function

void printRd(ofstream& outFile, string studName, int studId, char sex, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studName, studId, sex, exam1, exam2, exam3.
// Pre: outFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3 are printed in outFile.
// Note: none.
//*********************************************

{
  outFile << left << setw(20) <<  studName << setw(10) << studId << setw(10)
          << sex << setw(10) << exam1 << setw(10) << exam2 << setw(15) << exam3  << setw(15);
}//end function

int avg(float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Calculates avg of 3 exams converted to the next integer.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2, exam3 are valid and have data.
// Output: int.
// Post: The avg of 3 exams converted to the next integer is returned.
// Note: none.
//*********************************************

{
  return ceil((exam1+exam2+exam3)/3);
}//end function

void printAvgAndGrade(ofstream& outFile, int examAvg, Grades studGrade)
//*********************************************
// Purpose: Prints student avg and letter data.
// Input: examAvg, studGrade.
// Pre: outFile is opened & ok. examAvg, studGrade are valid and have data, datatype Grades is valid.
// Output: outFile.
// Post: Avg and grade are printed to outFile.
// Note: none.
//*********************************************

{
  string outputGrade;
  
  switch(studGrade)
  {
    case EXCELLENT:
      outputGrade = "EXCELLENT";
    break;

    case GOOD:
      outputGrade = "GOOD";
    break;

    case OK:
      outputGrade = "OK";
    break;

    case WEAK:
      outputGrade = "WEAK";
    break;

    case FAILING:
      outputGrade = "FAILING";
    break;
  }//end switch
  
  outFile << examAvg << outputGrade << endl;
}//end function

void printInvalidDataMsg(ofstream& outFile)
//*********************************************
// Purpose: Prints invalid data line.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: "~~ Invalid data ~~" line is printed in outFile.
// Note: none.
//*********************************************

{
  outFile << "~~ Invalid data ~~" << endl;
}//end function

Grades grade(int examAvg)
//*********************************************
// Purpose: Returns the exams avg to Grades datatype.
// Input: examAvg.
// Pre: examAvg is valid and have data, datatype Grades is valid.
// Output: Grades.
// Post: Returns enum value of Grades that matches exams Avg.
// Note: none.
//*********************************************

{
  Grades output;

  switch(examAvg)
  {
    case EXCELLENT_MIN ... EXCELLENT_MAX:
      output = EXCELLENT;
    break;

    case GOOD_MIN ... GOOD_MAX:
      output = GOOD;
    break;

    case OK_MIN ... OK_MAX:
      output = OK;
    break;

    case WEAK_MIN ... WEAK_MAX:
      output = WEAK;
    break;

    case FAILING_MIN ... FAILING_MAX:
      output = FAILING;
    break;
  }//end switch

  return output;
}//end function

void countGrades(Grades studGrade, int& cntExcellent, int& cntGood, int& cntOk, int& cntWeak, int& cntFailing)
//*********************************************
// Purpose: Depending on the input, grade count is increased by one.
// Input: studGrade.
// Pre: studGrade has value and valid grade, cntcntExcellent, cntGood, cntOk,
//      cntWeak, cntFailing has valid values. datatype Grades is valid
// Output: cntExcellent, cntGood, cntOk, cntWeak, cntFailing.
// Post: Count of one of the grades cnt variables is ancreased by one, depending on the input.
// Note: none.
//*********************************************

{
  switch(studGrade)
  {
    case EXCELLENT:
      cntExcellent++;
    break;

    case GOOD:
      cntGood++;
    break;

    case OK:
      cntOk++;
    break;

    case WEAK:
      cntWeak++;
    break;

    case FAILING:
      cntFailing++;
    break;
  }//end switch
}//end function

void printBarChart(ofstream& outFile, int studCnt, int cntExcellent, int cntGood, int cntOk, int cntWeak, int cntFailing)
//*********************************************
// Purpose: Prints Grade Destitution Bar Chart.
// Input: studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing.
// Pre: outFile is opened & ok. studCnt, cntExcellent, cntGood, cntOk, cntWeak, cntFailing have values.
// Output: outFile.
// Post: grade performance bar chart is printed to outFile.
// Note: none.
//*********************************************

{
  string starsForGrade = "***";

  outFile << endl << "Bar chart for Performance"
          << endl << "-------------------------"
          << endl << left << setw(10) << "EXCELLENT" << "|";

  for (int i = 1; i <= cntExcellent; i++)
    outFile << starsForGrade;//end for

  outFile << endl << setw(10) << "GOOD" << "|";

  for (int i = 1; i <= cntGood; i++)
    outFile << starsForGrade;//end for

  outFile << endl << setw(10) << "OK" << "|";

  for (int i = 1; i <= cntOk; i++)
    outFile << starsForGrade;//end for

  outFile << endl << setw(10) << "WEAK" << "|";

  for (int i = 1; i <= cntWeak; i++)
    outFile << starsForGrade;//end for

  outFile << endl << setw(10) << "FAILING" << "|";

  for (int i = 1; i <= cntFailing; i++)
    outFile << starsForGrade;//end for

  outFile << endl;
}//end function

void printNoValidData(ofstream& outFile)
//*********************************************
// Purpose: Prints an error message if there is no valid exam records.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: the meaning of "no valid student data, no bar chart and mean of all avg printed" is printed to outFile.
// Note: none.
//*********************************************

{
  outFile << endl << "No Valid students data in file to evaluate performance bar chart and the mean of all AVG!" << endl;
}//end function

void printMeanOfAllAvg(ofstream& outFile, int examAvgSum, int studCnt)
//*********************************************
// Purpose: Prints the mean of all avg's.
// Input: examAvgSum, studCnt.
// Pre: outFile is opened & ok, examAvgSum, studCnt have values.
// Output: outFile.
// Post: the mean of all exams AVG's is printed to outFile.
// Note: none.
//*********************************************

{
  float meanOfAllAvg = float(examAvgSum)/float(studCnt);
  outFile << endl << ">> Mean of all AVG: " << meanOfAllAvg << endl;
}

void printValidInvalidPerc(ofstream& outFile, int invalidCnt, int studCnt)
//*********************************************
// Purpose: Prints valid and invalid records percentage.
// Input: invalidCnt, studCnt.
// Pre: outFile is opened & ok, invalidCnt, studCnt have values.
// Output: outFile.
// Post: the percentage of valid and invalid records are printed in outFile.
// Note: none.
//*********************************************

{
  float total = invalidCnt + studCnt;
  float validPerc = (float(studCnt)/total)*100;
  float invalidPerc = (float(invalidCnt)/total)*100;
  outFile << endl << ">>% of Valid: " << validPerc << endl
          << ">>% of Invalid: " << invalidPerc << endl;
}