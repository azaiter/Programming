//Author: Abdulrahaman Zaiter //HW 6 //CS216 //Prof: Khandaker Abir Rahman
//Purpose: a C++ program to sort the elements in an array (of size 10) using Bubble Sort algorithm.
//         The type of the array can be any of the int, double or char. Therefore, you have to use function template.
//         User will be able to choose the data type at the beginning.
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

template <class TYP>
void bubble_sort(TYP arr[], int index)
//*********************************************
// Purpose: Sorts the given array using bubble sort algorithm.
// Input: arr, index
// Pre: a declared array and existence of data in it.
// Output: none.
// Post: array gets sorted ascendingly.
// Note: none.
//*********************************************

{
	for (int i = 0; i < index; ++i)
		for (int j = 0; j < index - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				TYP temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}

//declare array size
const int ARR_SIZE = 10;

int main()
{
	int choice;
	//asking for type of data.
	cout << "Enter 1 for int, 2 for double and 3 for char\n";
	cin >> choice;
	//handling the type and inputting into an array, then sorting it and outputting the array.
	if(choice == 1)
	{
		int arr[ARR_SIZE];
		cout << "Enter " << ARR_SIZE << " integers\n";
		for(int i=0;i<ARR_SIZE;i++)
			cin >> arr[i];
		bubble_sort(arr, ARR_SIZE);
		cout << "Sorted :\n";
		for(int i=0;i<ARR_SIZE;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else if(choice == 2)
	{
		double arr[ARR_SIZE];
		cout << "Enter " << ARR_SIZE << " doubles\n";
		for(int i=0;i<ARR_SIZE;i++)
			cin >> arr[i];
		bubble_sort(arr, ARR_SIZE);
		cout << "Sorted :\n";
		for(int i=0;i<ARR_SIZE;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else if(choice == 3)
	{
		char arr[ARR_SIZE];
		cout << "Enter " << ARR_SIZE << " characters\n";
		for(int i=0;i<ARR_SIZE;i++)
			cin >> arr[i];
		bubble_sort(arr, ARR_SIZE);
		cout << "Sorted :\n";
		for(int i=0;i<ARR_SIZE;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}