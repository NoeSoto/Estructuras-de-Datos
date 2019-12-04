#include "colaprio.h"

int
main ()
{
  printf ("Cola de prioridad\n");
  ColaPrioridad *cp1 = Iniciar ();	//Crear cola
  //llenar cola
  printf ("[Inicio] ");
  llenarCola (cp1, 1);
  llenarCola (cp1, 2);
  llenarCola (cp1, 3);
  llenarCola (cp1, 4);
  llenarCola (cp1, 5);
  llenarCola (cp1, 6);
  llenarCola (cp1, 7);
  llenarCola (cp1, 8);
  llenarCola (cp1, 9);
  llenarColaPrioridad (cp1, 1000, 100);	//10 entra al final de la cola pero con mayor prioridad asi que entra primero
  llenarColaPrioridad (cp1, 100, 10);
  llenarColaPrioridad (cp1, 10, 25);
  llenarColaPrioridad (cp1, 69, 30);

  while (!esVacio (cp1))
    {
      printf ("[%d] ", obtenerValor (cp1));
    }
  printf ("[Fin cola]");

  return 0;
}
