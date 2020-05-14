/*
 ============================================================================
 Name        : tp2.c
 Author      : NICOLAS EDUARDO PEREZ 1H
 Version     :
 Copyright   : Your copyright notice
 Description : TP 2 UTN C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"



#define EMPLOYEE_LEN 1000


int main(void) {

	setbuf(stdout,NULL);

	int lastId = 1;
	int salir = 0;
	int flagOrdenado = 0;
	int criterioDeOrdenado;
	static const char TIPO_ORDEN[2][12] ={"DESCENDENTE","ASCENDENTE"};

	Employee listaEmpleados[EMPLOYEE_LEN];


	if(!initEmployees(listaEmpleados,EMPLOYEE_LEN))
	{
		harckodearEmpleados(listaEmpleados,EMPLOYEE_LEN,&lastId);//lista pre cargada con empleados para prueba

		do
		{
			switch(menu())
			{
			case 1:
				if(!getEmployee(listaEmpleados,EMPLOYEE_LEN,&lastId))
				{
				printEmployees(listaEmpleados,EMPLOYEE_LEN);
				flagOrdenado = 0;
				}
				break;
			case 2:
				if(seIngresaronEmpleados(listaEmpleados,EMPLOYEE_LEN)>0)
				{
					modifiEmployee(listaEmpleados,EMPLOYEE_LEN);
					flagOrdenado = 0;
				}
				break;
			case 3:
				if(seIngresaronEmpleados(listaEmpleados,EMPLOYEE_LEN)>0)
				{
					getIdRemove(listaEmpleados,EMPLOYEE_LEN);
					flagOrdenado = 0;
				}
				break;
			case 4:
				if(seIngresaronEmpleados(listaEmpleados,EMPLOYEE_LEN)>0)
				{
					if(!utn_getNumero(&criterioDeOrdenado,"ELIJA EL CRITERIO DE ORDENADO\n"
														  "1 - DESCENDENTE\n"
														  "2 - ASCENDENTE\n","LA OPCION NO ES VALIDO\n",1,2,2) &&
							(flagOrdenado == 0 || flagOrdenado != criterioDeOrdenado))
					{
						sortEmployees(listaEmpleados,EMPLOYEE_LEN,criterioDeOrdenado-1);
						flagOrdenado = criterioDeOrdenado;
						printf("LA LISTA SE ORDENADO CORRECTAMENTE DE FORMA %s\n",TIPO_ORDEN[criterioDeOrdenado-1]);
					}
					else
					{
						printf("LA LISTA FUE ORDENADA ANTERIORMENTE POR EL MISMO CRITERIO\n");
					}
					printEmployees(listaEmpleados,EMPLOYEE_LEN);
					listarTotalYPromedios(listaEmpleados,EMPLOYEE_LEN);
				}
				break;
			case 5:
				salir = 1;
				break;
			}

		}while(salir!=1);
	}
	else
	{
		printf("ERROR AL INICIALIZAR LA LISTA\n");
	}





	return EXIT_SUCCESS;
}
