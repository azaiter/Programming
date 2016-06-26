// hw2c.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW2-c // DUE DATE: 2-10-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//  a C++ program to reverse the characters in a "char" array using pointer(s). Your program must have a function called 
//  "reverse_array()" which receives the beginning address of the array (which is to be declared inside main function) as argument.
//*******************************************************************

#include <iostream>
#include <string>
//#include <algorithm>

using namespace std;

void reverse_array(char *, int ARR_SIZE);
//*********************************************
// Purpose: prints the reverse of pointed array data.
// Input: char pointer.
// Pre: char pointer is properly declared and have values.
// Output: none.
// Post: The reverse of pointed array data are printed on screen.
// Note: none.
//*********************************************

int main()
{
	//declaring input variable
	string stringInput = "";
	
	//inputting data from user
	cout << "Enter stream of characters: " << endl;
	getline(cin, stringInput);
	
	//declaring other needed variables to convert a string array into char array
	const int ARR_SIZE = stringInput.length();
	char charArr[ARR_SIZE];
	char * charPtr = charArr;

	//inputting data in string array into char array as this is the only way to do it other than constant array size
	for (int i = 0; i < ARR_SIZE; i++)
	{
		*(charPtr+i) = stringInput[i];
	}
	
	//outputting the stream reversed
	cout << "The stream reversed is:" << endl;
	reverse_array(charPtr, ARR_SIZE);
	
	cout << endl;

	system("pause");
	return 0;
}

void reverse_array(char *charPtr, int ARR_SIZE)
//*********************************************
// Purpose: prints the reverse of pointed array data.
// Input: char pointer, ARR_SIZE.
// Pre: char pointer is properly declared and have values.
// Output: none.
// Post: The reverse of pointed array data are printed on screen.
// Note: none.
//*********************************************
{
	for (int j = ARR_SIZE-1; j >=  0; j--)
	{
		cout << (*(charPtr + j));
	}
}