#include "arbolBin.h"

ArbolBinario
CrearNodo (TipoElemento x)
{

  ArbolBinario a;

  a = (ArbolBinario) malloc (sizeof (ElementoDeArbolBin));

  a->Info = x;

  a->hijo_der = a->hijo_izq = NULL;

  return a;

}



int
gotoxy (int w, int s)
{

  printf ("%c[%d;%df", 0x1B, s, w);

  fflush (stdout);

}

//void gotoxy(int ex, int ey)
//{
//printf("33[%d;%df", ey, ex);
//fflush(stdout);
//}

void
preorden (ElementoDeArbolBin * p)
{

  if (p)

    {

      printf ("%d", p->Info);

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


ArbolBinario
insertar (ElementoDeArbolBin * p, TipoElemento x)
{

  if (!p)			//árbol vacío, se inserta raiz
    {

      // printf("Arbol vacio\n");
      p = CrearNodo (x);

      // X = 30;
      // Y = 20;
      // gotoxy(X,Y); printf("|");
    }

  else

    {

      if (x == (p->Info))

	printf ("Elemento repetido");

      else

	{

	  if (x < (p->Info))	//inserción lado izq
	    {

	      if ((p->hijo_izq) == NULL)

		p->hijo_izq = CrearNodo (x);

	      else

		{

		  p = p->hijo_izq;

		  p = insertar (p, x);

		  // if(X-10==21 && Y==19)X--;
		  // X--;
		  // gotoxy(X,Y); printf("%c",92);
		  // Y--;
		}

	    }

	  else			//inserción lado der
	    {

	      if ((p->hijo_der) == NULL)

		p->hijo_der = CrearNodo (x);

	      else

		{

		  p = p->hijo_der;

		  p = insertar (p, x);

		}

	      // X++;
	      // Y--;
	      // gotoxy(X,Y); printf("/");
	    }

	}

    }

  p->num_elementos++;

  return p;

}



void
fractal (ElementoDeArbolBin * p)
{

  int pot, i, j;

  X = 30;
  Y = 21;

  int n = 2;

  pot = profundidad (p);

  gotoxy (X, Y);
  printf ("|");
  Y--;

  for (i = 1; i <= pot; i++)
    {

      for (j = 1; j <= n; j++)
	{

	  if (0 != j % 2)
	    {

	      gotoxy (X, Y);
	      printf ("%c", 92);

	      X++;

	    }

	  else
	    {

	      gotoxy (X, Y);
	      printf ("/");

	      X++;

	    }

	}

      Y--;

      X = X - (n + 1);

      n = n + 2;

    }

}
