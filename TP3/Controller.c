#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
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
	int len = ll_len(pArrayListEmployee);
	char idAux[20];
	sprintf(idAux,"%d",len+1);
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

	if(pArrayListEmployee != NULL)
	{

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
    return 1;
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

