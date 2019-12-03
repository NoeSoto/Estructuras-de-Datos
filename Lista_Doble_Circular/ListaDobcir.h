#ifndef LISTADOBCIR_H_INCLUDED
#define LISTADOBCIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Circular
{
  struct Circular *inicio;
  struct Circular *fin;
  int dato;
  struct Circular *anterior;
  struct Circular *siguiente;
  int tamano;
};

void inicializacion (struct Circular *lista);
int insercion_lista_vacia (struct Circular *lista, int dato);
int insercion_inicio (struct Circular *lista, int dato);
int insercion_fin (struct Circular *lista, int dato);
void visualizar_adelante (struct Circular *lista);
void visualizar_atras (struct Circular *lista);
int eliminar (struct Circular *lista, int pos);

#endif
