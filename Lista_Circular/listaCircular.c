#include "listaCircular.h"

void inicializacion(struct ListaId *lista){

     lista->inicio = NULL;
     lista->fin = NULL;
     lista->tamano = 0;

}

int ins_lista_vacia(struct ListaId *lista, int dato){
                   if(lista->tamano == 0){
                     struct ElementoLista *nuevo_elemento;
                     if((nuevo_elemento = (struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
                       return -1;
                     nuevo_elemento->dato = dato;
                     nuevo_elemento->siguiente = lista->fin;
                     lista->inicio = nuevo_elemento;
                     lista->fin = nuevo_elemento;
                     lista->tamano++;
                   }
                   else
                   printf("La Lista esta vacia\n");
}

int ins_lista(struct ListaId *lista, int dato){
             struct ElementoLista *nuevo_elemento;
             if((nuevo_elemento = (struct ElementoLista *)malloc(sizeof(struct ElementoLista)))==NULL)
               return -1;
             nuevo_elemento->dato = dato;
             nuevo_elemento->siguiente = lista->inicio;
             lista->fin->siguiente = nuevo_elemento;
             lista->fin = nuevo_elemento;
             lista->tamano++;
             return 0;
}

int eliminar(struct ListaId *lista, int pos){
            int i;
            struct ElementoLista *sup_elemento, *actual, *aux;
            if(lista->tamano == 0)
              return -1;
            if(pos == 0){
              sup_elemento = lista->inicio;
              lista->inicio = lista->inicio->siguiente;
              lista->fin->siguiente = lista->inicio;
              }
            else if(pos == lista->tamano){
                   sup_elemento = lista->fin;
                   actual = lista->inicio;
                   for(i = 0; i<pos;++i){
                      actual = actual->siguiente;
                      if(i == pos-1){
                      lista->fin = actual;
                      lista->fin->siguiente = lista->inicio;
                      }
                   }
            }
            else {
                 actual = lista->inicio;
                 for(i = 0; i<pos; ++i)
                    actual = actual->siguiente;
                 aux = actual;
                 aux->siguiente = actual->siguiente;
                 actual = lista->inicio;
                 for(i = 1; i<pos-1; i++)
                    actual = actual->siguiente;
                 sup_elemento = actual->siguiente;
                 actual->siguiente = aux;
            }
            free(sup_elemento);
            lista->tamano--;
            return 0;
}

void visualizar(struct ListaId * lista){
               int b = 0;
               struct ElementoLista *actual;
               actual = lista->inicio;
               while(b != 1){
                    if(actual->siguiente == lista->inicio)
                    b++;
                    printf("%d ", actual->dato);
                    actual = actual->siguiente;
               }
               printf("\n");
}
