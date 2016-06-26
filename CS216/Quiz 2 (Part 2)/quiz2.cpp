#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int cs216Series(int in)
{
	if(in == 1) return 2;
	else if(in == 2) return 1;
	else
	{
		return 2* (cs216Series(in-2)+cs216Series(in-1));
	}
}

int main()
{
	cout << "The first 5 elements of the cs216 Series are:\n";
	for(int i=1;i<=5;i++)
		cout << cs216Series(i) << " ";
	cout << endl;
	system("pause");
	return 0;
}