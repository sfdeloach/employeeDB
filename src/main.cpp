#include <fstream>
#include <iostream>
#include <string>
#include "Name.h"
#include "Date.h"

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

   ofstream outFile;
   outFile.open("../db/store", ios_base::binary);
   today.write_binary(outFile);
   outFile.close();

   ofstream outJSON;
   outJSON.open("../db/store.json");
   today.write_JSON(outJSON);
   outJSON.close();

   Date unknown;

   ifstream inFile;
   inFile.open("../db/store", ios_base::binary);
   unknown.read_binary(inFile);
   inFile.close();

   cout << unknown.toString() << endl;

   return 0;
}
