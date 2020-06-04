#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
/* int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;*/
	int retorno = -1;
	char auxNombre[128];
	char auxId[20];
	char auxHoras[20];
	char auxSueldo[20];
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && pFile != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo))
			{
				auxEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
				if(auxEmployee != NULL && !ll_add(pArrayListEmployee,auxEmployee))
				{
					retorno = 0;
				}
			}


		}while(!feof(pFile));

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
