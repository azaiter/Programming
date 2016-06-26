//************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COUSE TITLE: Programming I
//
// COUSE NUMBER: CS116
//
// FROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #2
//
// DUE DATE: 9-15-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
//      This program inputs an item price from an input file and for
//      a given 6% tax rate, it will calculate item price. This program
//      will write the output to an output file.
//
//************************************************************

// including file and manipulation streams libraries needed for this assignment.
#include <fstream>
#include <iomanip>

using namespace std;

const float TAX_RATE = 0.06;            // Sale tax rate

int main()
{

    ofstream outFile; //system output stream named outFile
    ifstream inFile; //system input streean named inFile

	//opening input and output files
    outFile.open("out.data");
    inFile.open("in.data");

	//setting decimals to be fixed and round it to 2
    outFile.setf(ios::fixed);
    outFile.precision(2);

    float price, tax, salePrice;

    inFile >> price; // get price from the file.

    tax = price * TAX_RATE;
    salePrice = price + tax;
    
	//send data to the output file.
    outFile << "<* Sale Receipt *>" << endl << endl;
    outFile << "Sale price: $" << salePrice << endl << endl;
    outFile << "~ end ~" << endl;
	
	//clear up and close files.
    inFile.close();
    outFile.close();

    return 0; // indecate successful completion.
}

