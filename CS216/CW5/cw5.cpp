// hw4-2.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW3-b // DUE DATE: 3-23-2016 // POSSIBLE POINTS: 25 Points
// PURPOSE:
//  a C++ program for linked List. The program must meet the following requirements:          
//  a) Each Node's data section contains three fields: Student's First Name (at most 20 characters), Last Name (at most 20 characters), ID.
//  b) Operations on the List: Search (by ID or position), insert a Node (at any location), delete Node (from any location or by any search criteria on First Name or ID).
//  c) Show the contents of the List (i.e., ID, Names etc. for each Node) when user selects the "Show List" option from the choice menu.
//*******************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int QSIZE = 7;

int main()
{
	int mainQ[QSIZE];
	
	//declaring needed variables for the choices
	int choice = 0;
	int data = 0;
	int front = -1;
	int rear = -1;
	int item = 0;
	
	for (int i =0; i < QSIZE; i++)
		mainQ[i] = 0;
	//doing main menu loop. any other input other than 13 will be ignored.
	do
	{
		//clearing the screen and showing the menu
		system("cls");
		cout 
		<< "1) Enqueue" << endl
		<< "2) Dequeue" << endl
		<< "3) ShowQ" << endl
		<< "4) Exit" << endl
		;
		
		// input data validation in order to make the program perfect
		for (;;) 
		{
			cout << "Please Select An Option ..."<< endl;
			if (cin >> choice) {
				break;
			} else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
	if (choice == 3) //1) Show students List
	{
		cout << "Q is :" << endl;
		for (int i =0; i < QSIZE; i++)
			cout << mainQ[i] << endl;
		system("pause");
	}
	else if (choice == 1) //2) Search by ID
		{
			//asking for needed data
			cout << "Enter data: ";
			cin >> data;
			if(rear == QSIZE-1)
			{
				cout << "queue overflow" << endl;
				system("pause");
			}
			else 
			{
				rear = rear + 1;
				mainQ[rear] = data;
				cout << "added successfully" << endl;
				system("pause");
			}

		}
	else if (choice == 2)//3) Search by position
		{
		if(front == rear)
		{
			cout << "queue empty" << endl;
			system("pause");
		}
		else
		{
		 front = front + 1;
		 item = mainQ [front];
		 cout << "item is : " << item << endl;
		 system("pause");
		}
		}	
	}
	while(choice != 4); //14) Exit
	
	return 0;
}