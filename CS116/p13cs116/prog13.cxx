//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming I // COURSE NUMBER: CS116 // PROF NAME: Moe Bidgoli
// ASSIGNMENT NUMBER: #13 // DUE DATE: 11-17-2015 // POSSIBLE POINTS: 40 Points
// PURPOSE:
//  a program that reads students records from a file and determine their class standing
//  and prints a bar chart of performance, mean of all avg , valid and invalid data male and female percentages 
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
const char MALE_ID = 'M';
const char FEMALE_ID = 'F';
const int ARRAY_SIZE = 10;

struct Student
{
  string studName;
  int studId;
  char sex;
  float exam1;
  float exam2;
  float exam3;
  int examAvg;
  string studGrade;
};//end struct

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

void printHeadingSortedId(ofstream& outFile);
//*********************************************
// Purpose: Print heading for output file of the sorted by id.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading of the sorted by id is printed in outFile.
// Note: none.
//*********************************************

void printHeadingSearch(ofstream& outFile);
//*********************************************
// Purpose: Print heading for output file of the searched id's.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading of the searched id's is printed in outFile.
// Note: none.
//*********************************************

void readRd(ifstream& inFile, Student studData[]);
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. Student struct is defined properly.
// Output: studData.
// Post: variables of studData struct are stored to their variables via inFile.
// Note: none.
//*********************************************

void printRd(ofstream& outFile, const Student studData[]);
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studData.
// Pre: outFile is opened & ok. Student struct is defined properly and its variables have valid values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3, avg and grade are printed in outFile.
// Note: none.
//*********************************************

void printOneRd(ofstream& outFile, const Student studData[], int i);
//*********************************************
// Purpose: Print one row of student and exams data.
// Input: studData, i.
// Pre: outFile is opened & ok. Student struct is defined properly and its variables have valid values, i has a valid data.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3, avg and grade of one record is printed in outFile.
// Note: none.
//*********************************************

void assignAvgAndGrade(Student studData[]);
//*********************************************
// Purpose: Calculates and assigns avg of 3 exams converted to the next integer and assigns its grade for each record.
// Input: studData.
// Pre: Student struct is defined properly and its variables have valid values.
// Output: studData.
// Post: The avg of 3 exams converted to the next integer and grades are assgined to the records in studData array.
// Note: none.
//*********************************************

string grade(int examAvg);
//*********************************************
// Purpose: Returns the exams avg to Grades datatype.
// Input: examAvg.
// Pre: examAvg is valid and have data, datatype Grades is valid.
// Output: string.
// Post: Returns string value of Grades that matches exams Avg.
// Note: none.
//*********************************************

void printMeanOfAllAvg(ofstream& outFile, int examAvgSum);
//*********************************************
// Purpose: Prints the mean of all avg's.
// Input: examAvgSum.
// Pre: outFile is opened & ok, examAvgSum have values.
// Output: outFile.
// Post: the mean of all exams AVG's is printed to outFile.
// Note: none.
//*********************************************

void maleAndFemalePrec(float maleCnt, float femaleCnt, float& malePerc, float& femalePerc);
//*********************************************
// Purpose: Assigning males and females percentages according to their count.
// Input: maleCnt, femaleCnt.
// Pre: maleCnt, femaleCnt have values, malePerc and femalePerc are declared and has values.
// Output: malePerc, femalePerc.
// Post: malePerc and femalePerc are assigned to their variables.
// Note: maleCnt, femaleCnt are both passed as float in order to get accurate float results in percentages.
//*********************************************

void printPrec(ofstream& outFile, float malePerc, float femalePerc);
//*********************************************
// Purpose: Prints males and females percentages.
// Input: malePerc, femalePerc.
// Pre: outFile is opened & ok. malePerc, femalePerc have values.
// Output: outFile.
// Post: males and females percentages are printed to outFile.
// Note: none.
//*********************************************

void selSort(Student studData[]);
//*********************************************
// Purpose: Sorting students based on their id's.
// Input: studData.
// Pre: Student structure is declared and valid, studData array has values.
// Output: studData.
// Post: Students in array of struct are sorted according to their id's.
// Note: none.
//*********************************************

void search(const Student studData[], int findId, int& findLoc, bool& found);
//*********************************************
// Purpose: Searching students based on their id's.
// Input: studData, findId, findLoc.
// Pre: Student structure is declared and valid, studData array has values.
//      findId has a value, findLoc and found are declared in the program.
// Output: found.
// Post: Changes the value of found to true if the id was found, otherwise to false.
// Note: none.
//*********************************************

