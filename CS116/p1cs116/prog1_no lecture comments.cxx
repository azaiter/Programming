// prog1.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter - Credits to Professor Bidgoli
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #1
//
// DUE DATE: 09-10-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
//      This program for a given item price and 6% tax rate calculate
//      and display item price.
//
//*******************************************************************

#include <iostream>

#include <iomanip>

using namespace std;

const float TAX_RATE = 0.06;            // Sale tax rate

int main()
{
    float price = 5.00; // float variable of the price
    float tax, salePrice; // variables of tax and salePrice

    cout.setf(ios::fixed); 
	
    cout.precision(2);

    tax = price * TAX_RATE;
    salePrice = price + tax;

    cout << "Sale price: $" << salePrice << endl;

    return 0;           // Indicate successful completio.
}