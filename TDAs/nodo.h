#include <stdlib.h>
#include <cstddef>

typedef struct Nodo nodo;

struct Nodo
{
    float dato;
    nodo *sig;
};

nodo *crearNodo(float dato)
{
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
        
    if(nuevoNodo != NULL)
    {
        nuevoNodo->dato = dato;
        nuevoNodo->sig = NULL;
        return nuevoNodo;
    }
    else
    {
        return NULL;
    }
}

float nodoMostrar(nodo *n)
{
    return n->dato;
}