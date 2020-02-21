#include "Name.h"
#include "functions.h"

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

const string Name::getFirstLast()
{
   return string(first + " " + last);
}

const string Name::getLastFirst()
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
      std::cerr << "unable to write to file, does db exist" << std::endl;
      return false;
   }

   // length is string length plus one for null zero
   size_t length = first.length() + 1;
   _outFile.write((char *)&length, sizeof(size_t));
   _outFile.write(first.c_str(), length);

   // write size of last name and last name
   length = last.length() + 1;
   _outFile.write((char *)&length, sizeof(size_t));
   _outFile.write(last.c_str(), length);

   return true;
}

bool Name::read_binary(ifstream &_inFile)
{
   if (!_inFile.is_open())
   {
      std::cerr << "unable to read from store, does db exist?" << std::endl;
      return false;
   }

   size_t len;
   _inFile.read((char *)len, sizeof(size_t));
   char firstArray[len];
   _inFile.read(firstArray, len);
   first.assign(firstArray);

   // char byteArray[sizeof(size_t)] = {0};

   // _inFile.read(byteArray, sizeof(size_t));
   // stringLength = 0;
   // if (byteToIntegral<size_t>(byteArray, sizeof(size_t), stringLength))
   // {
      // char firstNameArray[stringLength];
      // _inFile.read(firstNameArray, stringLength);
      // first.assign(firstNameArray);
   // }

   // _inFile.read(byteArray, sizeof(size_t));
   // stringLength = 0;
   // if (byteToIntegral<size_t>(byteArray, sizeof(size_t), stringLength))
   // {
      // char lastNameArray[stringLength];
      // _inFile.read(lastNameArray, stringLength);
      // last.assign(lastNameArray);
   // }

   return true;
}
