//Parte privada del Tad.
#include <stdio.h>
#include <string.h>
#include "cadena.h"
void leeCad(t_cad c, int tam ){
	int j=0,m;
	
	while (j<tam-1&&(m=getchar())!=EOF && m!='\n'){
		c[j]=m;
		j++;
	}
	c[j]='\0';
	while (m!=EOF && m!='\n')
		m=getchar();
}
	
short comparacadenas(t_cad cad1, t_cad cad2){
	return strcmp(cad1,cad2);// si la 1ra es mas grande retorna 1, iguales 0, la 2da mas grande rotrna -1
}
