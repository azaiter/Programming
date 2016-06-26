//StudType.h
#include <fstream>
#include <iostream>
#include <iomanip>

const float EXAM_MAX = 100.00;
const float EXAM_MIN = 0.00;
const int ID_MAX = 999;
const int ID_MIN = 111;
const float PASS_SCORE = 70.00;


using namespace std;

class StudType
{
  public:
  
  //first constructor
    StudType();
    //*******************************************
    //Purpose: Initializes private data to default values
    //Input: None
    //Pre: None
    //Output: None
    //Post: Private data initialized to default values
    //Note: None
    //*******************************************

    //SECOND CONSTRUCTOR -- they will be excuted first when u intialize itg
    StudType(int inId, float inE1, float inE2, float inE3);
    //*******************************************
    //Purpose: Initializes private data to incoming values
    //Input: inId, inE1, inE2, inE3
    //Pre: inId, inE1, inE2, inE3 have values
    //Output: none
    //Post: private data intialized to incoming values
    //Note: None
    //*******************************************

    void setRd(int inId, float inE1, float inE2, float inE3);
    //*******************************************
    //Purpose: Initializes private data to incoming values
    //Input: inId, inE1, inE2, inE3
    //Pre: inId, inE1, inE2, inE3 have values
    //Output: none
    //Post: private data intialized to incoming values
    //Note: None
    //*******************************************

   int getId();
    //*******************************************
    //Purpose: It Retruns ID
    //Input: none
    //Pre: object is created.
    //Output: int
    //Post: return the private data id
    //Note: None
    //*******************************************

   float getExam1();
    //*******************************************
    //Purpose: It Retruns exam1
    //Input: none
    //Pre: object is created.
    //Output: float
    //Post: return the private data exam1
    //Note: None
    //*******************************************

    float getExam2();
    //*******************************************
    //Purpose: It Retruns exam2
    //Input: none
    //Pre: object is created.
    //Output: float
    //Post: return the private data exam2
    //Note: None
    //*******************************************

    float getExam3();
    //*******************************************
    //Purpose: It Retruns exam3
    //Input: none
    //Pre: object is created.
    //Output: float
    //Post: return the private data exam3
    //Note: None
    //*******************************************

    bool validRd();
    //*******************************************
    //Purpose: determine if private data are valid
    //Input: none
    //Pre: none
    //Output: bool
    //Post: return true if data are valid, otherwise false
    //Note: None
    //*******************************************

    void findMax();
    //*******************************************
    //Purpose: find max of exams 
    //Input: none
    //Pre: valid data are stored in private data
    //Output: none
    //Post: max is set to the maximum exam score
    //Note: None
    //*******************************************

    void findMin();
    //*******************************************
    //Purpose: find min of exams 
    //Input: none
    //Pre: valid data are stored in private data
    //Output: none
    //Post: min is set to the maximum exam score
    //Note: None
    //*******************************************

    void findAvg();
    //*******************************************
    //Purpose: find avg of exams
    //Input: none
    //Pre: valid data are stored in private data
    //Output: none
    //Post: avg is set to the avg of exams
    //Note: None
    //*******************************************

    void findPassOrFail();
    //*******************************************
    //Purpose: finds either the student's score is Pass or Fail
    //Input: none
    //Pre: valid data are stored in private data
    //Output: none
    //Post: P is assigned to passOrFail if passing, otherwise F if failing.
    //Note: None
    //*******************************************

    void printInvalidMsg(ofstream& outFile);
    //*******************************************
    //Purpose: print the invalid data message
    //Input: none
    //Pre: invalid data are stored in private data, outFile is opened & ok
    //Output: outFile.
    //Post: the output file contains invalid data message
    //Note: None
    //*******************************************

    void readRd(ifstream& inFile);
    //*******************************************
    //Purpose: reads students data and store it.
    //Input: inFile
    //Pre: inFile is opened & ok.
    //Output: none
    //Post: student data is stored.
    //Note: None
    //*******************************************

    void writeRd(ofstream& outFile);
    //*******************************************
    //Purpose: writes intial line of student data
    //Input: none
    //Pre: outFile is opened & ok, data stored in private data.
    //Output: outFile.
    //Post: intial line of student data is outputted in outFile stream.
    //Note: None
    //*******************************************

    void writeMaxMinAvgPOrF(ofstream& outFile);
    //*******************************************
    //Purpose: writes max, min, avg and passing or failing to student data.
    //Input: none
    //Pre: outFile is opened & ok, data stored in private data.
    //Output: outFile.
    //Post: max, min, avg and passing or failing is outputted in outFile stream.
    //Note: None
    //*******************************************

    char passOrFail;

  private:
    int id;
    float exam1, exam2, exam3, max, min, avg;
    
};