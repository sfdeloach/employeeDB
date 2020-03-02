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
public:
   // Constructors/Destructor
   Employee(string _last = "unknown",
            string _first = "unknown",
            unsigned short _deptID = 0);
   Employee(const Employee &_employee);
   ~Employee();

   // Accessors
   const string toString() const;
   const Name getName() const;
   unsigned short getDeptID() const;
   const CareerHist *getCareerHist() const;

   // Mutators
   void setName(string _last, string _first);
   void setDeptID(unsigned short _id);
   void addCareerHist(CareerHist &_careerHist);

   // Operator Overloads
   Employee &operator=(const Employee &_employee);

   // File I/O
   bool write_binary(ofstream &_outFile);
   bool read_binary(ifstream &_inFile);
   bool write_JSON(ofstream &_outFile);

private:
   Name name;
   unsigned short deptID;
   CareerHist *careerHist;
   unsigned long histLength;
   const string fileNotOpen = "unable to open store, does db directory exist?";

   void _copy(const Employee &_employee);
};
