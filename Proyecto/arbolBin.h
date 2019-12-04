#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int TipoElemento;
struct Nodo
{
  TipoElemento Info;
  struct Nodo *hijo_izq;
  struct Nodo *hijo_der;
  int num_elementos;
  //int Y;
};
typedef struct Nodo ElementoDeArbolBin;
typedef ElementoDeArbolBin *ArbolBinario;
//prototipos
ArbolBinario CrearNodo (TipoElemento x);
void preorden (ElementoDeArbolBin * p);
void enorden (ElementoDeArbolBin * p);
int profundidad (ElementoDeArbolBin * p);
ArbolBinario insertar (ElementoDeArbolBin * p, TipoElemento x);
void fractal (ElementoDeArbolBin * p);
int X;
int Y;

#endif
