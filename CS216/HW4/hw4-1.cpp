// hw4-1.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW3-b // DUE DATE: 3-23-2016 // POSSIBLE POINTS: 10 Points
// PURPOSE:
//   a C++ program with the following requirements:
//   - User will fix the number of inputs (integer) to be entered at the beginning
//   - Program will create an array dynamically using "new" operator to store exactly that many inputs and take the inputs from keyboard
//   - Output the sum (total) of the inputs on screen 
//*******************************************************************

#include <iostream>
#include <string>
using namespace std;
int main()
{
	//declaring needed variables for counter and summation.
    int cnt_num, num_sum = 0;
	//asking user for numbers count.
    cout << "How many numbers?" << endl;
    cin >> cnt_num;
	//declaring an array dynamically with given count.
    int* arr_num = new int[cnt_num];
	//asking user to input data, which will be inputted to the array.
    cout << "Enter " << cnt_num << " numbers: ";
    for(int i = 0; i < cnt_num; i++)
    {
		//adding data to array
        cin >> arr_num[i];
		//adding data to the sum
        num_sum += arr_num[i];
    }
	//outputting the sum.
    cout << "Sum is " << num_sum << endl;
	//deleting the dynamically allocated array.
    delete[] arr_num;
	system("pause");
	return 0;
}