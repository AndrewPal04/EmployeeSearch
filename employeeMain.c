// Compile using:
// gcc employeeMain.c employeeTable.c employeeOne.c
// OR
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

// Function declarations (match what's implemented in employeeOne.c or employeeTwo.c)
PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

// Defined in employeeTable.c
extern Employee EmployeeTable[];     
extern const int EmployeeTableEntries;

int main(void) {
    PtrToEmployee matchPtr;

    // 🔍 ID (No Match)
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    // 🔍 Name (Match)
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // 🔍 Phone (Match)
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-1235");  // Tony Bobcat
    if (matchPtr != NULL)
        printf("Employee with phone 909-555-1235 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone 909-555-1235 is NOT found in the record\n");

    // 🔍 Phone (No Match)
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "111-222-3333");
    if (matchPtr != NULL)
        printf("Employee with phone 111-222-3333 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone 111-222-3333 is NOT found in the record\n");

    // 🔍 Salary (Match)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);  // Daphne Borromeo
    if (matchPtr != NULL)
        printf("Employee with salary 8.78 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 8.78 is NOT found in the record\n");

    // 🔍 Salary (No Match)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 90000.00);
    if (matchPtr != NULL)
        printf("Employee with salary 90000.00 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 90000.00 is NOT found in the record\n");

    return EXIT_SUCCESS;
}
