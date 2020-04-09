/*
 * utn.c
 *
 *  Created on: 24 mar. 2020
 *      Author: Nicolas Eduardo Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(int operando1, int operando2,int flag1, int flag2)
{
	int opcion;
	printf("Elija una opcion:\n");
	if(flag1 == 0)
	{
		printf("1 - Ingresar 1er operando A\n");
	}
	else
	{
		printf("1 - Ingresar 1er operando A = %d\n",operando1);
	}
	if(flag2 == 0)
	{
		printf("2 - Ingresar 2do operando B\n");
	}
	else
	{
		printf("2 - Ingresar 2do operando B = %d\n",operando2);
	}

	printf("3 - Calcular todas las operaciones\n");
	printf("4 - Informar resultados\n");
	printf("5 - SALIR\n");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;
}
int get_Numero(int* pResultado, char* mensaje, char* mensajeError)
{
	int buffer;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		if(scanf("%d",&buffer))
		{
			*pResultado = buffer;
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}
	return retorno;

}

int sumar(int numero1, int numero2)
{
	int respuesta = numero1+numero2;
	return respuesta;
}
int restar(int numero1, int numero2)
{
	int respuesta = numero1-(numero2);
	return respuesta;
}
int multiplicar(int numero1, int numero2)
{
	int respuesta = numero1*numero2;
	return respuesta;
}
int dividir(float* pResultado, int numero1, int numero2)
{
	float buffer;
	int respuesta = -1;

	if(numero2 != 0 && pResultado != NULL)
	{
		buffer = (float)numero1/numero2;
		*pResultado = buffer;
		respuesta = 0;
	}


	return respuesta;
}
int factorial(long* pResultado, int numero)
{
	long factorial = 1;
	int respuesta = -1;

	if(numero > 0 && pResultado != NULL)
	{
		for(int i=numero;i>0;i--)
		{
		factorial = factorial * i;
		}
		*pResultado = factorial;
		respuesta = 0;
	}

	return respuesta;
}



































































void copia()
{
	printf("\nTRABAJO PRACTICO N 1, PROGRAMADO POR NICOLAS EDUARDO PEREZ, DIVISION 1H\n");
}

