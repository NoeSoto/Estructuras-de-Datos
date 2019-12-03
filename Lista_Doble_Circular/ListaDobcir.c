#include "ListaDobcir.h"

void
inicializacion (struct Circular *lista)
{
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->tamano = 0;
}

int
insercion_lista_vacia (struct Circular *lista, int dato)
{
  if (lista->tamano == 0)
    {
      struct Circular *nuevo_elemento;
      if ((nuevo_elemento =
	   (struct Circular *) malloc (sizeof (struct Circular))) == NULL)
	return -1;
      nuevo_elemento->dato = dato;
      nuevo_elemento->anterior = lista->inicio;
      nuevo_elemento->siguiente = lista->fin;
      lista->inicio = nuevo_elemento;
      lista->fin = nuevo_elemento;
      lista->tamano++;
      return 0;
    }
  else
    {
      printf ("La lista no esta vacia\n");
      return 0;
    }
}

int
insercion_inicio (struct Circular *lista, int dato)
{
  struct Circular *nuevo_elemento;
  if ((nuevo_elemento =
       (struct Circular *) malloc (sizeof (struct Circular))) == NULL)
    return -1;
  nuevo_elemento->dato = dato;
  nuevo_elemento->anterior = lista->fin;
  nuevo_elemento->siguiente = lista->inicio;
  lista->inicio->anterior = nuevo_elemento;
  lista->inicio = nuevo_elemento;
  lista->tamano++;
  return 0;
}

int
insercion_fin (struct Circular *lista, int dato)
{
  struct Circular *nuevo_elemento;
  if ((nuevo_elemento =
       (struct Circular *) malloc (sizeof (struct Circular))) == NULL)
    return -1;
  nuevo_elemento->dato = dato;
  nuevo_elemento->siguiente = lista->inicio;
  nuevo_elemento->anterior = lista->fin;
  lista->fin->siguiente = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;
  return 0;
}

void
visualizar_adelante (struct Circular *lista)
{
  struct Circular *actual;
  int i;
  actual = lista->inicio;
  for (i = 1; i <= lista->tamano; i++)
    {
      printf ("%d ", actual->dato);
      actual = actual->siguiente;
    }
  printf ("\n");
}

void
visualizar_atras (struct Circular *lista)
{
  struct Circular *actual;
  int i;
  actual = lista->fin;
  for (i = 1; i <= lista->tamano; i++)
    {
      printf ("%d ", actual->dato);
      actual = actual->anterior;
    }
  printf ("\n");
}

int
eliminar (struct Circular *lista, int pos)
{
  int i;
  struct Circular *sup_elemento, *actual;
  if (lista->tamano == 0)
    return -1;
  if (pos == 0)
    {
      sup_elemento = lista->inicio;
      lista->inicio = lista->inicio->siguiente;
      if (lista->inicio == NULL)
	lista->fin == NULL;
      else
	lista->inicio->anterior == lista->fin;
    }
  else if (pos == lista->tamano)
    {
      sup_elemento = lista->fin;
      lista->fin = lista->fin->anterior;
    }
  else
    {
      actual = lista->inicio;
      for (i = 0; i < pos - 1; ++i)
	actual = actual->siguiente;
      sup_elemento = actual;
      actual->anterior->siguiente = actual->siguiente;
      actual->siguiente->anterior = actual->anterior;
    }
  free (sup_elemento);
  lista->tamano--;
  return 0;
}
