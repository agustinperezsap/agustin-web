//Modelo Matemático = Estructura de datos a manejar
#ifndef CADENA_H
#define CADENA_H

#define TAM 150
typedef char t_cad[TAM];

//Operaciones públicas que manejan el modelo = Prototipos de Funciones y Procedimientos 
//que manejan una cadena.

void leeCad(t_cad , int );
short comparacadenas(t_cad , t_cad);

#endif
