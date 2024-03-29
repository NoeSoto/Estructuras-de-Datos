#include "listaSimple.h"

void
inicializacion (struct Lista *lista)
{

  lista->inicio = NULL;
  lista->fin = NULL;
  lista->tamano = 0;

}

int
ins_lista_vacia (struct Lista *lista, int dato)
{

  if (lista->tamano == 0)
    {
      struct Lista *nuevo_elemento;
      if ((nuevo_elemento =
           (struct Lista *) malloc (sizeof (struct Lista))) == NULL)
        return -1;
      nuevo_elemento->dato = dato;
      nuevo_elemento->siguiente = lista->fin;
      lista->inicio = nuevo_elemento;
      lista->fin = nuevo_elemento;
      lista->tamano++;
      return 0;

    }
  else
    printf ("La lista esta vacia\n");

}

int
ins_lista (struct Lista *lista, int dato)
{

  struct Lista *nuevo_elemento;
  if ((nuevo_elemento =
       (struct Lista *) malloc (sizeof (struct Lista))) == NULL)
    return -1;
  nuevo_elemento->dato = dato;
  nuevo_elemento->siguiente = NULL;
  lista->fin->siguiente = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;
  return 0;
}

int
eliminar (struct Lista *lista, int pos)
{
  int i;
  struct Lista *sup_elemento, *actual, *aux;
  if (lista->tamano == 0)
    return -1;
  if (pos == 0)
    {
      sup_elemento = lista->inicio;
      lista->inicio = lista->inicio->siguiente;
      if (lista->inicio == NULL)
        lista->fin = NULL;
    }
  else if (pos == lista->tamano)
    {
      sup_elemento = lista->fin;
      actual = lista->inicio;
      for (i = 0; i < pos; ++i)
        {
          actual = actual->siguiente;
          if (i == pos - 1)
            {
              lista->fin = actual;
              lista->fin->siguiente = NULL;
            }
        }
    }
  else
    {
      actual = lista->inicio;
      for (i = 0; i < pos; ++i)
        actual = actual->siguiente;

   
      aux = actual;
      aux->siguiente = actual->siguiente;
      actual = lista->inicio;
      for (i = 1; i < pos - 1; i++)
        actual = actual->siguiente;

      sup_elemento = actual->siguiente;
      actual->siguiente = aux;
    }
  free (sup_elemento);
  lista->tamano--;
  return 0;
}

void
visualizar (struct Lista *lista)
{
  struct Lista *actual;
  actual = lista->inicio;
  while (actual != NULL)
    {
      printf ("%d ", actual->dato);
      actual = actual->siguiente;
    }
  printf ("\n");
}
