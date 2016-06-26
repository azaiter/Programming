// prog7.cxx
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
//
// COURSE TITLE: Programming I
//
// COURSE NUMBER: CS116
//
// PROF NAME: Moe Bidgoli
//
// ASSIGNMENT NUMBER: #7
//
// DUE DATE: 10-29-2015
//
// POSSIBLE POINTS: 20 Points
//
// PURPOSE:
//
// Find student quiz average and number of student in input file 
// At the end print mean of AVG and number of student & number of quizzes.
//*******************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	//defining streams and opening files
	ofstream outFile;
	ifstream inFile;
	outFile.open("out.data");
	inFile.open("in.data");

	//file checks
	if (inFile.fail() || outFile.fail())
	{
		outFile << "Check your input and/or output file !!" << endl;
		return 1;
	}

	//setting numbers after decimal point to 2
	outFile.setf(ios::fixed);
	outFile.precision(2);

	//declaring variables
	int studId,numOfQuiz,quizCount,recordCount,studCount;
	float quizScore,quizAvg,avgMean,quizAvgSum;

	//outputting intial aligned output
	outFile << "*~~< Stud Quiz Report >~~*" << endl << endl;
	outFile << left << setw(17) << "Stud Id" << setw(14) << "AVG of Quizzes" << endl;
	outFile << left << setw(17) << "-------" << setw(14) << "--------------" << endl;

	//inputing data from file
	inFile >> studId >> numOfQuiz;

	//doing the main loop till the end of the file
	while (inFile)
	{
		int tempCount = 0;
		float tempSumScore = 0;
		if (numOfQuiz > 0)
			++recordCount;
		++studCount;

		while(numOfQuiz > 0)
		{
			inFile >> quizScore;
			--numOfQuiz;
			++quizCount;
			++tempCount;
			tempSumScore = tempSumScore + quizScore;
		}

		//print intial data to reduce duplication
		outFile << left << setw(17) << studId << setw(14);

		if (tempCount > 0)
		{
			//Calculating avg and other data
			quizAvg = tempSumScore/tempCount;
			quizAvgSum = quizAvgSum + quizAvg;

			//outputting data
			outFile << quizAvg << endl;
		}
		else
		{
			outFile << "No Quizzes" << endl;
		}

		//re-reading the input data
		inFile >> studId >> numOfQuiz;

	}

	if (recordCount > 0)
	{
		avgMean = quizAvgSum / recordCount;
		outFile << endl << ">>>Mean of AVG of Quizzes: " << avgMean << endl << endl;
	}
	else
		outFile << endl << "There is enough data to calculate the Mean of the AVG for it !" << endl << endl;

	outFile << ">>>There were " << studCount << " students & " << quizCount << " quizzes in file." << endl;

	//closing input and output files
	inFile.close();
	outFile.close();

    return 0;
}

