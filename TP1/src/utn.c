/*
 * utn.c
 *
 *  Created on: 24 mar. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int opcion;
	printf("Elija una opcion:\n");
	printf("1 - Ingresar operando 1\n");
	printf("2 - Ingresar operando 2\n");
	printf("3 - Calcular operaciones\n");
	printf("4 - Mostrar resultados\n");
	printf("5 - Salir\n");
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
long factorial(int numero)
{
	long factorial=1;
	for(int i=numero;i>0;i--)
	{
	factorial = factorial * i;
	}

	return factorial;
}



