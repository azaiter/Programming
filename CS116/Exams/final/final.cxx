#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int ARR_SIZE = 10;

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

void readExam(ifstream& inFile, int examList[]);
//*********************************************
// Purpose: Reads Exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. examList is valid.
// Output: examList.
// Post: data of examList are stored to their indexes via inFile.
// Note: none.
//*********************************************

void printExam(ofstream& outFile, int examList[]);
//*********************************************
// Purpose: Prints exams.
// Input: examList.
// Pre: outFile is opened & ok. examList is valid and has values.
// Output: outFile.
// Post: exams data in the array are printed in outFile.
// Note: none.
//*********************************************

void maxAndMin(int examList[], int& examMax, int& examMin);
//*********************************************
// Purpose: it assigns highest and lowest values of examList array.
// Input: examList.
// Pre: examList is valid and has values.
// Output: examMax,  examMin.
// Post: highest and lowest values of examList array are assigned to their variables.
// Note: none.
//*********************************************


float avg(int examList[]);
//*********************************************
// Purpose: it returns the average of exams.
// Input: examList.
// Pre: examList is valid and has values. 
// Output: float.
// Post: average of exams in array is returned.
// Note: none.
//*********************************************

int main()
{
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");
  //file checking
  if (!filesCheck(outFile, inFile))
    return 1;//endif
  //setting numbers after decimal point to 2
  setPrecision(outFile, 2);
  //declaring vars
  int examList[ARR_SIZE], examMax, examMin;
  //main job:
  outFile << "<* Exams *>" << endl;
  readExam(inFile, examList);
  printExam(outFile, examList);
  maxAndMin(examList, examMax, examMin);
  outFile << endl << "AVG: " << avg(examList) << endl
          << "MAX: " << examMax << endl
          << "MIN: " << examMin << endl << endl
          << "List of odd num only : ";
  for (int i = 0; i < ARR_SIZE; i++)
  {
    if(examList[i]%2 == 1)
      outFile << examList[i] << "\t";
    examList[i] = examList[i] + 2;
  }
  outFile << endl << endl << "~* Exams + 2*: ";
  printExam(outFile, examList);
  outFile << endl << "< end >";
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

void readExam(ifstream& inFile, int examList[])
//*********************************************
// Purpose: Reads Exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. examList is valid.
// Output: examList.
// Post: data of examList are stored to their indexes via inFile.
// Note: none.
//*********************************************

{
  for(int i = 0; i < ARR_SIZE; i++)
    inFile >> examList[i];
}

void printExam(ofstream& outFile, int examList[])
//*********************************************
// Purpose: Prints exams.
// Input: examList.
// Pre: outFile is opened & ok. examList is valid and has values.
// Output: outFile.
// Post: exams data in the array are printed in outFile.
// Note: none.
//*********************************************

{
  for(int i = 0; i < ARR_SIZE; i++)
    outFile << examList[i] << "\t";
  outFile << endl;
}

void maxAndMin(int examList[], int& examMax, int& examMin)
//*********************************************
// Purpose: it assigns highest and lowest values of examList array.
// Input: examList.
// Pre: examList is valid and has values.
// Output: examMax,  examMin.
// Post: highest and lowest values of examList array are assigned to their variables.
// Note: none.
//*********************************************

{
  examMax = examMin = examList[0];
  for(int i = 0; i < ARR_SIZE; i++)
  {
    if(examList[i] > examMax)
      examMax = examList[i];
    if(examList[i] < examMin)
      examMin = examList[i];
  }
}

float avg(int examList[])
//*********************************************
// Purpose: it returns the average of exams.
// Input: examList.
// Pre: examList is valid and has values. 
// Output: float.
// Post: average of exams in array is returned.
// Note: none.
//*********************************************

{
  float sum = 0;
  for(int i = 0; i < ARR_SIZE; i++)
    sum = sum + examList[i];
  return (sum/ARR_SIZE);
}

