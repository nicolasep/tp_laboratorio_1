#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo desde el cual se van a cargar los datos
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista donde se van a cargar
 * \return int devuelve 0 si se pudo cargar y -1 si no
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* p = fopen(path,"r");
		if(p==NULL)
		{
			printf("\nNo se pudo abrir el archivo\n");
		}
		else
		{
			if(!parser_EmployeeFromText(p,pArrayListEmployee))
			{
				printf("\nEmpleados cargados de archivo en modo texto con exito\n");
				retorno = 0;
			}
			fclose(p);
		}

	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo desde el cual se van a cargar los datos
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista donde se van a cargar
 * \return int devuelve 0 si se pudo cargar y -1 si no
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* p;
	if(pArrayListEmployee != NULL && path)
	{
		p =fopen(path,"rb");
		if(p==NULL)
		{
			printf("\nNo se pudo abrir el archivo\n");
		}
		else
		{
			if(parser_EmployeeFromBinary(p,pArrayListEmployee)>0)
			{
				printf("\nEmpleados cargados de archivo en modo binario con exito\n");
				retorno = 0;
			}

			fclose(p);
		}
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo cargar y -1 si no se pudo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	char idAux[20];
	char nombreAux[128];
	char sueldoAux[20];
	char horasAux[20];

	if(pArrayListEmployee != NULL)
	{

		printf("\n----ALTA EMPLEADO----\n");
		if(!utn_getNombre(nombreAux,128,"\nIngrese nombre: ","Error, solo se deben ingresar letras\n",2)&&
				!utn_getDescripcion(horasAux,20,"Ingrese cantidad de horas trabajadas: ","Error, deben ser solo numeros\n",2)&&
				!utn_getDescripcion(sueldoAux,20,"Ingrese el sueldo: ","Error, deben ser solo numeros\n",2))
		{
			sprintf(idAux,"%d",employee_idMax(pArrayListEmployee));
			auxEmployee = employee_newParametros(idAux,nombreAux,horasAux,sueldoAux);
			if(
				!ll_add(pArrayListEmployee,(Employee*)auxEmployee))
			{
				retorno = 0;
				printf("\nEmpleado ingresado con exito\n");
			}
		}

	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo modificar y -1 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idEmpleado;
	int opcion;
	int len = ll_len(pArrayListEmployee);
	Employee* aux;
	char auxString[128];
	int auxInt;
	int indice;


	if(pArrayListEmployee != NULL)
	{
		printf("\n----MODIFICAR EMPLEADO----\n");
		if(!controller_ListEmployee(pArrayListEmployee)&&
	       !utn_getNumero(&idEmpleado,"\nIngrese el id del empleado a modificar: ","Error, debe ser un numero\n",1,len,2)&&
	       (indice = employee_findById(pArrayListEmployee,idEmpleado))>=0)
		{
			printf("\nEl empleado a modificar es: ");
			employee_printById(pArrayListEmployee,idEmpleado);

			 if(!utn_getNumero(&opcion,"\nIngrese el campo a modificar\n"
									   "1 - Modificar nombre\n"
									   "2 - Modificar horas trabajadas\n"
									   "3 - Modificar sueldo\n"
									   "4 - Salir\n","Error, debe ser un numero\n",1,4,2))
			{

				aux = ll_get(pArrayListEmployee,indice);
				switch(opcion)
				{
				case 1:
					if(!utn_getNombre(auxString,128,"\nIngrese nuevo nombre: ","Error, debe contener solo letras\n",2)&&
					   !utn_confirmacionAccionChar("Esta seguro que decea cambiar el nombre? ingrese s para seguir\n"))
					{
						employee_setNombre(aux,auxString);
						ll_set(pArrayListEmployee,indice,aux);
						printf("\nEl nombre del empleado se modifico con exito!!!\n");
						retorno = 0;
					}
					break;
				case 2:
					if(!utn_getNumero(&auxInt,"\nIngrese horas trabajadas: ","Error, debe contener solo numeros\n",0,1000,2)&&
					   !utn_confirmacionAccionChar("\nEsta seguro que decea cambiar las horas trabajadas? ingrese s para seguir\n"))
					{
						employee_setHorasTrabajadas(aux,auxInt);
						ll_set(pArrayListEmployee,indice,aux);
						printf("Las horas trabajadas se modificaron con exito!!!\n");
						retorno = 0;
					}
					break;
				case 3:
					if(!utn_getNumero(&auxInt,"\nIngrese nuevo sueldo: ","Error, debe contener solo numeros\n",0,1000000,2)&&
					   !utn_confirmacionAccionChar("\nEsta seguro que decea cambiar el sueldo? ingrese s para seguir\n"))
					{
						employee_setSueldo(aux,auxInt);
						ll_set(pArrayListEmployee,indice,aux);
						printf("\nEl sueldo del empleado se modifico con exito!!!\n");
						retorno = 0;
					}
					break;
				case 4:
					printf("\nOperacion cancelada\n");
					break;
				}
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo eliminar y -1 si no se pudo
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idEliminar;
	int indiceEliminar;
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL && !controller_ListEmployee(pArrayListEmployee))
	{
		if(!utn_getNumero(&idEliminar,"\nElija el id del empleado a eliminar: ","Error, debe ser un numero\n",1,employee_idMax(pArrayListEmployee),2)&&
			(indiceEliminar=employee_findById(pArrayListEmployee,idEliminar))>=0)
		{
			printf("El empleado a eliminar es: ");
			employee_printById(pArrayListEmployee,idEliminar);
			if(!utn_confirmacionAccionChar("\nEsta seguro que desea eliminar el empleado? ingrese 'S' para confirmar\n"))
			{
				auxEmployee = (Employee*)ll_pop(pArrayListEmployee,indiceEliminar);
				employee_delete(auxEmployee);
				retorno = 0;
				printf("\nEmpleado eliminado con exito\n");
			}
			else
			{
				printf("\nOperacion cancelada\n");
			}
		}
		else
		{
			printf("\nEl empleado no existe\n");
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo mostrar y -1 si no se pudo
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* aux;
	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			if(aux != NULL)
			{
				employee_printEmployee(aux);
			}
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo ordenar y -1 si no se pudo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int criterioOrden;

	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&criterioOrden,"\n----ORDENAR LISTA----\n"
				                         "\nElija el criterio de orden\n"
										   "1 - Descendente\n"
				                           "2 - Ascendente\n","Opcion incorrecta\n",1,2,2))
		{
			printf("\nAguarde un memonto mientras se ordena la lista.......\n");
			if(!ll_sort(pArrayListEmployee,employee_funcionCriterioPorSueldo,criterioOrden-1))
			{
				printf("\nLista ordenada con exito\n");
				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* archivo en el cual se van a guardar los datos
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo guardar la lista completa y -1 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;

	Employee* aux;
	FILE* p;
	int contador = 0;
	p =fopen(path,"w");

	if(pArrayListEmployee != NULL && p != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			if(aux != NULL)
			{
				fprintf(p,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
				contador ++;
			}
		}
		if(contador == ll_len(pArrayListEmployee))
		{
			printf("Lista guardada en modo texto con exito\n");
			retorno = 0;
		}
	}

	fclose(p);


	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* archivo en el cual se van a guardar los datos
 * \param pArrayListEmployee LinkedList* puntero a la direccion de memoria de la lista
 * \return int devuelve 0 si se pudo guardar la lista completa y -1 si no se pudo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* aux;
	FILE* p;
	int contador = 0;
	p =fopen(path,"wb");

	if(pArrayListEmployee != NULL && p != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			aux =(Employee*) ll_get(pArrayListEmployee,i);
			if(aux != NULL)
			{
				fwrite(aux,sizeof(Employee),1,p);
				contador ++;
			}

		}
		if(contador == ll_len(pArrayListEmployee))
		{
			printf("Lista guardada en binario con exito\n");
			retorno = 0;
		}

	}
	fclose(p);
	return retorno;
}

