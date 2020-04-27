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


int menu();

void harckodearEmpleados(Employee* list,int len,int* lastId);

int seIngresaronEmpleados(Employee* list, int len);

int swapEmployee(Employee* pNumeroA, Employee* pNumeroB);

int initEmployees(Employee* list, int len);
int searchFree(Employee* list, int len);
Employee newEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);

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

int findIndiceEmployeeById(Employee* list, int len,int id);

int listarTotalYPromedios(Employee* list, int len);

int main(void) {

	setbuf(stdout,NULL);


	//El sistema deberá tener el siguiente menú de opciones:
	//1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
	//de Id. El resto de los campos se le pedirá al usuario.
	//2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
	//o Salario o Sector
	//3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
	//4. INFORMAR:
	//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
	//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	//NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
	//Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algun empleado.

	int lastId = 1;
	int salir = 0;

	Employee listaEmpleados[TAM];
	initEmployees(listaEmpleados,TAM);
	harckodearEmpleados(listaEmpleados,TAM,&lastId);


	do
	{
		switch(menu())
		{
		case 1:
			if(!getEmployee(listaEmpleados,TAM,&lastId))
			{
				lastId++;
			}
			printEmployees(listaEmpleados,TAM);
			break;
		case 2:
			if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
			{
				modifiEmployee(listaEmpleados,TAM);
			}
			break;
		case 3:
			if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
			{
				getIdRemove(listaEmpleados,TAM);
			}
			break;
		case 4:
			if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
			{
				sortEmployees(listaEmpleados,TAM,1);
				printEmployees(listaEmpleados,TAM);
				listarTotalYPromedios(listaEmpleados,TAM);
			}
			break;
		case 5:
			salir = 1;
			break;
		}

	}while(salir!=1);



	return EXIT_SUCCESS;
}
void harckodearEmpleados(Employee* list,int len,int* lastId)
{
	char nombres[7][51]={{"NICOLAS"},{"MATIAS"},{"ALEJANDRO"},{"SILVIA"},{"JOSE"},{"LEANDRO"},{"CRISTIAN"}};
	char apellidos[7][51]={{"PEREZ"},{"ARMOLLA"},{"ARMOLLA"},{"GOMEZ"},{"ESPOSITO"},{"FERNANDES"},{"MINUTILLO"}};
	float sueldos[7]={4200,3210,12000,24980,60321,43809,29825};
	int sectores[7]={6,10,3,5,2,8,9};

	int i;

	if(list != NULL)
	{
		for(i=0;i<7;i++)
		{
			if(!addEmployee(list,len,*lastId,nombres[i],apellidos[i],sueldos[i],sectores[i]))
			{
				*lastId+=1;
			}
		}

	}

}
int menu()
{
	int opcion;

	printf("INGRESE UNA OPCION\n");
	printf("1 - ALTA EMPLEADO\n");
	printf("2 - MODIFICAR EMPLEADO\n");
	printf("3 - BAJA EMPLEADO\n");
	printf("4 - INFORMAR\n");
	printf("5 - SALIR\n");
	utn_getNumero(&opcion,"OPCION: ","ERROR, NO ES UNA OPCION CORRECTA\n",1,5,0);


	return opcion;
}

