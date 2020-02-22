#include <fstream>
#include <iostream>
#include <string>
#include "Name.h"
#include "Date.h"

using namespace std;

int main()
{
   ofstream outFile("../db/store", ios_base::binary);
   Name steven("Steven", "DeLoach");
   steven.write_binary(outFile);
   outFile.close();

   ifstream inFile("../db/store", ios_base::binary);
   Name unknown;
   cout << unknown.getLastFirst() << endl;
   unknown.read_binary(inFile);
   cout << unknown.getLastFirst() << endl;
   inFile.close();

   Date today(2020, 2, 20);

   ofstream outFile2;
   outFile2.open("../db/store", ios_base::binary);
   today.write_binary(outFile);
   outFile2.close();

   ofstream outJSON2;
   outJSON2.open("../db/store.json");
   today.write_JSON(outJSON2);
   outJSON2.close();

   Date unknownDate;

   ifstream inFile2;
   inFile2.open("../db/store", ios_base::binary);
   unknownDate.read_binary(inFile);
   inFile2.close();

   cout << unknownDate.toISODate() << endl;

   return 0;
}
