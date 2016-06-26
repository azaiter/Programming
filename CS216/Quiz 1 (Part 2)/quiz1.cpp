#include <iostream>

using namespace std;

int main()
{
	int arr[3];
	int *arrPtr = arr;
	int minNum;
	cout << "Enter 3 non-negative integers:" << endl;
	cin >> *arrPtr;
	minNum = *arrPtr;
	for (int i = 1; i < 3; i++)
	{
		cin >> *(arrPtr+i);
		if (*(arrPtr+i) < minNum )
			minNum = *(arrPtr+i);
	}
	cout << "inputted data:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << *(arrPtr+i) << " ";
	}
	cout << endl << endl;
	cout << "The result after substracting the minnimum from all three numbers :" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << *(arrPtr+i)-minNum << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}