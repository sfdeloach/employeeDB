#include <fstream>
#include <iostream>
#include <string>
#include "Name.h"

using namespace std;

int main()
{
   ofstream outFile("database.txt", ios_base::binary);
   Name steven("Steven", "DeLoach");
   steven.write(outFile);
   outFile.close();

   ifstream inFile("database.txt", ios_base::binary);
   Name unknown;
   cout << unknown.getFirstLastName() << endl;
   unknown.read(inFile);
   cout << unknown.getFirstLastName() << endl;
   inFile.close();

   return 0;
}
