/*
 * bicicletas.h
 *
 *  Created on: 12 oct. 2021
 *      Author: User
 */



/*
 * ArrayeArcades.h
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */

#ifndef ARCADE_H_
#define ARCADE_H_


#define TAM_DATOARCADE 64
#define TAM_ARCADE 1000
#define OCUPADO 0
#define VACIO 1
#define MONO 1
#define ESTEREO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputsGets.h"
#include <ctype.h>

typedef struct
{
    char nombreDelJuego[TAM_DATOARCADE];
    char nacionalidad[TAM_DATOARCADE];
    int tipoDeSonido;
    int cantidadDeJugadores;
    int capacidadMaxFichas;
    int idArcade;
    int idSalon;
    int isEmpty;

}eArcade;


int createIdArcade(void);

int arc_iniArcade(eArcade listArcade[], int len);
int arc_cargarArcade(eArcade listArcade[], int idSalon);
int arc_adhArcade(eArcade listArcade[], int len, int idArcade,char nombreDelJuego[],char nacionalidad[],int tipoDeSonido,int cantidadDeJugadores, int capacidadMaxFichas,int idSalon);
int arc_buscarLibreArcade(eArcade listArcade[], int len);
int crearId(void);
int arc_buscarPorId(eArcade listArcade[], int len,int id);
int arc_borrarArcade(eArcade* listArcade, int len, int id);
//Ordena por Texto1(apellido) y si son == ordenar Int1(Legajo)
int arc_ordenarArcadeDosVar(eArcade listArcade[], int len, int order);
//ordena por el Int1, ejemplo edades legajos.
int arc_ordenarArcade(eArcade listArcade[], int len, int order);
void arc_mostrarArcade(eArcade listArcade[], int len);
void arc_cargarMostrarArcade(eArcade listArcade);
int arc_promedioDeArcade (eArcade listArcade[],int len,float *promedio,int *contador,float *acumulador);
void arc_mostrarTodosLosVacios(eArcade listArcade[], int len);
int addForcedArcade(eArcade listArcade[], int len,int index, int *id, char nombre[],char pais[],int tipo,int jugadores,int fichas, int idSalon);
int cuantosArcadesPorJuego(eArcade listArcade[],int lenArcade,int *pContadorArcades);
#endif /* ARCADE_H_ */


