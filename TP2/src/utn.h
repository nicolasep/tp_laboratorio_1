/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Jesi
 */

#ifndef UTN_H_
#define UTN_H_



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* UTN_H_ */
