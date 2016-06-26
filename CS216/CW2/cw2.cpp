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
	char what_Greater( char n1, char n2);
	float what_Greater( float n1, float n2);
	double what_Greater( double n1, double n2);
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

char Finding_Nums::what_Greater( char n1, char n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}

float Finding_Nums::what_Greater( float n1, float n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}

double Finding_Nums::what_Greater( double n1, double n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}

int main()
{
	int a,b;
	cout << "Enter Two Integer" << endl;
	cin >> a >> b;
	Finding_Nums ab(a,b);
	cout << "The Greater input is " << ab.what_Greater(a,b) << endl<< endl;
	//////////////////////
	char c,d;
	cout << "Enter Two Chars" << endl;
	cin >> c >> d;
	Finding_Nums cd(c,d);
	cout << "The Greater input is " << cd.what_Greater(c,d) << endl<< endl;
	//////////////////////
	float e,f;
	cout << "Enter Two floats" << endl;
	cin >> e >> f;
	Finding_Nums ef(e,f);
	cout << "The Greater input is " << ef.what_Greater(e,f) << endl<< endl;
	//////////////////////
	double g,h;
	cout << "Enter Two doubles" << endl;
	cin >> g >> h;
	Finding_Nums gh(g,h);
	cout << "The Greater input is " << gh.what_Greater(g,h) << endl<< endl;
	//////////////////////
	
	getch();
	return 0;
}