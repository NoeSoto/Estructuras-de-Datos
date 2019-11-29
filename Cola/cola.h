#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct ElementoCola {
  int dato;
  struct ElementoCola *siguiente;
};

struct ColaId {
  struct ElementoCola *inicio;
  struct ElementoCola *fin;
  int tamano;
};

void inicializacion(struct ColaId *cola);
int ins_cola_vacia(struct ColaId *cola, int dato);
int ins_cola(struct ColaId *cola, int dato);
void visualizar(struct ColaId *cola);
int eliminar(struct ColaId *cola);

#endif
