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
		cout << endl << f_name << "'s (ID: " << stud_id << ") average quiz score is " << cs216_avg();
		};
	protected:
	float quiz1, quiz2;
};
class CS216Midterm: public CS216 
{
	public:
	void cs216Midterm_init(float m1, float m2) {MidtermPart1 = m1; MidtermPart2 = m2;};
	float cs216Midterm_avg() {return (MidtermPart1+MidtermPart2)/2;};
	void cs216Midterm_show() {
		cs216_show();
		cout << " and average midterm score is " << cs216Midterm_avg()  << endl;
		};
	protected:
	float MidtermPart1, MidtermPart2;
};

int main()
{
	int stud_id;
	float q1,q2,m1,m2;
	string name;
	
	cout << "Enter the First name: ";
	cin >> name;
	cout << endl << "Enter the ID: ";
	cin >> stud_id;
	cout << endl << "Enter Quiz1 score: ";
	cin >> q1;
	cout << endl << "Enter Quiz2 score: ";
	cin >> q2;
	cout << endl << "Enter Midterm Part1 score: ";
	cin >> m1;
	cout << endl << "Enter Midterm Part2 score: ";
	cin >> m2;
	
	CS216Midterm student;
	student.stud_init(stud_id,name);
	student.cs216_init(q1,q2);
	student.cs216Midterm_init(m1,m2);
	student.cs216Midterm_show();
	
	cout << endl;
	system("pause");
	return 0;
	
}