//libfun.cxxChap3II
// C++ Library Mathematical Functions/CS116 Moe Bidgoli

#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("outLibMath.data");

    outFile.setf(ios::fixed);
    outFile.precision(3);

    double x, y;
    x = 10.0;
    y = 3.0;

    outFile << "*< Sample of C++ Library Mathematical Functions >*" << endl << endl;
    outFile << "Square root of 10.0  = " << sqrt( x) << endl;
    outFile << "Natural logarithm 10.0 = " << log(x) << endl;
    outFile << "Absolute value of -2 * 10.0 = " << fabs(-2.0 * x) << endl;
    outFile << "Ceiling value of 8.123 = " << ceil(8.123) << endl;
    outFile << "Floor value of 8.123 = " << floor(8.123) << endl;
    outFile << "3.0 raised to power 2.2 = " << pow(y, 2.2)<< endl;
    outFile << "Squar root of pwr(3.0, 3.0) = " << sqrt(pow(y, 3.0)) << endl << endl;
    outFile << "~~< end >~~" << endl;

    outFile.close();
    return 0;
}

