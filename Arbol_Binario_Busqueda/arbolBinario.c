#include "arbolBinario.h"

 ArbolBinario CrearNodo (TipoElemento x)
{

ArbolBinario a;

a = (ArbolBinario) malloc (sizeof (ElementoDeArbolBin));

a->Info = x;

a->hijo_der = a->hijo_izq = NULL;

return a;

}


void
preorden (ElementoDeArbolBin * p)
{

if (p)

    {

printf ("%d\n", p->Info);

preorden (p->hijo_izq);

preorden (p->hijo_der);

}

}


void
enorden (ElementoDeArbolBin * p)
{

if (p)

    {

enorden (p->hijo_izq);

printf ("%d\n", p->Info);

enorden (p->hijo_der);

}

}



int
profundidad (ElementoDeArbolBin * p)
{

if (!p)

return 0;

  else

    {

int profund_I = profundidad (p->hijo_izq);

int profund_D = profundidad (p->hijo_der);

if (profund_I > profund_D)

return profund_I + 1;

      else

return profund_D + 1;

}

}


ArbolBinario insertar (ElementoDeArbolBin * p, TipoElemento x)
{

if (!p)			//arbol vacio, se inserta raiz
    {

	//printf("Arbol vacio");
	p = CrearNodo (x);

}

  else

    {

if (x == (p->Info))

printf ("Elemento repetido");

      else

	{

if (x < (p->Info))	//insercion lado izq
	    {

if ((p->hijo_izq) == NULL)

p->hijo_izq = CrearNodo (x);

	      else

		{

p = p->hijo_izq;

p = insertar (p, x);

}

}

	  else			//insercion lado der
	    {

if ((p->hijo_der) == NULL)

p->hijo_der = CrearNodo (x);

	      else

		{

p = p->hijo_der;

p = insertar (p, x);

}

}

}

}

return p;

}



