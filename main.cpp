#include <fstream>
#include <iostream>
#include <string>
#include "Name.h"

using namespace std;

int main()
{
   ofstream outFile("database.bin", ios_base::binary);
   Name steven("Steven", "DeLoach");
   steven.write_binary(outFile);
   outFile.close();

   ifstream inFile("database.bin", ios_base::binary);
   Name unknown;
   cout << unknown.getFirstLastName() << endl;
   unknown.read_binary(inFile);
   cout << unknown.getFirstLastName() << endl;
   inFile.close();

   return 0;
}
