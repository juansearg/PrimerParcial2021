/*
 * ArrayeEntidad3s.c
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */


#define OCUPADO 0
#define VACIO 1
#include "Informes.h"






/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eEntidad3* Pointer to array of eEntidad3s
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int inf_borrarSalonYArcade(eSalon listSalon[], int lenSalon,int idSalon,eArcade listArcade[], int lenArcade)
{
	int retorno=-1;
	int bufferindice;
	int i;
	int opcion;
	int opcionDos;


	if(listSalon!=NULL && lenSalon>0 && listArcade!=NULL && lenArcade>0)
	{
		bufferindice=sal_buscarPorId(listSalon,TAM_SALON,idSalon);


		if(bufferindice>=0 && listSalon[bufferindice].isEmpty==OCUPADO)
		{
			puts("ID encontrado, por favor Ingrese 1 para borrar, 2 para cancelar");

			if(utn_obtenerEnteroConReintentosMinMax(&opcion,"Ingrese su opcion: ","Error, Dato invalido",1,2,3)==-1)
			{
				puts("Cantidad de reintentos superada");
			}else
			{
				switch(opcion)
				{
				case 1:
					if(inf_salonConArcades(listSalon,TAM_SALON,idSalon,listArcade,TAM_ARCADE)==0)
					{

						puts("El Salon posee Arcades, desea borrar los arcades?, 1 para borrar, 2 para cancelar");
						if(utn_obtenerEnteroConReintentosMinMax(&opcionDos,"Ingrese su opcion:","Error, cantidad de reintentos superada",1,2,3)==-1)
						{
							puts("Cantidad de reintentos superada");
						}else
						{

							switch(opcionDos)
							{
							case 1:
								listSalon[bufferindice].isEmpty=VACIO;

								for(i=0;i<TAM_ARCADE;i++)
								{
									if(listArcade[i].idSalon==idSalon && listArcade[i].isEmpty==OCUPADO)
									{
										listArcade[i].isEmpty=VACIO;
										retorno = 0;
									}
								}
							break;
							case 2:
							puts("Se ha cancelado la opcion de elimiar el salon");
							break;
							}
						}
					}
					else
					{
						puts("El Salon No posee Arcades, 1 para borrar, 2 para cancelar");
						if(utn_obtenerEnteroConReintentosMinMax(&opcionDos,"Ingrese su opcion:","Error, cantidad de reintentos superada",1,2,3)==-1)
						{
							puts("Cantidad de reintentos superada");
						}else
						{
							switch(opcionDos)
							{
							case 1:
								listSalon[bufferindice].isEmpty=VACIO;
							break;
							case 2:
							puts("\nSe ha cancelado la opcion de elimiar el salon");
							break;
							}
						}
					}
				break;
				case 2:
				puts("\nSe ha cancelado la opcion de elimiar el salon");
				break;
				}
			}
		}else
		{
			puts("\nEl salon ingresado no se encuentra de Alta");
		}
	}

	return retorno;
}






int inf_eliminarArcadeYVerSalon(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon)
{
	int estado = -1;

	if(listSalon!=NULL && lenSalon>0 && listArcade!=NULL && lenArcade>0)
	{

		arc_mostrarArcade(listArcade,TAM_ARCADE);
		estado=0;

	}

	return estado;

}



int inf_salonConArcades(eSalon listSalon[], int lenSalon,int idSalon,eArcade listArcade[], int lenArcade)
{

	int i;
	int estado=-1;

	if(listSalon!=NULL && lenSalon>0 && listArcade!=NULL && lenArcade>0)
	{
		for(i=0;i<TAM_ARCADE;i++)
		{
			if(listArcade[i].idSalon==idSalon && listArcade[i].isEmpty==OCUPADO)
			{
				estado=0;
			}
		}
	}

return estado;
}




