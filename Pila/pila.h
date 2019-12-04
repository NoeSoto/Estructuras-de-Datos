#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Pila
{
  int dato;
  struct Pila *tope;
  struct Pila *fondo;
  struct Pila *siguiente;
  int tamano;
};

void inicializacion (struct Pila *pila);
int push_pila_vacia (struct Pila *pila, int dato);
int push_pila (struct Pila *pila, int dato);
void visualizar (struct Pila *pila);
int pop (struct Pila *pila);

#endif
