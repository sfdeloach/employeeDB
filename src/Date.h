#pragma once
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

class Date
{
private:
   unsigned short *year;
   unsigned char *month;
   unsigned char *day;

public:
   // Constructors/Destructor
   Date(unsigned short _year = 1970,
        unsigned char _month = 1,
        unsigned char _day = 1);
   Date(const Date &date);
   ~Date();

   // Accessors
   const string toISODate();
   const string toString();

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
