// hw5-2.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW5-2 // DUE DATE: 4-11-2016 // POSSIBLE POINTS: 25 Points
// PURPOSE:
//  a C++ program to compute the result from a postfix (Inverse Polish Notation) mathematical expression using stack.
//  The stack can be implemented by one char array. Max size of the stack is 30. 
//*******************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

//declaring stack size.
const unsigned int arrSIZE = 30;

bool filesCheck(ofstream& outFile, ifstream& inFile)
//*********************************************
// Purpose: Checks if either input or output files exists.
// Input: none.
// Pre: Declaration of both input and output streams before calling this function.
// Output: bool.
// Post: return true if files are loaded successfully, false if not.
// Note: none.
//*********************************************
{
  if (inFile.fail() || outFile.fail())
  {
    cout << "Check your input and/or output file !!" << endl;
    return 0;
  }
  else
    return 1;
}

void stackPush(float inArr[], float inChar, int& top)
//*********************************************
// Purpose: pushes data into the stack array.
// Input: none.
// Pre: Declaration of stack array.
// Output: inArr, top.
// Post: data passed into the function gets inputted into the stack array.
// Note: none.
//*********************************************
{
	if(top != arrSIZE-1){
		top++;
		inArr[top] = inChar;
	}
	else
		cout << "Error! Stack is full, can't add more values" << endl;
}

float stackPop(float inArr[], int& top)
//*********************************************
// Purpose: pops first stack item and returns it.
// Input: none.
// Pre: Declaration of stack array.
// Output: inArr, top.
// Post: first stack item gets returned and deleted from the stack.
// Note: none.
//*********************************************
{
	if(top != -1)
	{
		top--;
		return inArr[top+1];
	}
	else
	{
		cout << "Eror! Stack is empty!" << endl;
	}
}

void parseCalculation(string item, float stack[], int& top, float& total)
//*********************************************
// Purpose: it will parse string and convert it to float and do inverswe polish notation calculations.
// Input: none.
// Pre: Declaration of stack array and string that has one character.
// Output: inArr, top, stack[].
// Post: string gets parsed and converted to float and inversed into polish notation calculations.
// Note: none.
//*********************************************
{
	if(item[0] >= '0' && item[0] <= '9') //if it's normal number character
			{
				float num = float(item[0])-48; // take out the ascii value from it : ie 48
				stackPush(stack,num,top);
			}
			else if (item[0] == '*') // multiplication
			{
				total = (stackPop(stack, top));
				total *=(stackPop(stack, top));
				stackPush(stack,total,top);
			}
			else if (item[0] == '-') // substraction 
			{
				total = (stackPop(stack, top));
				total = (stackPop(stack, top)) - total;
				stackPush(stack,total,top);
			}
			else if (item[0] == '+') // addition
			{
				total = (stackPop(stack, top));
				total = (stackPop(stack, top)) + total;
				stackPush(stack,total,top);
			}
			else if (item[0] == '/') // division
			{
				total = (stackPop(stack, top));
				total = (stackPop(stack, top)) / total;
				stackPush(stack,total,top);
			}
}

int main()
{
	//defining streams and opening files
	ofstream outFile;
	ifstream inFile;
	outFile.open("out.txt");
	inFile.open("in.txt");

	//file checks
	if (!filesCheck(outFile, inFile))
		return 1;
	
	//declaring character stack array.
	float stack[arrSIZE];
	unsigned char itemTmp;
	string item;
	
	int top = -1;
	float total;
	string line;
	// parsing input file till it hits zero string 
	while(getline(inFile,line) && line != "0")
	{
		top = -1;
		total = 0;
		
		//this while loop is to seperate using space.
		while(line.find(' ') != string::npos)
		{
			int index = line.find(' ');
			item = line.substr(0,index);
			//call function that parses the stack, to make the program more protable.
			parseCalculation(item, stack, top, total);
			line = line.substr(index+1,line.length());
		}
		//on the last element left do the same
			item = line[0];
			parseCalculation(item, stack, top, total);
		// output the total to file and on sceeen.
		outFile << total << endl;
		cout << total << endl;
	}
	//closing input and output files
	inFile.close();
	outFile.close();
	system("pause");
	return 0;
}
