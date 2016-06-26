//While loop Chap6I
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("out.dat");
    inFile.open("in.dat");

    outFile.setf(ios::fixed);
    outFile.precision(2);

    float examScore, avg;
    float sumOfScore = 0.0;
    int count = 0;
    float max = 0.0;
    float min = 100.0;

    outFile << "*** Exam Report ***" << endl;
    outFile << endl;

    inFile >> examScore;
    while(inFile)
    {
       if((examScore >= 0) && (examScore <=100))
       {
          outFile << examScore << endl;
          sumOfScore = sumOfScore + examScore;
          count = count + 1;

          if(examScore > max)
             max = examScore;

          if(examScore < min)
            min = examScore;
       }
       else
          outFile << examScore << "     Invalid exam" << endl;

       inFile >> examScore;

    }

	if (count > 0)
    {
		avg = sumOfScore/count;
	    outFile << "Exam Max: " << max << endl;
    	outFile << "Exam Min: " << min << endl;
		outFile << "Exam Avg: " << avg << endl;

	}
	else
		outFile << "There is no Valid Exam Scores. No Average." << endl;

    outFile << endl;
    outFile << "< end >" << endl;

    return 0;
}

