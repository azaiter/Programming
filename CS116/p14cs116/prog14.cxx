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

using namespace std;

const int NUM_SEC = 3;
const int NUM_STUD = 3;
const int NUM_EXAMS = 3;

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

void printHeading(ofstream& outFile, int sec_num);
//*********************************************
// Purpose: Print heading for output file depending on section number.
// Input: sec_num.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile depending on section number.
// Note: none.
//*********************************************

void readRd(ifstream& inFile, int studData[][NUM_STUD][NUM_EXAMS]);
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studData array is defined properly.
// Output: studData.
// Post: variables of studData array are stored to their variables via inFile.
// Note: none.
//*********************************************

void printRdAndStats(ofstream& outFile, const int studData[][NUM_STUD][NUM_EXAMS], int sec_num );
//*********************************************
// Purpose: Print exams data and stats of specefic section.
// Input: studData, sec_num.
// Pre: outFile is opened & ok. studData array is defined properly.
// Output: outFile.
// Post: exams data and stats of specefic section are printed in outFile.
// Note: none.
//*********************************************


void printClassesReports(ofstream& outFile, const int studData[][NUM_STUD][NUM_EXAMS]);
//*********************************************
// Purpose: Print all exams data and all stats of exams.
// Input: studData.
// Pre: outFile is opened & ok. studData array is defined properly.
// Output: outFile.
// Post: all exams data and all stats of exams are printed in outFile.
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
  int studData[NUM_SEC][NUM_STUD][NUM_EXAMS];

  
  //doing main job in sequence
  for (int sec_num =0; sec_num < NUM_SEC; sec_num++)
  {
  printHeading(outFile,sec_num);
  readRd(inFile, studData);
  printRdAndStats(outFile, studData, sec_num);
  outFile << endl;
  }
  
  printClassesReports(outFile, studData);
  
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

void printHeading(ofstream& outFile, int sec_num)
//*********************************************
// Purpose: Print heading for output file depending on section number.
// Input: sec_num.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading is printed in outFile depending on section number.
// Note: none.
//*********************************************

{
  outFile << "*~~< Stud Exam Report For Class: " << sec_num+1 << " >~~*" << endl;
  
  for (int i_exams = 0; i_exams < NUM_EXAMS; i_exams++)
  {
    string combined;
    stringstream combineName;
    combineName << "Exam" << i_exams+1;
    combined = combineName.str();
    outFile << left << setw(10) << combined;
  }
  outFile << endl;
}//end function

void readRd(ifstream& inFile, int studData[][NUM_STUD][NUM_EXAMS])
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studData array is defined properly.
// Output: studData.
// Post: variables of studData array are stored to their variables via inFile.
// Note: none.
//*********************************************

{
  for (int i_sec = 0; i_sec < NUM_SEC; i_sec++)
  {
    for (int i_stud = 0; i_stud < NUM_STUD; i_stud++)
    {
      for (int i_exams = 0; i_exams < NUM_EXAMS; i_exams++)
      {
        inFile >> studData[i_sec][i_stud][i_exams];
      }
    }
  }
}//end function


void printRdAndStats(ofstream& outFile, const int studData[][NUM_STUD][NUM_EXAMS], int sec_num )
//*********************************************
// Purpose: Print exams data and stats of specefic section.
// Input: studData, sec_num.
// Pre: outFile is opened & ok. studData array is defined properly.
// Output: outFile.
// Post: exams data and stats of specefic section are printed in outFile.
// Note: none.
//*********************************************

{
   int examCnt = NUM_STUD * NUM_EXAMS;
   int examSum = 0;
   int examMax = studData[sec_num][1][1];
   int examMin = studData[sec_num][1][1];
   float examAvg = 0;
   
   for (int i_stud = 0; i_stud < NUM_STUD; i_stud++)
   {
     for (int i_exams = 0; i_exams < NUM_EXAMS; i_exams++)
     {
      int grade = studData[sec_num][i_stud][i_exams];
      outFile << left << setw(10) << grade;
      examSum = examSum + grade;
      if (grade > examMax)
        examMax = grade;
      if (grade < examMin)
        examMin = grade;
     }
     outFile << endl;
   }
   
   examAvg = float(examSum)/float(examCnt);
   
   outFile << endl << "Max: " << examMax <<	" Min: " << examMin << " Avg: " <<  examAvg << endl;
   
}//end function

void printClassesReports(ofstream& outFile, const int studData[][NUM_STUD][NUM_EXAMS])
//*********************************************
// Purpose: Print all exams data and all stats of exams.
// Input: studData.
// Pre: outFile is opened & ok. studData array is defined properly.
// Output: outFile.
// Post: all exams data and all stats of exams are printed in outFile.
// Note: none.
//*********************************************
{
  outFile << "Class1, 2, & 3 Reports" << endl << endl;
  int examCnt = NUM_STUD * NUM_EXAMS * NUM_SEC;
  int examSum = 0;
  int examMax = studData[1][1][1];
  int examMin = studData[1][1][1];
  float examAvg = 0.00;
  for (int i_sec = 0; i_sec < NUM_SEC; i_sec++)
  {
    for (int i_stud = 0; i_stud < NUM_STUD; i_stud++)
    {
      for (int i_exams = 0; i_exams < NUM_EXAMS; i_exams++)
      {
       int grade = studData[i_sec][i_stud][i_exams];
       examSum = examSum + grade;
       if (grade > examMax)
         examMax = grade;
       if (grade < examMin)
         examMin = grade;
      }
    }
  }
  examAvg = float(examSum)/float(examCnt);
  
  outFile << "Max of all exams: " << examMax << endl << "Min of all exams: " 
          << examMin << endl << "Avg of all exmas: " << examAvg << endl;
}