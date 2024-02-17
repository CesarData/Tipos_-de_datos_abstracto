#include "nodo.h"
#include "iostream"


//Definición 

typedef struct Cola cola;

struct Cola
{
    nodo *cabeza;
    nodo *cola;
    int cantidad;
};


//Operaciones

cola *crearCola()
{
    cola *nuevaCola = (cola*)malloc(sizeof(cola));
        
    if(nuevaCola != NULL)
    {
        nuevaCola->cabeza = NULL;
        nuevaCola->cola = NULL;
        nuevaCola->cantidad = 0;
        return nuevaCola;
    }
    else
    {
        return NULL;
    }
}

bool colaVacia(cola *c)
{
    return c->cabeza == NULL ? true : false;
}

bool colaInsertar(cola* c, float valor)
{
    nodo* nuevoNodo = crearNodo(valor);
    if(colaVacia(c))
    {  
        c->cabeza = nuevoNodo;
    }
    else
    {
        c->cola->sig = nuevoNodo;
    }
    c->cola = nuevoNodo;
    c->cantidad++;

    return true;
}  

bool colaQuitar(cola *c)
{
    if(!colaVacia(c))
    {
        nodo *aux = c->cabeza;
        if(c->cantidad == 1)
        {
            c->cabeza = NULL;
            c->cola = NULL;
        }
        else
        {
            c->cabeza = c->cabeza->sig;
        } 
        c->cantidad--;
        free(aux);

        return true;
    }
    else
    {
        return false;
    }
}

void colaMostrar(cola *c)
{
    nodo* aux = c->cabeza;
    for(int i = 1; i <= c->cantidad; i++)
    {
        printf("%.2f \n", nodoMostrar(aux));
        aux = aux->sig;
    }
    free(aux);
}


float colaFrente(cola *c)
{
    return c->cabeza->dato;
}

float colaFinal(cola *c)
{
    return c->cola->dato;
}

int colaTamano(cola *c)
{
    return c->cantidad;
}

bool colaLimpiar(cola *c)
{
    while(!colaVacia(c))
    {
        colaQuitar(c);
    }
        
    return true;
}

bool colaEliminar(cola *c)
{
    colaLimpiar(c);
    free(c);
   
    return true;
}
