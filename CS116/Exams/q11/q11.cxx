//Abdulrahman Zaiter

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int ARRAY_SIZE = 10;

bool filesCheck(ofstream& outFile, ifstream& inFile);
void setPrecision(ofstream& outFile, int data);
void readRd(ifstream& inFile, int studData[]);
void selSort(int studData[]);

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

  int studData[ARRAY_SIZE];
  readRd(inFile, studData);
  
  outFile << "*~~< Stud Id Report >~~*" << endl;
  for (int i = 0; i < ARRAY_SIZE; i++)
    outFile << studData[i] << endl;
  outFile << "<* end *>" << endl << endl;
  
  outFile << "*~ Sorted Id ~*" << endl;
  selSort(studData);
  for (int i = 0; i < ARRAY_SIZE; i++)
    outFile << studData[i] << endl;
  outFile << "<* end *>" << endl << endl;

  outFile << "*~ Even Id ~*" << endl;
  bool found = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    if ( studData[i] % 2 == 0 )
    {
      found = 1;
      outFile << studData[i] << endl;
    }
  }
  if (found == 0)
    outFile << "None" << endl;
  
  outFile << "<* end *>" << endl << endl;
  //closing input and output files
  inFile.close();
  outFile.close();
  return 0;
}


bool filesCheck(ofstream& outFile, ifstream& inFile)
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
{
  outFile.setf(ios::fixed);
  outFile.precision(data);
}//end function



void readRd(ifstream& inFile, int studData[])
{
  for (int i = 0; i < ARRAY_SIZE; i++)
    inFile >> studData[i];
}//end function

void selSort(int studData[])
{
  int temp;
  int firstControl;
  int secondControl;
  int minIndex;

  for (firstControl = 0; firstControl < ARRAY_SIZE - 1; firstControl++)
  {
    minIndex = firstControl;

    for (secondControl = firstControl + 1; secondControl < ARRAY_SIZE; secondControl++)
      if (studData[secondControl] < studData[minIndex])
        minIndex = secondControl;//end if//end for

    temp = studData[minIndex];
    studData[minIndex] = studData[firstControl];
    studData[firstControl] = temp;
  }//end for
}//end function
