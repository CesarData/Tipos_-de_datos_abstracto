/******************************************************************************

Pilas

Universidad Tecnológica de México

Ingeniería en Ciencia de Datos

Estructura de datos.
Prof. Gerardo Estrada Gutiérrez

César Agustín González Ortiz
Matrícula 340029038

16 de febrero de 2024

*******************************************************************************/

#include <iostream>
#include <conio.h>
#include "pila.h"

using namespace std;

void apilar(pila *p);
void desapilar(pila *p);
void mostrarTope(pila *p);
void mostrarPila(pila *p);
void mostrarTamano(pila *p);
void limpiarPila(pila *p);
void eliminarPila(pila *p);

int main()
{
    pila *pilaReales = crearPila();
    int opcion = 0;

    do{
        system("cls");
        cout << "************************************************************" << endl;
        cout << "                          Pila                              " << endl;
        cout << "************************************************************" << endl << endl;
        cout << "Elige una opcion" << endl << endl;
        cout << "1. Apilar" << endl;
        cout << "2. Desapilar" << endl;
        cout << "3. Mostrar Tope" << endl;
        cout << "4. Mostrar Pila" << endl;
        cout << "5. Mostrar tamano" << endl;
        cout << "6. Limpiar Pila" << endl;
        cout << "7. Eliminar Pila" << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Opcion... ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            apilar(pilaReales);
            break;
        case 2:
            desapilar(pilaReales);
            break;
        case 3:
            mostrarTope(pilaReales);
            break;
        case 4:
            mostrarPila(pilaReales);
            break;
        case 5:
            mostrarTamano(pilaReales);
            break;
        case 6:
            limpiarPila(pilaReales);
            break;
        case 7:
            eliminarPila(pilaReales);
            break;
        case 0:
            pilaLimpiar(pilaReales);
            pilaEliminar(pilaReales);
            cout << "Cerrando..." << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }

    }while(opcion != 7 && opcion != 0);

    free(pilaReales);
    getch();
    return 0;
}

void apilar(pila *p)
{

    system("cls");
    float real = 0;

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa un numero real:    ";
    cin >> real;
    pilaInsertar(p, real);
}

void desapilar(pila *p)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    pilaQuitar(p);
    cout << "El Tope ha sido borrado...";
    getch();


}

void mostrarTope(pila *p)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    if(!pilaVacia(p))
    {
        cout << "El Tope de la Pila es: " << pilaTope(p);
    }
    else
    {
        cout << "La Pila esta vacia ";
    }
    getch();
}


void mostrarPila(pila *p)
{
    system("cls");
    nodo* aux = p->cabeza;

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    if(!pilaVacia(p))
    {
        cout << "Elementos de Pila:       " << endl << endl;
        cout << "Posicion       Elemento" << endl;
        for(int i = 1; i <= p->cantidad; i++)
        {
            cout << "   " << i << "             " << nodoMostrar(aux) << "      " << endl;
            aux = aux->sig;
        }
    }
    else
    {
        cout << "La Pila esta vacia " << endl;
    }    
    free(aux);
    cout << endl << "Presiona cualquier tecla para regresar al menu...";
    getch();
}

void mostrarTamano(pila *p)
{
    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Numero de elementos de la Pila:       " << pilaTamano(p) << endl;
    getch();
}

void limpiarPila(pila *p)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    pilaLimpiar(p);
    cout << "Los elementos de la Pila han sido borrados...";
    getch();
} 

void eliminarPila(pila *p)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Pila                              " << endl;
    cout << "************************************************************" << endl << endl;

    pilaEliminar(p);
    cout << "La Pila ha sido eliminada...";  
    getch();
}