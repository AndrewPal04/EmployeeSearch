#include <stdio.h> 

#include <stddef.h> 

typedef struct { 

    long number; 

    char *name; 

    char *phone; 

    double salary; 

} Employee, *PtrToEmployee; 

 

typedef const Employee *PtrToConstEmployee; 

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char *targetPhone);
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName);
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char *targetPhone);
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);
