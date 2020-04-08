/*
 ============================================================================
 Name        : TP1.c
 Author      : Nicolas Eduardo Perez
 Version     : 4.1
 Copyright   : Your copyright notice
 Description : Ansi-style, Calculadora en C
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

	//VANDERAS PARA VERIFICAR RETORNOS
	int flagOperando1 = 0;
	int flagOperando2 = 0;
	int flagOperaciones = 0;

	int respuestaDivision;
	int respuestaFactorialOp1;
	int respuestaFactorialOp2;


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

		switch(menu(operando1,operando2,flagOperando1,flagOperando2))
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
				respuestaDivision = dividir(&resultadoDivision, operando1,operando2);
				resultadoMultiplicacion = multiplicar(operando1,operando2);
				respuestaFactorialOp1 = factorial(&resultadoFactorialOp1, operando1);
				respuestaFactorialOp2 = factorial(&resultadoFactorialOp2, operando2);
				flagOperaciones = 1;
				printf("OPERACIONES REALIZADAS CON EXITO!!!\n");
			}
			else
			{
				printf("PRIMERO DEBE INGRESAR AMBOS OPERANDOS!!!\n");
			}

			break;

		case 4:
			//MUESTRA UNA ALERTA SI EL USUARIO QUIERE INFORMAR LOS RESULTADOS SIN ANTES CALCULAR LAS OPERACIONES
			//O SI ALGUN OPERANDO FUE MODIFICADO
			//SI TODO ESTA BIEN INFORMA RESULTADOS
			if(flagOperaciones)
			{
				printf("El resultado de A+B es: %d\n",resultadoSuma);
				printf("El resultado de A-B es: %d\n",resultadoResta);

				if(respuestaDivision == 0)//VERIFICA QUE EL OPERANDO B NO SEA 0 Y EN ESE CASO MUESTRA EL ERROR
				{
					printf("El resultado de A/B es: %.2f\n",resultadoDivision);
				}
				else
				{
					printf("No se puede dividir por 0\n");
				}

				printf("El resultado de A*B es: %d\n",resultadoMultiplicacion);



				if(respuestaFactorialOp1 == 0 && respuestaFactorialOp2 == 0)//VERIFICA QUE LOS OPERANDOS SEAN MAYOR QUE 0, DE LO CONTRARIO MUESTRA ERROR SEGUN EL CASO
				{
					printf("El factorial de A es: %li y El factorial de B es: %li\n",resultadoFactorialOp1,resultadoFactorialOp2);
				}
				else
				{
					if(respuestaFactorialOp1 == -1 && respuestaFactorialOp2 == 0)
					{
						printf("No se puede calcular el factorial del operando A por que el numero ingresado debe ser mayor a 0\n");
						printf("El resultado del factorial del operando B es: %li\n",resultadoFactorialOp2);
					}
					else if(respuestaFactorialOp1 == 0 && respuestaFactorialOp2 == -1)
					{
						printf("El resultado del factorial del operando A es: %li\n",resultadoFactorialOp1);
						printf("No se puede calcular el factorial del operando B por que el numero ingresado debe ser mayor a 0\n");
					}
					else
					{
						printf("No se puede calcular el factorial de A y B por que ambos deben ser mayor a 0\n");
					}
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



	copia();
	system("pause");

	return EXIT_SUCCESS;
}

