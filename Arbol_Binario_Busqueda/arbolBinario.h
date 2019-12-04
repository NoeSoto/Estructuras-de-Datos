#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int TipoElemento;	// Puede ser cualquier tipo
struct Nodo
{
  TipoElemento Info;
  struct Nodo *hijo_izq;
  struct Nodo *hijo_der;
};
typedef struct Nodo ElementoDeArbolBin;
typedef ElementoDeArbolBin *ArbolBinario;
//prototipos
ArbolBinario CrearNodo (TipoElemento x);
void preorden (ElementoDeArbolBin * p);
void enorden (ElementoDeArbolBin * p);
int profundidad (ElementoDeArbolBin * p);
ArbolBinario insertar (ElementoDeArbolBin * p, TipoElemento x);

#endif
