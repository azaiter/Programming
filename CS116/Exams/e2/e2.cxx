//Abdulrahman Zaiter
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const float GPA_MAX = 4.00;
const float GPA_MIN = 0.00;
const int ID_MAX = 999;
const int ID_MIN = 111;
const char MALE_ID = 'M';
const char FEMALE_ID = 'F';

bool filesCheck(ofstream& outFile, ifstream& inFile);
void setPrecision(ofstream& outFile, int data);
void printHeading(ofstream& outFile);
void readRd(ifstream& inFile, string& studName, int& studId, char& studSex, float& studGpa);
bool validData(int studId, char studSex, float studGpa);
void printRd(ofstream& outFile, string studName, int studId, char studSex, float studGpa);
float findMaxGpa(float studGpa, float gpaMax);
void findAvgGpas(int gpaCnt, float gpaSum, float& gpaAvg);

int main()
{
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");
  if (!filesCheck(outFile, inFile))
    return 1;
  setPrecision(outFile, 2);
  
  string studName;
  int studId;
  char studSex;
  float studGpa;
  int gpaCnt = 0;
  float gpaSum = 0;
  float gpaMax = 0;
  float gpaAvg = 0;

  printHeading(outFile);
  readRd(inFile, studName, studId, studSex, studGpa);
  while (inFile)
  {
    printRd(outFile, studName, studId, studSex, studGpa);

    if(validData(studId, studSex, studGpa))
    {
       gpaSum = gpaSum + studGpa;
       gpaCnt = gpaCnt + 1;
       gpaMax = findMaxGpa(studGpa, gpaMax);
       outFile << endl;
    }
    else
      outFile << "~~~> Invalid data!" << endl;

    readRd(inFile, studName, studId, studSex, studGpa);
  }
  
  if (gpaCnt > 0)
  {
  findAvgGpas(gpaCnt,gpaSum,gpaAvg);
  outFile << endl << "MAX GPA: " << gpaMax << endl;
  outFile << "AVG OF GPA: " << gpaAvg << endl;
  }
  else 
    outFile << endl << "No Valid data, No GPA & MAX!" << endl;
  outFile << endl << "<* end *>";
  
}
  
  
bool filesCheck(ofstream& outFile, ifstream& inFile)
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
{
  outFile.setf(ios::fixed);
  outFile.precision(data);
}

void printHeading(ofstream& outFile)
{
  outFile << left << setw(10) << "Name" << setw(10) << "Id" << setw(10) << "SEX" << setw(10) << "GPA" << endl;
}

void readRd(ifstream& inFile, string& studName, int& studId, char& studSex, float& studGpa)
{
  inFile >> studName >> studId >> studSex >> studGpa;
}

void printRd(ofstream& outFile, string studName, int studId, char studSex, float studGpa)
{
  outFile << left << setw(10) << studName << setw(10) << studId << setw(10) << studSex << setw(10) << studGpa;
}


bool validData(int studId, char studSex, float studGpa)
{
  if((studGpa >= GPA_MIN && studGpa <= GPA_MAX) && (studSex == MALE_ID || studSex == FEMALE_ID) && (studId >= ID_MIN && studId <= ID_MAX))
    return 1;
  else
    return 0;
}


float findMaxGpa(float studGpa, float gpaMax)
{
  float result;
  if (studGpa > gpaMax)
    result = studGpa;
  else
    result = gpaMax;
  return result;
}

void findAvgGpas(int gpaCnt, float gpaSum, float& gpaAvg)
{
  gpaAvg = gpaSum/float(gpaCnt);
}