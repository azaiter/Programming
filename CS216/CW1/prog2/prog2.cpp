#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <conio.h>

using namespace std;



class Finding_Nums
{
  public:
    Finding_Nums( int n1, int n2);
	~Finding_Nums();
	int what_Greater( int n1, int n2);
  private:
  int n1, n2;
};

Finding_Nums::Finding_Nums( int n1_in, int n2_in )
{
	n1 = n1_in;
	n2 = n2_in;
}

Finding_Nums::~Finding_Nums(void)
{
	cout << "Good Bye" << endl;
}

int Finding_Nums::what_Greater( int n1, int n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}

int main()
{
	int a,b;
	cout << "Enter Two Numbers" << endl;
	cin >> a >> b;
	try
	{
		if(a==b)
			throw string("Numbers are equal");
		if((a<0)||(b<0))
			throw string("Numbers must be posittive");
		//else
		//{
			Finding_Nums aa(a,b);
			cout << "The Greater Number is " << aa.what_Greater(a,b) << endl;
		//}
	}
	
	catch (string message)
	{
		cout << message << endl;
	}
	
	getch();
	return 0;
}