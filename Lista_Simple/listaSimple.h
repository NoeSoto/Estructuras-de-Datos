#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct ElementoLista {
  int dato;
  struct ElementoLista *siguiente;
};

struct ListaId {
  struct ElementoLista *inicio;
  struct ElementoLista *fin;
  int tamano;
};

void inicializacion(struct ListaId *lista);
int ins_lista_vacia(struct ListaId *lista, int dato);
int ins_lista(struct ListaId *lista, int dato);
void visualizar(struct ListaId *lista);
int eliminar(struct ListaId *lista, int pos);

#endif
