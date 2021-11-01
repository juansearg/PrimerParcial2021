/*
 * bicicletas.h
 *
 *  Created on: 12 oct. 2021
 *      Author: User
 */

#ifndef SALON_H_
#define SALON_H_

/*
 * ArrayeEntidad1s.h
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */

#ifndef ARRAYeEntidad1S_H_
#define ARRAYeEntidad1S_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputsGets.h"
#include <ctype.h>
#define TAM_SALON 100
#define TAM_DATOSALON 64
#define OCUPADO 0
#define VACIO 1
#define SHOPPING 1
#define LOCAL 2
typedef struct
{
    char nombre[TAM_DATOSALON];
    char direccion[TAM_DATOSALON];
    int tipo;
    int idSalon;
    int isEmpty;

}eSalon;

int createIdSalon(void);
int sal_adhSalon(eSalon listSalon[], int len, int idSalon,char nombre[],char direccion[],int tipo);

int sal_iniciarListSalon(eSalon listSalon[], int len);
int sal_cargarSalon(eSalon listSalon[], int *bufferIdSalon);
int sal_buscarLibreSalon(eSalon listSalon[], int len);
int crearId(void);
int sal_buscarPorId(eSalon listSalon[], int len,int idSalon);
int sal_borrarSalon(eSalon listSalon[], int len, int idSalon);

//Ordena por Texto1(apellido) y si son == ordenar Int1(Legajo)
int sal_ordenarSalonDosVar(eSalon listSalon[], int len, int order);
//ordena por el Int1, ejemplo edades legajos.
int sal_ordenarSalon(eSalon listSalon[], int len, int order);
void sal_mostrarPorId(eSalon listSalon[], int len, int idSalon);
void sal_mostrarSalon(eSalon listSalon[], int len);
void sal_cargarMostrarSalon(eSalon listSalon);
int sal_modificarSalonporId (eSalon listSalon[], int len, int idSalon);
int sal_promedioDeSalon (eSalon listSalon[],int len,float *promedio,int *contador,float *acumulador);
void sal_mostrarTodosLosVacios(eSalon listSalon[], int len);
void sal_cargarMostrarSalonSinTipo(eSalon listSalon);
void sal_mostrarSalonSinTipo(eSalon listSalon[], int len);
int addForced(eSalon listSalon[], int len,int index, int *id, char nombre[],char direccion[],int tipo);
#endif /* ARRAYeEntidad1S_H_ */


#endif /* SALON_H_ */
