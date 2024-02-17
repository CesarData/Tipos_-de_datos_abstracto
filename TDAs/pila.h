#include "nodo.h"
#include "iostream"


//Definición 

typedef struct Pila pila;

struct Pila
{
    nodo *cabeza;
    nodo *cola;
    int cantidad;
};


//Operaciones

pila *crearPila()
{
    pila *nuevaPila = (pila*)malloc(sizeof(pila));
        
    if(nuevaPila != NULL)
    {
        nuevaPila->cabeza = NULL;
        nuevaPila->cola = NULL;
        nuevaPila->cantidad = 0;
        return nuevaPila;
    }
    else
    {
        return NULL;
    }
}

bool pilaVacia(pila *l)
{
    return l->cabeza == NULL ? true : false;
}

bool pilaInsertar(pila* p, float valor)
{
    nodo* nuevoNodo = crearNodo(valor);
    if(pilaVacia(p))
    {  
        p->cabeza = nuevoNodo;
    }
    else
    {
        p->cola->sig = nuevoNodo;
    }
    p->cola = nuevoNodo;
    p->cantidad++;

    return true;
}   

nodo *pilaPenultimo(pila *p)
{
    nodo *aux = p->cabeza;
    for(int i = 1; i < p->cantidad - 1; i++)
    {
        aux = aux->sig;
    }
    return aux;
}

bool pilaQuitar(pila *p)
{
    if(!pilaVacia(p))
    {
        nodo *aux = p->cabeza;
        if(p->cantidad == 1)
        {
            p->cabeza = NULL;
            p->cola = NULL;
        }
        else
        {
            nodo *nodoAnterior = pilaPenultimo(p);
            aux = nodoAnterior->sig;
            nodoAnterior->sig = NULL;
            p->cola = nodoAnterior;
        } 
        p->cantidad--;
        free(aux);

        return true;
    }
    else
    {
        return false;
    }
}

void pilaMostrar(pila *p)
{
    nodo* aux = p->cabeza;
    for(int i = 1; i <= p->cantidad; i++)
    {
        printf("%.2f \n", nodoMostrar(aux));
        aux = aux->sig;
    }
    free(aux);
}


float pilaTope(pila *p)
{
    return p->cola->dato;
}

int pilaTamano(pila *p)
{
    return p->cantidad;
}

bool pilaLimpiar(pila *p)
{
    while(!pilaVacia(p))
    {
        pilaQuitar(p);
    }
        
    return true;
}

bool pilaEliminar(pila *p)
{
    pilaLimpiar(p);
    free(p);
   
    return true;
}