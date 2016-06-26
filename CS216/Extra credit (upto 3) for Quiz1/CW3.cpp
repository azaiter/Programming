#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
	void stud_init(int in_id, string in_name) {stud_id = in_id; f_name = in_name;};
	protected:
	int stud_id;
	string f_name;
};

class CS216: public Student 
{
	public:
	void cs216_init(float q1, float q2) {quiz1 = q1; quiz2 = q2;};
	float cs216_avg() {return (quiz1+quiz2)/2;};
	void cs216_show() {
		cout << endl << f_name << "'s (ID: " << stud_id << ") average quiz score is " << cs216_avg() << endl;
		};
	protected:
	float quiz1, quiz2;
};

int main()
{
	int stud_id;
	float q1,q2;
	string name;
	
	cout << "Enter the First name: ";
	cin >> name;
	cout << endl << "Enter the ID: ";
	cin >> stud_id;
	cout << endl << "Enter Quiz1 score: ";
	cin >> q1;
	cout << endl << "Enter Quiz2 score: ";
	cin >> q2;
	
	CS216 student;
	student.stud_init(stud_id,name);
	student.cs216_init(q1,q2);
	student.cs216_show();
	
	cout << endl;
	system("pause");
	return 0;
	
}