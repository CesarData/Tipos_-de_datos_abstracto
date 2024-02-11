/******************************************************************************

Listas

Universidad Tecnológica de México

Ingeniería en Ciencia de Datos

Estructura de datos.
Prof. Gerardo Estrada Gutiérrez

César Agustín González Ortiz
Matrícula 340029038

11 de febrero de 2024

*******************************************************************************/

#include <iostream>
#include <conio.h>
#include "lista.h"

using namespace std;

void insertarInicio(lista *l);
void insertarFinal(lista *l);
void insertarPosicion(lista *l);
void borrarInicio(lista *l);
void borrarFinal(lista *l);
void borrarPosicion(lista *l);
void mostrarLista(lista *l);
void limpiarLista(lista *l);
void eliminarLista(lista *l);

int main()
{
    lista *listaReales = crearLista();
    int opcion = 0;

    do{
        system("cls");
        cout << "************************************************************" << endl;
        cout << "             Listas simplemente enlazadas             " << endl;
        cout << "************************************************************" << endl << endl;
        cout << "Elige una opcion" << endl << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Borrar al inicio" << endl;
        cout << "5. Borrar al final" << endl;
        cout << "6. Borrar en posicion" << endl;
        cout << "7. Mostrar lista" << endl;
        cout << "8. Limpiar lista" << endl;
        cout << "9. Eliminar lista" << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Opcion... ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarInicio(listaReales);
            break;
        case 2:
            insertarFinal(listaReales);
            break;
        case 3:
            insertarPosicion(listaReales);
            break;
        case 4:
            borrarInicio(listaReales);
            break;
        case 5:
            borrarFinal(listaReales);
            break;
        case 6:
            borrarPosicion(listaReales);
            break;
        case 7:
            mostrarLista(listaReales);
            break;
        case 8:
            limpiarLista(listaReales);
            break;
        case 9:
            if(listaReales == NULL)
                cout << "La lista ya ha sido eliminada...";  
            else
                eliminarLista(listaReales);
            break;
        case 0:
            listaLimpiar(listaReales);
            listaEliminar(listaReales);
            cout << "Cerrando..." << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }

    }while(opcion != 0);

    free(listaReales);
    getch();
    return 0;
}

void insertarInicio(lista *l){

    system("cls");
    float real = 0;

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa un numero real:    ";
    cin >> real;
    listaInsertarInicio(l, real);
}

void insertarFinal(lista *l){

    system("cls");
    float real = 0;

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa un numero real:    ";
    cin >> real;
    listaInsertarFinal(l, real);
}

void insertarPosicion(lista *l){

    system("cls");
    float real = 0;
    int pos = 0;

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa un numero real:    ";
    cin >> real;
    cout << "Ingresa la pocision:       ";
    cin >> pos;
    listaInsertarPosicion(l, pos, real);
}

void borrarInicio(lista *l){

    system("cls");

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    listaBorrarInicio(l);
    cout << "El primer elemento ha sido borrado...";
    getch();
}

void borrarFinal(lista *l){

    system("cls");

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    listaBorrarFinal(l);
    cout << "El ultimo elemento ha sido borrado...";
    getch();
}

void borrarPosicion(lista *l){

    system("cls");
    int pos = 0;

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa la pocision:       ";
    cin >> pos;
    listaBorrarPosicion(l, pos);
    cout << endl << "El elemento en la posicion " << pos << "  ha sido borrado...";
    getch();
}

void mostrarLista(lista *l)
{
    system("cls");
    nodo* aux = l->cabeza;

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Elementos de lista:       " << endl << endl;
    cout << "Posicion       Elemento" << endl;
    for(int i = 1; i <= l->cantidad; i++)
    {
        cout << "   " << i << "             " << nodoMostrar(aux) << "      " << endl;
        aux = aux->sig;
    }
    free(aux);
    cout << endl << "Presiona cualquier tecla para regresar al menu...";
    getch();
}

void limpiarLista(lista *l){

    system("cls");

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    listaLimpiar(l);
    cout << "Los elementos de la lista han sido borrados...";
    getch();
} 

void eliminarLista(lista *l){

    system("cls");

    cout << "************************************************************" << endl;
    cout << "             Listas simplemente enlazadas             " << endl;
    cout << "************************************************************" << endl << endl;

    listaEliminar(l);
    cout << "La lista ha sido eliminada...";  
    
    getch();
}