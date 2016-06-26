// hw3b.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW3-b // DUE DATE: 2-22-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//  a  C++ program to find the division of two numbers (int or float or double) using function overloading. 
//  The program must have the three separate functions (one for int, one for float and one for double data types) named
//  "divN(x, y)" which will return the division of x and y.
//  With divide by zero exception handling.
//*******************************************************************

#include<iostream>
using namespace std;

void divNums(int x, int y)
//*********************************************
// Purpose: prints the division of two provided numbers. if division by zero happens, exception will be thrown
// Input: int x, int y.
// Pre: x and y are properly declared and have values.
// Output: none.
// Post: The division of two provided numbers is printed on screen.
// Note: none.
//*********************************************
{
	try
	{
		if (y==int(0)) throw string ("Error!! Cannot divide by zero!!\n");
		cout << double(x)/double(y);
	}
	catch (string s)
	{
		cout << s;
	}
}

void divNums(float x, float y)
//*********************************************
// Purpose: prints the division of two provided numbers. if division by zero happens, exception will be thrown
// Input: float x, float y.
// Pre: x and y are properly declared and have values.
// Output: none.
// Post: The division of two provided numbers is printed on screen.
// Note: none.
//*********************************************
{
	try
	{
		if (y==float(0)) throw string ("Error!! Cannot divide by zero!!\n");
		cout << double(x)/double(y);
	}
	catch (string s)
	{
		cout << s;
	}
}

void divNums(double x, double y)
//*********************************************
// Purpose: prints the division of two provided numbers. if division by zero happens, exception will be thrown
// Input: double x, double y.
// Pre: x and y are properly declared and have values.
// Output: none.
// Post: The division of two provided numbers is printed on screen.
// Note: none.
//*********************************************
{
	try
	{
		if (y==double(0)) throw string ("Error!! Cannot divide by zero!!\n");
		cout << double(x)/double(y);
	}
	catch (string s)
	{
		cout << s;
	}
}

void divCall(int choice)
//*********************************************
// Purpose: Handles the division based on client choice, 1 for int, 2 for float, 3 for double.
// Input: int choice.
// Pre: choice is properly declared and have values, divNums functions must be declared before this function.
// Output: none.
// Post: The division division based on client code is handled.
// Note: none.
//*********************************************
{	
	//declaring function variables to be taken from user
	int xInt,yInt = 0;
	float  xFloat,yFloat = 0.0;
	double xDbl,yDbl = 0.0;
	int choiceAfter = 0;
	
	//main handling procedure based on client choice (input then function call).
	switch(choice)
	{
		case 1:
		cout << "Enter two integers:\n";
		cin >> xInt >> yInt;
		divNums(xInt,yInt);
		break;
		
		case 2:
		cout << "Enter two floats:\n";
		cin >> xFloat >> yFloat;
		divNums(xFloat,yFloat);
		break;
		
		case 3:
		cout << "Enter two doubles:\n";
		cin >> xDbl >> yDbl;
		divNums(xDbl,yDbl);
		break;
		
		// keep asking the client for correct choice before closing the program.
		default:
		cout << "Invalid Choice!\n";
		cout << "Enter your choice: 1 for int, 2 for float, 3 for double\n";
		cin >> choiceAfter;
		divCall(choiceAfter);
		break;
		
	}
	cout << endl;
}
int main()
{
	//taking choice from client and calling choice handler.
	int choice = 0;
	cout << "Enter your choice: 1 for int, 2 for float, 3 for double\n";
	cin >> choice;
	divCall(choice);
	system("pause");
	return 0;
}