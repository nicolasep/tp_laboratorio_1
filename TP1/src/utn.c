/*
 * utn.c
 *
 *  Created on: 24 mar. 2020
 *      Author: Nicolas Eduardo Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * muestra el menu y devuelve la opcion seleccionada y valida si no se ingresar
 * param1 variable del primer numero
 * param2 variable del segundo numero
 * param3 variable utulizada para mostrar en el menu el primer numero si se ingreso
 * param4 variable utilizada como mostrar en el menu el segundo numero si se ingreso
 * return retorna el numero de la opcion seleccionada
 * */

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
/*
 * pide un numero lo valida y lo devuelve
 * param1 puntero a la variable del numero validado
 * param2 mensaje para mostrar
 * param3 mensaje de error
 * return devuelve -1 si no es un numero y 0 si esta bien
 * */
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
/*
 * suma dos numeros y devuelve el resultado
 * param1 variable del primer numero
 * param2 vaiable del segundo numero
 * return retorna el resultado de la operacion
 * */
int sumar(int numero1, int numero2)
{
	int respuesta = numero1+numero2;
	return respuesta;
}
/*
 * resta dos numeros y devuelve el resultado
 * param1 variable del primer numero
 * param2 vaiable del segundo numero
 * return retorna el resultado de la operacion
 * */
int restar(int numero1, int numero2)
{
	int respuesta = numero1-(numero2);
	return respuesta;
}
/*
 * multiplica dos numeros y devuelve el resultado
 * param1 variable del primer numero
 * param2 vaiable del segundo numero
 * return retorna el resultado de la operacion
 * */
int multiplicar(int numero1, int numero2)
{
	int respuesta = numero1*numero2;
	return respuesta;
}
/*
 * divide dos numeros y devuelve el resultado. valida que el segundo numero sea mayor a cero
 * param1 puntero a variable donde se guarda el resultado de la operacion
 * param2 variable del primer numero
 * param3 vaiable del segundo numero
 * return retorna -1 si fue errror y 0 si se pudo hacer la operacion
 * */
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
/*
 * realiza el calculo de factorial de un numreo y devuleve el resultado
 * param1 puntero a la variable donde se guarda el resultado
 * param2 numero a cual se le realiza la operacion
 * return devuelve -1 si no se puedo hacer y 0 si se concreto la operacion
 * */
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

