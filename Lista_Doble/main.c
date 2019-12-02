#include "listaDoble.h"

int
main ()
{
  int opcion, pos, i;
  char dato;
  struct ListaDob *lista;
  struct ListaDob *prueba;
  //Inicializacion
  if ((lista = (struct ListaDob *) malloc (sizeof (struct ListaDob))) == NULL)
    return -1;
  ListaDoble_inicializacion (lista);

  ListaDoble_insercion_en_lista_vacia (lista, 0);

  for (i = 1; i <= 6; i++)
    {
      ListaDoble_ins_fin_lista (lista, i);
    }
  ListaDoble_eliminar (lista, 3);
  ListaDoble_visualiza_adelante (lista);
  return 0;
}
