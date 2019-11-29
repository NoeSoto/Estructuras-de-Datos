#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ElementoLista
{
  int dato;
  struct ElementoLista *anterior;
  struct ElementoLista *siguiente;
};

struct ListaId
{
		struct ElementoLista *inicio;
		struct ElementoLista *fin;
		int tamano;
};

void ListaDoble_inicializacion(struct ListaId *lista);
int ListaDoble_insercion_en_lista_vacia(struct ListaId *lista, int dato);
int ListaDoble_ins_inicio_lista(struct ListaId *lista, int dato);
int ListaDoble_ins_fin_lista(struct ListaId *lista, int dato);
int ListaDoble_ins_antes(struct ListaId *lista, int dato, int pos);
int ListaDoble_ins_despues(struct ListaId *lista, int dato, int pos);
void ListaDoble_visualiza_adelante(struct ListaId *lista);
void ListaDoble_visualiza_atras(struct ListaId *lista);
int ListaDoble_eliminar(struct ListaId *lista, int pos);
char ListaDoble_ver_caracter(struct ListaId *lista, int pos);
//void ListaDoble_destruir(ListaDoble *lista);// Debera implementar esta funcion
//int ListaDoble_sup_inicio(ListaDoble * lista);
//int ListaDoble_sup_en_lista(ListaDoble * lista, int pos);
//int ListaDoble_ins_lista(ListaDoble *lista, char *dato,int pos);


#endif
