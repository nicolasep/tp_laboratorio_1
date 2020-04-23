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
#include <string.h>
#include "utn.h"


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

#define TAM 1000

int swapEmployee(Employee* pNumeroA, Employee* pNumeroB);

int initEmployees(Employee* list, int len);
int searchFree(Employee* list, int len);
Employee newEmployee(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int len);



int main(void) {


	//El sistema deber� tener el siguiente men� de opciones:
	//1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
	//de Id. El resto de los campos se le pedir� al usuario.
	//2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
	//o Salario o Sector
	//3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
	//4. INFORMAR:
	//1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
	//2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
	//NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
	//Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algun empleado.

	//eEmployee listaEmpleados[TAM];






	return EXIT_SUCCESS;
}
int initEmployees(Employee* list, int len)
{
	int flag = 0;
	int i;

	for(i=0; i<len; i++)
	{
		list[i].isEmpty = 1;

	}
	if(i == len)
	{
		flag = 1;
	}

 return flag;
}
int searchFree(Employee* list, int len)
{
	int indice = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			indice = i;
		}
	}

	return indice;
}
Employee newEmployee(Employee* list, int len)
{
	Employee aux;
	if(list != NULL && len > 0)
	{
		aux.id = list->id;
		strcpy(aux.name,list->name);
		strcpy(aux.lastName,list->lastName);
		aux.salary = list->salary;
		aux.sector = list->sector;
		aux.isEmpty = 0;
	}
	return aux;
}
int newEmployeeParam(Employee* list, int len, int id)
{
	int retorno = -1;
	int indice = searchFree(list,len);
	int arraySalioBien[4] = {-1,-1,-1,-1};

	if(list != NULL && len > 0 && id > 0)
	{
		arraySalioBien[0] = utn_getCadena(list[indice].name,"Ingrese Nombre: ","Error, ingrese solo letras\n",3,51,3);
		arraySalioBien[1] = utn_getCadena(list[indice].lastName,"Ingrese Apellido: ","Error, ingrese solo letras\n",3,51,3);
		arraySalioBien[2] = utn_getNumeroFlotante(&list[indice].salary,"Ingrese Salario: ","Error, ingrese solo numeros\n",1.0,10000.0,3);
		arraySalioBien[3] = utn_getNumero(&list[indice].sector,"Ingrese sector: ","Error, ingrese solo numeros\n",1,1000,3);

		if(arraySalioBien[0]==0 && arraySalioBien[1]==0 && arraySalioBien[2]==0 && arraySalioBien[3]==0)
		{

		}

	}

	return retorno;
}
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
 int flag = -1;

 if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL)
 {

 }


 return flag;
}
int findEmployeeById(Employee* list, int len,int id)
{

 return 0;
}
int removeEmployee(Employee* list, int len, int id)
{
 return -1;
}
/*
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int contador = 0;
	int limiteVariable;

	if(list != NULL && len > 0)
	{
		limiteVariable = len -1;
		retorno = 0;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteVariable;i++)
			{
				contador++;
				if(list[i] < list[i+1])
				{
					intSwap(list+i,list+i+1);

					flagSwap = 1;
				}
			}

			limiteVariable--;
		}while(flagSwap);
		retorno = contador;
	}

	return retorno;
}*/
int swapEmployee(Employee* pNumeroA, Employee* pNumeroB)
{
	int retorno = -1;
	Employee buffer;
	if(pNumeroA != NULL && pNumeroB != NULL)
	{
		buffer = *pNumeroA;
	    *pNumeroA = *pNumeroB;
	    *pNumeroB = buffer;
	    retorno = 0;
	}
	return retorno;
}
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int contador = 0;
	int limiteVariable;

	if(list != NULL && len > 0 && (order == 1 || order == 2))
	{
		limiteVariable = len -1;
		retorno = 0;
		do
		{

			for(i=0; i<limiteVariable;i++)
			{
				contador++;
				flagSwap = 0;
				if(order == 1)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
					{
						swapEmployee(list+i,list+i+1);
						flagSwap = 1;
					}
					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
					{
						if(list[i].sector > list[i+i].sector)
						{
							swapEmployee(list+i,list+i+1);
							flagSwap = 1;
						}
					}
				}
				else
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) < 0)
					{
						swapEmployee(list+i,list+i+1);
						flagSwap = 1;
					}
					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
					{
						if(list[i].sector < list[i+i].sector)
						{
							swapEmployee(list+i,list+i+1);
							flagSwap = 1;
						}
					}
				}
			}

			limiteVariable--;
		}while(flagSwap);
		retorno = contador;
	}

	return retorno;
}

int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int cont = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(cont == 0)
				{
					printf("ID NOMBRE APELLIDO SALARIO SECTOR\n");
					cont = 1;
				}
				printf("%d %s %s %.2f %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);

				retorno = 0;
			}
		}
	}

 return retorno;
}



