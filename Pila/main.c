#include "pila.h"

int
main ()
{

  int opcion, i;
  int dato;
  struct Pila *pila;
  struct Pila *prueba;
  if ((pila = (struct Pila *) malloc (sizeof (struct Pila))) == NULL)
    return -1;
  inicializacion (pila);
  push_pila_vacia (pila, 0);

  for (i = 1; i <= 7; i++)
    {
      push_pila (pila, i);
    }
  visualizar (pila);
  pop (pila);
  visualizar (pila);

  return 0;
}