int inf_cargarArcadeConSalon(eArcade listArcade[],eSalon listSalon[],int lenSalon, int idSalon)
 {

	int retorno = -1;
	int bufferIdArcade;
	char nombreDelJuego[TAM_ARCADE];
	char nacionalidad[TAM_ARCADE];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaxFichas;
	int bufferIndexSalon;

	bufferIndexSalon=sal_buscarPorId(listSalon,TAM_SALON,idSalon);


	if(listSalon[bufferIndexSalon].isEmpty==OCUPADO)
	{


	if (listArcade != NULL)
		{
			if (utn_getDescripcion(nombreDelJuego, TAM_DATOARCADE, "Por favor ingrese el Nombre del Arcade: ", "Dato invalido.\n", 3)== 0 &&
					utn_getDescripcion(nacionalidad, TAM_DATOARCADE, "Por favor ingrese la nacionalidad: ", "Dato invalido.\n", 3)== 0 &&
				utn_obtenerEnteroConReintentosMinMax(&tipoDeSonido,"Por favor ingrese el tipo de SONIDO, 1=MONO - 2=STEREO: ","Dato invalido.\n", 1, 2, 3) == 0 &&
				utn_obtenerEnteroConReintentosMinMax(&cantidadDeJugadores,"Por favor ingrese la cantidad de jugadores de 1 a 10: ","Dato invalido.\n", 1, 10, 3) == 0 &&
				utn_obtenerEnteroConReintentosMinMax(&capacidadMaxFichas,"Por favor ingrese la capacidad maxima de fichas de 1 a 1000: ","Dato invalido.\n", 1, 1000, 3)== 0)
				{

				bufferIdArcade = createId();
				retorno = 0;
				inf_adhArcadeConSalon(listArcade, TAM_ARCADE, bufferIdArcade,nombreDelJuego, nacionalidad,tipoDeSonido, cantidadDeJugadores, capacidadMaxFichas,idSalon);

				}
		}


	}
	return retorno;
}

int createId(void)
{
    static int createId = 0;

    createId++;

    return createId;

}

/**
 * @brief adhArcadeConSalon
 * @param listArcade
 * @param len
 * @param idArcade
 * @param nombreDelJuego
 * @param nacionalidad
 * @param tipoDeSonido
 * @param cantidadDeJugadores
 * @param capacidadMaxFichas
 * @param idSalon
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/


int inf_adhArcadeConSalon(eArcade listArcade[], int len, int idArcade,char nombreDelJuego[],char nacionalidad[],int tipoDeSonido,int cantidadDeJugadores, int capacidadMaxFichas,int idSalon)
{


	int bufferindice;

	if(listArcade!=NULL && len>0 &&  nombreDelJuego!=NULL && nacionalidad!=NULL)
	{
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
	}



 return -1;
}


int inf_initJuegos(eJuegos listJuegos[], int len)
{
	int indice;
	int estado = -1;
	if (listJuegos != NULL && len > 0)
	{
		for (indice = 0; indice < len; indice++)
		{
			listJuegos[indice].isEmpty = VACIO;
			estado=0;
		}
	}
		return estado;

}
/**
 * @brief
 * @param listJuegos
 * @param len
 * @param nombreJuego
 * @return
 */

int inf_JuegoEnArcade(eJuegos listJuegos[], int len,char nombreJuego[])
{

	int i;
	int estado=-1;

	if(listJuegos!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(listJuegos[i].isEmpty==OCUPADO)
			{
				if(strncmp(listJuegos[i].nombreDelJuego,nombreJuego,TAM_DATOARCADE)==0)
				{
					estado=1;
					break;
				}
			}

		}

	}
return estado;

}
/**
 *
 * @param listJuegos
 * @param lenJuego
 * @param listArcade
 * @param lenArcade
 * @return
 */
int inf_crearListJuego(eJuegos listJuegos[], int lenJuego,eArcade listArcade[], int lenArcade)
{


	inf_initJuegos(listJuegos,TAM_DATOARCADE);


	int i;
	int estado=-1;
	int indiceJuegos=0;

	if(listArcade!=NULL && listJuegos!=NULL && lenArcade>0 && lenJuego>0)
	{
		for(i=0;i<lenArcade;i++)
		{
			if(listArcade[i].isEmpty==OCUPADO)
			{
				puts("estoy aca");
				if(inf_JuegoEnArcade(listJuegos,TAM_ARCADE,listArcade[i].nombreDelJuego)==1)
				{
					puts("estoy aca 2");
					strncpy(listJuegos[indiceJuegos].nombreDelJuego,listArcade[i].nombreDelJuego,TAM_DATOARCADE);
					listJuegos[indiceJuegos].isEmpty=OCUPADO;
					estado=0;
					indiceJuegos++;

				}
			}
		}

	}
	return estado;

}


