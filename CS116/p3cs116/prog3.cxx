//************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COUSE TITLE: Programming I
//
// COUSE NUMBER: CS116
//
// FROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #3
//
// DUE DATE: 09-22-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
//      This program will calculate different expressions given in the assignment
//      from 1-5 will give 3 decimals, and from 5 decimals from 5-10
//      will write the output to an output file, no input file required.
//
//************************************************************
//including needed libraries.
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

//making output stream and opening output file
ofstream outFile;
outFile.open("out.data");

//setting decimals to fixed and change it to 3
outFile.setf(ios::fixed);
outFile.precision(3);

//declaring variables and setting the expressions.
float calcExpr1, calcExpr2, calcExpr3, calcExpr4, calcExpr5, calcExpr6, calcExpr7, calcExpr8, calcExpr9, calcExpr10;
calcExpr1 = sqrt(2.0);
calcExpr2 = sqrt(4.0);
calcExpr3 = log10(100.0);
calcExpr4 = log(100.0);
calcExpr5 = pow(1.23, 2.0);
calcExpr6 = ceil(sqrt(6.6));
calcExpr7 = floor(sqrt(6.6));
calcExpr8 = pow(1.23, 1.23);
calcExpr9 = floor(pow(1.23, 1.23));
calcExpr10 = (sqrt(pow(10.246, 1.123) * 1.123 + 1.123 - 10.00))/(123.456 * 9.876);

//outputting data
outFile << "<** Report of Assignment Expressions Solutions **>" << endl << endl;
outFile << "1) Square root of 2.0 = " << calcExpr1 << endl << endl;
outFile << "2) Square root of 4.0 = " << calcExpr2 << endl << endl;
outFile << "3) Logarithm on base 10 of 100.0 = " << calcExpr3 << endl << endl;
outFile << "4) Natural logarithm of 100.0 = " << calcExpr4 << endl << endl;
outFile << "5) Power 2 of 1.23 = " << calcExpr5 << endl << endl;
//setting decimals to 5
outFile.precision(5);
outFile << "6) Ceiling value of square root of 6.6 = " << calcExpr6 << endl<<endl;
outFile << "7) Floor value of square root of 6.6 = " << calcExpr7 <<endl<< endl;
outFile << "8) Value of 1.23^1.23 = " << calcExpr8 << endl << endl;
outFile << "9) Floor of 1.23^1.23 = " << calcExpr9 << endl << endl;
outFile << "10) [Square root of (10.246^1.123  X  1.123 + 1.123 -10.00)]/(123.456 * 9.876) = " << calcExpr10 << endl << endl;
outFile << "<** end **>";
//closing output file
outFile.close();

return 0;
}
