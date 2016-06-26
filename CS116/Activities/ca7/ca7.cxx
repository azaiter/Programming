// Value-Returning & void functions Chap8I

#include <fstream>
#include <iomanip>

using namespace std;

int maxOfTwoNums(int num1, int num2); // pass by value. in peranthesis are input
//**************************3P/IO*************************
// Purpose: Finds maximum of two integer number.
// Input: num1, num2
// Pre: num1 and num2 have value.
// Output: int
// Post: It returns max of two inegers
// Note: none
//********************************************************

void swapTwoNums(int& num1, int& num2);//pass by refernce-= changiing it . in peranthesis in/out
//********************************************************
// Purpose: swap two ineger values
// Input: num1 , num2
// Pre: num1 and num2 have values
// Output: num1 , num2
// Post: Value of num1 and num2 are swaped.
// Note: None.
//********************************************************

void printHeading(ofstream& outFile);
//********************************************************
// Purpose: Print heading
// Input:None
// Pre: File is open and okay
// Output: outFile
// Post: Heading is printed
// Note: None
//********************************************************

int main()
{
    ofstream outFile;
    ifstream inFile;

    outFile.open("out.data");
    inFile.open("in1.data");

    int num1, num2, max;

    inFile >> num1 >> num2;

    printHeading(outFile);
    outFile << "num1: " << num1 << endl;
    outFile << "num2: " << num2 << endl << endl;

    max = maxOfTwoNums(num1, num2);
    swapTwoNums(num1, num2);

    outFile << "Print num1 & num2 after swapping:" << endl;
    outFile << "num1: " << num1 << endl;
    outFile << "num2: " << num2 << endl << endl;
    outFile << "MAX of num1 & num2 is: " <<  max << endl << endl;
    outFile << "~ end ~ " << endl;

    inFile.close();
    outFile.close();

    return 0;
}

//definition

int maxOfTwoNums(int num1, int num2)
//**********************************************
//Repeat 3P/IO

{
    if (num1 > num2)
       return num1; //it must have return!!
    else
       return num2;
}

void swapTwoNums(int& num1, int& num2)
//*********************
// repeat

{
   int temp; //local variable just for this function

   temp = num2;
   num2 = num1;
   num1 = temp;
}

void printHeading(ofstream& outFile)
// repeat

{
   outFile << "Void and Value-Returning Functions" << endl;
   outFile << "----------------------------------" << endl;
}
