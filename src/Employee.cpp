#include "Employee.h"

/*=== Constructors/Destructor ================================================*/

Employee::Employee(Name _name, unsigned short _deptID) : name(_name),
                                                         deptID(_deptID)
{
   careerHist = nullptr;
   histLength = 0;
}

Employee::Employee(const Employee &_employee)
{
   name = _employee.name;
   deptID = _employee.deptID;
   // TODO copy careerHist array
}

/*=== Accessors ==============================================================*/

const string Employee::toString() const
{
   // TODO
   return "";
}

const Employee &Employee::findByID(const unsigned short _id) const {}

/*=== Mutators ===============================================================*/

bool Employee::addCareerHist(CareerHist &_careerHist)
{
   // TODO
   return true;
}

/*=== Operator Overloads =====================================================*/

Employee &Employee::operator=(const Employee &_employee)
{
   // TODO
   return *this;
}

/*=== File I/O ===============================================================*/

bool Employee::write_binary(ofstream &_outFile)
{
   // TODO
   return true;
}

bool Employee::read_binary(ifstream &_inFile)
{
   // TODO
   return true;
}

bool Employee::write_JSON(ofstream &_outFile)
{
   // TODO
   return true;
}
