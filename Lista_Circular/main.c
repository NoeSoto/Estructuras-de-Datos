#include "listaCircular.h"

int
main ()
{
  int opcion, pos, i;
  int dato;
  struct Listacir *lista;
  struct Listacir *prueba;
  if ((lista = (struct Listacir *) malloc (sizeof (struct Listacir))) == NULL)
    return -1;
  inicializacion (lista);
  ins_lista_vacia (lista, 0);
  // visualizar(lista);
  for (i = 1; i <= 7; i++)
    ins_lista (lista, i);

  visualizar (lista);
  eliminar (lista, 3);
  visualizar (lista);
  return 0;
}