int seIngresaronEmpleados(Employee* list, int len)
{
	int contadorEmpleados = 0;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			contadorEmpleados++;
		}
	}
	if(contadorEmpleados == 0)
	{
		printf("PRIMERO DEBE INGRESAR EMPLEADOS\n");
	}

	return contadorEmpleados;
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
			break;
		}
	}

	return indice;
}
Employee newEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
	Employee aux;
	if(list != NULL && len > 0)
	{
		aux.id = id;
		strcpy(aux.name,name);
		strcpy(aux.lastName,lastName);
		aux.salary =salary;
		aux.sector =sector;
		aux.isEmpty = 0;
	}
	return aux;
}
int getEmployee(Employee* list, int len, int* id)
{
	int retorno = -1;

	char auxName[51];
	char auxLast[51];
	float auxSalary;
	int auxSector;

	if(list != NULL && len > 0 && id > 0)
	{

		if(!utn_getCadena(auxName,"Ingrese Nombre: ","Error, ingrese solo letras\n",3,51,3)
		&& !utn_getCadena(auxLast,"Ingrese Apellido: ","Error, ingrese solo letras\n",3,51,3)
		&& !utn_getNumeroFlotante(&auxSalary,"Ingrese Salario: ","Error, ingrese solo numeros\n",1.0,10000000.0,3)
		&& !utn_getNumero(&auxSector,"Ingrese sector: ","Error, ingrese solo numeros\n",1,1000,3))
		{
			if(!addEmployee(list,len,*id,auxName,auxLast,auxSalary,auxSector))
			{
				retorno = 0;
				*id+=1;
			}
		}

	}

	return retorno;
}
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
 int retorno = -1;
 int indice = searchFree(list,len);
 Employee aux = newEmployee(list,len,id,name,lastName,salary,sector);

 if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && indice != -1)
 {
	 list[indice] = aux;
	 retorno = 0;
 }

 return retorno;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > 0)
	{
		for(i=0 ; i<len; i++)
		{
			if(list[i].id == id)
			{
				retorno = 0;
			}
		}

	}

 return retorno;
}
int findIndiceEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > 0)
	{
		for(i=0 ; i<len; i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}

	}

 return retorno;
}
int printEmployee(Employee* list, int len, int indice)
{
	int retorno = -1;
	if(list != NULL && len>0)
	{
		printf("%d%13s%13s   %.2f\t %d\n",list[indice].id,list[indice].name,list[indice].lastName,list[indice].salary,list[indice].sector);
	}
	retorno = 0;

	return retorno;
}
int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int mostroMensaje = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(mostroMensaje==0)
				{
					printf("\nID\tNOMBRE\t   APELLIDO  SALARIO\tSECTOR\n\n");

				 mostroMensaje = 1;
				}
				retorno = printEmployee(list,len,i);
			}

		}
	}
	return retorno;
}
int printEmployeById(Employee* list, int len, int id)
{
	int retorno = -1;
	int mostroMensaje = 0;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==0 && list[i].id==id)
			{
				if(mostroMensaje==0)
				{
					printf("ID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");

				    mostroMensaje = 1;
				}
				printEmployee(list,len,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}
int modifiEmployee(Employee* list, int len)
{
	int retorno = -1;
	int idEmpleado;
	int indice;
	int opcionModificar;

	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;


	if(list != NULL && len > 0)
	{
		printf("----MODIFICAR EMPLEADO----\n");
		printEmployees(list, len);
		if(utn_getNumero(&idEmpleado,"Ingrese el ID del empleado a modificar","Error, no es un valor aceptado\n",1,10000,3)==0 &&
		   findEmployeeById(list,len,idEmpleado)==0)
		{
			indice = findIndiceEmployeeById(list,len,idEmpleado);

			printf("El empleado seleccionado es:\n");
			printEmployee(list,len,indice);

			if(!utn_getNumero(&opcionModificar,"Indique el campo a modificar\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n","Error, No se encuentra entre las opciones\n",1,4,3))
			{
				switch(opcionModificar)
				{
				case 1:
					if(!utn_getCadena(auxNombre,"Ingrese Nuevo nombre: ","Error, deben ser letras!!!\n",3,51,3))
					{
						strcpy(list[indice].name,auxNombre);
					}
					break;
				case 2:
					if(!utn_getCadena(auxApellido,"Ingrese Nuevo apellido: ","Error, deben ser letras!!!\n",3,51,3))
					{
						strcpy(list[indice].lastName,auxApellido);
					}
					break;
				case 3:
					if(!utn_getNumeroFlotante(&auxSalario,"Ingrese Nuevo salario: ","Error, deben ser numeros!!!\n",0,1000000,3))
					{
						list[indice].salary = auxSalario;
					}
					break;
				case 4:
					if(!utn_getNumero(&auxSector,"Ingrese Nuevo sector: ","Error, deben ser numeros!!!\n",1,10000,3))
					{
						list[indice].sector = auxSector;
					}
					break;
				}

				retorno = 0;
			}
			else
			{
				printf("Operacion cancelada\n");
			}
		}
	}

	return retorno;
}
/*
int getIdRemove(Employee* list, int len)
{
	int retorno = -1;
	int idEliminar;
	int indice;
	char confirmacion;


	if(list != NULL && len > 0)
	{
		printf("----REMOVER EMPLEADO----\n");
		printEmployees(list, len);
		if(utn_getNumero(&idEliminar,"Ingrese el ID del empleado a eliminar","Error, no es un valor aceptado\n",1,1000,3)==0 &&
		   findEmployeeById(list,len,idEliminar)==0)
		{
			indice = findIndiceEmployeeById(list,len,idEliminar);
			printf("El empleado seleccionado es:\n");
			printEmployee(list,len,indice);
			fflush(stdin);
			if(utn_getChar(&confirmacion,"Esta seguro que desea seguir, Igrese S para eliminar: ","Operacion cancelada\n",'s','S',0)
			&&(confirmacion =='s' || confirmacion =='S'))
			{
				list[indice].isEmpty = -1;
				retorno = 0;
			}

		}
		else
		{
			printf("EL ID DE EMPLEADO NO EXISTE\n");
		}
	}


	 return retorno;
}*/
int getIdRemove(Employee* list, int len)
{
	int retorno = -1;
	int idEliminar;
	char confirmacion;


	if(list != NULL && len > 0)
	{
		printf("----REMOVER EMPLEADO----\n");
		printEmployees(list, len);
		if(utn_getNumero(&idEliminar,"Ingrese el ID del empleado a eliminar","Error, no es un valor aceptado\n",1,1000,3)==0 &&
		   findEmployeeById(list,len,idEliminar)==0)
		{

			printf("El empleado seleccionado es:\n");
			printEmployeById(list,len,idEliminar);
			fflush(stdin);
			if(!utn_getChar(&confirmacion,"Esta seguro que desea seguir, Igrese S para eliminar: ","Operacion cancelada\n",'S','s',0)
			&&(confirmacion =='s' || confirmacion =='S'))
			{
				if(!removeEmployee(list,len,idEliminar))
				{
					retorno = 0;
					printf("EMPLEADO ELIMINADO CON EXITO\n");
				}

			}

		}
		else
		{
			printf("EL ID DE EMPLEADO NO EXISTE\n");
		}
	}


	 return retorno;
}
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int indice;

	if(list != NULL && len > 0 && id > 0)
	{
		indice = findIndiceEmployeeById(list,len,id);

				list[indice].isEmpty = -1;
				retorno = 0;

	}

 return retorno;
}
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
				if(list[i].isEmpty==0)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
					{
						swapEmployee(list+i,list+i+1);
						flagSwap = 1;
					}
					/*else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
						{
							if(list[i].sector > list[i+i].sector)
							{
								swapEmployee(list+i,list+i+1);
								flagSwap = 1;
							}
						}
					}*/
				}
			}
			limiteVariable--;

		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}
int listarTotalYPromedios(Employee* list, int len)
{
	int retorno = -1;
	float promedio;
    float acumuladorSalarios = 0;
    int contadorSuperanPromedio = 0;
    int contadorEmpleados = 0;
    int i;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumuladorSalarios += list[i].salary;
				contadorEmpleados ++;
			}
		}
		promedio = acumuladorSalarios / contadorEmpleados;
		for(i=0; i<len; i++)
		{
			if(list[i].salary > promedio && list[i].isEmpty == 0)
			{
				contadorSuperanPromedio++;
			}
		}
		printf("\nEL TOTAL DE LOS SALARIOS ES: %.2f\n",acumuladorSalarios);
		printf("EL PROMEDIO DE SALARIOS ES: %.2f\n",promedio);
		printf("LA CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO ES: %d\n\n",contadorSuperanPromedio);

		retorno = 0;
	}

	return retorno;
}
/*

					else if(order == 2 && list[i].isEmpty==0)
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
}
*/



