#include <iostream>
using namespace std;

class TwoDBOX
{
	protected:
	double lenght, width;
	public:
	void twoD_init(double l, double w) {lenght = l; width = w; }
	double twoD_area(){return lenght*width;}
	void twoD_out()
		{

				cout << "Area of the box is: " << twoD_area();
			}
		
};

class ThreeDBOX : public TwoDBOX
{
	protected:
	double height;
	public:
	void threeD_init(double l, double w, double h){lenght = l; width = w; height = h;}
	double threeD_volume(){return lenght * width * height;}
	void threeD_out(){
		try 
		{
			if ((lenght >= 0) && (width >= 0) && (height >= 0)) {} else {throw string("Invalid input! Negative numbers not allowed.");}
			twoD_out();
			cout << endl << endl << "Volume of the box is: " << threeD_volume();
		}
		catch(string s)
		{
			cout << s << endl;
		}
		
	}
};

int main()
{
	double l,w,h;
	cout << "Enter the lenght: ";
	cin >> l;
	cout << endl << "Enter the width: ";
	cin >> w;
	cout << endl << "Enter the height: ";
	cin >> h;
	ThreeDBOX obj;
	obj.threeD_init(l,w,h);
	cout << endl;
	obj.threeD_out();
	cout << endl << endl;
	system("pause");
	return(0);
}