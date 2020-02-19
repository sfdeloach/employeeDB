#include <string>
#include "Name.h"

using std::string;

// Constructors
Name::Name(string _first, string _last) : first(_first), last(_last) {}

// Accessors
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

// Mutators
void Name::setFirst(string &_first)
{
   first = _first;
}

void Name::setLast(string &_last)
{
   last = _last;
}

// File I/O
void Name::write(ofstream &_outFile)
{
   if (!_outFile.is_open())
      return;

   _outFile.write(first.c_str(), first.length() + 1);
   _outFile.write(last.c_str(), last.length() + 1);
}

void Name::read(ifstream &_inFile) {
   if (!_inFile.is_open())
      return;

   // TODO
}
