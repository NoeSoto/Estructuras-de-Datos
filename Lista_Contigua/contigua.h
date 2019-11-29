#ifndef __CONTIGUA_H__
#define __CONTIGUA_H__

#include<stdio.h>
#include<stdlib.h>
struct Contigua
{
  int *datos;
  int actual;
  int cuantos;
};

void insertar (struct Contigua **, int);
void eliminar (struct Contigua **, int);
void mostrar (struct Contigua *);
#endif
