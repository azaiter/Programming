#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int CLASS_SIZE = 10;

void GetData(ifstream& inFile, int id[]);
void SelSort(int id[]);
void PrintData(ofstream& f, const int id[]);

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("out");
    inFile.open("in");

    int id[CLASS_SIZE];

    GetData(inFile, id);

    outFile << "< Unsorted ID >" << endl;
    PrintData(outFile, id);

    SelSort(id);

    outFile << "< Sorted ID >" << endl;
    PrintData(outFile, id);

    return 0;
}

void GetData(ifstream& inFile, int id[])
{
        int i;
        for (i = 0; i < CLASS_SIZE; i++)
                inFile >> id[i];
}

void PrintData(ofstream& f, const int id[])
{
        int i;
        for (i = 0; i < CLASS_SIZE; i++)
                f << id[i] << endl;

}




void SelSort(int id[])
{
   int      temp;               // Temporary variable for id
   int      passCount;          // Loop control variable
   int      placeCount;         // Loop control variable
   int      minIndex;           // Index of minimum so far

   for (passCount = 0; passCount < CLASS_SIZE - 1; passCount++) //as many elements u have
   {
     minIndex = passCount;

     for (placeCount = passCount + 1; placeCount < CLASS_SIZE; placeCount++) // does the trick and swaps

        if (id[placeCount] < id[minIndex])
           minIndex = placeCount;

     temp = id[minIndex];
     id[minIndex] = id[passCount];
     id[passCount] = temp;

   }
}

