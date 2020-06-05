#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* p = fopen(path,"r");
		if(!parser_EmployeeFromText(p,pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(p);
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	char idAux[20];
	sprintf(idAux,"%d",employee_idMax(pArrayListEmployee));
	char nombreAux[128];
	char sueldoAux[20];
	char horasAux[20];

	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNombre(nombreAux,128,"Ingrese nombre: ","Error, solo se deben ingresar letras\n",2)&&
				!utn_getDescripcion(horasAux,20,"Ingrese cantidad de horas trabajadas: ","Error, deben ser solo numeros\n",2)&&
				!utn_getDescripcion(sueldoAux,20,"Ingrese el sueldo: ","Error, deben ser solo numeros\n",2))
		{
			auxEmployee = employee_newParametros(idAux,nombreAux,horasAux,sueldoAux);
			if(
				!ll_add(pArrayListEmployee,(Employee*)auxEmployee))
			{
				retorno = 0;
				printf("Empleado ingresado con exito\n");
			}
		}

	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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


	if(pArrayListEmployee != NULL && !employee_printEmployees(pArrayListEmployee)&&
	   !utn_getNumero(&idEmpleado,"Ingrese el id del empleado a modificar: ","Error, debe ser un numero",1,len,2)&&
	   (indice = employee_findById(pArrayListEmployee,idEmpleado))>=0)
	{
		printf("El empleado a modificar es: ");
		employee_printById(pArrayListEmployee,idEmpleado);

		 if(!utn_getNumero(&opcion,"Ingrese el campo a modificar\n"
								   "1 - Modificar nombre\n"
								   "2 - Modificar horas trabajadas\n"
								   "3 - Modificar sueldo\n"
								   "4 - Salir\n","Error, debe ser un numero\n",1,4,2))
		{

			aux = ll_get(pArrayListEmployee,indice);
			switch(opcion)
			{
			case 1:
				if(!utn_getNombre(auxString,128,"Ingrese nuevo nombre: ","Error, debe contener solo letras\n",2)&&
				   !utn_confirmacionAccionChar("Esta seguro que decea cambiar el nombre? ingrese s para seguir\n"))
				{
					employee_setNombre(aux,auxString);
					ll_set(pArrayListEmployee,indice,aux);
					printf("El nombre del empleado se modifico con exito!!!\n");
				}

				break;
			case 2:
				if(!utn_getNumero(&auxInt,"Ingrese horas trabajadas: ","Error, debe contener solo numeros\n",0,1000,2)&&
								   !utn_confirmacionAccionChar("Esta seguro que decea cambiar las horas trabajadas? ingrese s para seguir\n"))
				{
					employee_setHorasTrabajadas(aux,auxInt);
					ll_set(pArrayListEmployee,indice,aux);
					printf("Las horas trabajadas se modificaron con exito!!!\n");
				}
				break;
			case 3:
				if(!utn_getNumero(&auxInt,"Ingrese nuevo sueldo: ","Error, debe contener solo numeros\n",0,1000000,2)&&
							   !utn_confirmacionAccionChar("Esta seguro que decea cambiar el sueldo? ingrese s para seguir\n"))
				{
					employee_setSueldo(aux,auxInt);
					ll_set(pArrayListEmployee,indice,aux);
					printf("El sueldo del empleado se modifico con exito!!!\n");
				}
				break;
			case 4:
				printf("Operacion cancelada\n");
				break;
			}
		}

	}


    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idEliminar;
	int indiceEliminar;
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&idEliminar,"Elija el id del empleado a eliminar: ","Error, debe ser un numero\n",1,employee_idMax(pArrayListEmployee),2)&&
			(indiceEliminar=employee_findById(pArrayListEmployee,idEliminar))>=0)
		{
			auxEmployee = (Employee*)ll_remove(pArrayListEmployee,indiceEliminar);
			employee_delete(auxEmployee);

		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

