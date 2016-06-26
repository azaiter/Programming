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

//the directive #include <iostream> tells the preprocessor (# sign) to include the iostream standard file (standard input & output library).
#include <iostream>

//list of IO manipulators are in this preprocessor. <iomanip> is required for most of those.
#include <iomanip>

//A namespace is like adding a new group name to which you can add functions and other data, so that it will become distinguishable.
//The keyword using technically means, use this whenever you can. This refers, in this case, to the std namespace. So whenever the computer comes across cout, cin, endl or anything of that matter, it will read it as std::cout, std::cin or std::endl. and so on.
using namespace std;
// declaring the float constant which is named TAX_RATE and have the value of 0.06
const float TAX_RATE = 0.06;            // Sale tax rate
// here we have the declaration of main function, The function named main is a special function in all C++ programs; it is the function called when the program is run. The execution of all C++ programs begins with the main function, regardless of where the function is actually located within the code.
int main()
{
    float price = 0; // float variable of the price - STATIC
    float tax, salePrice; // variables of tax and salePrice - Dynamic

// setting cout flag when printing float to be with a fixed number of decimals
    cout.setf(ios::fixed);
// setting the number of decimals that could be couted to 2. so it will cout it rounded to 2 decimals .
    cout.precision(2);

    tax = price * TAX_RATE;
    salePrice = price + tax;
// now echo Sale price. - pronouced SEE OUT , endl ending line. like enter or new line.
    cout << "Sale price: $" << salePrice << endl;

    return 0;           // Indicate successful completion, since it is INT MAIN(). it is supposed to return int. and 0 indicates successful completion (program executed without errors).
}

