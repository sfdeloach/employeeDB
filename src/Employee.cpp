#include "Employee.h"

/*=== Constructors/Destructor ================================================*/

Employee::Employee(const string _last,
                   const string _first,
                   const unsigned short _deptID)
{
   name.setLast(_last);
   name.setFirst(_first);
   deptID = _deptID;
   careerHist = nullptr;
   histLength = 0;
}

Employee::Employee(const Employee &_employee)
{
   _copy(_employee);
}

Employee::~Employee()
{
   delete[] careerHist;
}

/*=== Accessors ==============================================================*/

const string Employee::toString() const
{
   string result;
   result += "          Name: " + name.getLastFirst() + "\n";
   result += "       Dept ID: " + to_string(deptID) + "\n";
   result += "Career History: ";

   if (histLength == 0)
   {
      result += "< no entries found >\n";
   }
   else
   {
      result += careerHist[0].toString() + "\n";
      for (unsigned int i = 1; i < histLength; ++i)
      {
         for (unsigned int j = 0; j < 16; ++j)
            result += " ";
         result += careerHist[i].toString() + "\n";
      }
   }

   return result;
}

const Name Employee::getName() const
{
   return name;
}

unsigned short Employee::getDeptID() const
{
   return deptID;
}

const CareerHist *Employee::getCareerHist() const
{
   return careerHist;
}

/*=== Mutators ===============================================================*/

void Employee::setName(string _last, string _first)
{
   name.setLast(_last);
   name.setFirst(_first);
}

void Employee::setDeptID(unsigned short _id)
{
   deptID = _id;
}

void Employee::addCareerHist(CareerHist &_careerHist)
{
   CareerHist *newHist = new CareerHist[histLength + 1];

   for (unsigned int i = 0; i < histLength; ++i)
   {
      newHist[i] = careerHist[i];
   }

   if (histLength > 0)
      delete[] careerHist;

   newHist[histLength] = _careerHist;
   careerHist = newHist;
   ++histLength;
}

/*=== Operator Overloads =====================================================*/

Employee &Employee::operator=(const Employee &_employee)
{
   if (histLength > 0)
      delete[] careerHist;

   _copy(_employee);

   return *this;
}

/*=== File I/O ===============================================================*/

bool Employee::write_binary(ofstream &_outFile)
{
   // TODO
   _outFile.getloc(); // temp added to remove compiler warnings
   return true;
}

bool Employee::read_binary(ifstream &_inFile)
{
   // TODO
   _inFile.getloc(); // temp added to remove compiler warnings
   return true;
}

bool Employee::write_JSON(ofstream &_outFile)
{
   // TODO
   _outFile.getloc(); // temp added to remove compiler warnings
   return true;
}

/*=== Private helper function(s) =============================================*/

void Employee::_copy(const Employee &_employee)
{
   name = _employee.name;
   deptID = _employee.deptID;
   histLength = _employee.histLength;

   if (_employee.histLength > 0)
   {
      careerHist = new CareerHist[histLength];

      for (unsigned int i = 0; i < histLength; ++i)
      {
         careerHist[i] = _employee.careerHist[i];
      }
   }
   else
   {
      careerHist = nullptr;
   }
}
