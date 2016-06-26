//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming I // COURSE NUMBER: CS116 // PROF NAME: Moe Bidgoli
// ASSIGNMENT NUMBER: #12 // DUE DATE: 11-xx-2015 // POSSIBLE POINTS: 40 Points
// PURPOSE:
//  a program that reads gpa records from a file. The content of the record is student’s gpa(float).
//  Store data into an array, print input data, sorted data and find students maximum, minimum pga, 
//  and average of gpa. Print all top student with gpa higher than 3.50 from sorted array and probationary
//  students with gps below 2.00. If you do not have any top and/or probationary students give an appropriate message
//*******************************************************************

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

void printHeading(ofstream& outFile);
//*********************************************
// Purpose: Print heading for output file.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile.
// Note: none.
//*********************************************

void getData(ifstream& inFile, float gpaList[]);
//*********************************************
// Purpose: Reads GPA data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. gpaList is valid.
// Output: gpaList.
// Post: data of gpaList are stored to their indexes via inFile.
// Note: none.
//*********************************************

void selSort(float gpaList[]);
//*********************************************
// Purpose: it orders the data in the given array increasingly.
// Input: gpaList.
// Pre: gpaList is valid and has values.
// Output: gpaList.
// Post: data of the array gpaList is ordered increasingly from low to high.
// Note: none.
//*********************************************

void printSorts(ofstream& outFile, float gpaList[]);
//*********************************************
// Purpose: Prints GPA's in order and in reverse order
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values.
// Output: outFile.
// Post: data of the array in order and in reverse order are printed in outFile.
// Note: none.
//*********************************************

void findPrintMaxMinMeanGPA(ofstream& outFile, float gpaList[]);
//*********************************************
// Purpose: prints highest and lowest and the means values of gpaList array.
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values. function meanOfGpa is defined correctly.
// Output: outFile.
// Post: highest and lowest and the means values of gpaList array are printed in outFile.
// Note: none.
//*********************************************

float meanOfGpa(float gpaList[]);
//*********************************************
// Purpose: to return the mean of values in gpaList array.
// Input: gpaList.
// Pre: gpaList is valid and has values.
// Output: float.
// Post: Returns the mean of values in gpaList array.
// Note: none.
//*********************************************

void printTopsLows(ofstream& outFile, float gpaList[]);
//*********************************************
// Purpose: Prints the GPA's >= 3.50 and GPA's < 2.00
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values.
// Output: outFile.
// Post: data of the array that is >= 3.5 and < 2.00 are printed in outFile.
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
  float gpaList[ARR_SIZE];
  //main job functions
  getData(inFile, gpaList);
  selSort(gpaList);
  printHeading(outFile);
  printSorts(outFile, gpaList);
  printTopsLows(outFile, gpaList);
  findPrintMaxMinMeanGPA(outFile, gpaList);
  outFile << endl << "***< end >***" << endl;
  //closing input and output files
  inFile.close();
  outFile.close();
  return 0;
}//end function

void getData(ifstream& inFile, float gpaList[])
//*********************************************
// Purpose: Reads GPA data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. gpaList is valid.
// Output: gpaList.
// Post: data of gpaList are stored to their indexes via inFile.
// Note: none.
//*********************************************

{
  for (int i = 0; i < ARR_SIZE; i++)
    inFile >> gpaList[i];//end for
}

void selSort(float gpaList[])
//*********************************************
// Purpose: it orders the data in the given array increasingly.
// Input: gpaList.
// Pre: gpaList is valid and has values.
// Output: gpaList.
// Post: data of the array gpaList is ordered increasingly from low to high.
// Note: none.
//*********************************************

{
  float temp;
  int firstControl;
  int secondControl;
  int minIndex;

  for (firstControl = 0; firstControl < ARR_SIZE - 1; firstControl++)
  {
    minIndex = firstControl;

    for (secondControl = firstControl + 1; secondControl < ARR_SIZE; secondControl++)
      if (gpaList[secondControl] < gpaList[minIndex])
        minIndex = secondControl;//end if//end for

    temp = gpaList[minIndex];
    gpaList[minIndex] = gpaList[firstControl];
    gpaList[firstControl] = temp;
  }//end for
}//end function