void inf_mostrarJuegos(eJuegos listJuegos[], int lenJuego)
{
	if(listJuegos!=NULL && lenJuego>0)
	{
		for (int i = 0; i < lenJuego; i++)
		{
			if(listJuegos[i].isEmpty==OCUPADO)
			{
				inf_cargarMostrarJuegos(listJuegos[i]);
			}
		}
	}
}

void inf_cargarMostrarJuegos(eJuegos listJuegos)
{
	printf("%-20s", listJuegos.nombreDelJuego);

}



void inf_mostrarArcadeConSalon(eArcade listArcade[], int lenArcade,eSalon listSalon[],int lenSalon)
{
	int i;
	int bufferId;
	int j;
	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
		{
			for (i = 0; i < lenArcade; i++)
			{
				if(listArcade[i].isEmpty==OCUPADO)
				{
					for(j=0;j<lenSalon;j++)
					{
						if(listArcade[i].idSalon==listSalon[j].idSalon && listSalon[j].isEmpty==OCUPADO)
						{
							bufferId=sal_buscarPorId(listSalon,TAM_SALON,listSalon[j].idSalon);
							inf_cargarMostrarArcade(listArcade,i);

							if(listSalon[bufferId].tipo==SHOPPING)
							{
								printf("\n%3d %10s %20s %25s\n", listSalon[bufferId].idSalon, listSalon[bufferId].nombre, listSalon[bufferId].direccion, "SHOPPING");

							}else
							{
								printf("\n%3d %10s %20s %25s\n", listSalon[bufferId].idSalon, listSalon[bufferId].nombre, listSalon[bufferId].direccion, "LOCAL");

							}

						}
					}
				}
			}
		}
}

//				arc_cargarMostrarArcade(listArcade[i],listSalon[i]);


void inf_cargarMostrarArcade(eArcade listArcade[], int index)
{
	if(listArcade[index].tipoDeSonido==MONO)
	{
		printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade[index].idArcade,listArcade[index].idSalon, listArcade[index].nombreDelJuego, listArcade[index].nacionalidad,"Sonido MONO ", listArcade[index].cantidadDeJugadores, listArcade[index].capacidadMaxFichas);

	}else
	{
		printf("\n%3d %3d %-20s %-20s %10s %10d %10d", listArcade[index].idArcade,listArcade[index].idSalon, listArcade[index].nombreDelJuego, listArcade[index].nacionalidad,"Sonido ESTEREO ", listArcade[index].cantidadDeJugadores, listArcade[index].capacidadMaxFichas);

	}

}


int arc_modificarArcadeporId(eArcade listArcade[], int lenArcade, int id)
{

		int retorno = -1;

		char nombreDelJuego[TAM_DATOARCADE];
		int cantidadDeJugadores;
		int bufferindice;
		int opcion;

	if(listArcade!=NULL && lenArcade>0)
	{

		bufferindice = arc_buscarPorId(listArcade, lenArcade, id);

			if (bufferindice >= 0 && listArcade[bufferindice].isEmpty == OCUPADO)
			{
				printf("ID %d encontrado, por favor ingrese\n",(bufferindice+1));
				puts("1 para modificar nombre Del Juego");
				puts("2 para modificar cantidad De Jugadores");
				puts("3 para cancelar la modificacion");
				if (utn_obtenerEnteroConReintentos(&opcion,
						"\nIngrese su opcion: ",
						"Dato invalido.", 3) == 0)
				{

					switch (opcion)
					{
					case 1:
						//inf_crearListJuego(listJuegos,lenJuegos,listArcade,lenArcade);
						//inf_mostrarJuegos(listJuegos,lenJuegos);
						mostrarListaJuegosSinRepetir(listArcade,TAM_ARCADE);

						if (utn_getDescripcion(nombreDelJuego,TAM_DATOARCADE,"\nPor favor ingrese nombre Del Juego: ","Dato invalido.",3)== 0)
						{
							strncpy(listArcade[bufferindice].nombreDelJuego,nombreDelJuego,TAM_DATOARCADE);
						}
						retorno = 0;
					break;
					case 2:
						if (utn_obtenerEnteroConReintentos(&cantidadDeJugadores,"\nPor favor ingrese cantidad De Jugadores: ","Dato invalido.", 3)== 0)
						{
							listArcade[bufferindice].cantidadDeJugadores = cantidadDeJugadores;
						}
						retorno = 0;
					break;
					case 3:
						puts("Se ha cancelado la modificacion");
						retorno = 0;
					break;
					}
				}

			}
	}


return retorno;
}

