#include <fstream>
#include <iostream>
#include <string>
#include "Name.h"
#include "Date.h"
#include "CareerHist.h"

using namespace std;

int main()
{
   ofstream outFile("./db/store", ios_base::binary);
   Date date(2020, 2, 1);
   CareerHist ch1(date, CareerHist::HIRED, "Hire date");
   ch1.write_binary(outFile);
   outFile.close();

   cout << ch1.toString() << endl;

   ifstream inFile("./db/store", ios_base::binary);
   CareerHist ch2;
   cout << ch2.toString() << endl;
   ch2.read_binary(inFile);
   cout << ch2.toString() << endl;
   inFile.close();

   ofstream outJSON("./db/store.json", ios_base::binary);
   ch2.write_JSON(outJSON);
   outJSON.close();

   // ofstream outFile("./db/store", ios_base::binary);
   // Name steven("Steven", "DeLoach");
   // steven.write_binary(outFile);
   // outFile.close();

   // ifstream inFile("./db/store", ios_base::binary);
   // Name unknown;
   // cout << unknown.getLastFirst() << endl;
   // unknown.read_binary(inFile);
   // cout << unknown.getLastFirst() << endl;
   // inFile.close();

   // ofstream outJSON("./db/store.json");
   // unknown.write_JSON(outJSON);
   // outJSON.close();

   // Date today(2020, 2, 20);

   // ofstream outFile2;
   // outFile2.open("../db/store", ios_base::binary);
   // today.write_binary(outFile);
   // outFile2.close();

   // ofstream outJSON2;
   // outJSON2.open("../db/store.json");
   // today.write_JSON(outJSON2);
   // outJSON2.close();

   // Date unknownDate;

   // ifstream inFile2;
   // inFile2.open("../db/store", ios_base::binary);
   // unknownDate.read_binary(inFile);
   // inFile2.close();

   // cout << unknownDate.toISODate() << endl;

   return 0;
}
