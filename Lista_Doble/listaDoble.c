#include "listaDoble.h"

void ListaDoble_inicializacion(struct ListaId *lista)
{
    lista->inicio=NULL;
    lista->fin=NULL;
    lista->tamano=0;
}

/* inserción en una lista vacía */
int ListaDoble_insercion_en_lista_vacia(struct ListaId *lista, int dato)
{
    if(lista->tamano == 0){
        struct ElementoLista *nuevo_elemento;
        if((nuevo_elemento=(struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
            return -1;
        nuevo_elemento->dato = dato;
        nuevo_elemento->anterior=lista->inicio;
        nuevo_elemento->siguiente=lista->fin;
        lista->inicio=nuevo_elemento;
        lista->fin=nuevo_elemento;
        lista->tamano++;
    }
    else{
        printf("La lista no esta vacia \n");
        printf("Utilice alguna de las siguientes funciones: 1) inserci—n al inicio, 2) al final de la lista, 3) antes o 4)despuŽs de una posici—n");
    }
   return 0;
}

/* inserción al inicio de la lista */
int ListaDoble_ins_inicio_lista(struct ListaId *lista, int dato)
{
   struct ElementoLista *nuevo_elemento;
   if((nuevo_elemento=(struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
      return -1;
   nuevo_elemento->dato = dato;
   nuevo_elemento->anterior=NULL;
   nuevo_elemento->siguiente=lista->inicio;
   lista->inicio->anterior=nuevo_elemento;
   lista->inicio=nuevo_elemento;
   lista->tamano++;
   return 0;
}
/*inserción al final de la lista */
int ListaDoble_ins_fin_lista(struct ListaId *lista, int dato)
{
   struct ElementoLista *nuevo_elemento;
   if((nuevo_elemento=(struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
      return -1;
   nuevo_elemento->dato = dato;
   nuevo_elemento->siguiente = NULL;
   nuevo_elemento->anterior = lista->fin;
   lista->fin->siguiente = nuevo_elemento;
   lista->fin = nuevo_elemento;
   lista->tamano++;
   return 0;
}

/*inserción antes de un elemento */
int ListaDoble_ins_antes(struct ListaId *lista, int dato, int pos)
{
   int i;
   struct ElementoLista *nuevo_elemento, *actual;
   if((nuevo_elemento=(struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
      return -1;
   nuevo_elemento->dato = dato;
   actual=lista->inicio;
   for(i=1;i<pos;++i)
      actual=actual->siguiente;
   nuevo_elemento->siguiente=actual;
   nuevo_elemento->anterior=actual->anterior;
   if(actual->anterior==NULL)
      lista->inicio=nuevo_elemento;
   else
      actual->anterior->siguiente=nuevo_elemento;
   actual->anterior=nuevo_elemento;
   lista->tamano++;
   return 0;
}

/*inserción despues de un elemento */
int ListaDoble_ins_despues(struct ListaId *lista, int dato, int pos)
{
   int i;
   struct ElementoLista *nuevo_elemento, *actual;
   if((nuevo_elemento=(struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
      return -1;
   nuevo_elemento->dato =  dato;
   actual=lista->inicio;
   for(i=1;i<pos;++i)
      actual=actual->siguiente;
   nuevo_elemento->siguiente=actual->siguiente;
   nuevo_elemento->anterior=actual;
   if(actual->siguiente==NULL)
      lista->fin=nuevo_elemento;
   else
      actual->siguiente->anterior=nuevo_elemento;
   actual->siguiente=nuevo_elemento;
   lista->tamano++;
   return 0;
}

/* visualización de la lista */
/* visualización hacia adelante */
void ListaDoble_visualiza_adelante(struct ListaId *lista)
{
    struct ElementoLista *actual;
    actual=lista->inicio; //punto de inicio el 1er elemento
    printf("[ ");
    while(actual!=NULL)
    {
        printf("%d ",actual->dato);
        actual=actual->siguiente;
    }
    printf("]\n");
}
/* visualización hacia atrás */
void ListaDoble_visualiza_atras(struct ListaId *lista)
{
    struct ElementoLista *actual;
    actual=lista->fin; /* punto de inicio el ultimo elemento */
    printf("[ ");
    while(actual!=NULL)
    {
        printf("%d ",actual->dato);
        actual=actual->anterior;
    }
    printf("]\n");
}



int ListaDoble_eliminar(struct ListaId *lista, int pos)
{
   int i;
   struct ElementoLista *sup_elemento,*actual;
   if(lista->tamano==0)
      return -1;
   /* eliminación del 1er elemento */
   if(pos==0)
   {
      sup_elemento=lista->inicio;
      lista->inicio=lista->inicio->siguiente;
      if(lista->inicio==NULL)
         lista->fin=NULL;
      else
         lista->inicio->anterior==NULL;
   /* eliminación del último elemento */
   }
   else if(pos==lista->tamano)
   {
      sup_elemento=lista->fin;
      lista->fin->anterior->siguiente=NULL;
      lista->fin=lista->fin->anterior;
   /* eliminación en otra parte */
   }
   else
   {
      actual = lista->inicio;
      for(i=0;i<pos-1;++i)
         actual=actual->siguiente;
      sup_elemento=actual;
      actual->anterior->siguiente=actual->siguiente;
      actual->siguiente->anterior=actual->anterior;
   }
   free(sup_elemento);
   lista->tamano--;
   return 0;
}

char ListaDoble_ver_caracter(struct ListaId *lista, int pos){
    struct ElementoLista *actual;
    actual=lista->inicio; //punto de inicio el 1er elemento
    int contador = 0;
    while(contador != pos)
    {
        actual = actual->siguiente;
        contador++;
    }
    return actual->dato;

}



