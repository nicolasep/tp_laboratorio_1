/*
 * Employee.c
 *
 *  Created on: 7 may. 2020
 *      Author: Nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

void harckodearEmpleados(Employee* list,int len,int* lastId)
{
	char nombres[7][51]={{"NICOLAS"},{"MATIAS"},{"ALEJANDRO"},{"SILVIA"},{"JOSE"},{"LEANDRO"},{"CRISTIAN"}};
	char apellidos[7][51]={{"PEREZ"},{"ARMOLLA"},{"ARMOLLA"},{"GOMEZ"},{"ESPOSITO"},{"FERNANDES"},{"MINUTILLO"}};
	float sueldos[7]={4200,3210,12000,24980,60321,43809,29825};
	int sectores[7]={6,10,3,5,2,8,9};

	int i;

	if(list != NULL)
	{
		for(i=0;i<7;i++)
		{
			if(!addEmployee(list,len,*lastId,nombres[i],apellidos[i],sueldos[i],sectores[i]))
			{
				*lastId+=1;
			}
		}

	}

}
int menu()
{
	int opcion;

	printf("INGRESE UNA OPCION\n");
	printf("1 - ALTA EMPLEADO\n");
	printf("2 - MODIFICAR EMPLEADO\n");
	printf("3 - BAJA EMPLEADO\n");
	printf("4 - INFORMAR\n");
	printf("5 - SALIR\n");
	utn_getNumero(&opcion,"OPCION: ","ERROR, NO ES UNA OPCION CORRECTA\n",1,5,0);

	return opcion;
}

/*
 * \brief verifica si se encontraron elementos cargados en el array empleados y devuelve el resultado
 * \param array de emplados
 * \param longitud del array
 * \return si hay empleados cargados devulve la cantidad y si no los hay devuelve 0 mas un mensaje de aviso
 */
int seIngresaronEmpleados(Employee* list, int len)
{
	int contadorEmpleados = 0;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			contadorEmpleados++;
			break;
		}
	}
	if(contadorEmpleados == 0)
	{
		printf("PRIMERO DEBE INGRESAR EMPLEADOS\n");
	}

	return contadorEmpleados;
}
/*
 * \brief inicializa el campo isEmpy del array de empleados
 * \param array de empleados
 * \param longitud del array de empleados
 * \return retorna 0 si lo puedo hacer y -1 si no
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
	    {
			list[i].isEmpty = 1;
	    }
		retorno = 0;
	}

 return retorno;
}
/*
 * \brief busca la primera posicion libre del array y la devuelve
 * \param array de empleados
 * \param longitud del array de empleados
 * \return devuelve la posicion libre del array y si no encontro devuelve -1
 */
int searchFree(Employee* list, int len)
{
	int indice = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

/*
 * \brief pide los datos de un empleado al usuario y los valida
 * \param array de empleados
 * \param longitud del array de empleados
 * \param id es el id a utilizar por el nuevo emplado
 * \return devuelve 0 si se pudo cargar y -1 si no
 */
int getEmployee(Employee* list, int len, int* id)
{
	int retorno = -1;

	Employee auxEmployee;

	if(list != NULL && len > 0 && id > 0)
	{

		if(!utn_getCadena(auxEmployee.name,"Ingrese Nombre: ","Error, ingrese solo letras\n",3,51,3)
		&& !utn_getCadena(auxEmployee.lastName,"Ingrese Apellido: ","Error, ingrese solo letras\n",3,51,3)
		&& !utn_getNumeroFlotante(&auxEmployee.salary,"Ingrese Salario: ","Error, ingrese solo numeros\n",1.0,10000000.0,3)
		&& !utn_getNumero(&auxEmployee.sector,"Ingrese sector: ","Error, ingrese solo numeros\n",1,1000,3))
		{
			if(!addEmployee(list,len,*id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector))
			{
				retorno = 0;
				*id+=1;
			}
		}

	}

	return retorno;
}
/*
 * \brief carga los datos de un empleado en el array
 * \param array de empleados
 * \param longitud del array de empleados
 * \param id del empleado
 * \param nombre del empleado
 * \param apellido del empleado
 * \param salario del emplado
 * \param sector del empleado
 * \return devuelve 0 si lo pudo cargar y -1 si no pudo
 */
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
 int retorno = -1;
 int indice = searchFree(list,len);

 if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL &&
	indice != -1 && salary >= 0 && sector >= 0)
 {

	list[indice].id = id;
	strcpy(list[indice].name,name);
	strcpy(list[indice].lastName,lastName);
	list[indice].salary =salary;
	list[indice].sector =sector;
	list[indice].isEmpty = 0;

	 retorno = 0;
 }

 return retorno;
}
/*
 * \brief busca un empleado por su id y devuelve el resultado
 * \param array de empleados
 * \param longitud del array de empleados
 * \param id a ser buscado
 * \return devuelve la posicion del array del id ingresado y si no lo encuentra devuelve -1
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > 0)
	{
		for(i=0 ; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
			}
		}

	}

 return retorno;
}

int printEmployee(Employee* list, int len, int indice)
{
	int retorno = -1;
	if(list != NULL && len>0)
	{
		printf("%d%13s%13s   %.2f\t %d\n",list[indice].id,list[indice].name,list[indice].lastName,list[indice].salary,list[indice].sector);
	}
	retorno = 0;

	return retorno;
}
/*
 * \brief imprime la lista de empleados
 * \param array de empleados
 * \param longitud del array empleados
 * \return devuelve 0 si los pudo imprimir y -1 si no
 */
