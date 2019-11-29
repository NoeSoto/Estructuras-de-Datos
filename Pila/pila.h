#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct ElementoPila{
  int dato;
  struct ElementoPila *siguiente;
};

struct PilaId {
  struct ElementoPila *tope;
  struct ElementoPila *fondo;
  int tamano;
};

void inicializacion(struct PilaId *pila);
int push_pila_vacia(struct PilaId *pila, int dato);
int push_pila(struct PilaId *pila, int dato);
void visualizar(struct PilaId *pila);
int pop(struct PilaId *pila);

#endif
