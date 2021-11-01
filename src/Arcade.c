/*
 * ArrayeArcades.c
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */

#include "Arcade.h"










/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eArcade* Pointer to array of eArcades
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int arc_iniArcade(eArcade listArcade[], int len)
{
	int indice;
	int status = -1;
	if (listArcade != NULL && len > 0)
	{
		status = 0;
		for (indice = 0; indice < len; indice++)
		{
			listArcade[indice].isEmpty = VACIO;
		}
	}
	return status;
}


/*    char variableTxt3[64];
    char nombreDelJuego[64];
    char nacionalidad[64];
    int tipoDeSonido;
    int cantidadDeJugadores;
    int capacidadMaxFichas;
    float varFloat2;
    char varChar;
    int idArcade;
    int idArcade;
    int isEmpty;
   */

int arc_cargarArcade(eArcade listArcade[], int idSalon)
 {

	int status = -1;
	int bufferIdArcade;
	char nombreDelJuego[TAM_ARCADE];
	char nacionalidad[TAM_ARCADE];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaxFichas;




	if (listArcade != NULL)
		{
			if (utn_getDescripcion(nombreDelJuego, TAM_DATOARCADE, "Por favor ingrese el nombre del Juego: ", "Dato invalido.\n", 3)== 0 &&
				utn_getDescripcion(nacionalidad, TAM_DATOARCADE, "Por favor ingrese la nacionalidad: ", "Dato invalido.\n", 3)== 0 &&
				utn_obtenerEnteroConReintentosMinMax(&tipoDeSonido,"Por favor ingrese el tipo de SONIDO, 1=MONO - 2=STEREO: ","Dato invalido.\n", 1, 2, 3) == 0 &&
				utn_obtenerEnteroConReintentosMinMax(&cantidadDeJugadores,"Por favor ingrese la cantidad de jugadores: ","Dato invalido.\n", 1, 4, 3) == 0 &&
				utn_obtenerEnteroConReintentosMinMax(&capacidadMaxFichas,"Por favor ingrese la capacidad maxima de fichas: ","Dato invalido.\n", 1, 500, 3)== 0)
				{

				bufferIdArcade = createIdArcade();
					status = 0;
					arc_adhArcade(listArcade, TAM_ARCADE, bufferIdArcade,nombreDelJuego, nacionalidad,tipoDeSonido, cantidadDeJugadores, capacidadMaxFichas,idSalon);

				}
		}

	return status;
}


 int createIdArcade(void)
{
    static int createId = 0;

    createId++;

    return createId;

}
/**
 * @brief
 * @param listArcade
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/


int arc_adhArcade(eArcade listArcade[], int len, int idArcade,char nombreDelJuego[],char nacionalidad[],int tipoDeSonido,int cantidadDeJugadores, int capacidadMaxFichas,int idSalon)
{

	int bufferindice;

	if((bufferindice=arc_buscarLibreArcade(listArcade,len))>=0)
	{
		listArcade[bufferindice].idArcade=idArcade;
		listArcade[bufferindice].idSalon=idSalon;
		strncpy(listArcade[bufferindice].nombreDelJuego,nombreDelJuego,sizeof(listArcade->nombreDelJuego));
		strncpy(listArcade[bufferindice].nacionalidad,nacionalidad,sizeof(listArcade->nacionalidad));
		listArcade[bufferindice].tipoDeSonido=tipoDeSonido;
		listArcade[bufferindice].cantidadDeJugadores=cantidadDeJugadores;
		listArcade[bufferindice].capacidadMaxFichas=capacidadMaxFichas;
		listArcade[bufferindice].isEmpty=OCUPADO;
		return 0;

	}

 return -1;
}


int arc_buscarLibreArcade(eArcade listArcade[], int len)
{
	int i=0;
	int indiceLibre=-1;

	if(listArcade!=NULL && len>0)
	{
		indiceLibre=-2;

		for (i=0;i<len;i++)
		{

			if(listArcade[i].isEmpty==VACIO)
			{
				indiceLibre=i;
				break;
			}

		}

	}

	return indiceLibre;

}


int crearIdArcade(void)
{
    static int crearId = 0;

    crearId++;

    return crearId;

}



/** \brief find an eArcade by Id en returns the indice position in array.
 *
 * \param list eArcade*
 * \param len int
 * \param id int
 * \return Return eArcade indice position or (-1) if [Invalid length or NULL
pointer received or eArcade not found]
 *
 */
int arc_buscarPorId(eArcade listArcade[], int len,int idArcade)
{

		int indice;
		int estado = -1;
		if (listArcade != NULL && len > 0)
		{
			for (indice = 0; indice < len; indice++)
			{
				if (listArcade[indice].isEmpty != VACIO)
				{
					if (listArcade[indice].idArcade == idArcade)
					{
						estado = indice;
						break;
					}
				}//else
				//{
					//puts("Slot vacio");
			//	}
			}
		}
 return estado;

}




