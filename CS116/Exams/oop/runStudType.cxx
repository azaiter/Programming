//runStudType.cxx
#include "StudType.h"
intmain()
{
ifstreaminFile;
ofstreamoutFile;
inFile.open("in.data");
outFile.open("out.data");
outFile.setf(ios::fixed);
outFile.precision(2);
StudTyperd1;
StudTyperd2(222, 92.75);
StudTyperd3;
rd1.ReadRd(inFile);
rd3.SetRd(333, 67.8);
outFile<< "<<<~~~ Stud RD ~~~>>>" << endl;
outFile<< "Stud Id" << setw(10) << "E x a m" << endl;
outFile<< "-------" << setw(10) << "-------" << endl;
rd1.PrintRd(outFile);
rd1.PrintPassOrFail(outFile);
rd2.PrintRd(outFile);
rd2.PrintPassOrFail(outFile);
rd3.PrintRd(outFile);
rd3.PrintPassOrFail(outFile);
return 0;
}


