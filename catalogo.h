
#include "pelicula.h"

typedef t_pelicula t_catalogo[20]; //Vector de registro.

typedef	struct{
	t_catalogo lista;
	int tam;
}tlista; //Un registro que contiene el vector y el tamaño.


tlista InicializarLista();//publico
tlista CargarLista(); //Inicializa la lista con elementos.
int listaLlena(tlista );
int listaVacia(tlista );
void EliminarElemento(tlista *aux); 
void AgregarUnoOrdenado(tlista *);
void MostrarSaldo0(tlista );
void muestraPeliculaActor(tlista);
void muestra_lista(tlista );
void muestraPeliculaGenero(tlista);
void mostrar_grup_genero(tlista );
void modificarPelicula(tlista *);
void muestraPeliculaGenero(tlista );
