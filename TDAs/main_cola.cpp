/******************************************************************************

Colas

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
#include "cola.h"

using namespace std;

void encolar(cola *c);
void desencolar(cola *c);
void mostrarFrente(cola *c);
void mostrarFinal(cola *C);
void mostrarCola(cola *c);
void mostrarTamano(cola *c);
void limpiarCola(cola *c);
void eliminarCola(cola *c);

int main()
{
    cola *colaReales = crearCola();
    int opcion = 0;

    do{
        system("cls");
        cout << "************************************************************" << endl;
        cout << "                          Cola                              " << endl;
        cout << "************************************************************" << endl << endl;
        cout << "Elige una opcion" << endl << endl;
        cout << "1. Encolar" << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Mostrar Frente" << endl;
        cout << "4. Mostrar Final" << endl;
        cout << "5. Mostrar Cola" << endl;
        cout << "6. Mostrar tamano" << endl;
        cout << "7. Limpiar Cola" << endl;
        cout << "8. Eliminar Cola" << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Opcion... ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            encolar(colaReales);
            break;
        case 2:
            desencolar(colaReales);
            break;
        case 3:
            mostrarFrente(colaReales);
            break;
        case 4:
            mostrarFinal(colaReales);
            break;
        case 5:
            mostrarCola(colaReales);
            break;
        case 6:
            mostrarTamano(colaReales);
            break;
        case 7:
            limpiarCola(colaReales);
            break;
        case 8:
            eliminarCola(colaReales);
            break;
        case 0:
            colaLimpiar(colaReales);
            colaEliminar(colaReales);
            cout << "Cerrando..." << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }

    }while(opcion != 8 && opcion != 0);

    free(colaReales);
    getch();
    return 0;
}

void encolar(cola *c)
{

    system("cls");
    float real = 0;

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Ingresa un numero real:    ";
    cin >> real;
    colaInsertar(c, real);
}

void desencolar(cola *c)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    colaQuitar(c);
    cout << "El primer elemento ha sido borrado...";
    getch();

}

void mostrarFrente(cola *c)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    if(!colaVacia(c))
    {
        cout << "El Frente de la Cola es: " << colaFrente(c);
    }    
    else
    {
        cout << "La Cola esta vacia ";
    }    
    getch();
}

void mostrarFinal(cola *c)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    if(!colaVacia(c))
    {
        cout << "El Final de la Cola es: " << colaFinal(c);
    }    
    else
    {
        cout << "La Cola esta vacia ";
    }  
    getch();
}

void mostrarCola(cola *c)
{
    system("cls");
    nodo* aux = c->cabeza;

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    if(!colaVacia(c))
    {
        cout << "Elementos de Cola:       " << endl << endl;
        cout << "Posicion       Elemento" << endl;
        for(int i = 1; i <= c->cantidad; i++)
        {
            cout << "   " << i << "             " << nodoMostrar(aux) << "      " << endl;
            aux = aux->sig;
        }
    }
    else
    {
        cout << "La Cola esta vacia " << endl;
    } 
    free(aux);
    cout << endl << "Presiona cualquier tecla para regresar al menu...";
    getch();
}

void mostrarTamano(cola *c)
{
    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    cout << "Numero de elementos de la Cola:       " << colaTamano(c) << endl;
    getch();
}

void limpiarCola(cola *c)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    colaLimpiar(c);
    cout << "Los elementos de la Cola han sido borrados...";
    getch();
} 

void eliminarCola(cola *c)
{

    system("cls");

    cout << "************************************************************" << endl;
    cout << "                          Cola                              " << endl;
    cout << "************************************************************" << endl << endl;

    colaEliminar(c);
    cout << "La Cola ha sido eliminada...";  
    getch();
}