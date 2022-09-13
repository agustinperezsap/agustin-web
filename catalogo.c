#include "catalogo.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


tlista InicializarLista(){/**publico*/
	tlista lista;
	lista.tam = 0;
	return lista;
}

int listaLlena(tlista aux){//publico
	if(aux.tam < 20){
		return 1;
	}
	else{
		return 0;
	}
}
int listaVacia(tlista aux){//publico
	if(aux.tam != 0){
		return 1;
	}
	else{
		return 0;
	}
}
	
	
	
int  busbin_rec(t_catalogo vec, int ini, int fin, long bus){//privado
	
	int m=(ini+fin)/2;
	
	if (ini>fin)
		return -1;
	else
		if(Retornarcodigo(vec[m])==bus)
		return m;
		else
			if (bus > Retornarcodigo(vec[m]))
				return busbin_rec(vec,m+1,fin,bus);
			else
				return busbin_rec(vec,ini,m-1,bus);
	
}
void Ordenar_Uno_Baraja_rec(t_catalogo vec,int tam){//privado
	
	if (Retornarcodigo(vec[0]) >= Retornarcodigo(vec[tam]))
		vec[tam+1]=vec[0];
	else {
		vec[tam+1]=vec[tam];
		Ordenar_Uno_Baraja_rec(vec,tam-1);
	}	
}

void Carga_uno_ordenado_validado_rec(t_catalogo vec, int tam){
	int pos;
	long codigo;
	
	printf("Ingrese un nro de codigo de la pelicula:");
	scanf ("%ld",&codigo);
	
	pos = busbin_rec(vec,1,tam,codigo);//Controlar que el nro de codigo de pelicula no este duplicado
	
	if (pos==-1){
		vec[tam]=CargarRegistro(codigo);
		vec[0]= vec[tam]; //Agrego al final el nuevo registro
		Ordenar_Uno_Baraja_rec(vec,tam-1);
	}	
	else{
		printf("Pelicula duplicada");
		Carga_uno_ordenado_validado_rec(vec,tam-1);
	}
}
	
void Cargar_Vector_rec(t_catalogo vec, int tam){ //es una operación privada.
	if (tam!=0){
		Cargar_Vector_rec(vec,tam-1);
		Carga_uno_ordenado_validado_rec(vec,tam);
	}
	
}

tlista CargarLista(){/*publico*/
	tlista aux;
	printf ("Ingrese el tamaño del catalogo:");
	scanf("%d",&aux.tam);
	Cargar_Vector_rec(aux.lista,aux.tam);
	
	return aux;
	
}

void AgregarUnoOrdenado(tlista *aux){
	aux->tam=aux->tam+1;
	Carga_uno_ordenado_validado_rec(aux->lista, aux->tam);
}
	
	
/**---------*/

int fechaAntigua(t_catalogo V, int N,long menor){
	
	if(N==0) return menor;
	else{
		if(RetornarfechaPubliccaion(V[N])<menor)
			menor=RetornarfechaPubliccaion(V[N]);
		return fechaAntigua(V,N-1,menor);
	}
}
	
void Eliminar_uno_rec(t_catalogo vec,int tam, int pos){ //operacion privada
	if (pos!=tam){
		vec[pos]=vec[pos+1];
		Eliminar_uno_rec(vec,tam,pos+1);
	}
}
int bus_rec(t_catalogo V,int N,long menor){//operacion privado
	if(N!=0&&RetornarfechaPubliccaion(V[N])!=menor) return bus_rec(V,N-1,menor);
	else if(N==0) return -1;
	else return N;
}
void EliminarElemento(tlista *aux){//publico
	int pos;
	long menor;
	menor=fechaAntigua(aux->lista,aux->tam,RetornarfechaPubliccaion(aux->lista[1]));
	pos=bus_rec(aux->lista,aux->tam,menor);
	Eliminar_uno_rec(aux->lista,aux->tam,pos);
	aux->tam=aux->tam-1;
}
	
/**------------*/

