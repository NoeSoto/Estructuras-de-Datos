#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListaDob
{
  int dato;
  struct ListaDob *inicio;
  struct ListaDob *fin;
  struct ListaDob *siguiente;
  struct ListaDob *anterior;
  int tamano;
};

void ListaDoble_inicializacion (struct ListaDob *lista);
int ListaDoble_insercion_en_lista_vacia (struct ListaDob *lista, int dato);
int ListaDoble_ins_inicio_lista (struct ListaDob *lista, int dato);
int ListaDoble_ins_fin_lista (struct ListaDob *lista, int dato);
int ListaDoble_ins_antes (struct ListaDob *lista, int dato, int pos);
int ListaDoble_ins_despues (struct ListaDob *lista, int dato, int pos);
void ListaDoble_visualiza_adelante (struct ListaDob *lista);
void ListaDoble_visualiza_atras (struct ListaDob *lista);
int ListaDoble_eliminar (struct ListaDob *lista, int pos);
char ListaDoble_ver_caracter (struct ListaDob *lista, int pos);


#endif
