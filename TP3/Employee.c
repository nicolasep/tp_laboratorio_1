#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


static int esId(char* cadena,int limite);



Employee* employee_new()
{
	Employee* auxEmployee = (Employee*)malloc(sizeof(Employee));
	if(auxEmployee != NULL)
	{
		auxEmployee->id=0;
		auxEmployee->nombre[0]='\0';
		auxEmployee->horasTrabajadas=0;
		auxEmployee->sueldo=0;
	}

	return auxEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* SueldoStr)
{

	Employee* auxEmployee = employee_new();

		if(auxEmployee != NULL &&
		   !employee_setId(auxEmployee,atoi(idStr)) &&
		   !employee_setNombre(auxEmployee,nombreStr)&&
		   !employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr))&&
		   !employee_setSueldo(auxEmployee,atoi(SueldoStr)))
		{
			return auxEmployee;
		}
		else
		{
			return NULL;
		}

}
void employee_delete(Employee* pEmployee)
{
	if(pEmployee != NULL)
	{
		free(pEmployee);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	char auxChar[128];
	sprintf(auxChar,"%d",id);
	if(this !=NULL && id > 0 && esId(auxChar,10))
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,128);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;

		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;

		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;

		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;

		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param limite de la cadena
 * \return Retorna 1 (verdadero) si el numero es valido y 0 (falso) si no lo es
 *
 */
static int esId(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}


	return retorno;
}
int employee_printEmployees(LinkedList* pArrayListEmployee)
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
				//printf("%d - %s - %d - %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
				employee_printEmployee(aux);
			}
			retorno = 0;
		}
	}
	return retorno;
}
int employee_printEmployee(Employee* pElement)
{
	int retorno = -1;
	if(pElement != NULL)
	{
		printf("ID: %d - NOMBRE: %s - HORAS T: %d - SUELDO: %d\n",pElement->id,pElement->nombre,pElement->horasTrabajadas,pElement->sueldo);
		retorno = 0;
	}
	return retorno;
}
int employee_printById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{

			if(id == ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				employee_printEmployee((Employee*)ll_get(pArrayListEmployee,i));
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{
			if(id == ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int employee_idMax(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idMax = 1;

	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			if(idMax < ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				idMax = ((Employee*)ll_get(pArrayListEmployee,i))->id;
				idMax++;
			}
		}

		retorno = idMax;
	}

	return retorno;
}
int employee_funcionCriterio(void* item1,void* item2)
{
	int retorno = 0;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{
			if(sueldo1 > sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo1 < sueldo2)
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}
