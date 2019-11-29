#ifndef LISTADOBCIR_H_INCLUDED
#define LISTADOBCIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct ElementoCircular{
       int dato;
       struct ElementoCircular *anterior;
       struct ElementoCircular *siguiente;
};

struct CircularId{
       struct ElementoCircular *inicio;
       struct ElementoCircular *fin;
       int tamano;
};

void inicializacion(struct CircularId *lista);
int insercion_lista_vacia(struct CircularId *lista, int dato);
int insercion_inicio(struct CircularId *lista, int dato);
int insercion_fin(struct CircularId *lista, int dato);
void visualizar_adelante(struct CircularId *lista);
void visualizar_atras(struct CircularId *lista);
int eliminar(struct CircularId *lista, int pos);

#endif
