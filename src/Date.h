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
public:
   // Constructors/Destructor
   Date(unsigned short _year = 1970,
        unsigned char _month = 1,
        unsigned char _day = 1);
   Date(const Date &_date);
   ~Date();

   // Accessors
   const string toISODate() const;
   const string toString() const;

   // Mutators
   void setDate(unsigned short _year, unsigned char _month, unsigned char _day);
   void clear();

   // Operator Overloads
   Date &operator=(const Date &_date);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);

private:
   unsigned short *year;
   unsigned char *month;
   unsigned char *day;

   const string fileNotOpen = "unable to open store, does db directory exist?";
   const string months[12] = {"January ", "February ", "March ", "April ",
                              "May ", "June ", "July ", "August ",
                              "September ", "October ", "November ", "December "};

   // Helper Function
   void _copy(const Date &_date);
};
