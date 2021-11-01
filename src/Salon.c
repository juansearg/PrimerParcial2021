/*
 * ArrayeEntidad1s.c
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 *
 *
 *
 *
 *
 *
 *
 *
 */


#include "Salon.h"









/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eEntidad1* Pointer to array of eEntidad1s
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sal_iniciarListSalon(eSalon listSalon[], int len)
{
	int indice;
	int status = -1;
	if (listSalon != NULL && len > 0)
	{
		status = 0;
		for (indice = 0; indice < len; indice++)
		{
			listSalon[indice].isEmpty = VACIO;
		}
	}
	return status;
}


/*    char variableTxt3[64];
    char nombre[64];
    char direccion[64];
    int tipo;
    int varInt2;
    float varFloat1;
    float varFloat2;
    char varChar;
    int idSalon;
    int idSegEntidad;
    int isEmpty;
   */

int sal_cargarSalon(eSalon listSalon[], int *bufferIdSalon)
 {

	int status = -1;
	char nombre[TAM_DATOSALON];
	char direccion[TAM_DATOSALON];
	int idSalon;
	int tipo;


	if (listSalon != NULL)
		{
			if (utn_getDescripcion(nombre, TAM_DATOSALON, "Por favor ingrese el nombre del Salon: ", "Dato invalido.\n", 3)== 0 &&
				utn_getDescripcion(direccion, TAM_DATOSALON, "Por favor ingrese la direccion: ", "Dato invalido.\n", 3)== 0 &&
				utn_obtenerEnteroConReintentosMinMax(&tipo,"Por favor ingrese el tipo de Salon:  1=SHOPPING - 2=LOCAL: ","Dato invalido.\n", 1, 2, 3) == 0 )
			{

					idSalon = createIdSalon();
					*bufferIdSalon=idSalon;
					status = 0;
					sal_adhSalon(listSalon, TAM_DATOSALON,idSalon,nombre, direccion,tipo);

				}
		}

	return status;
}

int createIdSalon(void)
{
    static int createId = 0;

    createId++;

    return createId;

}

/**
 *
 * @param listSalon
 * @param len
 * @param idSalon
 * @param nombre
 * @param direccion
 * @param tipo
 * @return
 */


int sal_adhSalon(eSalon listSalon[], int len, int idSalon,char nombre[],char direccion[],int tipo)
{

	int bufferindice;

	if((bufferindice=sal_buscarLibreSalon(listSalon,len))>=0)
	{
		listSalon[bufferindice].idSalon=idSalon;
		strncpy(listSalon[bufferindice].nombre,nombre,sizeof(listSalon->nombre));
		strncpy(listSalon[bufferindice].direccion,direccion,sizeof(listSalon->direccion));
		listSalon[bufferindice].tipo=tipo;
		listSalon[bufferindice].isEmpty=OCUPADO;
		return 0;

	}

 return -1;
}


int sal_buscarLibreSalon(eSalon listSalon[], int len)
{
	int i=0;
	int indiceLibre=-1;

	if(listSalon!=NULL && len>0)
	{
		indiceLibre=-2;

		for (i=0;i<len;i++)
		{

			if(listSalon[i].isEmpty==1)
			{
				indiceLibre=i;
				break;
			}

		}

	}

	return indiceLibre;

}


int crearId(void)
{
    static int crearId = 0;

    crearId++;

    return crearId;

}



/** \brief find an eEntidad1 by Id en returns the indice position in array.
 *
 * \param list eEntidad1*
 * \param len int
 * \param id int
 * \return Return eEntidad1 indice position or (-1) if [Invalid length or NULL
pointer received or eSalon not found]
 *
 */
