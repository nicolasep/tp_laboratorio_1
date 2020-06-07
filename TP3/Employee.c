#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#define NOMBRE_LEN 128

static int esId(char* cadena,int limite);
static int esNombreg(char* cadena,int longitud);
static int sonHorasT(char* cadena,int limite);
static int esSueldo(char* cadena,int limite);


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
	char auxChar[10];
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
int employee_getIdChar(Employee* this,char* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
	  sprintf(id,"%d",this->id);

		retorno = 0;
	}

	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && esNombreg(nombre,NOMBRE_LEN))
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
	char auxHorasT[20];
	sprintf(auxHorasT,"%d",horasTrabajadas);
	if(this != NULL && horasTrabajadas >= 0 && sonHorasT(auxHorasT,20))
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
int employee_getHorasTrabajadasChar(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);

		retorno = 0;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	char auxSueldo[20];
	sprintf(auxSueldo,"%d",sueldo);
	if(this != NULL && sueldo >= 0 && esSueldo(auxSueldo,20))
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
int employee_getSueldoChar(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		sprintf(sueldo,"%d",this->sueldo);

		retorno = 0;
	}
	return retorno;
}
//////////FUNCIONES DE VALIDACION DE GETTERS//////////
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
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}


	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombreg(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )&& cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
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
static int sonHorasT(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && cadena[i] == '+')
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
/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param limite de la cadena
 * \return Retorna 1 (verdadero) si el numero es valido y 0 (falso) si no lo es
 *
 */
static int esSueldo(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && cadena[i] == '+')
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
////////////////////////////////////////////////////

int employee_printEmployee(Employee* pElement)
{
	int retorno = -1;
	int auxId;
	char auxNombre[128];
	int auxHorasT;
	int auxSueldo;

	if(pElement != NULL &&
	   !employee_getId(pElement,&auxId)&&
	   !employee_getNombre(pElement,auxNombre)&&
	   !employee_getHorasTrabajadas(pElement,&auxHorasT)&&
	   !employee_getSueldo(pElement,&auxSueldo))
	{
		printf("ID: %4d - NOMBRE: %15s - HORAS T: %4d - SUELDO: %d\n",auxId,auxNombre,auxHorasT,auxSueldo);
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
int employee_funcionCriterioPorSueldo(void* item1,void* item2)
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
			else
			{
				retorno = employee_funcionCriterioPorHorasT(item1,item2);
			}
		}

	}
	return retorno;
}
int employee_funcionCriterioPorHorasT(void* item1,void* item2)
{
	int retorno = 0;
	int horasT1;
	int horasT2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getHorasTrabajadas(aux1,&horasT1)&&
		   !employee_getHorasTrabajadas(aux2,&horasT2))
		{
			if(horasT1 > horasT2)
			{
				retorno = 1;
			}
			else if(horasT1 < horasT2)
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}
