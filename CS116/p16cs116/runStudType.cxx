//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming I // COURSE NUMBER: CS116 // PROF NAME: Moe Bidgoli
// ASSIGNMENT NUMBER: #14 // DUE DATE: 12-3-2015 // POSSIBLE POINTS: 40 Points
// PURPOSE:
//  a program that solves this problem: I’m teaching 3 sections of CS116 and for 
//  each class I have a table for exams performances. For each class I have 3 students
//  and three exams. I like to know maximum, minimum, and average of each class and all 
//  of my students
//*******************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include "StudType.h"

using namespace std;

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
// Purpose: Print heading for output file .
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile.
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

  StudType rd;
  //rd.StudType();

  int cntPass, cntFail, cntValid, cntInvalid;
  cntPass = cntFail = cntValid = cntInvalid = 0;
  printHeading(outFile);
  
  rd.readRd(inFile);
  while(inFile)
  {
    rd.writeRd(outFile);
    if (rd.validRd())
    {
      cntValid++;
      rd.findMax();
      rd.findMin();
      rd.findAvg(); 
      rd.findPassOrFail();
      if (rd.passOrFail == 'P')
        cntPass++;
      else
        cntFail++;
      rd.writeMaxMinAvgPOrF(outFile);
    }
    else
    {
      cntInvalid++;
      rd.printInvalidMsg(outFile);
    }
    
    rd.readRd(inFile);
  }
  
  outFile << endl << "*** Num of valid data = " << cntValid << endl << "*** Num of invalid data = " << cntInvalid << endl << endl;
  
  if(cntValid > 0)
    outFile << "*** Num of P = " << cntPass << endl << "*** Num of F = " << cntFail << endl;
  else
    outFile << "There is no Valid data to count P and F" << endl;
  
  outFile << endl << "*< end >*" << endl;

  //closing input and output files
  inFile.close();
  outFile.close();

  return 0;
  
}

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
// Purpose: Print heading for output file .
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile .
// Note: none.
//*********************************************

{
  outFile << "*~< Student Exam Report >~*" << endl;
  outFile << left  << setw(10) << "ID" << setw(10)
          << "Exam1" << setw(10) << "Exam2" << setw(15) << "Exam3"
          << setw(15) << setw(10) << "Max" << setw(10) << "Min" << setw(10) << "AVG" << setw(10) << "P/F";;
  outFile << endl;
}//end function