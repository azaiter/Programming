//StudType.h
#ifndefSTUDTYPE_H
#define STUDTYPE_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class StudType
{
public:
StudType(intidVal, float examVal);
StudType();
void ReadRd(ifstream& inFile);
void PrintRd(ofstream& outFile);
void SetRd(intidVal, float examVal);
void PrintPassOrFail(ofstream& outFile);
private:
intid;
float exam;
};
#endif
