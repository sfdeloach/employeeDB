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
   Name(string _first = "<null>",
        string _last = "<null>");

   // Accessors
   const string getFirst();
   const string getLast();
   const string getFirstLastName();
   const string getLastFirstName();

   // Mutators
   void setFirst(string &_first);
   void setLast(string &_last);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool write_JSON(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool read_JSON(ifstream &_inFile);
};
