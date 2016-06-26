#include <iostream>
using namespace std;

int jj(int x, int y);

int main()
{
    int x = 1;
    int y = 10;
int test = jj(x,y);
    cout << "jj returns: " << test << endl;

    return 0;
}

int jj(int x, int y)
{
  int t = 2;

  x++;
  --y;
  cout << "t is: " << t << endl;
  cout << "x is: " << x << "  y is: " << y << endl;

  return x * y + t;
}

