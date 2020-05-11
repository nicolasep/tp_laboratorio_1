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
#include "Employee.h"



#define TAM 1000


int menu();



int main(void) {

	setbuf(stdout,NULL);

	int lastId = 1;
	int salir = 0;
	int flagOrdenado = 0;
	Employee listaEmpleados[TAM];


	if(!initEmployees(listaEmpleados,TAM))
	{
		harckodearEmpleados(listaEmpleados,TAM,&lastId);

		do
		{
			switch(menu())
			{
			case 1:
				getEmployee(listaEmpleados,TAM,&lastId);
				printEmployees(listaEmpleados,TAM);
				flagOrdenado = 0;
				break;
			case 2:
				if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
				{
					modifiEmployee(listaEmpleados,TAM);
					flagOrdenado = 0;
				}
				break;
			case 3:
				if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
				{
					getIdRemove(listaEmpleados,TAM);
					flagOrdenado = 0;
				}
				break;
			case 4:
				if(seIngresaronEmpleados(listaEmpleados,TAM)>0)
				{
					if(flagOrdenado == 0)
					{
						sortEmployees(listaEmpleados,TAM,1);
						flagOrdenado = 1;
					}
					printEmployees(listaEmpleados,TAM);
					listarTotalYPromedios(listaEmpleados,TAM);
				}
				break;
			case 5:
				salir = 1;
				break;
			}

		}while(salir!=1);
	}





	return EXIT_SUCCESS;
}
