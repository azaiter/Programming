#include <iostream>
using namespace std;

template <class TYP>
void BubbleSortReverse(TYP arr[], int arrSize)
{
	for (int i = arrSize-1; i >= 0; --i)
		for (int j = arrSize - i - 1; j > 0 ; --j)
		{
			if (arr[j] > arr[j - 1])
			{
				TYP temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
}

int main()
{
	int arr[10];
	cout << "enter 10 integers\n";
	for(int i=0;i<10;i++)
		cin >> arr[i];
	BubbleSortReverse(arr, 10);
	cout << "sorted:\n";
	for(int i=0;i<10;i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
