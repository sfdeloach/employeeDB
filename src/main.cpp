#include <fstream>
#include <iostream>
#include <string>
#include "Date.h"
#include "Name.h"

using namespace std;

int main()
{
   // ofstream outFile("../db/store", ios_base::binary);
   // Name steven("Steven", "DeLoach");
   // steven.write_binary(outFile);
   // outFile.close();

   // ifstream inFile("../db/store", ios_base::binary);
   // Name unknown;
   // cout << unknown.getLastFirst() << endl;
   // unknown.read_binary(inFile);
   // cout << unknown.getLastFirst() << endl;
   // inFile.close();

   Date today(2020, 2, 20);
   Date epoch;
   Date copy = today;
   cout << "today: " << today.toISODate() << endl;
   cout << "epoch: " << epoch.toISODate() << endl;
   cout << "copy:  " << copy.toISODate() << endl;

   copy.setDate(1976, 4, 12);
   cout << "copy:  " << copy.toString() << endl;

   return 0;
}
