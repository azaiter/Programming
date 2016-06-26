#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  //defining streams and opening files
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");

  //file checks
  if (inFile.fail() || outFile.fail())
  {
    outFile << "Check your input and/or output file !!" << endl;
    return 1;
  }

  //setting numbers after decimal point to 2
  outFile.setf(ios::fixed);
  outFile.precision(2);

  //declaring variables
  int studId, exam, examMax, examMin;
  int examCount = 0;
  float examAvg;
  float examSum = 0.00;
  examMin = 100;
  //outputting intial aligned output
  outFile << "<* Exam Report *>" << endl;

  //inputing data from file
  inFile >> studId >> exam;

  // HERE YOU ASSIGN MIN AND MAX RATHER THAN ASSIGN 100 TO MIN

  //doing the main loop till the end of the file
  while (inFile)
  {
    //adding it to count
    examCount = examCount + 1;
    //adding to sum
    examSum = examSum + exam;
    //outputting main data
    outFile << left << setw(5) << studId << setw(5) << exam << endl;
	//Max and Min
	if (exam > examMax)
	  examMax = exam;
    if (exam < examMin)
	  examMin = exam;
    //re-reading the input data
    inFile >> studId >> exam;
  }

  //calculate AVG
  examAvg = examSum/examCount;
  //output last data
  outFile << endl << "MIN: " << examMin << endl;
  outFile << "MAX: " << examMax << endl;
  outFile << "AVG: " << examAvg << endl << endl;
  outFile << "<* end *>" << endl;
  //closing input and output files
  inFile.close();
  outFile.close();

  return 0;
}



