
#include "cadena.h"
typedef struct{
	long  codigo;
	long duracion;
	long fechaPublicacion; 
	t_cad  titulo;
	int  genero;
	t_cad artista;
	
}t_pelicula;


t_pelicula CargarRegistro(long );
void MostrarReg(t_pelicula );
void ModificarSaldo(t_pelicula *, float );
long Retornarcodigo(t_pelicula );
int Retornargenero(t_pelicula );
int comparaTitulo(t_pelicula , t_pelicula );
int compara_Actor_ingresado(t_cad , t_pelicula );
int comparaActor(t_pelicula , t_pelicula );
long RetornarfechaPubliccaion(t_pelicula);
void Modificar(t_pelicula *, long );
