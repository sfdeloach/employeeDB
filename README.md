# employeeDB

Keep track of an employee's work history

## Overview

A database-like program that allows a user to persist data on employees. Data
will be saved to disk in both text (JSON format) and binary formats.

Simple interface that allows users to create, read, update, and delete data.

## Schema

```text
vector<Employee>
   Name (class)
      first (string)
      last (string)
   deptID (unsigned short)
   CareerHist[] (class array)
      Date (class)
         day (unsigned char)
         month (unsigned char)
         year (unsigned short)
      Event (enum)
         HIRED, RETIRED, RESIGNED, PROMOTED, DEMOTED, TRANSFERRED, OTHER
      description (string)
```

## Notes

1. Will need to indicate size of strings and arrays in output file