int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int mostroMensaje = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(mostroMensaje==0)
				{
					printf("\nID\tNOMBRE\t   APELLIDO  SALARIO\tSECTOR\n\n");

				 mostroMensaje = 1;
				}
				printEmployee(list,len,i);
			}
			retorno = 0;

		}
	}
	return retorno;
}
/*
 * \brief imprime un empleado ingresado por id
 * \param array de empleados
 * \param longitud del array empleado
 * \param id del empleado a imprimir
 * \return 0 si lo pudo imprimir y -1 si no
 */
int printEmployeById(Employee* list, int len, int id)
{
	int retorno = -1;
	int mostroMensaje = 0;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==0 && list[i].id==id)
			{
				if(mostroMensaje==0)
				{
					printf("ID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");

				    mostroMensaje = 1;
				}
				printEmployee(list,len,i);
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}
/*
 * \brief pide al usuario que ingrese el id de un empleado y lo modifica
 * \param array de empleados
 * \param longitud del array de empleados
 * return devuelve 0 si lo pudo modificar y -1 si no
 */
int modifiEmployee(Employee* list, int len)
{
	int retorno = -1;
	int idEmpleado;
	int indice;
	int opcionModificar;

	char auxString[51];
	float auxFloat;
	int auxInt;


	if(list != NULL && len > 0)
	{
		printf("----MODIFICAR EMPLEADO----\n");
		printEmployees(list, len);
		if(utn_getNumero(&idEmpleado,"Ingrese el ID del empleado a modificar","Error, no es un valor aceptado\n",1,10000,3)==0)
		{
			indice = findEmployeeById(list,len,idEmpleado);
			if(indice >=0)
			{
				printf("El empleado seleccionado es:\n");
				printEmployee(list,len,indice);

				if(!utn_getNumero(&opcionModificar,"Indique el campo a modificar\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n","Error, No se encuentra entre las opciones\n",1,4,3))
				{
					switch(opcionModificar)
					{
					case 1:
						if(!utn_getCadena(auxString,"Ingrese Nuevo nombre: ","Error, deben ser letras!!!\n",3,51,3))
						{
							strcpy(list[indice].name,auxString);
						}
						break;
					case 2:
						if(!utn_getCadena(auxString,"Ingrese Nuevo apellido: ","Error, deben ser letras!!!\n",3,51,3))
						{
							strcpy(list[indice].lastName,auxString);
						}
						break;
					case 3:
						if(!utn_getNumeroFlotante(&auxFloat,"Ingrese Nuevo salario: ","Error, deben ser numeros!!!\n",0,1000000,3))
						{
							list[indice].salary = auxFloat;
						}
						break;
					case 4:
						if(!utn_getNumero(&auxInt,"Ingrese Nuevo sector: ","Error, deben ser numeros!!!\n",1,10000,3))
						{
							list[indice].sector = auxInt;
						}
						break;
					}

					retorno = 0;
				}
				else
				{
					printf("Operacion cancelada\n");
				}
			}


		}
	}

	return retorno;
}
/*
 * \brief pide al usuario que elija un usuario a ser eliminado
 * \param array de empleados
 * \param longitud del array de empleados
 * \return devuelve 0 si lo pudo eliminar y -1 si no
 */
