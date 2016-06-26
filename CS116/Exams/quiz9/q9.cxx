#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool filesCheck(ofstream& outFile, ifstream& inFile);

void setPrecision(ofstream& outFile, int data);

void printHeading(ofstream& outFile);

void readRd(ifstream& inFile, int& studId, int& exam1, int& exam2);

int findMaxExam(int& exam1, int& exam2);

void setAvgExam(float& examAvg, int exam1, int exam2);

void printRd(ofstream& outFile, int studId, int exam1, int exam2);

void printRecordCount(ofstream& outFile, int recordCount);

void printAvgMax(ofstream& outFile, float examAvg, int maxExam);

int main()
{
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");
  
  if (!filesCheck(outFile, inFile))
    return 1;

  setPrecision(outFile, 2);

  int studId, exam1, exam2;
  int recordCount = 0;
  float examAvg = 0;
  int maxExam = 0;
  
  printHeading(outFile);
  
  readRd(inFile, studId, exam1, exam2);
  
  while (inFile)
  {
     maxExam = findMaxExam(exam1, exam2);

     printRd(outFile, studId, exam1, exam2);

     setAvgExam(examAvg, exam1, exam2);

     recordCount = recordCount + 1;

     printAvgMax(outFile, examAvg, maxExam);

     readRd(inFile, studId, exam1, exam2);
  }
  
  printRecordCount(outFile, recordCount);
  
  outFile << endl << "<* end *>" << endl;
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
  outFile << "<* Exam Report *>" << endl;
  outFile << left << setw(10) <<  "ID" << setw(10) << "E1" 
          << setw(10) << "E2" << setw(10) << "AVG" << setw(10) << "MAX" << endl;
}

void readRd(ifstream& inFile, int& studId, int& exam1, int& exam2)

{
  inFile >> studId >> exam1 >> exam2;
}

int findMaxExam(int& exam1, int& exam2)

{
  int max = exam1;
  if (exam2 > max)
  {
     max = exam2;
  }
  
  return max;
}

void setAvgExam(float& examAvg, int exam1, int exam2)

{
  examAvg = (exam1 + exam2)/2.00;
}

void printRd(ofstream& outFile, int studId, int exam1, int exam2)

{
  outFile << left << setw(10) <<  studId << setw(10) << exam1 
          << setw(10) << exam2;
}

void printRecordCount(ofstream& outFile, int recordCount)
{
  outFile << endl << "*** Number of records: " << recordCount << endl;
}

void printAvgMax(ofstream& outFile, float examAvg, int maxExam)

{
  outFile << setw(10) << examAvg << setw(10) << maxExam << endl;
}