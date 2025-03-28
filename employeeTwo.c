#include <string.h>
#include "employee.h"

// General search function using function pointers
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee)) 
{ 
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) 
    {
        if ((*functionPtr)(targetPtr, ptr) == 0) 
            return (PtrToEmployee) ptr;
    }
    return NULL; 
}

// Comparison function for Employee Number
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) 
{ 
    return *(long *)targetPtr != tableValuePtr->number; 
}

// Comparison function for Employee Name
static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) 
{ 
    return strcmp((char *)targetPtr, tableValuePtr->name);
}

// Comparison function for Employee Phone
static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr) 
{ 
    return strcmp((char *)targetPtr, tableValuePtr->phone);
}

// Comparison function for Employee Salary
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr) 
{ 
    return *(double *)targetPtr != tableValuePtr->salary;
}

// Wrapper functions
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) 
{ 
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber); 
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name) 
{ 
    return searchEmployeeTable(ptr, size, name, compareEmployeeName); 
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* phone) 
{ 
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone); 
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary) 
{ 
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary); 
}
