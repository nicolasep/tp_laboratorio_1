/*
 * Employee.h
 *
 *  Created on: 7 may. 2020
 *      Author: Nico
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

void harckodearEmpleados(Employee* list,int len,int* lastId);

int seIngresaronEmpleados(Employee* list, int len);

int swapEmployee(Employee* pNumeroA, Employee* pNumeroB);

int initEmployees(Employee* list, int len);
int searchFree(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);

int getIdRemove(Employee* list, int len);

int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int len);
int modifiEmployee(Employee* list, int len);

int printEmployee(Employee* list, int len, int indice);
int printEmployeById(Employee* list, int len, int id);
int getEmployee(Employee* list, int len, int* id);

int listarTotalYPromedios(Employee* list, int len);

#endif /* EMPLOYEE_H_ */
