/*
 * bicicletas.h
 *
 *  Created on: 12 oct. 2021
 *      Author: User
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/*
 * ArrayeEntidad3s.h
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputsGets.h"
#include <ctype.h>
#include "Arcade.h"
#include "Salon.h"

typedef struct
{
	char nombreDelJuego[TAM_DATOARCADE];
	int isEmpty;
}eJuegos;

int createId(void);


int inf_borrarSalonYArcade(eSalon listSalon[], int lenSalon,int idSalon,eArcade listArcade[], int lenArcade);
int inf_eliminarArcadeYVerSalon(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon);
int inf_salonConArcades(eSalon listSalon[], int lenSalon,int idSalon,eArcade listArcade[], int lenArcade);
int inf_cargarArcadeConSalon(eArcade listArcade[],eSalon listSalon[],int lenSalon, int idSalon);
int inf_adhArcadeConSalon(eArcade listArcade[], int len, int idArcade,char nombreDelJuego[],char nacionalidad[],int tipoDeSonido,int cantidadDeJugadores, int capacidadMaxFichas,int idSalon);
int inf_initJuego(eJuegos listJuegos[], int len);
int inf_JuegoEnArcade(eJuegos listJuegos[], int len,char nombreJuego[]);
int inf_crearListJuego(eJuegos listJuegos[], int lenJuego,eArcade listArcade[], int lenArcade);
void inf_mostrarJuegos(eJuegos listJuegos[], int lenJuego);
void inf_cargarMostrarJuegos(eJuegos listJuegos);
void inf_cargarMostrarJuegos(eJuegos listJuegos);
void inf_mostrarJuegosStruct(eJuegos listJuegos[],int lenJuegos);
void inf_mostrarArcadeConSalon(eArcade listArcade[], int lenArcade,eSalon listSalon[],int lenSalon);
void inf_cargarMostrarArcade(eArcade listArcade[], int index);
int arc_modificarArcadeporId(eArcade listArcade[], int lenArcade, int id);
int inf_contarSalonesConArcades(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon);
int inf_contarArcadesDosJugadores(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int *pContador);
int inf_mostrarSalonPorIdconArcade(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int idSalon);
int inf_juegoContarArcades(eJuegos listJuegos,int lenJuegos,eArcade listArcade, int lenArcade);
int inf_salonCompleto(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade);
int inf_promedioArcade(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade);
int inf_masCantidadArcades(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade);
int inf_initJuegos(eJuegos listJuegos[], int len);
int mostrarListaJuegosSinRepetir(eArcade listArcade[], int lenArcade);
int inf_mostrarArcadesDeUnSalon(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int idSalon);
int montoMaximoEnPesos (eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade, int idSalon,float precioDeFicha);
#endif /* INFORMES_H_ */
