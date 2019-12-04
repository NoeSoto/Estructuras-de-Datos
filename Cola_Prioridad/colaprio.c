#include "colaprio.h"

/*Iniciar ColaPrioridad Valores Null*/
ColaPrioridad *
Iniciar ()
{
  ColaPrioridad *Nueva = (ColaPrioridad *) malloc (sizeof (ColaPrioridad));
  Nueva->tail = NULL;
  Nueva->top = NULL;
  return Nueva;
}

/*Iniciar verificar que parte superio nodo es igual vacio*/
int
esVacio (ColaPrioridad * c)
{
  return c->top == NULL;
}

/*Llenar cola  con numero*/
void
llenarCola (ColaPrioridad * c, int num)
{
  ColaPrioridad *nuevoNodo =
    (ColaPrioridad *) malloc (sizeof (ColaPrioridad));
  nuevoNodo->numero = num;
  nuevoNodo->siguiente = NULL;
  nuevoNodo->prioridad = PRIO_MAXIMA;

  if (!esVacio (c))
    {
      c->tail->siguiente = nuevoNodo;
      c->tail = nuevoNodo;
    }
  else
    {
      c->top = nuevoNodo;
      c->tail = nuevoNodo;
    }
}

/*Llenar cola  con numero y prioridad*/
void
llenarColaPrioridad (ColaPrioridad * c, int num, int prioridad)
{
  ColaPrioridad *nuevoNodo =
    (ColaPrioridad *) malloc (sizeof (ColaPrioridad));
  nuevoNodo->numero = num;
  nuevoNodo->siguiente = NULL;
  if (prioridad > PRIO_MAXIMA)
    {
      prioridad = PRIO_MAXIMA;
    }

  if (!esVacio (c))
    {
      if (nuevoNodo->prioridad < c->top->prioridad)
	{
	  nuevoNodo->siguiente = c->top;
	  c->top = nuevoNodo;
	}
      else
	{
	  ColaPrioridad *previoTemporal = c->top;
	  ColaPrioridad *temporal = c->top->siguiente;
	  while (temporal != NULL
		 && temporal->prioridad < nuevoNodo->prioridad)
	    {
	      previoTemporal = temporal;
	      temporal = temporal->siguiente;
	    }
	  if (temporal == NULL)
	    {
	      previoTemporal->siguiente = nuevoNodo;
	      c->tail = nuevoNodo;
	    }
	  else
	    {
	      nuevoNodo->siguiente = temporal;
	      previoTemporal->siguiente = nuevoNodo;
	    }
	}
    }
  else
    {
      c->top = nuevoNodo;
      c->tail = nuevoNodo;
    }
}

/*Imprimir Cola*/
int
obtenerValor (ColaPrioridad * c)
{
  if (esVacio (c))
    {
      printf ("La cola de prioridad esta vacia");
      return 0;
    }
  int topNum = c->top->numero;
  ColaPrioridad *temporal = c->top;
  c->top = c->top->siguiente;
  free (temporal);
  return topNum;
}