int inf_contarSalonesConArcades(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon)
{

	int estado = -1;
	int i;
	int j;
	int contador=0;


	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{
		for(i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				for(j=0;j<lenArcade;j++)
				{
					if(listArcade[j].isEmpty==OCUPADO)
					{
						if(listSalon[i].idSalon==listArcade[j].idSalon)
						{
							contador++;
						}
					}
				}
			}
			if(contador>4)
			{
				estado=0;
				puts("Lista Salones con mas de 4 Arcades");

				if(listSalon[i].tipo==SHOPPING)
				{
					printf("\n%3d %-20s %-20s %10s", listSalon[i].idSalon, listSalon[i].nombre, listSalon[i].direccion, "SHOPPING");

				}else
				{
					printf("\n%3d %-20s %-20s %10s", listSalon[i].idSalon, listSalon[i].nombre, listSalon[i].direccion, "LOCAL");

				}
			}
			contador=0;

		}
	}

	return estado;
}

int inf_contarArcadesDosJugadores(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int *pContador)
{
	int estado=-1;
	int contador=0;
	int i;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0 && pContador!=NULL)
	{



		for(i=0;i<lenArcade;i++)
		{
			if(listArcade[i].isEmpty==OCUPADO && listArcade[i].cantidadDeJugadores>2)
			{
				contador++;
				estado =0;
			}
		}

		*pContador=contador;
	}
	return estado;
}


int inf_mostrarSalonPorIdconArcade(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int idSalon)
{
	int estado=-1;
	int bufferIndice;
	int i;
	int contador=0;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{

		bufferIndice=sal_buscarPorId(listSalon,TAM_SALON,idSalon);


		if(listSalon[bufferIndice].isEmpty==OCUPADO)
		{
			for(i=0;i<lenArcade;i++)
			{

				if(idSalon==listArcade[i].idSalon)
				{
					contador++;
				}
			}

			estado=0;
			if(listSalon[bufferIndice].tipo==SHOPPING)
			{
				printf("%3d %-20s %-20s %10s Total de Arcades: %10d\n", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "SHOPPING",contador);

			}else
			{
				printf("%3d %-20s %-20s %10s Total de Arcades: %10d\n", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "LOCAL",contador);

			}


		}else
		{
			puts("El salon se encuentra de baja");
		}

	}
	return estado;
}
int inf_mostrarArcadesDeUnSalon(eArcade listArcade[],int lenArcade,eSalon listSalon[],int lenSalon,int idSalon)
{
	int estado=-1;
	int bufferIndice;
	int i;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{

		bufferIndice=sal_buscarPorId(listSalon,TAM_SALON,idSalon);


		if(listSalon[bufferIndice].isEmpty==OCUPADO)
		{
			if(listSalon[bufferIndice].tipo==SHOPPING)
			{
				printf("%3d %-18s %-20s %10s", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "SHOPPING");

			}else
			{
				printf("%3d %-18s %-20s %10s", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "LOCAL");

			}
			for(i=0;i<lenArcade;i++)
			{

				if(idSalon==listArcade[i].idSalon && listArcade[i].isEmpty==OCUPADO)
				{

					if(listArcade[i].tipoDeSonido==MONO)
						{
							printf("\n%3d %3d %-20s %-20s %10s %20d %10d", listArcade[i].idArcade,listArcade[i].idSalon, listArcade[i].nombreDelJuego, listArcade[i].nacionalidad,"Sonido MONO ", listArcade[i].cantidadDeJugadores, listArcade[i].capacidadMaxFichas);

						}else
						{
							printf("\n%3d %3d %-20s %-20s %10s %17d %10d", listArcade[i].idArcade,listArcade[i].idSalon, listArcade[i].nombreDelJuego, listArcade[i].nacionalidad,"Sonido ESTEREO ", listArcade[i].cantidadDeJugadores, listArcade[i].capacidadMaxFichas);

						}



				}
			}
		}else
		{
			puts("El ID no se encuentra activo");
		}

	}
	return estado;
}

