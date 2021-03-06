#include "Date.h"

/*=== Constructors/Destructor ================================================*/

// default constructor
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

// copy constructor
Date::Date(const Date &_date)
{
   _copy(_date);
}

// destructor
Date::~Date()
{
   clear();
}

/*=== Accessors ==============================================================*/

const string Date::toISODate() const
{
   string mm = *month > 9 ? to_string(*month) : string("0") + to_string(*month);
   string dd = *day > 9 ? to_string(*day) : string("0") + to_string(*day);

   return to_string(*year) + "-" + mm + "-" + dd;
}

const string Date::toString() const
{
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

Date &Date::operator=(const Date &_date)
{
   clear();
   _copy(_date);

   return *this;
}

/*=== File I/O ===============================================================*/

bool Date::write_binary(ofstream &_outFile)
{
   if (!_outFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   _outFile.write((const char *)year, sizeof(*year));
   _outFile.write((const char *)month, sizeof(*month));
   _outFile.write((const char *)day, sizeof(*day));

   return true;
}

bool Date::read_binary(ifstream &_inFile)
{
   if (!_inFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   _inFile.read((char *)year, sizeof(*year));
   _inFile.read((char *)month, sizeof(*month));
   _inFile.read((char *)day, sizeof(*day));

   return true;
}

bool Date::write_JSON(ofstream &_outFile)
{
   if (!_outFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   _outFile << "      \"Date\": {" << endl
            << "         \"year\": " << *year << "," << endl
            << "         \"month\": " << (unsigned short)*month << "," << endl
            << "         \"day\": " << (unsigned short)*day << endl
            << "      }," << endl;

   return true;
}

/*=== Helper Function =i=======================================================*/

void Date::_copy(const Date &_date)
{
   year = new unsigned short;
   *year = *_date.year;

   month = new unsigned char;
   *month = *_date.month;

   day = new unsigned char;
   *day = *_date.day;
}
