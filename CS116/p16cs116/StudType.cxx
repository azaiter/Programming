// fill functions and add 3pio

//** make exam max and exam min exam avg as void function to find and put them, and for printing 
// desgin a function to print them

//StudType.cxx
#include "StudType.h"
//CONSTANTS IN SPECIFICATION FILE

StudType::StudType()
//*******************************************
//Purpose: Initializes private data to default values
//Input: None
//Pre: None
//Output: None
//Post: Private data initialized to default values
//Note: None
//*******************************************
{
  //default
  id = -111;
  exam1 = -100.00;
  exam2 = -100.00;
  exam3 = -100.00;
  max = -11.00;
  min = -1.00;
  avg = -111.00;
  passOrFail = 'Z';
}

StudType::StudType(int inId, float inE1,  float inE2,  float inE3)
//*******************************************
//Purpose: Initializes private data to incoming values
//Input: inId, inE1, inE2, inE3
//Pre: inId, inE1, inE2, inE3 have values
//Output: none
//Post: private data intialized to incoming values
//Note: None
//*******************************************
{
  //intializor
  id = inId;
  exam1 = inE1;
  exam2 = inE2;
  exam3 = inE3;
}

void StudType::setRd(int inId, float inE1,  float inE2,  float inE3)
//*******************************************
//Purpose: Initializes private data to incoming values
//Input: inId, inE1, inE2, inE3
//Pre: inId, inE1, inE2, inE3 have values
//Output: none
//Post: private data intialized to incoming values
//Note: None
//*******************************************

{
  id = inId;
  exam1 = inE1;
  exam2 = inE2;
  exam3 = inE3;
}

int StudType::getId()
//*******************************************
//Purpose: It Retruns ID
//Input: none
//Pre: object is created.
//Output: int
//Post: return the private data id
//Note: None
//*******************************************

{
  return id;
}

float StudType::getExam1()
//*******************************************
//Purpose: It Retruns exam1
//Input: none
//Pre: object is created.
//Output: float
//Post: return the private data exam1
//Note: None
//*******************************************

{
  return exam1;
}

float StudType::getExam2()
//*******************************************
//Purpose: It Retruns exam2
//Input: none
//Pre: object is created.
//Output: float
//Post: return the private data exam2
//Note: None
//*******************************************

{
  return exam2;
}

float StudType::getExam3()
//*******************************************
//Purpose: It Retruns exam3
//Input: none
//Pre: object is created.
//Output: float
//Post: return the private data exam3
//Note: None
//*******************************************

{
  return exam3;
}

bool StudType::validRd()
//*******************************************
//Purpose: determine if private data are valid
//Input: none
//Pre: none
//Output: bool
//Post: return true if data are valid, otherwise false
//Note: None
//*******************************************

{
  return((exam1 >= EXAM_MIN && exam1 <= EXAM_MAX) && (exam2 >= EXAM_MIN && exam2 <= EXAM_MAX) &&
     (exam3 >= EXAM_MIN && exam3 <= EXAM_MAX) && (id >= ID_MIN && id <= ID_MAX));
}

void StudType::findMax()
//*******************************************
//Purpose: find max of exams 
//Input: none
//Pre: valid data are stored in private data
//Output: none
//Post: max is set to the maximum exam score
//Note: None
//*******************************************

{
  max = ( exam1 < exam2 ) ? exam2 : exam1;
  max = ( max < exam3 ) ? exam3 : max;
}

void StudType::findMin()
//*******************************************
//Purpose: find min of exams 
//Input: none
//Pre: valid data are stored in private data
//Output: none
//Post: min is set to the maximum exam score
//Note: None
//*******************************************

{
  min = (( exam1 > exam2 ) ? exam2 : exam1);
  min = ( ( max > exam3 ) ? exam3 : max );
}

void StudType::findAvg()
//*******************************************
//Purpose: find avg of exams
//Input: none
//Pre: valid data are stored in private data
//Output: none
//Post: avg is set to the avg of exams
//Note: None
//*******************************************

{
  avg = ((exam1+exam2+exam3)/3);
}

void StudType::findPassOrFail()
//*******************************************
//Purpose: finds either the student's score is Pass or Fail
//Input: none
//Pre: valid data are stored in private data
//Output: none
//Post: P is assigned to passOrFail if passing, otherwise F if failing.
//Note: None
//*******************************************

{
  if (avg >= PASS_SCORE)
  {
    passOrFail = 'P';
  }
  else
  {
    passOrFail = 'F';
  }
}

void StudType::printInvalidMsg(ofstream& outFile)
//*******************************************
//Purpose: print the invalid data message
//Input: none
//Pre: invalid data are stored in private data, outFile is opened & ok
//Output: outFile.
//Post: the output file contains invalid data message
//Note: None
//*******************************************

{
  outFile << "~~ Invalid data! ~~" << endl;
}

void StudType::readRd(ifstream& inFile)
//*******************************************
//Purpose: reads students data and store it.
//Input: inFile
//Pre: inFile is opened & ok.
//Output: none
//Post: student data is stored.
//Note: None
//*******************************************

{
  inFile >> id >> exam1 >> exam2 >> exam3;
}

void StudType::writeRd(ofstream& outFile)
//*******************************************
//Purpose: writes intial line of student data
//Input: none
//Pre: outFile is opened & ok, data stored in private data.
//Output: outFile.
//Post: intial line of student data is outputted in outFile stream.
//Note: None
//*******************************************

{
  outFile << left  << setw(10) << id << setw(10)
          << exam1 << setw(10) << exam2 << setw(15) << exam3  << setw(15);

}

void StudType::writeMaxMinAvgPOrF(ofstream& outFile)
//*******************************************
//Purpose: writes max, min, avg and passing or failing to student data.
//Input: none
//Pre: outFile is opened & ok, data stored in private data.
//Output: outFile.
//Post: max, min, avg and passing or failing is outputted in outFile stream.
//Note: None
//*******************************************

{
  if (StudType::validRd())
    outFile << setw(10) << max << setw(10) << min << setw(10) << avg << setw(10) << passOrFail << endl;
  else
    StudType::printInvalidMsg(outFile);
}