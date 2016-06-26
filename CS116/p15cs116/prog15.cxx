//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming I // COURSE NUMBER: CS116 // PROF NAME: Moe Bidgoli
// ASSIGNMENT NUMBER: #15 // DUE DATE: 12-3-2015 // POSSIBLE POINTS: 40 Points
// PURPOSE:
//  a program that solves this problem: Design, implement, and test a program that
// reads a text file and determine the following:
//1)  Number of char (excluding EOF and EOLN) of an input file.
//2)	Number of lines. //3)	Number of space character.
//4)	Number of alphabet. //5)	Number of digit.
//6)	Number of lower case characters. //7)	Number of upper case characters.
//8)	Replace all “svsu” with SVSU” and all “csis” with “CSIS”.
//*******************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>

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
  
  string strLine, strTotal;
  string::size_type position;
  int stringL, numLines, numSpaces, numAlpha, numDigit, numLower, numUpper, numPrint;
  stringL = numLines = numSpaces = numAlpha = numDigit = numLower = numUpper = numPrint = 0;

  getline(inFile, strLine);
  while (inFile)
  {
    strTotal= strTotal + strLine + "\n";
    numLines = numLines +1;
    getline(inFile, strLine);
  }
  
  stringL = strTotal.length();
    
  for (int i = 0; i < stringL; i++)
  {
    char tempChar = strTotal[i];
    if (tempChar == ' ')
      numSpaces = numSpaces + 1;
    if (isprint(tempChar))
      numPrint = numPrint + 1;
    if (isalpha(tempChar))
      numAlpha = numAlpha + 1;
    if (isdigit(tempChar))
      numDigit = numDigit + 1;
    if (islower(tempChar))
      numLower = numLower + 1;
    if (isupper(tempChar))
      numUpper = numUpper + 1;
  }
  
  int posSVSU = strTotal.find("svsu");
  while(posSVSU < string::npos)
  {
    strTotal.replace(posSVSU, 4,"SVSU");
    posSVSU= strTotal.find("svsu", posSVSU+ 1);
  }
  
  int posCSIS = strTotal.find("csis");
  while(posCSIS < string::npos)
  {
    strTotal.replace(posCSIS, 4,"CSIS");
    posCSIS= strTotal.find("csis", posCSIS + 1);
  }
  
  printHeading(outFile);
  outFile << strTotal
          << "1) Number of char (excluding EOF and EOLN): " << numPrint << endl
          << "2) Number of lines: " << numLines << endl
          << "3) Number of space character: " << numSpaces << endl
          << "4) Number of alphabet: " << numAlpha << endl
          << "5) Number of digit: " << numDigit << endl
          << "6) Number of lower case characters: " << numLower << endl
          << "7) Number of upper case characters: " << numUpper << endl
          << endl << "< end >";

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
  outFile << "<~~~ Text Analysis ~~~>" << endl << endl;
}//end function