void cntAvgMaleFemaleSum(const Student studData[], int& examAvgSum, int& maleCnt, int& femaleCnt);
//*********************************************
// Purpose: Counts avg sum, male and female counter to their variables.
// Input: studData.
// Pre: Student struct is defined properly and its variables have valid values..
// Output: examAvgSum, maleCnt, femaleCnt.
// Post: avg sum, male and female counter are assigned to their variables.
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
  Student studData[ARRAY_SIZE];
  int examAvgSum, findId, findLoc;
  int  examAvg, maleCnt, femaleCnt;
  float malePerc,femalePerc;
  maleCnt = femaleCnt = examAvgSum = 0;
  bool found;
  
  //doing main job in sequence
  printHeading(outFile);
  readRd(inFile, studData);
  assignAvgAndGrade(studData);
  printRd(outFile, studData);
  
  printHeadingSortedId(outFile);
  selSort(studData);
  printRd(outFile, studData);

  
  printHeadingSearch(outFile);
  inFile >> findId;
  while(inFile)
  {
    found = false;
    search(studData, findId, findLoc, found);
    if(found)
      printOneRd(outFile, studData, findLoc);
    else
      outFile << "**Student with id: " << findId << " Not found!" << endl;
    inFile >> findId;
  }
    
  cntAvgMaleFemaleSum(studData, examAvgSum, maleCnt, femaleCnt);
  printMeanOfAllAvg(outFile, examAvgSum);
  maleAndFemalePrec(maleCnt, femaleCnt, malePerc, femalePerc);
  printPrec(outFile, malePerc, femalePerc);
  
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
  outFile << "*~~< Stud Exam Report Unsorted>~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Sex" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Grade" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "---" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-----" << endl;
}//end function

void printHeadingSortedId(ofstream& outFile)
//*********************************************
// Purpose: Print heading for output file of the sorted by id.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading of the sorted by id is printed in outFile.
// Note: none.
//*********************************************

{
  outFile << endl << "*~~< Stud Exam Report Sorted By Id>~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Sex" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Grade" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "---" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-----" << endl;
}//end function

void printHeadingSearch(ofstream& outFile)
//*********************************************
// Purpose: Print heading for output file of the searched id's.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: Heading of the searched id's is printed in outFile.
// Note: none.
//*********************************************

{
  outFile << endl << "*~~< Searching From Exam Report >~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Sex" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Grade" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "---" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-----" << endl;
}//end function

void readRd(ifstream& inFile, Student studData[])
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. Student struct is defined properly.
// Output: studData.
// Post: variables of studData struct are stored to their variables via inFile.
// Note: none.
//*********************************************

{
  for (int i = 0; i < ARRAY_SIZE; i++)
    inFile >> studData[i].studName >> studData[i].studId >> studData[i].sex >> studData[i].exam1 >> studData[i].exam2 >> studData[i].exam3;
}//end function


void printRd(ofstream& outFile, const Student studData[])
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studData.
// Pre: outFile is opened & ok. Student struct is defined properly and its variables have valid values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3, avg and grade are printed in outFile.
// Note: none.
//*********************************************

{
  for (int i = 0; i < ARRAY_SIZE; i++)
    outFile << left << setw(20) <<  studData[i].studName << setw(10) << studData[i].studId << setw(10)
            << studData[i].sex << setw(10) << studData[i].exam1 << setw(10) << studData[i].exam2 
            << setw(15) << studData[i].exam3  << setw(15) << studData[i].examAvg  << studData[i].studGrade << endl;
  
  outFile << "< end >" << endl;
}//end function

void printOneRd(ofstream& outFile, const Student studData[], int i)
//*********************************************
// Purpose: Print one row of student and exams data.
// Input: studData, i.
// Pre: outFile is opened & ok. Student struct is defined properly and its variables have valid values, i has a valid data.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3, avg and grade of one record is printed in outFile.
// Note: none.
//*********************************************

{
    outFile << left << setw(20) <<  studData[i].studName << setw(10) << studData[i].studId << setw(10)
            << studData[i].sex << setw(10) << studData[i].exam1 << setw(10) << studData[i].exam2 
            << setw(15) << studData[i].exam3  << setw(15) << studData[i].examAvg  << studData[i].studGrade << endl;
}//end function

void assignAvgAndGrade(Student studData[])
//*********************************************
// Purpose: Calculates and assigns avg of 3 exams converted to the next integer and assigns its grade for each record.
// Input: studData.
// Pre: Student struct is defined properly and its variables have valid values.
// Output: studData.
// Post: The avg of 3 exams converted to the next integer and grades are assgined to the records in studData array.
// Note: none.
//*********************************************

{
  for (int i=0; i < ARRAY_SIZE; i++)
  {
    studData[i].examAvg = ceil((studData[i].exam1+studData[i].exam2+studData[i].exam3)/3);
    studData[i].studGrade = grade(studData[i].examAvg);
  }
}//end function

