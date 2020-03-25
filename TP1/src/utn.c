/*
 * utn.c
 *
 *  Created on: 24 mar. 2020
 *      Author: nico
 */

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

int suma(int numero1, int numero2)
{
	return (numero1+numero2);
}
int resta(int numero1, int numero2)
{
	return (numero1-numero2);
}
int multiplicacion(int numero1, int numero2)
{
	return (numero1*numero2);
}
float division(int numero1, int numero2)
{
	return ((float)numero1/numero2);
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



