#include <stdio.h>
#include <stdlib.h>
//Codigo por Gonzalo Rojas Terrisse
const int PRIORIDAD_MAXIMA = 999;

/*Creacion Estructuras*/
typedef struct nodo{
	int numero;
	int prioridad;
	struct nodo *siguiente;
}Nodo;


typedef struct colaprioridad{
	Nodo *top;
	Nodo *tail;
}ColaPrioridad;

/*Iniciar ColaPrioridad Valores Null*/
ColaPrioridad *Iniciar(){
	ColaPrioridad *NuevaCola = (ColaPrioridad *)malloc(sizeof(ColaPrioridad));
	NuevaCola->tail = NULL;
	NuevaCola->top = NULL;
	return NuevaCola;
}

/*Iniciar verificar que parte superio nodo es igual vacio*/
int esVacio(ColaPrioridad *c){
	return c->top == NULL;
}
/*Llenar cola  con numero*/
void llenarCola(ColaPrioridad *c, int num){
	Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
	nuevoNodo->numero = num;
	nuevoNodo->siguiente =NULL;
	nuevoNodo->prioridad = PRIORIDAD_MAXIMA;

	if(!esVacio(c))
	{
		c->tail->siguiente = nuevoNodo;
		c->tail = nuevoNodo;
	}
	else
	{
		c->top = nuevoNodo;
		c->tail = nuevoNodo;
	}
}
/*Llenar cola  con numero y prioridad*/
void llenarColaPrioridad(ColaPrioridad *c, int num, int prioridad){
	Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
	nuevoNodo->numero = num;
	nuevoNodo->siguiente = NULL;
	if(prioridad > PRIORIDAD_MAXIMA){
		prioridad = PRIORIDAD_MAXIMA;
	}

	if(!esVacio(c)){
		if(nuevoNodo->prioridad < c->top->prioridad){
			nuevoNodo->siguiente = c->top;
			c->top =nuevoNodo;
		}
		else{
			Nodo *previoTemporal = c->top;
			Nodo *temporal =c->top->siguiente;
			while(temporal != NULL && temporal->prioridad < nuevoNodo->prioridad){
				previoTemporal = temporal;
				temporal = temporal->siguiente;
			}
			if(temporal == NULL){
				previoTemporal->siguiente = nuevoNodo;
				c->tail = nuevoNodo;
			}else{
				nuevoNodo->siguiente = temporal;
				previoTemporal->siguiente = nuevoNodo;
			}
		}
	}else{
		c->top = nuevoNodo;
		c->tail = nuevoNodo;
	}
}
/*Imprimir Cola*/
int obtenerValor(ColaPrioridad *c){
	if(esVacio(c)){
		printf("La cola de prioridad esta vacia");
		return 0;
	}
	int topNum = c->top->numero;
	Nodo *temporal = c->top;
	c->top = c->top->siguiente;
	free(temporal);
	return topNum;
}

int main(){
	printf("Cola de prioridad\n");
	ColaPrioridad *cp1 = Iniciar();//Crear cola
	//llenar cola
	printf("[Inicio] ");
	llenarCola(cp1,1);
	llenarCola(cp1,2);
	llenarCola(cp1,3);
	llenarCola(cp1,4);
	llenarCola(cp1,5);
	llenarCola(cp1,6);
	llenarCola(cp1,7);
	llenarCola(cp1,8);
	llenarCola(cp1,9);
	llenarColaPrioridad(cp1,1000,100);//10 entra al final de la cola pero con mayor prioridad asi que entra primero
	llenarColaPrioridad(cp1,100,10);
	llenarColaPrioridad(cp1,10,25);
	llenarColaPrioridad(cp1,69,30);

	while(!esVacio(cp1)){
		printf("[%d] ", obtenerValor(cp1));
	}
	printf("[Fin cola]");

	return 0;
}


