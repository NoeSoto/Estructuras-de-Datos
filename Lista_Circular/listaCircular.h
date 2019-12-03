#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Listacir{
       int dato;
       struct Listacir *inicio;
       struct Listacir *fin;
       struct Listacir *siguiente;
       int tamano;
};

void inicializacion(struct Listacir *lista);
int ins_lista_vacia(struct Listacir *lista, int dato);
int ins_lista(struct Listacir *lista, int dato);
void visualizar(struct Listacir *lista);
int eliminar(struct Listacir *lista, int pos);

#endif
