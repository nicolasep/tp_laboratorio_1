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


	int operando1;
	int operando2;

	int opcion;
	int flagOperando1 = 0;
	int flagOperando2 = 0;
	int flagDivision;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialOp1;
	int resultadoFactorialOp2;



	/*printf("1 - Ingresar operando 1\n");
	printf("2 - Ingresar operando 2\n");
	printf("3 - Calcular operaciones\n");
	printf("4 - Mostrar resultados\n");
	printf("5 - Salir\n");*/
	do
	{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			printf("Ingrese operando 1: ");
			scanf("%d",&operando1);
			if(flagOperando1)
			{
				flagOperando1 = 0;
			}
			else
			{
				flagOperando1 = 1;
			}


			break;
		case 2:
			printf("Ingrese operando 2: ");
			scanf("%d",&operando2);
			if(flagOperando2)
			{
				flagOperando2 = 0;
			}
			else
			{
				flagOperando2 = 1;
			}
			break;
		case 3:
			if(flagOperando1 && flagOperando2)
			{
				resultadoSuma = sumar(operando1,operando2);
				resultadoResta = restar(operando1,operando2);
				resultadoMultiplicacion = multiplicar(operando1,operando2);
				flagDivision = dividir(operando1,operando2,&resultadoDivision);
				resultadoFactorialOp1 = factorial(operando1);
				resultadoFactorialOp2 = factorial(operando2);
			}
			else
			{
				printf("Primero debe ingresar operandos!!!\n");
			}

			break;
		case 4:
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

			printf("El resultado del factorial del operando 1 es: %d\n",resultadoFactorialOp1);
			printf("El resultado del factorial del operando 2 es: %d\n",resultadoFactorialOp2);

			break;
		case 5:
			break;
		default:
			break;

		}

		system("cls");
	}while(opcion != 5);




	return EXIT_SUCCESS;
}

