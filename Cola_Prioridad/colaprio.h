#ifndef COLAPRIO_H_INCLUDED
#define COLAPRIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

const int PRIO_MAXIMA = 999;

/*Creacion Estructuras*/

typedef struct colaprio
{
  int numero;
  struct colaprio *top;
  struct colaprio *tail;
  struct colaprio *siguiente;
  int prioridad;
} ColaPrioridad;

ColaPrioridad *Iniciar ();
int esVacio (ColaPrioridad * c);
void llenarCola (ColaPrioridad * c, int num);
void llenarColaPrioridad (ColaPrioridad * c, int num, int prioridad);
int obtenerValor (ColaPrioridad * c);

#endif
