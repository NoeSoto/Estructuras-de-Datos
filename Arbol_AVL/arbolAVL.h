#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode
{
  int clave;
  int bal;			/* Factor de balance -1,0,1 */
  struct avlnode *left, *right;
} nodo, *pnodo;

#define max(A,B) ((A)>(B)?(A):(B))	/* Definición de macros */
#define min(A,B) ((A)>(B)?(B):(A))


int flag;			/* Marca para registrar cambios de altura. En rebalance ascendente */
//flag = 1 indica que debe seguir el ascenso rebalanceando.
int key;			/* Variable global, para disminuir argumentos */
int altur = 0;			/* Altura árbol avl. Número de nodos desde la raíz a las hojas. */

pnodo lrot (pnodo t);
pnodo rrot (pnodo t);
void Error (int tipo);
int Altura ();
pnodo CrearNodo (int key);
pnodo InsertR (pnodo t);
pnodo InsertarAVL (int clave, pnodo t);
pnodo deleteR (pnodo t);
pnodo DescartarAVL (int clave, pnodo t);
pnodo deltreeR (pnodo t);
pnodo deltree (pnodo t);
void inorder (pnodo t, int profundidad);


#endif