int sal_buscarPorId(eSalon listSalon[], int len,int idSalon)
{

		int indice;
		int estado = -1;
		if (listSalon != NULL && len > 0)
		{
			for (indice = 0; indice < len; indice++)
			{
				if (listSalon[indice].isEmpty != 1)
				{
					if (listSalon[indice].idSalon == idSalon)
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


/** \brief Remove a eEntidad1 by Id (put isEmpty Flag in 1)
 *
 * \param list eEntidad1*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a eSalon] - (0) if Ok
 *
 */
int sal_borrarSalon(eSalon listSalon[], int len, int idSalon)
{

	int retorno=-1;
	int bufferindice;
	int opcion;

	if(listSalon!=NULL && len>0)
	{
		bufferindice=sal_buscarPorId(listSalon,len,idSalon);
				if(bufferindice>=0 && listSalon[bufferindice].isEmpty==0)
				{
					puts("ID encontrado, por favor Ingrese 1 para borrar, 2 para cancelar");
					utn_obtenerEnteroConReintentos(&opcion,"Ingrese su opcion: ","Error, cantidad de reintentos superada",3);
					switch (opcion)
					{
						case 1:
							listSalon[bufferindice].isEmpty=1;
							retorno = 0;
							break;
						case 2:
							puts("Se ha cancelado la opcion de elimiar usuario");
							break;
					}

				}else
				{
					retorno=1;
				}
	}





 return retorno;
}


/** \brief Sort the elements in the array of eEntidad1s, the argument order
indicate UP or DOWN order
 *
 * \param list eEntidad1*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
//por Texto1(apellido) y si son == ordenar Int1(Legajo)
int sal_ordenarSalonDosVar(eSalon listSalon[], int len, int order)
{
	int retorno = -1;
	eSalon bufferList;
	int i;
	int j;

	if (listSalon != NULL && len >= 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (strcmp(listSalon[i].nombre, listSalon[j].nombre) > 0 ||
					   (strcmp(listSalon[i].nombre, listSalon[j].nombre) == 0 && listSalon[i].tipo > listSalon[j].tipo)) // > de menor a mayor
						{
							bufferList = listSalon[i];
							listSalon[i] = listSalon[j];
							listSalon[j] = bufferList;
						}
				}
			}

			break;
		case 2:
			for (i = 0; i < len; i++)
			{
				for (j = i + 1; j < len; j++)
					if (strcmp(listSalon[i].nombre, listSalon[j].nombre) > 0 ||
					   (strcmp(listSalon[i].nombre, listSalon[j].nombre) == 0 && listSalon[i].tipo > listSalon[j].tipo)) // > de menor a mayor
						{
							bufferList = listSalon[i];
							listSalon[i] = listSalon[j];
							listSalon[j] = bufferList;
						}
			}

		break;
		}
	}
	return retorno;

}



//ordena por el Int1, ejemplo edades legajos.
int sal_ordenarSalon(eSalon listSalon[], int len, int order)
{
	int retorno = -1;
	eSalon bufferList;
	int i;
	int j;

	if (listSalon != NULL && len >= 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (listSalon[i].idSalon > listSalon[j].idSalon)
					{
						bufferList = listSalon[i];
						listSalon[i] = listSalon[j];
						listSalon[j] = bufferList;
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
					if (listSalon[i].idSalon < listSalon[j].idSalon)
					{
						bufferList = listSalon[i];
						listSalon[i] = listSalon[j];
						listSalon[j] = bufferList;
						retorno = 0;
					}
				}
			}
		break;
		}
	}
	return retorno;
}


/** \brief print the content of eEntidad1s array
 *
 * \param list eSalon*
 * \param length int
 * \return int
 *
 */



void sal_mostrarPorId(eSalon listSalon[], int len, int idSalon)
{
	if(listSalon!=NULL && len>0)
	{
		for (int i = 0; i < len; i++)
				{
					if(listSalon[i].isEmpty==OCUPADO && listSalon[i].idSalon==idSalon)
					{
						sal_cargarMostrarSalon(listSalon[i]);
					}
				}

	}




}

void sal_mostrarSalon(eSalon listSalon[], int len)
{
	int i;

		for (i = 0; i < len; i++)
		{
			if(listSalon[i].isEmpty==0)
			{
				sal_cargarMostrarSalon(listSalon[i]);
			}
		}

}

void sal_cargarMostrarSalon(eSalon listSalon)
{
	if(listSalon.tipo==SHOPPING)
	{
		printf("\n%3d %-20s %-20s %10s\n", listSalon.idSalon, listSalon.nombre, listSalon.direccion, "SHOPPING");

	}else
	{
		printf("\n%3d %-20s %-20s %10s\n", listSalon.idSalon, listSalon.nombre, listSalon.direccion, "LOCAL");

	}

}

void sal_mostrarSalonSinTipo(eSalon listSalon[], int len)
{
	if(listSalon!=NULL && len>0)
	{
		for (int i = 0; i < len; i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				sal_cargarMostrarSalonSinTipo(listSalon[i]);
			}
		}
	}
}

void sal_cargarMostrarSalonSinTipo(eSalon listSalon)
{
	printf("\n%3d %-20s %-20s\n", listSalon.idSalon, listSalon.nombre, listSalon.direccion);

}

/*
int sal_modificarSalonporId(eSalon listSalon[], int len, int idSalon)
{

		int retorno = -1;
		char nombre[TAM_DATOSALON];
		char direccion[TAM_DATOSALON];
		int tipo;
		int bufferindice;
		int opcion;

		if(listSalon!=NULL && len>0)
		{

		bufferindice = sal_buscarPorId(listSalon, len, idSalon);

			if (bufferindice >= 0 && listSalon[bufferindice].isEmpty == 0)
			{
				puts("ID encontrado, por favor ingrese");
				puts("1 para modificar nombre");
				puts("2 para modificar direccion");
				puts("3 para modificar variableTxt3");
				puts("4 para modificar varChar");
				puts("5 para modificar tipo");
				puts("6 para modificar varInt2");
				puts("7 para modificar varFloat1");
				puts("8 para modificar varFlaot2");
				puts("9 para cancelar la modificacion");
				if (utn_obtenerEnteroConReintentos(&opcion,
						"Ingrese su opcion: ",
						"Dato invalido.", 3) == 0)
				{

					switch (opcion)
					{
					case 1:
						if (utn_getNombreIntentos(nombre, TAM_DATOSALON,
								"Por favor ingrese nombre: ",
								"Dato invalido.", 3)
								== 0)
						{
							strncpy(listSalon[bufferindice].nombre, nombre,
									sizeof(listSalon->nombre));
						}
						retorno = 0;
						break;
					case 2:
						if (utn_getNombreIntentos(direccion, TAM_DATOSALON,
								"Por favor ingrese direccion : ",
								"Dato invalido.", 3)
								== 0)
						{
							strncpy(listSalon[bufferindice].direccion, direccion,
									sizeof(listSalon->direccion));
						}
						retorno = 0;
						break;
					case 3:
						if (utn_obtenerEnteroConReintentos(&tipo,
								"Por favor ingrese tipo: ",
								"Dato invalido.", 3)
								== 0)
						{
							listSalon[bufferindice].tipo = tipo;
						}
						retorno = 0;
						break;
					case 4:
						puts("Se ha cancelado la modificacion");
						retorno = 0;
						break;
					}
				}

			}

		}

return retorno;
}
*/


int addForced(eSalon listSalon[], int len,int index, int *id, char nombre[],char direccion[],int tipo)
{

	eSalon bufferSalon;
	int status = -1;

	if(listSalon != NULL && len>0 && index < len && index >= 0)
	{
		strncpy(bufferSalon.nombre,nombre,TAM_DATOSALON);
		strncpy(bufferSalon.direccion,direccion,TAM_DATOSALON);
		bufferSalon.tipo=tipo;
		bufferSalon.idSalon=*id;
		bufferSalon.isEmpty=0;
		status = 0;
		listSalon[index]=bufferSalon;
		(*id)++;



	}

 return status;
}
