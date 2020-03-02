#include "Name.h"

/*=== Constructor ============================================================*/

Name::Name(string _first, string _last) : first(_first), last(_last) {}

Name::Name(const Name &_name)
{
   first = _name.first;
   last = _name.last;
}

/*=== Accessors ==============================================================*/

const string Name::getFirst() const
{
   return first;
}

const string Name::getLast() const
{
   return last;
}

const string Name::getFirstLast() const
{
   return string(first + " " + last);
}

const string Name::getLastFirst() const
{
   return string(last + ", " + first);
}

/*=== Mutators ===============================================================*/

void Name::setFirst(const string &_first)
{
   first = _first;
}

void Name::setLast(const string &_last)
{
   last = _last;
}

/*=== Operator Overloads =====================================================*/

Name &Name::operator=(const Name &_name)
{
   first = _name.first;
   last = _name.last;

   return *this;
}

/*=== File I/O ===============================================================*/

/**
 * Writes this object to _outFile using the following format:
 * 
 *    | first name size (8 bytes) | first name (size bytes) |
 *    | last name size (8 bytes) | last name (size bytes) |i
 * 
 * The size of the string includes a null terminating zero (cstring style).
 * Returns true if write operation is successful
 */
bool Name::write_binary(ofstream &_outFile)
{
   if (!_outFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   size_t len;

   // length is string length plus one for null zero
   len = first.length() + 1;
   _outFile.write((char *)&len, sizeof(size_t));
   _outFile.write(first.c_str(), len);

   // write size of last name and last name
   len = last.length() + 1;
   _outFile.write((char *)&len, sizeof(size_t));
   _outFile.write(last.c_str(), len);

   return true;
}

bool Name::read_binary(ifstream &_inFile)
{
   if (!_inFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   size_t len;
   char *charArray;

   _inFile.read((char *)&len, sizeof(size_t));
   charArray = new char[len];
   _inFile.read(charArray, len);

   first.assign(charArray);

   delete[] charArray;

   _inFile.read((char *)&len, sizeof(size_t));
   charArray = new char[len];
   _inFile.read(charArray, len);

   last.assign(charArray);

   delete[] charArray;

   return true;
}

bool Name::write_JSON(ofstream &_outFile)
{
   if (!_outFile)
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   _outFile << "   \"Name\": {" << endl
            << "      \"first\": \"" << first << "\"," << endl
            << "      \"last\": \"" << last << "\"" << endl
            << "   }" << endl;

   return true;
}
