#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* SueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_getIdChar(Employee* this,char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getHorasTrabajadasChar(Employee* this,char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getSueldoChar(Employee* this,char* sueldo);

int employee_printEmployee(Employee* pElement);
int employee_printById(LinkedList* pArrayListEmployee, int id);
int employee_findById(LinkedList* pArrayListEmployee, int id);
int employee_idMax(LinkedList* pArrayListEmployee);
int employee_funcionCriterioPorSueldo(void* item1,void* item2);
int employee_funcionCriterioPorHorasT(void* item1,void* item2);



#endif // employee_H_INCLUDED
