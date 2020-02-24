#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

class CareerHist
{
private:
   Date date;
   // Event event; <-- TODO!
   string description;
   const string fileNotOpen = "unable to open store, does db directory exist?";

public:
   // Constructor
   CareerHist(Date _date = Date(1970, 1, 1), /*Event _evt,*/ string _desc = "");
   CareerHist(const CareerHist &_careerhist);

   // Accessors
   const string toString() const;

   // Mutators
   void setDate(Date &_date);
   // void setEvent (Event _evt); <-- TODO
   void setDescription(const string &_desc);

   // Operator Overloads
   CareerHist &operator=(const CareerHist &_careerhist);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);
};