string grade(int examAvg)
//*********************************************
// Purpose: Returns the exams avg to Grades datatype.
// Input: examAvg.
// Pre: examAvg is valid and have data, datatype Grades is valid.
// Output: string.
// Post: Returns string value of Grades that matches exams Avg.
// Note: none.
//*********************************************

{
  string output;

  switch(examAvg)
  {
    case EXCELLENT_MIN ... EXCELLENT_MAX:
      output = "EXCELLENT";
    break;

    case GOOD_MIN ... GOOD_MAX:
      output = "GOOD";
    break;

    case OK_MIN ... OK_MAX:
      output = "OK";
    break;

    case WEAK_MIN ... WEAK_MAX:
      output = "WEAK";
    break;

    case FAILING_MIN ... FAILING_MAX:
      output = "FAILING";
    break;
  }//end switch

  return output;
}//end function

void printMeanOfAllAvg(ofstream& outFile, int examAvgSum)
//*********************************************
// Purpose: Prints the mean of all avg's.
// Input: examAvgSum.
// Pre: outFile is opened & ok, examAvgSum have values.
// Output: outFile.
// Post: the mean of all exams AVG's is printed to outFile.
// Note: none.
//*********************************************

{
  float meanOfAllAvg = float(examAvgSum)/float(ARRAY_SIZE);
  outFile << endl << ">> Mean of all AVG: " << meanOfAllAvg << endl;
}//end function


void maleAndFemalePrec(float maleCnt, float femaleCnt, float& malePerc, float& femalePerc)
//*********************************************
// Purpose: Assigning males and females percentages according to their count.
// Input: maleCnt, femaleCnt.
// Pre: maleCnt, femaleCnt have values, malePerc and femalePerc are declared and has values.
// Output: malePerc, femalePerc.
// Post: malePerc and femalePerc are assigned to their variables.
// Note: maleCnt, femaleCnt are both passed as float in order to get accurate float results in percentages.
//*********************************************

{
  malePerc = ((maleCnt/float(ARRAY_SIZE))*100.00);
  femalePerc = ((femaleCnt/float(ARRAY_SIZE))*100.00);
}//end function

void printPrec(ofstream& outFile, float malePerc, float femalePerc)
//*********************************************
// Purpose: Prints males and females percentages.
// Input: malePerc, femalePerc.
// Pre: outFile is opened & ok. malePerc, femalePerc have values.
// Output: outFile.
// Post: males and females percentages are printed to outFile.
// Note: none.
//*********************************************

{
  outFile << endl << ">> Male: %" << malePerc 
          << endl << ">> Female: %" << femalePerc << endl;
}//end function

void selSort(Student studData[])
//*********************************************
// Purpose: Sorting students based on their id's.
// Input: studData.
// Pre: Student structure is declared and valid, studData array has values.
// Output: studData.
// Post: Students in array of struct are sorted according to their id's.
// Note: none.
//*********************************************

{
  Student studTemp;
  int passCount, placeCount, minIndex;

  for(passCount = 0; passCount < ARRAY_SIZE-1; passCount++)
  {
    minIndex = passCount;

    for(placeCount = passCount + 1; placeCount < ARRAY_SIZE; placeCount++)
      if(studData[placeCount].studId < studData[minIndex].studId)
         minIndex = placeCount;

      studTemp = studData[minIndex];
      studData[minIndex] = studData[passCount];
      studData[passCount] = studTemp;
    }
}

void search(const Student studData[], int findId, int& findLoc, bool& found)
//*********************************************
// Purpose: Searching students based on their id's.
// Input: studData, findId, findLoc.
// Pre: Student structure is declared and valid, studData array has values.
//      findId has a value, findLoc and found are declared in the program.
// Output: found.
// Post: Changes the value of found to true if the id was found, otherwise to false.
// Note: none.
//*********************************************

{
  findLoc = 0;
  while(findLoc < ARRAY_SIZE && findId != studData[findLoc].studId)
    findLoc++;

  found = (findLoc < ARRAY_SIZE);
}


void cntAvgMaleFemaleSum(const Student studData[], int& examAvgSum, int& maleCnt, int& femaleCnt)
//*********************************************
// Purpose: Counts avg sum, male and female counter to their variables.
// Input: studData.
// Pre: Student struct is defined properly and its variables have valid values..
// Output: examAvgSum, maleCnt, femaleCnt.
// Post: avg sum, male and female counter are assigned to their variables.
// Note: none.
//*********************************************

{
  examAvgSum = 0; 
  maleCnt = 0;
  femaleCnt = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    examAvgSum = examAvgSum + studData[i].examAvg;
    if (studData[i].sex == 'M')
      maleCnt = maleCnt +1;
    else
      femaleCnt = femaleCnt + 1;
  }
}