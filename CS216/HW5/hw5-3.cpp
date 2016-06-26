// hw5-3.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW5-3 // DUE DATE: 4-11-2016 // POSSIBLE POINTS: 25 Points
// PURPOSE:
//  Binary Search program in C++ using recursive function. The search will be applied on a sorted array (max. size 20).
//  The array elements are to be taken from keyboard. Use of Recursion is mandatory.  
//*******************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch(vector<int> inNumArray, int& item, int first, int last)
//*********************************************
// Purpose: Searches the vector using the binary search algorithim.
// Input: int item, int first, int last, vector<int> inNumArray.
// Pre: Declaration of both input and output streams before calling this function.
// Output: bool.
// Post: return true if item is found, false if not.
// Note: none.
//*********************************************
{
 int midPoint;
 if(first > last) 
	return false;
 else {
   midPoint = (first + last)/2;
   if(item < inNumArray[midPoint])
     return BinarySearch(inNumArray, item, first, midPoint-1);
   else if (item == inNumArray[midPoint]) {
	   item = inNumArray[midPoint];
     return true;
   }
   else
     return BinarySearch(inNumArray, item, midPoint+1, last);
 }
} 

int main()
{
	int itemCount=0;//Number of needed items to input from user.
	int inIntData; //For data insertion into the vector.
	int itemToSearch;//item to search.
	vector<int> numArray; //to enforce items sortation, it is said array, isn't vectors a dynamic arrays ??
	cout << "How many items ?\n";
	cin >> itemCount;
	cout << "\nEnter items as Sorted integers seperated by single space\n";
	for(int i=0;i<itemCount;i++)
	{
		cin >> inIntData;
		numArray.push_back(inIntData);
	}
	//sorting data even if it is not ordered :D
	sort(numArray.begin(),numArray.end());
	cout << "\nEnter the item to search: ";
	cin >> itemToSearch;
	if(BinarySearch(numArray,itemToSearch,0,itemCount-1))
		cout << "Item found\n";
	else
		cout << "Item not found\n";
	system("pause");
	return 0;
}