#include "catalogo.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
/**Alumno: Perez Santaigo*/



/**a) De la pel�cula se debe almacenar:*/
/*	Codigo:*/
/*	Titulo*/
/*	G�nero*/
/*	Duraci�n*/
/*	Actores:*/
/*	Fecha Publicaci�n.*/
/**	b) Agregar una pel�cula. La lista de pel�culas siempre debe estar ordenada por c�digo.*/
/**	c) Dar de baja la/s pel�cula/s m�s antigua/s.//n=n-1*/
/**	d) Modificar los datos de una pel�cula.. //pedimos que ingrese codigo de la pelicula y le retornamos si esta o no  esa pelicula. y si esta la modificamos.*/
/**	e) Mostrar las pel�culas de un g�nero dado ordenadas alfab�ticamente.*/
/**	f) Mostrar las pel�culas donde aparece un actor.*/
/**	g) Mostrar todas las pel�culas agrupadas por g�nero.*/


int menu(void);
	


int main(void){
	tlista pelicula;
	int opc;
	
	InicializarLista();

	pelicula = CargarLista();
	do
	{
		system("CLS");//Borra la pantalla
		opc=menu();
		switch(opc)
		{
		case 1://Agregar una pel�cula. La lista de pel�culas siempre debe estar ordenada por c�digo
			if(listaLlena(pelicula)){
				AgregarUnoOrdenado(&pelicula);
			}
			else{
				printf("Lista llena");
			}
			break;
		case 2://Dar de baja la/s pel�cula/s m�s antigua/s
			if(listaVacia(pelicula)){
				EliminarElemento(&pelicula);
				muestra_lista(pelicula);
			}
			else{
				printf("Lista Vacia:");
			}
			//publico
			break;
		case 3://Modificar los datos de una pel�cula
			if(listaVacia(pelicula)){
				modificarPelicula(&pelicula);
			}
			else{
				printf("Lista Vacia:");
			}
			
			break;
		case 4://Mostrar las pel�culas de un g�nero dado ordenadas alfab�ticamente.
			if(listaVacia(pelicula)){
				muestraPeliculaGenero(pelicula);
			}
			else{
				printf("Lista Vacia:");
			}
			
			printf("\n \n");
			break;
		case 5://Mostrar las pel�culas donde aparece un actor.
			if(listaVacia(pelicula)){
				muestraPeliculaActor(pelicula);
			}
			else{
				printf("Lista Vacia:");
			}
			break;
		case 6://Mostrar todas las pel�culas agrupadas por g�nero.
			if(listaVacia(pelicula)){
				mostrar_grup_genero(pelicula);
			}
			else{
				printf("Lista Vacia:");
			}
			break;
		default:
			printf("\n  Fin del Programa \n");
		}
		system("PAUSE");
	}while(opc!=0);
	
	return 0;
}

int menu(void)
{
	int rta,band;
	band=0;
	do
	{
		if(band == 1)
			printf("\n * !! Opcion fuera de rango !! * \n");
		printf("\n\n >1<Agregar una pelicula\n");
		printf(" -- - - -- - -- \n");
		printf(" >2< Dar de baja pelicula mas antigua\n" );
		printf(" -- - - -- - -- \n");
		printf(" >3< Modificar los datos de una pelicula\n" );
		printf(" -- - - -- - -- \n");
		printf(" >4< Mostrar peliculas de un genero:\n" );
		printf(" -- - - -- - -- \n");
		printf(" >5< Mostrar  peliculas de un determinado actor:\n" );
		printf(" -- - - -- - -- \n");
		printf(" >6< Mostrar peliculas agrupadas por genero:\n" );
		printf(" -- - - -- - -- \n");
		printf(" <0> SALIR\n");
		printf(" Elija su opcion: ");
		scanf("%d",&rta);
		band = 1;
	}while(rta < 0 || rta > 7);
	return rta;
}
	
	
	
