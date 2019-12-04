#include "cola.h"

int
main ()
{

  int opcion, pos, i;
  int dato;
  struct Cola *cola;
  struct Cola *prueba;
  if ((cola = (struct Cola *) malloc (sizeof (struct Cola))) == NULL)
    return -1;
  inicializacion (cola);
  ins_cola_vacia (cola, 0);

  for (i = 1; i <= 7; i++)
    {
      ins_cola (cola, i);
    }
  visualizar (cola);
  eliminar (cola);
  visualizar (cola);

  return 0;
}
