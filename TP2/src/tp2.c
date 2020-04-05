/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}eEmployee;

#define TAM 1000

int initEmployees(eEmployee* list, int len);
int searchFree(eEmployee* list, int len);

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(eEmployee* list, int len,int id);
int removeEmployee(eEmployee* list, int len, int id);
int sortEmployees(eEmployee* list, int len, int order);
int printEmployees(eEmployee* list, int len);


int main(void) {
	/*El sistema deberá tener el siguiente menú de opciones:
	1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
	de Id. El resto de los campos se le pedirá al usuario.
	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
	o Salario o Sector
	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
	4. INFORMAR:
	1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	carga de algún empleado.
	 * */

	eEmployee listaEmpleados[TAM];






	return EXIT_SUCCESS;
}
int initEmployees(eEmployee* list, int len)
{
	int flag = 0;
	int i;
	for(i=0; i<len; i++)
	{
		*list[i].isEmpty = 1;

	}
	if(i == len)
	{
		flag = 1;
	}

 return flag;
}
int searchFree(eEmployee* list, int len)
{
	int indice = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty)
		{
			indice = i;
		}
	}

	return indice;
}


int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

 return -1;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
 return NULL;
}

int removeEmployee(eEmployee* list, int len, int id)
{
 return -1;
}

int sortEmployees(eEmployee* list, int len, int order)
{
 return 0;
}
int printEmployees(eEmployee* list, int len)
{
	int flag = 0;
	int cont = 0;
	int i;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			if(cont == 0)
			{
				printf("ID NOMBRE APELLIDO SALARIO SECTOR\n");
			}
			printf("%d %s %s %.2f %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);

			flag = 1;
		}
	}
 return flag;
}