void printSorts(ofstream& outFile, float gpaList[])
//*********************************************
// Purpose: Prints GPA's in order and in reverse order
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values.
// Output: outFile.
// Post: data of the array in order and in reverse order are printed in outFile.
// Note: none.
//*********************************************

{
  outFile << endl << "~ Sorted GPA Low  to High ~" << endl;
  for (int i = 0; i < ARR_SIZE; i++)
    outFile << gpaList[i] << endl;//end if//end for
  outFile << "<- end ->" << endl;

  outFile << endl << "~ Sorted GPA High to Low ~" << endl;
  for (int i = (ARR_SIZE - 1); i >= 0; i--)
    outFile << gpaList[i] << endl;//end if//end for
  outFile << "<- end ->" << endl;

}//end function

void findPrintMaxMinMeanGPA(ofstream& outFile, float gpaList[])
//*********************************************
// Purpose: prints highest and lowest and the means values of gpaList array.
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values. function meanOfGpa is defined correctly.
// Output: outFile.
// Post: highest and lowest and the means values of gpaList array are printed in outFile.
// Note: none.
//*********************************************

{
  float maxGPA, minGPA;
  maxGPA = minGPA = gpaList[0];
  for (int i = 0; i < ARR_SIZE; i++)
  {
     if (gpaList[i] > maxGPA)
       maxGPA = gpaList[i];//end if

     if (gpaList[i] < minGPA)
       minGPA = gpaList[i];//end if
  }//end for
  
  outFile << endl << "~MAX GPA: " << maxGPA << endl;
  outFile << "~MIN  GPA: " << minGPA << endl;
  outFile << "~Mean of GPA: " << meanOfGpa(gpaList) << endl;
}//end function

float meanOfGpa(float gpaList[])
//*********************************************
// Purpose: to return the mean of values in gpaList array.
// Input: gpaList.
// Pre: gpaList is valid and has values.
// Output: float.
// Post: Returns the mean of values in gpaList array.
// Note: none.
//*********************************************

{
  float gpaSum = 0;
  for (int i = 0; i < ARR_SIZE; i++)
    gpaSum = gpaSum + gpaList[i];//end for
  return (gpaSum/ARR_SIZE);
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
  outFile << "*--< Stud Exam Report >--*" << endl;
}//end function

void printTopsLows(ofstream& outFile, float gpaList[])
//*********************************************
// Purpose: Prints the GPA's >= 3.50 and GPA's < 2.00
// Input: gpaList.
// Pre: outFile is opened & ok. gpaList is valid and has values.
// Output: outFile.
// Post: data of the array that is >= 3.5 and < 2.00 are printed in outFile.
// Note: none.
//*********************************************

{
  // First calculate # of values in each one of them:
  int validHighCnt = 0;
  int validLowCnt = 0;

  for (int i = 0; i < ARR_SIZE; i++)
    if (gpaList[i] >= 3.5)
      validHighCnt = validHighCnt + 1;
    
  for (int i = 0; i < ARR_SIZE; i++)
    if (gpaList[i] < 2.0)
      validLowCnt = validLowCnt + 1;

  //now outputting data
  if (validHighCnt > 0)
  {
  outFile << endl << "~ Student with GPA >= 3.50 ~" << endl;
  for (int i = 0; i < ARR_SIZE; i++)
    if (gpaList[i] >= 3.5)
      outFile << gpaList[i] << endl;
  outFile << "<- end ->" << endl;
  }
  else
    outFile << endl << "~ Can't Find Students with GPA  >= 3.50 !!" << endl;


  if (validLowCnt > 0)
  {
  outFile << endl << "~ Student with GPA < 2.00 ~" << endl;
  for (int i = 0; i < ARR_SIZE; i++)
    if (gpaList[i] < 2.0)
      outFile << gpaList[i] << endl;
  outFile << "<- end ->" << endl;
  }
  else
    outFile << endl << "~ Can't Find Students with GPA < 2.00 !!" << endl;
}