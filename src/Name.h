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
public:
   // Constructor
   Name(string _first = "<null>",
        string _last = "<null>");
   Name(const Name &_name);

   // Accessors
   const string getFirst() const;
   const string getLast() const;
   const string getFirstLast() const;
   const string getLastFirst() const;

   // Mutators
   void setFirst(const string &_first);
   void setLast(const string &_last);

   // Operator Overloads
   Name &operator=(const Name &_name);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);

private:
   string first;
   string last;
   const string fileNotOpen = "unable to open store, does db directory exist?";
};
