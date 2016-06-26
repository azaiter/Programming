#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXNUM = 100;
const int MINNUM = 0;

int main()
{
    ofstream outFile;
    ifstream inFile;

    outFile.open("out.data");
    inFile.open("in.data");

    outFile.setf(ios::fixed);
    outFile.precision(2);

    int num1, num2, max;
    float avg;

outFile << "~~< Two Numbers >~~" << endl << endl;
outFile << "Num1" << setw(10) << "Num2" << setw(10) << "MAX" <<  setw(10) << "AVG" << endl;
outFile << "----" << setw(10) << "----" << setw(10) << "---" << setw(10)  << "---" << endl;

    inFile >> num1 >> num2;

    outFile << num1 << setw(10) << num2;

if((num1 >= MINNUM && num1 <= MAXNUM) && (num2 >= MINNUM && num2 <= MAXNUM))
    {

       if (num1 >= num2)
          max = num1;
       else
          max = num2;

       avg = float(num1 + num2)/2.0;

       outFile << setw(11) << max << setw(13) << avg << endl << endl;

     }
     else

     outFile << setw(20) << "*** Invalid data" << endl << endl;

     outFile << endl << "*< end >*" << endl;

    return 0;
}

