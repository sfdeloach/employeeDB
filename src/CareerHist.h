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
public:
   enum Event
   {
      HIRED = 'H',
      TRANSFERRED = 'T',
      PROMOTED = 'P',
      DEMOTED = 'D',
      RESIGNED = 'S',
      RETIRED = 'R',
      OTHER = 'O',
      NOT_SPECIFIED = 'X'
   };

   // Constructors
   CareerHist(Date _date = Date(1970, 1, 1),
              Event _evt = NOT_SPECIFIED,
              string _desc = "");
   CareerHist(const CareerHist &_careerhist);

   // Accessors
   const string toString() const;
   const string getEvent() const;

   // Mutators
   void setDate(Date &_date);
   void setDate(unsigned short _y, unsigned char _m, unsigned char _d);
   void setEvent(Event _evt);
   void setDescription(const string &_desc);

   // Operator Overloads
   CareerHist &operator=(const CareerHist &_careerhist);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);

private:
   Date date;
   Event event;
   string description;
   const string fileNotOpen = "unable to open store, does db directory exist?";
};
