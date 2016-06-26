#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <conio.h>

using namespace std;

class Rectangle
{
  public:
    Rectangle( int l, int w);	
	int calcArea();
  private:
  int length, width;
};

Rectangle::Rectangle( int l, int w )
{
	length = l;
	width = w;
}

int Rectangle::calcArea()
{
	return (length*width);
}

int main()
{
  int a,b;
  cout << "enter width and length seperated via space" << endl;
  cin >> a >> b;
  Rectangle rec(a,b);
  cout << "the area is " << rec.calcArea() << endl;
  getch();
  return 0;
}