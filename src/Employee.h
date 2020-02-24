#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Name.h"
#include "CareerHist.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

class Employee
{
private:
   Name name;
   unsigned short deptID;
   CareerHist *careerHist;
   unsigned long histLength;

public:
   // Constructors/Destructor
   Employee(Name _name = Name("<null>", "<null>"), unsigned short _deptID = 0);
   Employee(const Employee &_employee);

   // Accessors
   const string toString() const;
   const Employee &findByID(const unsigned short _id) const;

   // Mutators
   bool addCareerHist(CareerHist &_careerHist);

   // Operator Overloads
   Employee &operator=(const Employee &_employee);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);
};
