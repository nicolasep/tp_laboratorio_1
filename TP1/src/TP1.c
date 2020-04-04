/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	//VARIABLES PARA DATOS INGRESADOS
	int operando1;
	int operando2;

	//VARIABLE PARA SALIR DEL WHILE
	int salir = 1;

	//VANDERAS PARA CONTROL DEL ACCESO DE DATOS
	int flagOperando1 = 0;
	int flagOperando2 = 0;
	int flagDivision;
	int flagFactorialOp1;
	int flagFactorialOp2;
	int flagOperaciones = 0;

	//VARIABLES DE RESULTADOS
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long resultadoFactorialOp1;
	long resultadoFactorialOp2;

	do
	{
		system("cls");

		switch(menu())
		{
		case 1:

			printf("Ingrese operando A: ");
			scanf("%d",&operando1);
			//SI EL USUARIO ESTA VOLVIENDO A INGRASAR UN NUMERO DE ESTA FORMA EXIGE EL CALCULO NUEVO DE OPERACIONES

			flagOperando1 = 1;
			flagOperaciones = 0;

			break;

		case 2:

			printf("Ingrese operando B: ");
			scanf("%d",&operando2);
			//SI EL USUARIO ESTA VOLVIENDO A INGRASAR UN NUMERO DE ESTA FORMA EXIGE EL CALCULO NUEVO DE OPERACIONES

			flagOperando2 = 1;
			flagOperaciones = 0;

			break;

		case 3:
			//DE ESTA FORMA EVALUO QUE USUARIO HALLA INGRESADO AMBOS DATOS PARA EL CALCULO DE OPERACIONES
			if(flagOperando1 && flagOperando2)
			{
				resultadoSuma = sumar(operando1,operando2);
				resultadoResta = restar(operando1,operando2);
				resultadoMultiplicacion = multiplicar(operando1,operando2);
				flagDivision = dividir(operando1,operando2,&resultadoDivision);
				flagFactorialOp1 = factorial(operando1,&resultadoFactorialOp1);
				flagFactorialOp2 = factorial(operando2,&resultadoFactorialOp2);
				flagOperaciones = 1;
				printf("OPERACIONES REALIZADAS CON EXITO!!!\n");
			}
			else
			{
				printf("PRIMERO DEBE INGRESAR AMBOS OPERANDOS!!!\n");
			}

			break;

		case 4:
			//MUESTRA UNA ALERTA SI EL USUARIO QUIERE INFORMAR LOS RESULTADOS SI ANTES CALCULARLOS O SI FUERON MODIFICADOS
			if(flagOperaciones)
			{
				printf("OPERANDO A: %d\n",operando1);
				printf("OPERANDO B: %d\n",operando2);

				printf("El resultado de la suma es: %d\n",resultadoSuma);
				printf("El resultado de la resta es: %d\n",resultadoResta);
				printf("El resultado de la multiplicacion es: %d\n",resultadoMultiplicacion);
				if(flagDivision)
				{
					printf("El resultado de la division es: %.2f\n",resultadoDivision);
				}
				else
				{
					printf("No se puede dividir por 0");
				}
				if(flagFactorialOp1)
				{
					printf("El resultado del factorial del operando A es: %li\n",resultadoFactorialOp1);
				}
				else
				{
					printf("No se puede calcular el factorial del operando A por que el numero ingresado debe ser mayor a 0\n");
				}

				if(flagFactorialOp2)
				{
					printf("El resultado del factorial del operando B es: %li\n",resultadoFactorialOp2);
				}
				else
				{
					printf("No se puede calcular el factorial del operando B por que el numero ingresado debe ser mayor a 0\n");
				}
			}
			else
			{
				printf("PRIMERO DEBE CALCULAR LAS OPERACIONES!!!\n");
			}

			break;

		case 5:
			salir = 0;

			break;

		default:
			printf("OPCION INCORRECTA!!!\n");

			break;
		}

		system("pause");

	}while(salir);




	return EXIT_SUCCESS;
}

