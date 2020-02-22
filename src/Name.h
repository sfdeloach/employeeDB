#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

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
   const string getFirstLast();
   const string getLastFirst();

   // Mutators
   void setFirst(string &_first);
   void setLast(string &_last);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);
   bool read_JSON(ifstream &_inFile);
};
