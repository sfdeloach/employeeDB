#pragma once
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

class Name
{
private:
   string first;
   string last;

public:
   // Constructors
   Name(string _first = "<first name null>",
        string _last = "<last name null>");

   // Accessors
   const string getFirst();
   const string getLast();
   const string getFirstLastName();
   const string getLastFirstName();

   // Mutators
   void setFirst(string &_first);
   void setLast(string &_last);

   // File I/O
   void write(ofstream &_outFile);
   void read(ifstream &_inFile);
};
