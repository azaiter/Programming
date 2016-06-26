// hw2b.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW2-b // DUE DATE: 2-10-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//  a program in C++ that takes five floating-point numbers from the keyboard, stores them in
//  an array and then doubles the contents.
//*******************************************************************

#include <iostream>

using namespace std;

//declaring array size as constant for future programming flexibility.
const int ARR_SIZE = 5;

void makeDouble(float *);
//*********************************************
// Purpose: prints the doubles of pointed array data.
// Input: Float pointer.
// Pre: float pointer is properly declared and have values.
// Output: none.
// Post: The doubles of pointed array data are printed on screen.
// Note: none.
//*********************************************
		
int main()
{
	//declaring variables.
	float array[ARR_SIZE];
	float *arrPtr = array;

	//inputting data from user into array.
	cout << "Enter " << ARR_SIZE << " floating numbers:" << endl;
	for(int i = 0 ; i < ARR_SIZE; i++)
	{
		cin >> *(arrPtr+i);
	}
	
	//outputting doubles using previously declared function
	makeDouble(arrPtr);
	
	system("pause");
	return 0;
}

void makeDouble(float *ptr)
//*********************************************
// Purpose: prints the doubles of pointed array data.
// Input: Float pointer.
// Pre: float pointer is properly declared and have values.
// Output: none.
// Post: The doubles of pointed array data are printed on screen.
// Note: none.
//*********************************************
{
	cout << "Doubles are: " << endl;
	for(int i = 0 ; i < ARR_SIZE; i++)
	{
		cout << (*(ptr+i))*2 << " ";
	}
	cout << endl;
}