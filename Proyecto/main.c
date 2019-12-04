#include "arbolBin.h"

int
main (void)
{
  printf ("Arbol binario\n");
  ArbolBinario raiz = NULL, aux;
  raiz = insertar (raiz, 14);
  aux = raiz;
  aux = insertar (aux, 16);
  aux = insertar (aux, 9);
  aux = insertar (aux, 8);
  aux = insertar (aux, 5);
  aux = insertar (aux, 20);
  aux = insertar (aux, 23);
  aux = insertar (aux, 25);
  fractal (raiz);
  //enorden(raiz);

  return 0;
}
