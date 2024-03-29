#include "pila.h"

void
inicializacion (struct Pila *pila)
{
  pila->fondo = NULL;
  pila->tope = NULL;
  pila->tamano = 0;
}

int
push_pila_vacia (struct Pila *pila, int dato)
{
  if (pila->tamano == 0)
    {
      struct Pila *nuevo_elemento;
      if ((nuevo_elemento =
	   (struct Pila *) malloc (sizeof (struct Pila))) == NULL)
	return -1;
      nuevo_elemento->dato = dato;
      nuevo_elemento->siguiente = pila->tope;
      pila->fondo = nuevo_elemento;
      pila->tope = nuevo_elemento;
      pila->tamano++;
      return 0;

    }
  else
    printf ("La pila esta vacia\n");

}

int
push_pila (struct Pila *pila, int dato)
{
  struct Pila *nuevo_elemento;
  if ((nuevo_elemento =
       (struct Pila *) malloc (sizeof (struct Pila))) == NULL)
    return -1;
  nuevo_elemento->dato = dato;
  nuevo_elemento->siguiente = NULL;
  pila->tope->siguiente = nuevo_elemento;
  pila->tope = nuevo_elemento;
  pila->tamano++;
  return 0;
}

void
visualizar (struct Pila *pila)
{
  struct Pila *actual;
  actual = pila->fondo;
  while (actual != NULL)
    {
      printf ("%d ", actual->dato);
      actual = actual->siguiente;
    }
  printf ("\n");
}

int
pop (struct Pila *pila)
{
  struct Pila *sup_elemento, *actual;
  int i;
  sup_elemento = pila->tope;
  actual = pila->fondo;
  for (i = 0; i < pila->tamano - 1; ++i)
    {
      actual = actual->siguiente;
      if (i == pila->tamano - 3)
	{
	  pila->tope = actual;
	  pila->tope->siguiente = NULL;
	}
    }
  free (sup_elemento);
  pila->tamano--;
  return 0;
}
