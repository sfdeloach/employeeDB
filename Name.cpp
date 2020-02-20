#include <iostream>
#include <string>
#include "Name.h"

using std::string;

/*=== Constructors ===========================================================*/

Name::Name(string _first, string _last) : first(_first), last(_last) {}

/*=== Accessors ==============================================================*/

const string Name::getFirst()
{
   return first;
}

const string Name::getLast()
{
   return last;
}

const string Name::getFirstLastName()
{
   return string(first + " " + last);
}

const string Name::getLastFirstName()
{
   return string(last + ", " + first);
}

/*=== Mutators ===============================================================*/

void Name::setFirst(string &_first)
{
   first = _first;
}

void Name::setLast(string &_last)
{
   last = _last;
}

/*=== File I/O ===============================================================*/

bool Name::write_binary(ofstream &_outFile)
{
   if (!_outFile.is_open())
      return false;

   size_t length = first.length();
   _outFile.write((char *)&length, sizeof(size_t));
   _outFile.write(first.c_str(), first.length());

   length = last.length();
   _outFile.write((char *)&length, sizeof(size_t));
   _outFile.write(last.c_str(), last.length());

   return true;
}

bool Name::read_binary(ifstream &_inFile)
{
   if (!_inFile.is_open())
      return false;

   char length[] = {0, 0, 0, 0, 0, 0, 0, 0};
   _inFile.read(length, sizeof(size_t));
   size_t len = 0;

   for (unsigned char i = 0; i < sizeof(size_t); ++i)
   {
      len += (unsigned char)length[i] << (8 * i);
   }

   char first_char_array[len];
   _inFile.read(first_char_array, len);
   first.assign(first_char_array);

   // TODO: review above, read last name below

   return true;
}
