/*
 ============================================================================
 Name        : 1erParcial.c
 Author      : JuanSebastian Viazzo Perrone
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

1) ALTA DE SALÓN
Se deberá dar de alta un salón con los siguientes datos: Nombre, dirección y tipo.
Se generará un ID único para gestionar los SALONES.
Este salón se imprimirá por pantalla si el alta es correcta.
2) ELIMINAR SALÓN
Se imprime la lista de salas listando ID, nombre y dirección.
Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.
3) IMPRIMIR SALONES
Se imprime la lista completa de salas con todos sus datos. Nombre, dirección y tipo.
4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE.
5) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego.
6) ELIMINAR ARCADE
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
confirmando si está seguro dar de baja esté mismo.
7) IMPRIMIR ARCADES
Se imprime la lista de arcades con ID, y sus datos.
8) IMPRIMIR JUEGOS
Se imprime la lista de juegos que contienen todos los arcades sin repetir.



 */


#include "Informes.h"


int main(void)
{


	setbuf(stdout, NULL);

	eSalon listSalon[TAM_SALON];
	sal_iniciarListSalon(listSalon,TAM_SALON);
	eArcade listArcade[TAM_ARCADE];
	arc_iniArcade(listArcade,TAM_ARCADE);



	int opcion;
	int idSalonArcade;
	int idSalon;
	int bufferIdSalon;
	int idArcade;
	int pDosJugadores;
	int aux=1;
	int buf=1;
	int idSalonMonto;
	float precioFicha;
	int pContadorArcades;
	int opcionDos;

	addForced(listSalon,TAM_SALON,0,&aux,"SACOA","LAVALLE 540",2);
	addForced(listSalon,TAM_SALON,1,&aux,"PLAYLAND","ABASTO",1);
	addForced(listSalon,TAM_SALON,2,&aux,"KIMOCHI","FLORIDA 950",2);
	addForced(listSalon,TAM_SALON,3,&aux,"OMEGA","SANTA FE Y PUEYRREDON",1);
	addForced(listSalon,TAM_SALON,4,&aux,"NETGAMES","GASCON Y CORRIENTES",2);
	addForced(listSalon,TAM_SALON,5,&aux,"EL CICLON","AVENIDA LA PLATA 1700",1);
	addForced(listSalon,TAM_SALON,6,&aux,"LA ROSADA","BALCARCE 50",2);
	addForced(listSalon,TAM_SALON,7,&aux,"LAS MALVINAS","SON ARGENTINAS 1982",2);
	addForced(listSalon,TAM_SALON,8,&aux,"RITMO","Y SUSTANCIA 666",2);
	addForced(listSalon,TAM_SALON,9,&aux,"MATRIX & TRON","LA NARANJA MECANICA",2);

	addForcedArcade(listArcade,TAM_ARCADE,0,&buf,"MORTAL KOMBAT","EEUU",1,8,500,4);
	addForcedArcade(listArcade,TAM_ARCADE,1,&buf,"MARADONA Y MESSI","ARGENTINA",2,9,500,1);
	addForcedArcade(listArcade,TAM_ARCADE,2,&buf,"ZAMBA Y ZUNGA","BRASIL",1,4,500,2);
	addForcedArcade(listArcade,TAM_ARCADE,3,&buf,"PATRICIO REY","ARGENTINA",1,10,800,1);
	addForcedArcade(listArcade,TAM_ARCADE,4,&buf,"INDIO SOLARI","ARGENTINA",2,9,300,1);
	addForcedArcade(listArcade,TAM_ARCADE,5,&buf,"VIRTUAL STRIKER","EEUU",2,4,700,4);
	addForcedArcade(listArcade,TAM_ARCADE,6,&buf,"VIRTUAL TENIS","RUSIA",1,6,500,5);
	addForcedArcade(listArcade,TAM_ARCADE,7,&buf,"PACMAN","JAPON",1,8,500,5);
	addForcedArcade(listArcade,TAM_ARCADE,8,&buf,"SKAY BEILINSON","ARGENTINA",1,9,500,1);
	addForcedArcade(listArcade,TAM_ARCADE,9,&buf,"KING OF FIGHTERS","EEUU",1,5,500,8);
	addForcedArcade(listArcade,TAM_ARCADE,10,&buf,"YVAN EHT NIOJ","USA",1,3,500,8);
	addForcedArcade(listArcade,TAM_ARCADE,11,&buf,"MORTAL KOMBAT","EEUU",1,2,500,7);
	addForcedArcade(listArcade,TAM_ARCADE,12,&buf,"SUMO","ARGENTINA",1,10,500,1);
	addForcedArcade(listArcade,TAM_ARCADE,13,&buf,"HELLBREATH","ARGENTINA",1,10,500,1);
	addForcedArcade(listArcade,TAM_ARCADE,14,&buf,"CHINA SUAREZ","CHINA",1,4,500,4);
	addForcedArcade(listArcade,TAM_ARCADE,15,&buf,"TC 2000","EUROPA",1,10,500,3);
	addForcedArcade(listArcade,TAM_ARCADE,16,&buf,"TC 2000","ARGENTINA",1,8,500,1);
	addForcedArcade(listArcade,TAM_ARCADE,17,&buf,"ARGENTUM ONLINE","ARGENTINA",1,10,500,1);





	do
	{

		menu(&opcion);

		switch (opcion)

		{
			case 1:


				if(sal_cargarSalon(listSalon,&bufferIdSalon)==0)
				{
					sal_mostrarPorId(listSalon,TAM_SALON,bufferIdSalon);
				}else
				{
					puts("Error, carga incorrecta");
				}

			break;
			case 2:

				sal_mostrarSalonSinTipo(listSalon,TAM_SALON);
				utn_obtenerEnteroConReintentos(&idSalonArcade,"\nPor favor ingrese el numero de Id del Salon: ","Error Dato Invalido",3);
				if(inf_borrarSalonYArcade(listSalon,TAM_SALON,idSalonArcade,listArcade,TAM_ARCADE)==0)
				{
					puts("\nBaja Correcta");
				}
				else
				{
					puts("\nNo se realizo la baja");
				}
			break;
			case 3:
				sal_ordenarSalon(listSalon,TAM_SALON,1);
				sal_mostrarSalon(listSalon,TAM_SALON);
			break;
			case 4:
				utn_obtenerEnteroConReintentos(&idSalon,"Por favor ingrese el Id del Salon al que pertenece el Arcade: ","Error cantidad de reintentos superada",3);
				if(inf_cargarArcadeConSalon(listArcade,listSalon,TAM_SALON,idSalon)==0)
				{
					puts("Se ha cargado el Arcade correctamente");
				}
			break;
			case 5:
				arc_mostrarArcade(listArcade,TAM_ARCADE);
				utn_obtenerEnteroConReintentos(&idArcade,"\nPor favor ingrese el Id del Arcade a modificar: ","\nError cantidad de reintentos superada",3);
				if(arc_modificarArcadeporId(listArcade,TAM_ARCADE,idArcade)==0)
				{
					puts("Modificacion correcta");
				}
				else
				{
					puts("No se ha podido procesar la modificacion");
				}
			break;
			case 6:
				inf_mostrarArcadeConSalon(listArcade,TAM_ARCADE,listSalon,TAM_SALON);
				utn_obtenerEnteroConReintentos(&idArcade,"\nPor favor ingrese el Id del Arcade para dar de baja: ","\nError cantidad de reintentos superada",3);
				if(arc_borrarArcade(listArcade,TAM_ARCADE,idArcade)==0)
				{
					puts("Baja correcta");
				}
				else
				{
					puts("No se ha podido procesar la baja");
				}
			break;
			case 7:
				arc_mostrarArcade(listArcade,TAM_ARCADE);
			break;
			case 8:
					//inf_crearListJuego(listJuegos,TAM_ARCADE,listArcade,TAM_ARCADE);
					//inf_mostrarJuegos(listJuegos,TAM_ARCADE);
					mostrarListaJuegosSinRepetir(listArcade,TAM_ARCADE);
			break;
			case 9:

				menuDos(&opcionDos);

				switch (opcionDos)
				{
					case 1:
						if(inf_contarSalonesConArcades(listArcade,TAM_ARCADE,listSalon,TAM_SALON)==1)
						{
							puts("\nNo hay salones con mas de 4 Arcades");
						}
						break;
					case 2:

						if(inf_contarArcadesDosJugadores(listArcade,TAM_ARCADE,listSalon,TAM_SALON,&pDosJugadores)==0)
						{
							printf("\n\nla cantidad de arcades con mas de dos jugadores son: %d\n",pDosJugadores);
						}else
						{
							puts("\nNo hay arcades con mas de dos jugadores");
						}
						break;
					case 3:
						utn_obtenerEnteroConReintentos(&idSalon,"\nPor favor ingrese el Id del Salon: ","Error datos invalidos",3);
						inf_mostrarSalonPorIdconArcade(listArcade,TAM_ARCADE,listSalon,TAM_SALON,idSalon);
						break;
					case 4:
						utn_obtenerEnteroConReintentos(&idSalon,"\nPor favor ingrese el Id del Salon: ","Error datos invalidos",3);
						inf_mostrarArcadesDeUnSalon(listArcade,TAM_ARCADE,listSalon,TAM_SALON,idSalon);

						break;
					case 5:
						inf_masCantidadArcades(listSalon,TAM_SALON,listArcade,TAM_ARCADE);
						break;
					case 6:
						utn_obtenerEnteroConReintentos(&idSalonMonto,"\nPor favor ingrese el Id del Salon: ","Error datos invalidos",3);
						utn_getNumeroFlotanteMinyMaxReintentos(&precioFicha,"Por favor ingrese el monto por Ficha: ","Error datos invalidos",0,10000,3);
						montoMaximoEnPesos(listSalon,TAM_SALON,listArcade,TAM_ARCADE,idSalonMonto,precioFicha);
						break;
					case 7:
						if(cuantosArcadesPorJuego(listArcade,TAM_ARCADE,&pContadorArcades)==0)
						{
							printf("\nLa cantidad de arcades que contienen el juego es: %d",pContadorArcades);
						}
						break;
					case 8:
						inf_salonCompleto(listSalon,TAM_SALON,listArcade,TAM_ARCADE);
						break;
					case 9:
						inf_promedioArcade(listSalon,TAM_SALON,listArcade,TAM_ARCADE);
						break;
				}
		}

	} while (opcion!=10);

return 0;

}

