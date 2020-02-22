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

class Date
{
private:
   unsigned short *year;
   unsigned char *month;
   unsigned char *day;

   // Helper Functions
   void _copy(const Date &_date);

public:
   // Constructors/Destructor
   Date(unsigned short _year = 1970,
        unsigned char _month = 1,
        unsigned char _day = 1);
   Date(const Date &date);
   ~Date();

   // Accessors
   const string toISODate() const;
   const string toString() const;

   // Mutators
   void setDate(unsigned short _year, unsigned char _month, unsigned char _day);
   void clear();

   // Operator Overloads
   Date &operator=(const Date &date);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool write_JSON(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool read_JSON(ifstream &_inFile);
};
