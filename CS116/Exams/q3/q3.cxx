#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
//defining streams and opening files
ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

//file checks
if (inFile.fail() || outFile.fail())
{
outFile << "Check your input and/or output file !!" << endl;
return 1;
}

//setting numbers after decimal point to 2
outFile.setf(ios::fixed);
outFile.precision(2);

//declaring constants
const float SHIP_PERCENTAGE = 0.10;
const float TAX = 0.05;
//declaring identifiers
int numShirts;
float priceShirts,shipCollected,totalShirtCost,taxCollected;

//inputing data from file
inFile >> numShirts >> priceShirts;

//calculating
taxCollected = priceShirts*numShirts*TAX;
shipCollected = priceShirts*numShirts*SHIP_PERCENTAGE;
totalShirtCost = taxCollected + shipCollected + (numShirts*priceShirts);

//outputting data to file
outFile << "<* CSIS T-shirt *>" << endl;
outFile << "Number of T-shirt: " << numShirts << endl;
outFile << "Price of T-shirt: $" << priceShirts << endl;
outFile << "Shipping Cost: $" << shipCollected << endl;
outFile << "Tax: $" << taxCollected << endl << endl;
outFile << "Total: $" << totalShirtCost  << endl << endl;
outFile << "<* end *>" << endl;

//closing input and output files
inFile.close();
outFile.close();

return 0;
}