int getIdRemove(Employee* list, int len)
{
	int retorno = -1;
	int idEliminar;
	char confirmacion;


	if(list != NULL && len > 0)
	{
		printf("----REMOVER EMPLEADO----\n");
		printEmployees(list, len);
		if(utn_getNumero(&idEliminar,"Ingrese el ID del empleado a eliminar","Error, no es un valor aceptado\n",1,1000,3)==0 &&
		   findEmployeeById(list,len,idEliminar)>=0)
		{

			printf("El empleado seleccionado es:\n");
			printEmployeById(list,len,idEliminar);
			fflush(stdin);
			if(!utn_getChar(&confirmacion,"Esta seguro que desea seguir, Igrese S para eliminar: ","Operacion cancelada\n",'S','s',0)
			&&(confirmacion =='s' || confirmacion =='S'))
			{
				if(!removeEmployee(list,len,idEliminar))
				{
					retorno = 0;
					printf("EMPLEADO ELIMINADO CON EXITO\n");
				}

			}

		}
		else
		{
			printf("EL ID DE EMPLEADO NO EXISTE\n");
		}
	}


	 return retorno;
}
/*
 * \brief elimina un usuario modificando el isEmpty
 * \param array de empleados
 * \param longitud del array empleados
 * \param id del empleado a eliminar
 * \return devuelve 0 si pudo eliminarlo y -1 si no
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int indice;

	if(list != NULL && len > 0 && id > 0)
	{
		indice = findEmployeeById(list,len,id);

				list[indice].isEmpty = -1;
				retorno = 0;

	}

 return retorno;
}
/*
 * \brief invierte el lugar de 2 elementos del array empleados
 * \param puntero al espacio de memoria reservado para el elemento
 * \param puntero al espacio de memoria reservado para el elemento
 * return devuelve 0 si puedo hacer el cambio y -1 si no
 */
int swapEmployee(Employee* pNumeroA, Employee* pNumeroB)
{
	int retorno = -1;
	Employee buffer;
	if(pNumeroA != NULL && pNumeroB != NULL)
	{
		buffer = *pNumeroA;
	    *pNumeroA = *pNumeroB;
	    *pNumeroB = buffer;
	    retorno = 0;
	}
	return retorno;
}
/*
 * \brief ordena el array de empleados siguiendo el orden seleccionado
 * \param array de empleados
 * \param longitud del array empleados
 * \param tipo de orden 0 ascendente y 1 descendente
 * \return devuelve 0 si lo pudo ordenar y -1 si no
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int limiteVariable;
	if(list != NULL && len > 0)
	{

		if(order == 0)
		{
			limiteVariable = len -1;
			retorno = 0;
			do
			{
				flagSwap = 0;

				for(i=0; i<limiteVariable;i++)
				{

					if((strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName)) > 0)||
					   (strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName)) == 0 &&
						list[i].sector > list[i+1].sector))
					{
						swapEmployee(list+i,list+i+1);
						flagSwap = 1;
					}


				}
				limiteVariable--;

			}while(flagSwap);
			retorno = 0;
		}
		else if(order == 1)
		{
			limiteVariable = len -1;
			retorno = 0;
			do
			{
				flagSwap = 0;

				for(i=0; i<limiteVariable;i++)
				{

					if((strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName)) < 0)||
					   (strncmp(list[i].lastName,list[i+1].lastName,sizeof(list[i].lastName)) == 0 &&
						list[i].sector < list[i+1].sector))
					{
						swapEmployee(list+i,list+i+1);
						flagSwap = 1;
					}


				}
				limiteVariable--;

			}while(flagSwap);
			retorno = 0;
		}

	}

	return retorno;
}
/*
 * \brief lista los salarios totales, el promedio y cuantos superan el promedio
 * \param array de empleados
 * \param longitud del array empleados
 * return devuelve 0 si pudo listar y -1 si no
 */
int listarTotalYPromedios(Employee* list, int len)
{
	int retorno = -1;
	float promedio;
    float acumuladorSalarios = 0;
    int contadorSuperanPromedio = 0;
    int contadorEmpleados = 0;
    int i;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumuladorSalarios += list[i].salary;
				contadorEmpleados ++;
			}
		}
		promedio = acumuladorSalarios / contadorEmpleados;
		for(i=0; i<len; i++)
		{
			if(list[i].salary > promedio && list[i].isEmpty == 0)
			{
				contadorSuperanPromedio++;
			}
		}
		printf("\nEL TOTAL DE LOS SALARIOS ES: %.2f\n",acumuladorSalarios);
		printf("EL PROMEDIO DE SALARIOS ES: %.2f\n",promedio);
		printf("LA CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO ES: %d\n\n",contadorSuperanPromedio);

		retorno = 0;
	}

	return retorno;
}
