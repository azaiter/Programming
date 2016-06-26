#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NAME_SIZE = 21;
typedef char NameString[NAME_SIZE];

struct Employee
{
        int id;
        NameString name;
        char gender;
        char maritalStatus;
        union //is an optional part, record size is not fixed. its variable, YOU COULD HAVE ONE UNION PER STRUCT
        {
                NameString spouseName;
                int date;
        };
};

void GetData(ifstream&, Employee&);
void PrintRd(ofstream&, Employee);

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("rd2out");
    inFile.open("rd2in");

    Employee emp;

    GetData(inFile, emp);
    outFile << "**-- Employee --**" << endl;
    PrintRd(outFile, emp);

    return 0;
}

void GetData(ifstream& inFile, Employee& emp)
{
        inFile >> emp.id >> emp.name >> emp.gender;
        inFile >> emp.maritalStatus;
        switch(emp.maritalStatus)
        {
                case 'M':       inFile >> emp.spouseName;
                                     break;
                case 'D':        inFile >> emp.date;
                                     break;
                case 'S':         break;

                default:         cout << "Unknown Marital Status!" << endl;
        }
}

void PrintRd(ofstream& f, Employee emp)
{

        f << "Name-> " << emp.name << endl;
        f << "Gender-> ";
        switch (emp.gender)
        {
                case 'F':
                case 'f':       f << "Female" << endl;
                                   break;

                case 'M':
                case 'm':       f << "Male" << endl;
                                     break;

                default:        cout << "Unknown Gender!" << endl;
        }
        
        f << "Marital Status-> ";
        switch (emp.maritalStatus)
        {
                case 'M':       f << "Married and Spouse Name-> ";
                                     f << emp.spouseName << endl;
                                      break;

                case 'D':       f << "Divorced and Date Of Divorced is->";
                                    f << emp.date << endl;
                                     break;

                case 'S':       f << "Single";
                                    break;
        }
}

