/*
 * utn.c
 *
 *  Created on: 18 abr. 2020
 *      Author: Jesi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "utn.h"

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena,int limite);
static int getInt(int* pResultado);

/*
static int validarNumeroFloat(char* cadena);
static int getFloat(float* pResultado);

static int validarCadena(char* cadena);
static int getCadena(char* pResultado);

static int esTelefono(char* telefono);
static int getTelefono(char* pResultado);

static int esEmail(char* cadena);
static int getEmail(char* pResultado);
*/
static int esChar(char letra);
static int getChar(char* pResultado);



int printArray(int* pArray, int len)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && len >= 0)
	{
		retorno = 0;
		for(i=0; i<len; i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n ",i,pArray[i]);
		}
	}

	return retorno;
}
void intSwap(int* pNumeroA, int* pNumeroB)
{
	int buffer;
	buffer = *pNumeroA;
	*pNumeroA = *pNumeroB;
	*pNumeroB = buffer;
}

int ordenarArrayNumerico(int* pArray, int len)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int contador = 0;
	int limiteVariable;

	if(pArray != NULL && len > 0)
	{
		limiteVariable = len -1;
		retorno = 0;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteVariable;i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					intSwap(pArray+i,pArray+i+1);

					flagSwap = 1;
				}
			}

			limiteVariable--;
		}while(flagSwap);
		retorno = contador;

	}

	return retorno;
}

//nuevas
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}
static int esChar(char letra)
{
	int retorno = 0;
	if(letra <'a' || letra >'z' || letra <'A' || letra >'Z')
	{
		retorno = -1;
	}

	return retorno;
}
static int getChar(char* pResultado)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL)
	{
		if(myGets(&buffer,sizeof(buffer))==0 && esChar(buffer) == 0)
		{
			*pResultado = buffer;
			retorno = 0;
		}
	}

	return retorno;
}
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	do
	{
		printf("%s",mensaje);
		if(getChar(&bufferChar) == 0 &&
		   bufferChar >= minimo &&
		   bufferChar <= maximo)
		{
			retorno = 0;
			*pResultado = bufferChar;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}
static int esNumerica(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;//continua salteando lo siguiente
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}

	}


	return retorno;
}
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
	   !myGets(bufferString,sizeof(bufferString)) &&
	   esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);

	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0 &&
		   bufferInt >= minimo &&
		   bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}
//
static int validarNumeroFloat(char* cadena)
{
    int retorno=1;
	int i;
	int contadorPuntos=0;

    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
        	// no estoy en el rango de los numeros
        	if(cadena[i]=='.') // es un punto
        	{
        		contadorPuntos++;
        		if(contadorPuntos>1)
        		{
        			// encontre un segundo punto, doy error
                    retorno=0;
                    break;
        		}
        	}
        	else
        	{
        		//Hay algo que no es un punto ni numero
        		if(i==0)
        		{
        			// me pongo a ver que onda con el caracter
        			if(cadena[i]!='+' && cadena[i]!='-')
        			{
        				retorno=0;
        				break;
        			}
        		}
        		else
        		{
        			retorno=0;
        			break;
        		}
        	}
        }
    }
    return retorno;
}
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  validarNumeroFloat(buffer))
	{
		retorno = 0;
		*pResultado =(float) atof(buffer);
	}

	return retorno;
}
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);

				if(getFloat(&bufferFloat) &&bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}

			}while(reintentos >= 0);


		}

		return retorno;
}
//cadenas
static int validarCadena(char* cadena)
{
    int retorno= 1;
	int i;

    for(i=0;cadena[i]!='\0';i++)
    {
      if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
      {
    	  retorno = 0;
    	  break;
      }
    }
    return retorno;
}
static int getCadena(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 &&  validarCadena(buffer))
	    {
		retorno = 0;
		strcpy(pResultado,buffer);
	    }
	}


	return retorno;
}
int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);

				if(getCadena(buffer)==0 && strnlen(buffer,sizeof(buffer)) >= minimo && strnlen(buffer,sizeof(buffer)) <= maximo)
				{
					strcpy(pResultado,buffer);
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}

			}while(reintentos >= 0);


		}

		return retorno;
}
//telefono
static int esTelefono(char* telefono)
{
	int retorno = 1;
	int contadorGuiones = 0;
	int i;

	for(i=0; telefono[i]!='\0' ; i++)
	{
		if(telefono[i]<'0' || telefono[i]>'9')
		{

			retorno = 0;
		}
		else
		{
			if(telefono[i] =='-')
			{
				contadorGuiones ++;
			}
		}
	}

	if(contadorGuiones<2)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}


	return retorno;

}
static int getTelefono(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  esTelefono(buffer))
	{
		retorno = 0;
		strcpy(pResultado,buffer);
	}

	return retorno;
}
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);

				if(getTelefono(buffer)==0 && sizeof(buffer) >= minimo && sizeof(buffer) <= maximo)
				{
					strcpy(pResultado,buffer);
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}

			}while(reintentos >= 0);


		}

		return retorno;
}
//funciones email

static int esEmail(char* cadena)
{
	int retorno = 1;
	int i;
	int contadorArroba = 0;
	int contadorPuntos = 0;
	int tienePuntoCom = 0;

	if(cadena != NULL)
	{
		for(i=0; cadena[i] !='\0'; i++)
		{
			if(cadena[i]=='@')
			{
				contadorArroba++;
				if(contadorArroba > 1)
				{
					retorno = 0;
				}
			}
			else
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
					if(contadorPuntos > 3)
					{
						retorno = 0;
					}
					else
					{
						if((cadena[i+1]=='c' && cadena[i+2]=='o' && cadena[i+3]=='m')||(cadena[i+1]=='C' && cadena[i+2]=='O' && cadena[i+3]=='M'))
						{
							tienePuntoCom++;
							if((tienePuntoCom > 1 || tienePuntoCom == 0) && contadorArroba == 1)
							{
								retorno = 0;
							}
						}
					}
				}
			}
		}
		if(tienePuntoCom == 0 || contadorArroba == 0)
		{
			retorno=0;
		}
	}

	return retorno;
}
static int getEmail(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  esEmail(buffer))
	{
		retorno = 0;
		strcpy(pResultado,buffer);
	}

	return retorno;
}
int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);

			if(getEmail(buffer) == 0 && strnlen(buffer,sizeof(buffer))>=minimo && strnlen(buffer,sizeof(buffer))<=maximo)
			{
				strcpy(pResultado,buffer);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);

	}

	return retorno;
}
