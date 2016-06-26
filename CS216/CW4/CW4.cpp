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

class CS216: virtual public Student 
{
	public:
	void cs216_init(float q1, float q2) {cs216_quiz1 = q1; cs216_quiz2 = q2;};
	float cs216_avg() {return (cs216_quiz1+cs216_quiz2)/2;};
	void cs216_show() {
		cout << ", average quiz score in CS216  is " << cs216_avg();
		};
	protected:
	float cs216_quiz1, cs216_quiz2;
};

class CS316: virtual public Student 
{
	public:
	void cs316_init(float q1, float q2) {cs316_quiz1 = q1; cs316_quiz2 = q2;};
	float cs316_avg() {return (cs316_quiz1+cs316_quiz2)/2;};
	void cs316_show() {
		cout << endl << f_name << "'s (ID: " << stud_id << ") average quiz score in CS316 is " << cs316_avg();
		};
	protected:
	float cs316_quiz1, cs316_quiz2;
};

class Midterm: public CS216, public CS316
{
	public:
	void Midterm_init(float m1, float m2) {MidtermPart1 = m1; MidtermPart2 = m2;};
	float Midterm_avg() {return (MidtermPart1+MidtermPart2)/2;};
	void Midterm_show() {
		cs316_show();
		cs216_show();
		cout << " and average midterm score is " << Midterm_avg()  << endl;
		};
	protected:
	float MidtermPart1, MidtermPart2;
};

int main()
{
	int stud_id;
	float cs216_q1,cs216_q2,cs316_q1,cs316_q2,m1,m2;
	string name;
	
	cout << "Enter the First name: ";
	cin >> name;
	cout << endl << "Enter the ID: ";
	cin >> stud_id;
	cout << endl << "Enter CS316 Quiz1 score: ";
	cin >> cs316_q1;
	cout << endl << "Enter CS316 Quiz2 score: ";
	cin >> cs316_q2;
	cout << endl << "Enter CS216 Quiz1 score: ";
	cin >> cs216_q1;
	cout << endl << "Enter CS216 Quiz2 score: ";
	cin >> cs216_q2;
	cout << endl << "Enter Midterm Part1 score: ";
	cin >> m1;
	cout << endl << "Enter Midterm Part2 score: ";
	cin >> m2;
	
	Midterm student;
	student.stud_init(stud_id,name);
	student.cs216_init(cs216_q1,cs216_q2);
	student.cs316_init(cs316_q1,cs316_q2);
	student.Midterm_init(m1,m2);
	student.Midterm_show();
	
	cout << endl;
	system("pause");
	return 0;
	
}