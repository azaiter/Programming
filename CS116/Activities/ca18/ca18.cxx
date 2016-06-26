#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 10;

struct stud
{
   int id;
   char sex;
};

void getData(ifstream& inFile, stud studArr[]);
void selSort(stud studArr[]);
void printData(ofstream& outFile, const stud studArr[]);
int numOfFemale(const stud studArr[]);
void search(const stud studArr[], int key, int& findLoc, bool& found);

int main()
{
    ofstream outFile;
    ifstream inFile;
    inFile.open("ArrStrin");
    outFile.open("ArrStrout");

    int index;
    stud studArr[ARRAY_SIZE];

    int findLoc, key;
    bool found;

    outFile << "*~~< Student Grade Report >~~*" << endl << endl;
    outFile << "Stud Id" << setw(10) << "Sex" << endl;
    outFile << "-------" << setw(10) << "---" << endl;

    getData(inFile, studArr);
    selSort(studArr);
    printData(outFile, studArr);
    outFile << endl << "Number of Female: "
            << numOfFemale(studArr) << endl << endl;







    inFile >> key;
    while(inFile)
    {
       found = false;
       search(studArr, key, findLoc, found);

       if(found)
       {
          outFile << "Student with id: " << key << " Sex is: "
                       << studArr[findLoc].sex << endl;
       }
       else
         outFile << "Student with id: " << key << " Not found!" << endl;

       inFile >> key;
    }


    outFile << endl << "*< end >*" << endl;

    return 0;
}

void getData(ifstream& inFile, stud studArr[]) // passing array of struct - passed by ref automatically
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        inFile >> studArr[i].id >> studArr[i].sex;
}

void selSort(stud studArr[])
{
  stud studTemp;
  int passCount, placeCount, minIndex;

  for(passCount = 0; passCount < ARRAY_SIZE-1; passCount++)
  {
    minIndex = passCount;

    for(placeCount = passCount + 1; placeCount < ARRAY_SIZE; placeCount++)
      if(studArr[placeCount].id < studArr[minIndex].id)
         minIndex = placeCount;

      studTemp = studArr[minIndex];
      studArr[minIndex] = studArr[passCount];
      studArr[passCount] = studTemp;
    }

}





void printData(ofstream& outFile, const stud studArr[]) // const = pass by value
{
    for(int i = 0; i<ARRAY_SIZE; i++)
       outFile << studArr[i].id << setw(12) << studArr[i].sex << endl;
}

int numOfFemale(const stud studArr[])
{
   int count = 0;

   for (int i = 0; i<ARRAY_SIZE; i++)
      if(studArr[i].sex  == 'F')
         ++count;

   return count;
}


void search(const stud studArr[], int key, int& findLoc, bool& found)
{
  findLoc = 0;
  while(findLoc < ARRAY_SIZE && key != studArr[findLoc].id)
    findLoc++;

  found = (findLoc < ARRAY_SIZE); //if not found will be false
}

