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

	int opcion=menu();

	while(opcion != 5)
	{
		switch(opcion)
		{
		case 1:
			printf("Ingrese operando 1: ");
			scanf("%d",&operando1);
			break;
		case 2:
			printf("Ingrese operando 2: ");
			scanf("%d",&operando2);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;

		}
		opcion=menu();
		system("cls");
	}











	return EXIT_SUCCESS;
}
