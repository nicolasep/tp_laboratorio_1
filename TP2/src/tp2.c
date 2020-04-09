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

	//eEmployee listaEmpleados[TAM];






	return EXIT_SUCCESS;
}
int initEmployees(eEmployee* list, int len)
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
 int flag = -1;


 return flag;
}
int findEmployeeById(eEmployee* list, int len,int id)
{

 return 0;
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

int pedirPalabra(char* mensaje, char* mensajeError, char* palabra, int tamMin, int tamMax)
{
	int flag = 0;
	char buffer[60];
	int valida;

		printf("%s",mensaje);
		fflush(stdin);
		gets(buffer);
		valida = validaPalabra(buffer,tamMin,tamMax);

		while(valida == 0)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			gets(buffer);
			valida = validaPalabra(buffer,tamMin,tamMax);
		}

		flag = 1;
		strcpy(palabra,buffer);

	return flag;
}
int validaPalabra(char* palabra, int tamMin, int tamMax)
{
	int flag = 0;
	int tam = strlen(palabra);

	int i;

	if(tam >= tamMin && tam <= tamMax)
	{
		for(i=0; i<tam; i++)
		{
			if(esLetra(palabra[i]))
			{
				flag = 1;
			}
			else
			{
				break;
			}
		}
	}

	return flag;
}


int esLetra(char letra)
{
	int flag = 0;
	if((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
	{
		flag = 1;
	}

	return flag;
}

int pedirNumero(int* retorno, char* mensaje, char* mensajeError)
{
	char buffer[100];
	//int buffer;
	int numero;
	int valida;
	int flag = 1;

	printf("%s",mensaje);
	fflush(stdin);
	//scanf("%s",&buffer);
	gets(buffer);

	  valida = esNumero(buffer,&numero);
	while (valida == 0)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		//scanf("%d",&buffer);
		gets(buffer);

		valida = esNumero(buffer,&numero);
		flag = 0;
	}
	flag = 1;
	*retorno = numero;



	return flag;
}

int esNumero(char* numero, int* retorno)
{
	int flag = 0;
	int contador = 0;
	int tam = strlen(buffer);

	int i;
	for(i=0; i<tam; i++)
	{
		if(buffer[i] <='9' && buffer[i] >= '0')
		{
			contador ++;
		}
		else
		{
		break;
		}
	}
	if(contador == tam)
	{

		*retorno = atoi(buffer);
		flag = 1;
	}


	return flag;
}

int esTelefononico(char* numero, char* retorno)
{
	int flag = 0;
	int contadorGuiones = 0;
	int tam = strlen(buffer);

	int i;
	for(i=0; i<tam; i++)
	{
		if(buffer[i] <= '9' && buffer[i] >= '0')
		{

		}
		else
		{
			if(buffer[i] == '-')
			{
				contadorGuiones++;
			}
			else
			{
				break;
			}
		}

	}

	if(contadorGuiones == 1)
	{
		flag = 1;
		strcpy(retorno,buffer);
	}

	return flag;
}



