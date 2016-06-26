#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 3;
const int NUM_COLS = 3;
const int INITILZ_VALUE = -99;
typedef int TableType [NUM_ROWS][NUM_COLS];

void Initialize(int [][NUM_COLS]);
void PrintTable(ofstream&, const TableType);
void GetData(ifstream&, TableType);
void AddRows(const TableType, int&);
void AddColumns(const TableType, int&);

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("twod1out");
    inFile.open("twod1in");

    int sumOfRows = 0;
    int sumOfColumns = 0;

    TableType table;

    Initialize(table);
    outFile << "<*----- Initialized Table -----*>" << endl;
    PrintTable(outFile, table);

    GetData(inFile, table);

    outFile << "<*----- Table Contents -----*>" << endl;
    PrintTable(outFile, table);

    AddRows(table, sumOfRows);
    outFile << endl << "The Sum Of The Rows: " << sumOfRows << endl;

    AddColumns(table, sumOfColumns);
    outFile << "The Sum Of The Columns: " << sumOfColumns << endl << endl;
    outFile << "\t>*--- End---*<" << endl;

    return 0;
}






void Initialize(TableType table)
{
        int row;
        int col;

        for (row = 0; row < NUM_ROWS; row++)
                for (col = 0; col < NUM_COLS; col++)
  	table[row][col] = INITILZ_VALUE;
}

void GetData(ifstream& inFile, TableType table)
{
        int row;
        int col;

        for (row = 0; row < NUM_ROWS; row++)
                for (col = 0; col < NUM_COLS; col++)
                        inFile >> table[row][col];

}

void PrintTable(ofstream& f, const TableType table)
{
        int row;
        int col;

        for (row = 0; row < NUM_ROWS; row++)
        {
                for (col = 0; col < NUM_COLS; col++)
                {
                        f << "\t";
                        f << table[row][col];
                }
                f << endl;
        }
}

void AddRows(const TableType table, int& sumrows)
{
        int row;
        int col;

        for (row = 0; row < NUM_ROWS; row++)
                for (col = 0; col < NUM_COLS; col++)
                        sumrows += table[row][col];
}







void AddColumns(const TableType table, int& sumcols)
{
        int row;
        int col;

        for (col = 0; col < NUM_COLS; col++)
                for (row = 0; row < NUM_ROWS; row++)
                        sumcols += table[row][col];
}

