//StudType.cxx
#include "StudType.h"
StudType::StudType(intidVal, float examVal)
{
id = idVal;
exam = examVal;
}
StudType::StudType()
{
id = -111;
exam = -100.00;
}

void StudType::ReadRd(ifstream& inFile)
{
inFile >> id >> exam;
}
void StudType::PrintRd(ofstream& outFile)
{
outFile << id << setw(12) << exam << endl;
}
void StudType::SetRd(int idVal, float examVal)
{
id = idVal;
exam = examVal;
}

void StudType::PrintPassOrFail(ofstream& outFile)
{
outFile << "Exam Status: ";
if (exam >= 70.00)
outFile << "Pass" << endl;
else
outFile << "Fail" << endl;
}
