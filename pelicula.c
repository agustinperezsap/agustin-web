#include "pelicula.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


t_pelicula CargarRegistro(long codigo){
	
	t_pelicula aux;
	
	aux.codigo = codigo;
	fflush(stdin);
	printf("\nDuracion: \n");
	scanf("%ld",&aux.duracion);
	fflush(stdin);
	printf("\nFecha de publicacion: \n");
	scanf("%ld", &aux.fechaPublicacion);
	fflush(stdin);
	printf("\nTitulo: \n");
	leeCad(aux.titulo,TAM);
	fflush(stdin);
	printf("\nGenero: \n");
	do{
		printf("[1]: Accion.\n");
		printf("[2]: Comedia.\n");
		printf("[3]: Terror.\n");
		printf("[4]: Romantica.\n");
		printf("[5]: Crimen.\n");
		printf("[6]: Documental.\n");
		printf("[7]: Drama.\n");
		printf("[8]: Musical.\n");
		printf("[9]: Aventura.\n");
		printf("[10]: Ciencia Ficcion.\n");
		scanf("%d",&aux.genero);
	} while(aux.genero<0||aux.genero>10);
	printf("\nNombre del Actor: \n"); fflush(stdin);
	leeCad(aux.artista,TAM);
	fflush(stdin);
	
	return aux;
}
	
void MostrarReg(t_pelicula aux ){
	printf ("\nNro codigo: %ld",aux.codigo);
	printf ("\nFecha de publicacion: %ld",aux.fechaPublicacion);
	printf ("\nTitulo: %s",aux.titulo);
	printf ("\nGenero: %d",aux.genero);
	printf ("\nNombre del actor: %s",aux.artista);
	
	printf("\n\n");
}
	
long Retornarcodigo(t_pelicula aux){
	return aux.codigo;
}
	
long RetornarfechaPubliccaion(t_pelicula aux){
	return aux.fechaPublicacion;
}

int comparaTitulo(t_pelicula aux, t_pelicula aux2){
	return comparacadenas(aux.titulo,aux2.titulo);
}

int compara_Actor_ingresado(t_cad aux, t_pelicula aux2){
	return comparacadenas(aux, aux2.artista);
}
	
int comparaActor(t_pelicula aux, t_pelicula aux2){
	return comparacadenas(aux.artista, aux2.artista);
}

int Retornargenero(t_pelicula aux){
	return aux.genero;
}
	
void Modificar(t_pelicula *aux, long codigo){
	printf("\n***Ingrese los nuevos datos de la pelicula*** \n");
	fflush(stdin);
	*aux=CargarRegistro(codigo);
	printf("\n\t.:Modificacion completa:.\n");
	
	MostrarReg(*aux);
}
