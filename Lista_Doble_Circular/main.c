#include "ListaDobcir.h"
int main(){
    int opcion, pos, i;
    char dato;
    struct CircularId *lista;
    struct ElementoCircular *prueba;
    //Inicializacion
    if((lista=(struct CircularId *)malloc(sizeof(struct CircularId)))==NULL)
        return -1;
    inicializacion(lista);

    insercion_lista_vacia(lista, 0);

    for(i=1;i<=6;i++){
    insercion_fin(lista, i);
}
visualizar_adelante(lista);
eliminar(lista, 3);
visualizar_adelante(lista);
return 0;
}
