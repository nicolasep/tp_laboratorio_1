/*
 * ArrayEmployees.h
 *
 *  Created on: 11 may. 2020
 *      Author: NICO
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NOMBRE_LEN 51
#define APELLIDO_LEN 51

typedef struct
{
	int id;
	char name[NOMBRE_LEN];
	char lastName[APELLIDO_LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;


int menu();

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
int printEmployee(Employee* pEmployee);
int printEmployeById(Employee* list, int len, int id);
int getEmployee(Employee* list, int len, int* id);
int listarTotalYPromedios(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