void modificarPelicula(tlista *pelicula){
	
	long buscado;
	int posicion;
	printf("ingrese el codigo a de la pelicula a modificar: \n");
	fflush(stdin);
	scanf("%ld",&buscado);
	fflush(stdin);
	posicion = busbin_rec(pelicula->lista,1,pelicula->tam,buscado);
	
	if(posicion != 0){
	Modificar(&pelicula->lista[posicion],buscado);
	}
	else{
		printf("\nLa pelicula no se encuentra en el catalogo :\n");
	}
}
	
/**-------------*/
	
void Ordenar_Alfabeticaente_qsort(t_catalogo a, int ini, int fin) { 
	int izq, der, med;
	t_pelicula piv;
	
	if (ini<fin)
	{
		piv = a[ini];
		izq = ini; 
		der = fin; 
		
		while(izq<der) 
		{   
		while(der>izq && (comparaTitulo(a[der],piv))>0){ 
			der--;
		}
		if(der>izq) 
		{ 
			a[izq]= a[der]; 
			izq++; 
		}	
		while(izq<der && (comparaTitulo(a[izq],piv)<0)){
			izq++;
		}
		if(izq<der)
		{ 
			a[der]= a[izq]; 
			der--; 
		} 
		}
		a[der]=piv;
		med = der;
		Ordenar_Alfabeticaente_qsort(a,ini, med-1); 
		Ordenar_Alfabeticaente_qsort(a, med+1, fin); 
	} /*fin de if (ini<fin)*/ 
} /*fin de quicksort */ 


/**-----------------------*/
	
	
void muestraPeliculaGenero(tlista V){
tlista aux;
int i;
int genero;

printf("Ingrese genero a mostrar:\n");
do{
	system("CLS");
	printf("\n[1]: Accion.\n");
	printf("[2]: Comedia.\n");
	printf("[3]: Terror.\n");
	printf("[4]: Romantica.\n");
	printf("[5]: Crimen.\n");
	printf("[6]: Documental.\n");
	printf("[7]: Drama.\n");
	printf("[8]: Musical.\n");
	printf("[9]: Aventura.\n");
	printf("[10]: Ciencia Ficcion.\n");
	fflush(stdin);
	scanf("%d",&genero);
} while(genero<0 || genero>11);
system("PAUSE");
aux.tam = 0;
/***/
	for(i=1;i <= V.tam;i++){
		if(Retornargenero(V.lista[i]) == genero){
			aux.tam = aux.tam + 1;
			fflush(stdin);
			aux.lista[aux.tam]=V.lista[i];
		}
	}
	Ordenar_Alfabeticaente_qsort(aux.lista, 1, aux.tam);
	printf("\n/-----------------/");
	muestra_lista(aux);
	
}

void MostrarRecursivo(t_catalogo aux, int TP){ 
	
	if (TP > 0)
	{ 
		MostrarRecursivo(aux, (TP-1));
		MostrarReg(aux[TP]);
	}
}
	
void muestra_lista(tlista lis){//publico
	MostrarRecursivo(lis.lista,lis.tam);
}
	
void muestraPeliculaActor(tlista V){
	tlista aux;
	int i;
	t_cad actor;
	
	aux.tam = 0;
	
	printf("Ingrese el nombre del Actor: \n");
	fflush(stdin);
	leeCad(actor,TAM);
	fflush(stdin);
	
	for(i = 1; i<=V.tam;i++){
		if(compara_Actor_ingresado(actor, V.lista[i])==0){
			aux.tam = aux.tam + 1;
			aux.lista[aux.tam]=V.lista[i];
		}
	}
	Ordenar_Alfabeticaente_qsort(aux.lista, 1, aux.tam);
	muestra_lista(aux);
}
	
/**-------------------------------------*/
	
void mostrar_grup_genero(tlista V){
	int i,genero;
	genero=1;
	while(genero<=10){
		for(i=1;i <= V.tam;i++){
			if(Retornargenero(V.lista[i])==genero)
				MostrarReg(V.lista[i]);
		}
		genero++;
	}
}

