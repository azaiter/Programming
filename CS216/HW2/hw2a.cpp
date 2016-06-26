// hw2a.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW2-a // DUE DATE: 2-10-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//  a C++ program to swap two integer numbers using pointer(s). Two numbers will be taken from
//  keyboard and stored in an integer array (of size two) 
//*******************************************************************

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

//declaring array size as constant for future programming flexibility.
const int ARR_SIZE = 2;

int main()
{
	//declaring variables and pointers.
	int swapArr[ARR_SIZE];
	int * arrPtr = swapArr;
	
	//inputting data from user.
	cout << "Enter " <<  ARR_SIZE << " integer numbers then press enter:" << endl;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cin >> *(arrPtr+i);
	}
	
	//printing inputted data from user using pointers.
	cout << endl << "Before swapping: First number = " << *(arrPtr) << " and Second number = " << *(arrPtr+1) << endl << endl;
	
	//checking if array size is capable of swapping first two elements.
	if (ARR_SIZE >= 2)
	{
		//swapping first two elements of the array using a temporary variable.
		int tempInt;
		tempInt = *(arrPtr+0);
		*(arrPtr+0) = *(arrPtr+1);
		*(arrPtr+1) = tempInt;
	}
	else cout << "Error: Array size is small for swapping first two numbers" << endl;
	
	//printing inputted data from user using pointers after the swap.
	cout << "After swapping: First number = " << *(arrPtr) << " and Second number = " << *(arrPtr+1) << endl << endl;
	
	system("pause");
	return 0;
}