int inf_masCantidadArcades(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade)
{

	int estado = -1;
	int i;
	int j;
	int contador=0;
	int max;
	int bufferIndice;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
		{
			for(i=0;i<lenSalon;i++)
			{
				if(listSalon[i].isEmpty==OCUPADO)
				{
					contador=0;
					for(j=0;j<lenArcade;j++)
					{
						if(listArcade[j].isEmpty==OCUPADO)
						{
							if(listSalon[i].idSalon==listArcade[j].idSalon)
							{
								{
									contador++;
								}
							}
						}
					}
						if(i==0 || max<contador)
						{
							bufferIndice=i;
							max=contador;
						}
				}
			}
		}


	printf("\n\nEl salon con mas arcades es ID %d \n",(bufferIndice+1));

	if(listSalon[bufferIndice].tipo==SHOPPING)
	{
		printf("%3d %-20s %-20s %10s\n", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "SHOPPING");

	}else
	{
		printf("%3d %-20s %-20s %10s\n", listSalon[bufferIndice].idSalon, listSalon[bufferIndice].nombre, listSalon[bufferIndice].direccion, "LOCAL");

	}

	printf("La cantidad de arcades es: %d \n",max);

	return estado;
}



/*H) Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. Listar los
salones que cumplan con este mínimo de requisito.*/



int inf_salonCompleto(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade)
{

	int estado = -1;
	int i;
	int j;
	int contador=0;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{
		for(i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				for(j=0;j<lenArcade;j++)
				{
					if(listSalon[j].isEmpty==OCUPADO)
					{
						if(listSalon[i].idSalon==listArcade[j].idSalon && listArcade[j].cantidadDeJugadores>2)
						{
							contador++;
						}
					}
				}
					if(contador>=8)
					{
						printf("\n %d %s %s",listSalon[i].idSalon,listSalon[i].nombre,listSalon[i].direccion);
					}
				contador=0;
			}
		}
	estado=0;
	}

return estado;
}

/*I) Imprimir el promedio de arcades por salón. (Cantidad de arcades totales / Cantidad de salones totales).
		*/




int inf_promedioArcade(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade)
{

	int estado = -1;
	int i;
	int j;
	int contadorArcade=0;
	int contadorSalon=0;
	float promedio;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{
		for(i=0;i<lenSalon;i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				contadorSalon++;
			}

		}
			for(j=0;j<lenArcade;j++)
			{
				if(listArcade[j].isEmpty==OCUPADO)
				{
					contadorArcade++;
				}
			}


			if(contadorSalon==0)
			{
				puts("No hubo salones cargados");
			}

			estado = 0;

			if(contadorArcade==0)
			{
				puts("No hubo arcades cargados");
			}

			promedio=(float)contadorArcade/contadorSalon;

			printf("\n el promedio es %2.f ",promedio);


	}

	return estado;
}


int cuentaFichasDeLSalon(eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade, int idSalon)
{
	int estado=-1;
	int acumuladorDeFichas;
	int i;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{
			for(i=0;i<lenSalon;i++)
			{
					if(listArcade[i].idSalon==idSalon && listArcade[i].isEmpty==OCUPADO)
					{
						acumuladorDeFichas+=listArcade[i].capacidadMaxFichas;
					}
			}

			estado=acumuladorDeFichas;
	}






	return estado;
}

int montoMaximoEnPesos (eSalon listSalon[],int lenSalon,eArcade listArcade[],int lenArcade, int idSalon,float precioDeFicha)
{

	int estado=-1;
	int totalDeFichas;
	float montoMaximo;

	if(listArcade!=NULL && listSalon!=NULL && lenArcade>0 && lenSalon>0)
	{
		totalDeFichas=cuentaFichasDeLSalon(listSalon,TAM_SALON,listArcade,TAM_ARCADE,idSalon);

		if(totalDeFichas>0)
		{

			montoMaximo=totalDeFichas*precioDeFicha;


		}

		printf("el monto Maximo que puede recaudar el salon es: %2.f",montoMaximo);
		estado=0;
	}



return estado;
}
















