#include "nodo.h"
#include "iostream"

typedef struct Lista lista;

struct Lista
{
    nodo *cabeza;
    nodo *cola;
    int cantidad;
};

lista *crearLista()
{
    lista *nuevaLista = (lista*)malloc(sizeof(lista));
        
    if(nuevaLista != NULL)
    {
        nuevaLista->cabeza = NULL;
        nuevaLista->cola = NULL;
        nuevaLista->cantidad = 0;
        return nuevaLista;
    }
    else
    {
        return NULL;
    }
}

bool listaVacia(lista *l)
{
    return l->cabeza == NULL ? true : false;
}

void listaMostrar(lista *l)
{
    nodo* aux = l->cabeza;
    for(int i = 1; i <= l->cantidad; i++)
    {
        printf("%.2f \n", nodoMostrar(aux));
        aux = aux->sig;
    }
    free(aux);
}

bool listaInsertarInicio(lista* l, float valor)
{
    nodo* nuevoNodo = crearNodo(valor);
    if(listaVacia(l))
    {  
        l->cola = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = l->cabeza;
    }
    l->cabeza = nuevoNodo;
    l->cantidad++;

    return true;
}   

bool listaInsertarFinal(lista* l, float valor)
{
    nodo* nuevoNodo = crearNodo(valor);
    if(listaVacia(l))
    {  
        l->cabeza = nuevoNodo;
    }
    else
    {
        l->cola->sig = nuevoNodo;
    }
    l->cola = nuevoNodo;
    l->cantidad++;

    return true;
}   

nodo *listaPosicion(lista *l, int posicion)
{
    nodo *aux = l->cabeza;
    for(int i = 1; i < posicion; i++)
    {
        aux = aux->sig;
    }
    return aux;
}

bool listaInsertarPosicion(lista *l, int pos, float valor)
{

    if(pos > 0 && (pos <= l->cantidad + 1))
    {
        if(pos == 1)
        {
            listaInsertarInicio(l, valor);
        }
        else if(pos == (l->cantidad + 1))
        {
            listaInsertarFinal(l, valor);
        }
        else
        {
            nodo* nuevoNodo = crearNodo(valor);
            nodo *nodoAnterior = listaPosicion(l, pos-1);
            nuevoNodo->sig = nodoAnterior->sig;
            nodoAnterior->sig = nuevoNodo;
            l->cantidad++;
            
            //free(nodoAnterior);
        }
            
    }

    return true;
}

bool listaBorrarInicio(lista *l)
{
    if(!listaVacia(l))
    {
        nodo *aux = l->cabeza;
        if(l->cantidad == 1)
        {
            l->cabeza = NULL;
            l->cola = NULL;
        }
        else
        {
            l->cabeza = l->cabeza->sig;
        } 
        l->cantidad--;
        free(aux);

        return true;
    }
    else
    {
        return false;
    }
}

bool listaBorrarPosicion(lista *l, int pos)
{
    if(pos > 0 && (pos <= l->cantidad))
    {
        if(pos == 1)
        {
            listaBorrarInicio(l);
        }
        else
        {
            nodo *aux;
            nodo *nodoAnterior = listaPosicion(l, pos-1);
            aux = nodoAnterior->sig;
            
            if(aux->sig != NULL)
            {
                nodoAnterior->sig = aux->sig;
            }
            else
            {
                nodoAnterior->sig = NULL;
                l->cola = nodoAnterior;
            } 
            l->cantidad--;
            //free(nodoAnterior);
            free(aux);
        }        
    }
    return true;
}

bool listaBorrarFinal(lista *l)
{
    if(!listaVacia(l))
    {
        listaBorrarPosicion(l, l->cantidad);
        return true;
    }
    else
    {
        return false;
    }
}

bool listaLimpiar(lista *l)
{
    while(!listaVacia(l))
    {
        listaBorrarInicio(l);
    }
        
    return true;
}

bool listaEliminar(lista *l)
{    
    listaLimpiar(l);
    free(l);
   
    return true;
}