/*
 * utn.c
 *
 *  Created on: 24 mar. 2020
 *      Author: Nicolas Eduardo Perez
 */

#include <stdio.h>
#include <stdlib.h>

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
		printf("2 - Ingresar 1er operando B = %d\n",operando2);
	}

	printf("3 - Calcular todas las operaciones\n");
	printf("4 - Informar resultados\n");
	printf("5 - SALIR\n");
	scanf("%d",&opcion);

	return opcion;
}

int sumar(int numero1, int numero2)
{
	int respuesta = numero1+numero2;
	return respuesta;
}
int restar(int numero1, int numero2)
{
	int respuesta = numero1-numero2;
	return respuesta;
}
int multiplicar(int numero1, int numero2)
{
	int respuesta = numero1*numero2;
	return respuesta;
}
int dividir(int numero1, int numero2, float* respuesta)
{
	int flag = 0;
	if(numero2 != 0)
	{
		*respuesta = (float)numero1/numero2;
		flag = 1;
	}
	return flag;
}
int factorial(int numero, long* resultado)
{
	long factorial=1;
	int flag = 0;

	if(numero > 0)
	{
		for(int i=numero;i>0;i--)
		{
		factorial = factorial * i;
		}
		*resultado = factorial;
		flag = 1;
	}

	return flag;
}



































































void copia()
{
	printf("\nTRABAJO PRACTICO N 1, PROGRAMADO POR NICOLAS EDUARDO PEREZ, DIVISION 1H\n");
}

