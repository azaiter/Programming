//Interactive I/O: use of cin & cout Chap4I
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    int id;
    float exam1, exam2, exam3, avg;
    string name;
    char sex;
    cout << "Note: eneter each data with a space." << endl;
    cout << "Enter Id, Name, Sex, Exam1, Exam2, Exam3:" << endl;
    cin >> id >> name >> sex >> exam1 >> exam2 >> exam3;

    avg = (exam1 + exam2 + exam3)/3;

    cout << "~*< Exam AVG Report >*~" << endl << endl;
    cout << "Id = " << id << endl;
    cout << "Name = " << name << endl;
    cout << "Sex = " << sex << endl;
    cout << "Exam1 = " << exam1 << endl;
    cout << "Exam2 = " << exam2 << endl;
    cout << "Exam3 = " << exam3 << endl << endl;
    cout << "Exam AVG = " << avg << endl << endl;
    cout << "~ end ~ " << endl;

    return 0;
}

