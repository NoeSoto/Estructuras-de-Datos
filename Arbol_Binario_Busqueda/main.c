#include "arbolBinario.c"

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
  enorden (raiz);

  return 0;
}
