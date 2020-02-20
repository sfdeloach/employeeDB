#include <fstream>
#include <string>
#include "Date.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

/*=== Constructors/Destructor ================================================*/

Date::Date(unsigned short _year,
           unsigned char _month,
           unsigned char _day)
{
   year = new unsigned short;
   *year = _year;

   month = new unsigned char;
   *month = _month;

   day = new unsigned char;
   *day = _day;
}

Date::Date(const Date &date)
{
   year = new unsigned short;
   *year = *date.year;

   month = new unsigned char;
   *month = *date.month;

   day = new unsigned char;
   *day = *date.day;
}

Date::~Date()
{
   clear();
}

/*=== Accessors ==============================================================*/

const string Date::toISODate()
{
   string mm = *month > 9 ? to_string(*month) : string("0") + to_string(*month);
   string dd = *day > 9 ? to_string(*day) : string("0") + to_string(*day);

   return to_string(*year) + "-" + mm + "-" + dd;
}

const string Date::toString()
{
   string months[] = {"January ", "February ", "March ", "April ",
                      "May ", "June ", "July ", "August ",
                      "September ", "October ", "November ", "December "};

   return months[*month - 1] + to_string(*day) + ", " + to_string(*year);
}

/*=== Mutators ===============================================================*/

void Date::setDate(unsigned short _year,
                   unsigned char _month,
                   unsigned char _day)
{
   clear();

   year = new unsigned short;
   *year = _year;
   month = new unsigned char;
   *month = _month;
   day = new unsigned char;
   *day = _day;
}

void Date::clear()
{
   delete year;
   delete month;
   delete day;
}

/*=== Operator Overloads =====================================================*/

Date &Date::operator=(const Date &date)
{
   return *this;
}

/*=== File I/O ===============================================================*/

bool Date::write_binary(ofstream &_outFile)
{
}

bool Date::write_JSON(ofstream &_outFile)
{
}

bool Date::read_binary(ifstream &_inFile)
{
}

bool Date::read_JSON(ifstream &_inFile)
{
}
