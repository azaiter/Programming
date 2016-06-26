// prog9.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #9
//
// DUE DATE: 11-05-2015
//
// POSSIBLE POINTS: 40 Points
//
// PURPOSE:
//  a program that reads records of name, id, male or female and exams data from an input file and
//  it calculates the average of exams data, determining if they pass or not, calculates the percentage
//  of male and females, and the destrubution of students, top exam performance and writes
//  data on a well aligned output file using functions.
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
const int A_MAX = 100;
const int A_MIN = 90;
const int B_MAX = 89;
const int B_MIN = 80;
const int C_MAX = 79;
const int C_MIN = 70;
const int D_MAX = 69;
const int D_MIN = 60;
const int F_MAX = 59;
const int F_MIN = 0;

bool filesCheck(ofstream& outFile, ifstream& inFile);
//*********************************************
// Purpose: Checks if either input or output files exists.
// Input: none.
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

void readRd(ifstream& inFile, string& studName, int& studId, char& sex, float& exam1, float& exam2, float& exam3);
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: studName, studId, exam1, exam2, exam3.
// Post: studName, studId, sex, exam1, exam2, exam3 are stored to their variables via inFile.
// Note: none.
//*********************************************

bool validData(int studId, char sex, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Checks if exam and student id are valid.
// Input: studId, sex, exam1, exam2, exam3.
// Pre: studId, sex, exam1, exam2, exam3 have values.
// Output: bool.
// Post: Returns True if data are valid, false is not.
// Note: none.
//*********************************************

void printRd(ofstream& outFile, string studName, int studId, char sex, float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studName, studId, sex, exam1, exam2, exam3.
// Pre: outFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3 are printed in outFile.
// Note: none.
//*********************************************

float avg(float exam1, float exam2, float exam3);
//*********************************************
// Purpose: Calculates avg of 3 exams converted to the next integer.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2, exam3 are valid and have data.
// Output: float.
// Post: The avg of 3 exams converted to the next integer is returned.
// Note: none.
//*********************************************

void printAvgAndGrade(ofstream& outFile, int examAvg, char studGrade);
//*********************************************
// Purpose: Prints student avg and letter grade data.
// Input: examAvg, studGrade.
// Pre: outFile is opened & ok. examAvg, studGrade are valid and have data.
// Output: outFile.
// Post: Avg and grade letter are printed to outFile.
// Note: none.
//*********************************************

char grade(int examAvg);
//*********************************************
// Purpose: Returns the exams avg to letter grading.
// Input: examAvg.
// Pre: examAvg is valid and have data.
// Output: char.
// Post: Letter of grading is returned, grades are: A,B,C,D,F.
// Note: none.
//*********************************************

void printInvalidDataMsg(ofstream& outFile);
//*********************************************
// Purpose: Prints invalid data line.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: "~~ Invalid data ~~" line is printed in outFile.
// Note: none.
//*********************************************

void countGrades(char studGrade, int& cntA, int& cntB, int& cntC, int& cntD, int& cntF);
//*********************************************
// Purpose: Depending on the input, grade count is increased by one.
// Input: studGrade.
// Pre: studGrade has value and valid grade, cnt A,B,C,D,F has values.
// Output: cntA, cntB, cntC, cntD, cntF.
// Post: Count of one of the grades cnt variables is ancreased by one, depending on the input.
// Note: none.
//*********************************************

void assignTopExam(float exam1, float exam2, float exam3, float& examTop);
//*********************************************
// Purpose: Assigning top exam value "if possible" to the examTop Variable.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2,exam3 has values, examTop is declared and has value.
// Output: examTop.
// Post: either exam1 or exam2 or exam3 is assigned to examtop if one or more of them is larger than examTop.
// Note: none.
//*********************************************

void assignTopAvg(int studId, float examAvg, float& examAvgTop, int& examAvgTopId);
//*********************************************
// Purpose: Assigning top avg value "if possible" to the examAvgTop Variable in parallel with examAvgTopId.
// Input: studId, examAvg.
// Pre: studId examAvg has values, examAvgTop and examAvgTopId are declared and has value.
// Output: examAvgTop, examAvgTopId.
// Post: examAvgTop is assigned as examAvg and examAvgTopId as studId Only if examAvg > examAvgTop.
// Note: none.
//*********************************************

void maleAndFemalePrec(float studCnt, float maleCnt, float femaleCnt, float& malePerc, float& femalePerc);
//*********************************************
// Purpose: Assigning males and females percentages according to their count.
// Input: studCnt, maleCnt, femaleCnt.
// Pre: studCnt, maleCnt, femaleCnt have values, malePerc and femalePerc are declared and has values.
// Output: malePerc, femalePerc.
// Post: malePerc and femalePerc are assigned to their variables.
// Note: maleCnt, femaleCnt are both passed as float in order to get accurate float results in percentages.
//*********************************************

void printBarChart(ofstream& outFile, int studCnt, int cntA, int cntB, int cntC, int cntD, int cntF);
//*********************************************
// Purpose: Prints Grade Destitution Bar Chart.
// Input: studCnt, cntA, cntB, cntC, cntD, cntF.
// Pre: outFile is opened & ok. studCnt, cntA, cntB, cntC, cntD, cntF have values.
// Output: outFile.
// Post: grade destitution bar chart is printed to outFile.
// Note: none.
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

void printBets(ofstream& outFile, float examTop, float examAvgTop, int examAvgTopId);
//*********************************************
// Purpose: Prints top exam performance and top avg with its student id.
// Input: examTop, examAvgTop.
// Pre: outFile is opened & ok. examTop, examAvgTop have values.
// Output: outFile.
// Post: top exam performance and top avg with its student id are printed to outFile.
// Note: none.
//*********************************************

void printNoValidDataForTopAndPerc(ofstream& outFile);
//*********************************************
// Purpose: Prints an error message if there is no valid exam records.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: the meaning of "No valid student data in file to evaluate chart, percentages and top exam and avg" is printed to outFile.
// Note: none.
//*********************************************

int main()
{
  //defining streams and opening files
  ofstream outFile;
  ifstream inFile;
  outFile.open("out.data");
  inFile.open("in.data");

  //file checks
  if (!filesCheck(outFile, inFile))
    return 1;//endif

  //setting numbers after decimal point to 2
  setPrecision(outFile, 2);

  //declaring variables
  int studId,examAvgTopId;
  int maleCnt, femaleCnt, studCnt, cntA, cntB, cntC, cntD, cntF;
  maleCnt = femaleCnt = studCnt = cntA = cntB = cntC = cntD = cntF = 0;
  float exam1,exam2,exam3,examAvg,examTop,examAvgTop,malePerc,femalePerc;
  string studName;
  char sex;

  //outputting intial aligned heading
  printHeading(outFile);

  //inputing data from file and do the loop
  readRd(inFile, studName, studId, sex, exam1, exam2, exam3);
  //intializing top values, I found that intializing with 0 is best for top.
  examTop = 0.00;
  examAvgTop = 0.00;

  while (inFile)
  {
    char studGrade;
    //print intial data
    printRd(outFile, studName, studId, sex, exam1, exam2, exam3);
    //this if statment well determine the validity of student id, sex, and exams.
    //if not, it will show invalid data error
    if(validData(studId, sex, exam1, exam2, exam3))
    {
      //calcualting the average
      examAvg = avg(exam1, exam2, exam3);
      studCnt++;
      if (sex == 'M')
        maleCnt++;
      else
        femaleCnt++;//end if
      studGrade = grade(int(examAvg));
      countGrades(studGrade, cntA, cntB, cntC, cntD, cntF);
      assignTopExam(exam1,exam2,exam3,examTop);
      assignTopAvg(studId,examAvg,examAvgTop,examAvgTopId);
      //outputting Passed Failed data
      printAvgAndGrade(outFile, int(examAvg), studGrade);
    }
    else
      printInvalidDataMsg(outFile);//end if

    //re-reading the input data
    readRd(inFile, studName, studId, sex, exam1, exam2, exam3);
  }//end While

  if (studCnt > 0)
  {
     maleAndFemalePrec(studCnt, maleCnt, femaleCnt, malePerc, femalePerc);
     printBarChart(outFile, studCnt, cntA, cntB, cntC, cntD, cntF);
     printPrec(outFile, malePerc, femalePerc);
     printBets(outFile, examTop, examAvgTop, examAvgTopId);
  }
  else
    printNoValidDataForTopAndPerc(outFile);//end if

  outFile << endl << "*< end >*" << endl;

  //closing input and output files
  inFile.close();
  outFile.close();

  return 0;
}//end function


bool filesCheck(ofstream& outFile, ifstream& inFile)
//*********************************************
// Purpose: Checks if either input or output files exists.
// Input: none.
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
  outFile << "*~~< Stud Exam Report >~~*" << endl;
  outFile << left << setw(20) <<  "Name" << setw(10) << "Stud Id" << setw(10) << "Sex" << setw(10) << "Exam 1" << setw(10) << "Exam 2"
          << left << setw(15) << "Exam 3"  << setw(15) << "AVG of Exams"  << "Grade" << endl;
  outFile << left << setw(20) <<  "----" << setw(10) << "-------" << setw(10) << "---" << setw(10) << "------" << setw(10) << "------"
          << left << setw(15) << "------"  << setw(15) << "------------"  << "-----" << endl;
}//end function

void readRd(ifstream& inFile, string& studName, int& studId, char& sex, float& exam1, float& exam2, float& exam3)
//*********************************************
// Purpose: Reads exams data from input file.
// Input: inFile.
// Pre: inFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: studName, studId, exam1, exam2, exam3.
// Post: studName, studId, sex, exam1, exam2, exam3 are stored to their variables via inFile.
// Note: none.
//*********************************************

{
  inFile >> studName >> studId >> sex >> exam1 >> exam2 >> exam3;
}//end function

bool validData(int studId, char sex, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Checks if exam and student id are valid.
// Input: studId, sex, exam1, exam2, exam3.
// Pre: studId, sex, exam1, exam2, exam3 have values.
// Output: bool.
// Post: Returns True if data are valid, false is not.
// Note: none.
//*********************************************

{
  if((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX) &&
     (exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (studId >= ID_MIN && studId <= ID_MAX) &&
     (sex == 'M' || sex == 'F'))
    return 1;
  else
    return 0;//end if
}//end function

void printRd(ofstream& outFile, string studName, int studId, char sex, float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Print intial row of student and exams data.
// Input: studName, studId, sex, exam1, exam2, exam3.
// Pre: outFile is opened & ok. studName, studId, sex, exam1, exam2, exam3 have values.
// Output: outFile.
// Post: Student name, id, sex, exam 1, exam 2, exam3 are printed in outFile.
// Note: none.
//*********************************************

{
  outFile << left << setw(20) <<  studName << setw(10) << studId << setw(10)
          << sex << setw(10) << exam1 << setw(10) << exam2 << setw(15) << exam3  << setw(15);
}//end function

float avg(float exam1, float exam2, float exam3)
//*********************************************
// Purpose: Calculates avg of 3 exams converted to the next integer.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2, exam3 are valid and have data.
// Output: float.
// Post: The avg of 3 exams converted to the next integer is returned.
// Note: none.
//*********************************************

{
  return ceil((exam1+exam2+exam3)/3);
}//end function

void printAvgAndGrade(ofstream& outFile, int examAvg, char studGrade)
//*********************************************
// Purpose: Prints student avg and letter grade data.
// Input: examAvg, studGrade.
// Pre: outFile is opened & ok. examAvg, studGrade are valid and have data.
// Output: outFile.
// Post: Avg and grade letter are printed to outFile.
// Note: none.
//*********************************************

{
  outFile << examAvg << studGrade << endl;
}//end function

void printInvalidDataMsg(ofstream& outFile)
//*********************************************
// Purpose: Prints invalid data line.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: "~~ Invalid data ~~" line is printed in outFile.
// Note: none.
//*********************************************

{
  outFile << "~~ Invalid data ~~" << endl;
}//end function

char grade(int examAvg)
//*********************************************
// Purpose: Returns the exams avg to letter grading.
// Input: examAvg.
// Pre: examAvg is valid and have data.
// Output: char.
// Post: Letter of grading is returned, grades are: A,B,C,D,F.
// Note: none.
//*********************************************

{
  char output;

  switch(examAvg)
  {
    case A_MIN ... A_MAX:
      output = 'A';
    break;

    case B_MIN ... B_MAX:
      output = 'B';
    break;

    case C_MIN ... C_MAX:
      output = 'C';
    break;

    case D_MIN ... D_MAX:
      output = 'D';
    break;

    case F_MIN ... F_MAX:
      output = 'F';
    break;
  }//end switch

  return output;
}//end function

void countGrades(char studGrade, int& cntA, int& cntB, int& cntC, int& cntD, int& cntF)
//*********************************************
// Purpose: Depending on the input, grade count is increased by one.
// Input: studGrade.
// Pre: studGrade has value and valid grade, cnt A,B,C,D,F has values.
// Output: cntA, cntB, cntC, cntD, cntF.
// Post: Count of one of the grades cnt variables is ancreased by one, depending on the input.
// Note: none.
//*********************************************

{
  switch(studGrade)
  {
    case 'A':
      cntA++;
    break;

    case 'B':
      cntB++;
    break;

    case 'C':
      cntC++;
    break;

    case 'D':
      cntD++;
    break;

    case 'F':
      cntF++;
    break;
  }//end switch
}//end function

void assignTopExam(float exam1, float exam2, float exam3, float& examTop)
//*********************************************
// Purpose: Assigning top exam value "if possible" to the examTop Variable.
// Input: exam1, exam2, exam3.
// Pre: exam1, exam2,exam3 has values, examTop is declared and has value.
// Output: examTop.
// Post: either exam1 or exam2 or exam3 is assigned to examtop if one or more of them is larger than examTop.
// Note: none.
//*********************************************

{
  if (exam1 > examTop)
    examTop = exam1;//endif

  if (exam2 > examTop)
    examTop = exam2;//endif

  if (exam3 > examTop)
    examTop = exam3;//endif
}//end funciton

void assignTopAvg(int studId, float examAvg, float& examAvgTop, int& examAvgTopId)
//*********************************************
// Purpose: Assigning top avg value "if possible" to the examAvgTop Variable in parallel with examAvgTopId.
// Input: studId, examAvg.
// Pre: studId examAvg has values, examAvgTop and examAvgTopId are declared and has value.
// Output: examAvgTop, examAvgTopId.
// Post: examAvgTop is assigned as examAvg and examAvgTopId as studId Only if examAvg > examAvgTop.
// Note: none.
//*********************************************

{
  if (examAvg > examAvgTop)
  {
    examAvgTop = examAvg;
    examAvgTopId = studId;
  }//end if
}//end function

void maleAndFemalePrec(float studCnt, float maleCnt, float femaleCnt, float& malePerc, float& femalePerc)
//*********************************************
// Purpose: Assigning males and females percentages according to their count.
// Input: studCnt, maleCnt, femaleCnt.
// Pre: studCnt, maleCnt, femaleCnt have values, malePerc and femalePerc are declared and has values.
// Output: malePerc, femalePerc.
// Post: malePerc and femalePerc are assigned to their variables.
// Note: maleCnt, femaleCnt are both passed as float in order to get accurate float results in percentages.

{
  malePerc = ((maleCnt/studCnt)*100.00);
  femalePerc = ((femaleCnt/studCnt)*100.00);
}//end function

void printBarChart(ofstream& outFile, int studCnt, int cntA, int cntB, int cntC, int cntD, int cntF)
//*********************************************
// Purpose: Prints Grade Destitution Bar Chart.
// Input: studCnt, cntA, cntB, cntC, cntD, cntF.
// Pre: outFile is opened & ok. studCnt, cntA, cntB, cntC, cntD, cntF have values.
// Output: outFile.
// Post: grade destitution bar chart is printed to outFile.
// Note: none.
//*********************************************

{
  string starsForGrade = "****";

  outFile << endl << "Grade Destitution Bar Chart" << endl << "A|";

  for (int i = 1; i <= cntA; i++)
    outFile << starsForGrade;//end for

  outFile << endl << "B|";

  for (int i = 1; i <= cntB; i++)
    outFile << starsForGrade;//end for

  outFile << endl << "C|";

  for (int i = 1; i <= cntC; i++)
    outFile << starsForGrade;//end for

  outFile << endl << "D|";

  for (int i = 1; i <= cntD; i++)
    outFile << starsForGrade;//end for

  outFile << endl << "F|";

  for (int i = 1; i <= cntF; i++)
    outFile << starsForGrade;//end for

  outFile << endl;
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
  outFile << endl << ">> Female: " << femalePerc << "%"
          << endl << ">> Male: " << malePerc << "%" << endl;
}//end function

void printBets(ofstream& outFile, float examTop, float examAvgTop, int examAvgTopId)
//*********************************************
// Purpose: Prints top exam performance and top avg with its student id.
// Input: examTop, examAvgTop.
// Pre: outFile is opened & ok. examTop, examAvgTop have values.
// Output: outFile.
// Post: top exam performance and top avg with its student id are printed to outFile.
// Note: none.
//*********************************************

{
  outFile << endl << ">> The top exam performance for this semester  is: " << examTop << "%" << endl
          << ">> The top avg of exams is for student with ID " << examAvgTopId
          << " & avg was " << int(examAvgTop) << "%" << endl;
}//end function

void printNoValidDataForTopAndPerc(ofstream& outFile)
//*********************************************
// Purpose: Prints an error message if there is no valid exam records.
// Input: none.
// Pre: outFile is opened & ok.
// Output: outFile.
// Post: the meaning of "No valid student data in file to evaluate chart, percentages and top exam and avg" is printed to outFile.
// Note: none.
//*********************************************

{
  outFile << endl << "No Valid students data in file to evaluate grade distribution chart, "
          << "male and female percentage and top exam and avg perfomance." << endl;
}//end function