/** \brief Remove a eArcade by Id (put isEmpty Flag in 1)
 *
 * \param list eArcade*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a eArcade] - (0) if Ok
 *
 */
int arc_borrarArcade(eArcade listArcade[], int len, int idArcade)
{

	int retorno=-1;
	int bufferindice;
	int opcion;
	int opcionDos;
	bufferindice=arc_buscarPorId(listArcade,len,idArcade);

		if(bufferindice>=0 && listArcade[bufferindice].isEmpty==0)
		{
			printf("Id %d encontrado, por favor Ingrese 1 para borrar, 2 para cancelar: \n",(bufferindice+1));
			utn_obtenerEnteroConReintentos(&opcion,"Ingrese su opcion: ","Error, dato invalido",3);
			switch (opcion)
			{
				case 1:
					if(listArcade[bufferindice].tipoDeSonido==MONO)
					{
						printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade[bufferindice].idArcade,listArcade[bufferindice].idSalon, listArcade[bufferindice].nombreDelJuego, listArcade[bufferindice].nacionalidad,"Sonido MONO", listArcade[bufferindice].cantidadDeJugadores, listArcade[bufferindice].capacidadMaxFichas);
					}else
					{
						printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade[bufferindice].idArcade,listArcade[bufferindice].idSalon, listArcade[bufferindice].nombreDelJuego, listArcade[bufferindice].nacionalidad,"Sonido ESTEREO", listArcade[bufferindice].cantidadDeJugadores, listArcade[bufferindice].capacidadMaxFichas);

					}
					puts("\npara confirmar la baja presione 1, 2 para cancelar:");
					utn_obtenerEnteroConReintentos(&opcionDos,"Opcion?: ","\nError Dato invalido ",3);
					switch(opcionDos)
					{
					case 1:
						listArcade[bufferindice].isEmpty=1;
						retorno = 0;
					break;
					case 2:
						puts("Se cancela la baja");
					}

					break;

			}

		}



 return retorno;
}


/** \brief Sort the elements in the array of eArcades, the argument order
indicate UP or DOWN order
 *
 * \param list eArcade*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
//por Texto1(apellido) y si son == ordenar Int1(Legajo)
int arc_ordenarArcadeDosVar(eArcade listArcade[], int len, int order)
{
	int retorno = -1;
	eArcade bufferList;
	int i;
	int j;

	if (listArcade != NULL && len >= 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (strcmp(listArcade[i].nombreDelJuego, listArcade[j].nombreDelJuego) > 0 ||
					   (strcmp(listArcade[i].nombreDelJuego, listArcade[j].nombreDelJuego) == 0 && listArcade[i].tipoDeSonido > listArcade[j].tipoDeSonido)) // > de menor a mayor
						{
							bufferList = listArcade[i];
							listArcade[i] = listArcade[j];
							listArcade[j] = bufferList;
						}
				}
			}

		break;
		case 2:
			for (i = 0; i < len; i++)
			{
				for (j = i + 1; j < len; j++)
					if (strcmp(listArcade[i].nombreDelJuego, listArcade[j].nombreDelJuego) > 0 ||
					   (strcmp(listArcade[i].nombreDelJuego, listArcade[j].nombreDelJuego) == 0 && listArcade[i].tipoDeSonido > listArcade[j].tipoDeSonido)) // > de menor a mayor
						{
							bufferList = listArcade[i];
							listArcade[i] = listArcade[j];
							listArcade[j] = bufferList;
						}
			}

		break;
	}
}
	return retorno;

}
//ordena por el Int1, ejemplo edades legajos.
int arc_ordenarArcade(eArcade listArcade[], int len, int order)
{
	int retorno = -1;
	eArcade bufferList;
	int i;
	int j;

	if (listArcade != NULL && len >= 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (listArcade[i].tipoDeSonido > listArcade[j].tipoDeSonido)
					{
						bufferList = listArcade[i];
						listArcade[i] = listArcade[j];
						listArcade[j] = bufferList;
						retorno = 0;
					}
				}
			}
		break;
		case 2:
			for (i = 0; i < len; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (listArcade[i].tipoDeSonido < listArcade[j].tipoDeSonido)
					{
						bufferList = listArcade[i];
						listArcade[i] = listArcade[j];
						listArcade[j] = bufferList;
						retorno = 0;
					}
				}
			}
		break;
		}
	}
	return retorno;
}


/** \brief segnt the content of eArcades array
 *
 * \param list eArcade*
 * \param length int
 * \return int
 *
 */
void arc_mostrarArcade(eArcade listArcade[], int len)
{
	int i;

		for (i = 0; i < len; i++)
		{
			if(listArcade[i].isEmpty==0)
			{
				arc_cargarMostrarArcade(listArcade[i]);
			}
		}

}

