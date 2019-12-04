#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Cola
{
  int dato;
  struct Cola *inicio;
  struct Cola *fin;
  struct Cola *siguiente;
  int tamano;
};

void inicializacion (struct Cola *cola);
int ins_cola_vacia (struct Cola *cola, int dato);
int ins_cola (struct Cola *cola, int dato);
void visualizar (struct Cola *cola);
int eliminar (struct Cola *cola);

#endif
