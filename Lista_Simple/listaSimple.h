#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct ElementoLista {
  int dato;
  struct ElementoLista *siguiente;
};

struct Lista {
  int dato;
  struct Lista *siguiente;
  struct Lista *actual;
  int tamano
};

void inicializacion(struct Lista *lista);
int ins_lista_vacia(struct Lista *lista, int dato);
int ins_lista(struct Lista *lista, int dato);
void visualizar(struct Lista *lista);
int eliminar(struct Lista *lista, int pos);

#endif