//				arc_cargarMostrarArcade(listArcade[i]);


void arc_cargarMostrarArcade(eArcade listArcade)
{
	if(listArcade.tipoDeSonido==MONO)
	{
		printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade.idArcade,listArcade.idSalon, listArcade.nombreDelJuego, listArcade.nacionalidad," MONO ", listArcade.cantidadDeJugadores, listArcade.capacidadMaxFichas);
	}else
	{
		printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade.idArcade,listArcade.idSalon, listArcade.nombreDelJuego, listArcade.nacionalidad," ESTEREO ", listArcade.cantidadDeJugadores, listArcade.capacidadMaxFichas);

	}
}






//2. Total y promedio de la capacidadMaxFichas, y cuántos variableTexto1 superan capacidadMaxFichas promedio.


int arc_promedioDeArcade (eArcade listArcade[],int len,float *promedio,int *contador,float *acumulador)
{

	int i;
	int retorno=-1;
	float bufferAcumulador=0;
	int bufferContador=0;
	int bufferContadorMayor=0;
	float bufferPromedio;
	if (listArcade != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (listArcade[i].isEmpty == 0)
			{
				bufferAcumulador = bufferAcumulador + listArcade[i].capacidadMaxFichas;
				bufferContador++;
				retorno=0;
			}
		}
	}

	*acumulador=bufferAcumulador;
	bufferPromedio=bufferAcumulador/bufferContador;
	*promedio=bufferPromedio;

	for (i = 0; i < len; i++)
			{
				if (listArcade[i].isEmpty == OCUPADO && listArcade[i].capacidadMaxFichas>bufferPromedio)
				{

					bufferContadorMayor++;

				}

			*contador=bufferContadorMayor;

			}
return retorno;


}

int addForcedArcade(eArcade listArcade[], int len,int index, int *id, char nombre[],char pais[],int tipo,int jugadores,int fichas, int idSalon)
{

	eArcade bufferArcade;
	int status = -1;

	if(listArcade != NULL && len>0 && index < len && index >= 0)
	{
		strncpy(bufferArcade.nombreDelJuego,nombre,TAM_DATOARCADE);
		strncpy(bufferArcade.nacionalidad,pais,TAM_DATOARCADE);
		bufferArcade.tipoDeSonido=tipo;
		bufferArcade.cantidadDeJugadores=jugadores;
		bufferArcade.capacidadMaxFichas=fichas;
		bufferArcade.idArcade=*id;
		bufferArcade.isEmpty=0;
		bufferArcade.idSalon=idSalon;
		status = 0;
		listArcade[index]=bufferArcade;
		(*id)++;



	}

 return status;
}
int mostrarListaJuegosSinRepetir(eArcade listArcade[], int lenArcade)
{

	int estado=-1;
	int i;
	int j;
	int bufferstrncmp=1;
//1 mortal kombat 11 mortal kombat,


	if(listArcade!=NULL && lenArcade>0)
	{
		puts("Lista de juegos cargados:");

		for(i=0;i<lenArcade;i++)
		{

			if(listArcade[i].isEmpty==OCUPADO)
			{
				bufferstrncmp=0;

				for(j=i+1;j<lenArcade;j++)
				{
					//[1][2][3][4][5][6][7][8][9][10]
					//1 MK    8MK --------  1 es == a 2? no....pero cuando llego al 8, ya no recorro el 1, recorro de 8 en adelante por lo cual recien ahi muestro
					if(listArcade[j].isEmpty==OCUPADO && strncmp(listArcade[i].nombreDelJuego,listArcade[j].nombreDelJuego,TAM_DATOARCADE)==0)
					{
						bufferstrncmp=1;
						break; //tiro break porque es innecesario seguir iterando despues de encontrar el primero
					}
				}
				if(bufferstrncmp==0)
				{
					printf("%s\n",listArcade[i].nombreDelJuego);
					estado=0; // cuando salgo de j en contador estado etc, reseteo la variable.
				}
			}

		}
	 }

return estado;
}

int cuantosArcadesPorJuego(eArcade listArcade[],int lenArcade,int *pContadorArcades)
{


	int estado=-1;
	int contador=0;
	int i;
	char nombreDelJuego[TAM_DATOARCADE];


		if(listArcade!=NULL  && lenArcade>0)
		{
			utn_getDescripcion(nombreDelJuego,TAM_DATOARCADE, "\nPor favor ingrese el nombre del Juego: ", "Dato invalido.\n", 3);

				for(i=0;i<lenArcade;i++)
				{
						if(strncmp(nombreDelJuego,listArcade[i].nombreDelJuego,TAM_DATOARCADE)==0 && listArcade[i].isEmpty==OCUPADO)
						{
							contador++;
						}
				}

				estado=0;
		}

		*pContadorArcades=contador;







	return estado;



}
