// Functions
#include <iostream>
#include <iomanip>
using namespace std;

int f(int x);
void k(int& a);

int main()
{

    int n1 = 11;
    int n2 = 17;
    int n3;

    n3 = n1 * n2 % f(n1, n2); //One Extra Argument Here!
    cout << n3 << endl;
    n = k(n3);
    cout << n3 << endl;

    return 0;
}

int f(int x, int y)
{
   int n1 = 3;

   if(x > n1)
     return x * n1;
   else
     return y % n1;
}

void k(int& a)
{
  return ++a; // void does not return a value
}

