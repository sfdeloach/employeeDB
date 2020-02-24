#include "CareerHist.h"

/*=== Constructor ============================================================*/

CareerHist::CareerHist(Date _date, /*Event _evt,*/ string _desc) : date(_date),
                                                                    /*event(_evt),*/
                                                                    description(_desc)
{
}

CareerHist::CareerHist(const CareerHist &_careerhist)
{
   date = _careerhist.date;
   description = _careerhist.description;
}

/*=== Accessors ==============================================================*/

const string CareerHist::toString() const
{
   string result;
   result += "       Date: " + date.toISODate() + "\n";
   result += "      Event: TODO!\n";
   result += "Description: " + description + "\n";

   return result;
}

/*=== Mutators ===============================================================*/

void CareerHist::setDate(Date &_date)
{
   date = _date;
}

// void CareerHist::setEvent (Event _evt); <-- TODO

void CareerHist::setDescription(const string &_desc)
{
   description = _desc;
}

/*=== Operator Overloads =====================================================*/

CareerHist &CareerHist::operator=(const CareerHist &_careerhist)
{
   date = _careerhist.date;
   description = _careerhist.description;

   return *this;
}

/*=== File I/O ===============================================================*/

bool CareerHist::write_binary(ofstream &_outFile)
{
   if (!_outFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   // write date
   date.write_binary(_outFile);

   // write event <-- TODO!
   // event.write_binary(_outFile);

   // write description
   size_t len = description.length() + 1;
   _outFile.write((const char *)&len, sizeof(size_t));
   _outFile.write(description.c_str(), len);

   return true;
}

bool CareerHist::read_binary(ifstream &_inFile)
{

   if (!_inFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   // read date
   date.read_binary(_inFile);

   // read event <-- TODO!

   // read description
   size_t len;
   char *charArray;

   _inFile.read((char *)&len, sizeof(size_t));
   charArray = new char[len];
   _inFile.read(charArray, len);

   description.assign(charArray);

   delete[] charArray;

   return true;
}

bool CareerHist::write_JSON(ofstream &_outFile)
{
   if (!_outFile.is_open())
   {
      cerr << fileNotOpen << endl;
      return false;
   }

   // TODO

   return true;
}
