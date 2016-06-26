#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

const int NAME_SIZE = 21;
const int CLASS_SIZE = 10;

typedef char Name[NAME_SIZE];

void GetData(ifstream&, Name nameList[], float exam[], int);
void SelSort(Name nameList[], float exam[], int);
void PrintData(ofstream&, const Name nameList[], const float exam[], int);

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("nameout");
    inFile.open("namein");

    Name nameList[CLASS_SIZE];
    float exam[CLASS_SIZE];

    GetData(inFile, nameList, exam, CLASS_SIZE);

    outFile << "<<<*** Unsorted Data ***>>>" << endl;
    outFile << "N  a  m  e" << "\t\t" << "E x m e" << endl;
    outFile << "----------" << "\t\t" << "-------" << endl;
    PrintData(outFile, nameList, exam, CLASS_SIZE);

    SelSort(nameList, exam, CLASS_SIZE);

    outFile << "<<<*** Sorted Data ***>>>" << endl;
    outFile << "N  a  m  e" << "\t\t" << "E x m e" << endl;
    outFile << "----------" << "\t\t" << "-------" << endl;
    PrintData(outFile, nameList, exam, CLASS_SIZE);

    return 0;
}

void GetData(ifstream& inFile, Name nameList[], float exam[], int MAX)
{
        int i;

        for (i = 0; i < MAX; i++)
        {
                inFile.get(nameList[i], 21);
                inFile.ignore(80, '\n');
                inFile >> exam[i];
                inFile.ignore(80, '\n');
        }
}

void PrintData(ofstream& f, const Name nameList[], const float exam[], int MAX)
{
        int i;

        for (i = 0; i < MAX; i++)
                f << nameList[i] << "\t\t" << exam[i] << endl;

}





void SelSort(Name nameList[], float exam[], int length)
{
   Name     temp1;              // Temporary variable for name
   float    temp2;              // Temporary variable for exam
   int      passCount;          // Loop control variable
   int      placeCount;         // Loop control variable
   int      minIndex;           // Index of minimum so far

	//principle is same, sorting by name
	//you need 2 swaps this time, one for name and one for exam
	//

   for (passCount = 0; passCount < length - 1; passCount++)
   {
     minIndex = passCount;

     for (placeCount = passCount + 1; placeCount < length; placeCount++)

        if (strcmp(nameList[placeCount], nameList[minIndex]) < 0)
           minIndex = placeCount;

     strcpy(temp1, nameList[minIndex]);
     strcpy(nameList[minIndex], nameList[passCount]);
     strcpy(nameList[passCount], temp1);
     
     temp2 = exam[minIndex];
     exam[minIndex] = exam[passCount];
     exam[passCount] = temp2;

   }
}

