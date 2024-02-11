/******************************************************************************

Listas

Universidad Tecnológica de México

Ingeniería en Ciencia de Datos

Estructura de datos.
Prof. Gerardo Estrada Gutiérrez

César Agustín González Ortiz
Matrícula 340029038

10 de febrero de 2024

*******************************************************************************/

#include <iostream>
#include <conio.h>
#include "lista.h"

using namespace std;

int main()
{
    lista *listaReales = crearLista();
    listaInsertarFinal(listaReales, 3);
    listaInsertarFinal(listaReales, 7);
    listaInsertarFinal(listaReales, 9);
    cout << "Lista: " << listaReales << " Vacia: " <<listaVacia(listaReales) << " Cantidad: " <<listaReales->cantidad <<endl;
    cout << endl << endl;
    cout <<"Cantidad 1:" << listaReales->cantidad <<endl;
    listaMostrar(listaReales);
    listaInsertarPosicion(listaReales, 4, 17.56);
    cout << endl << endl;
    cout <<"Cantidad 2:" << listaReales->cantidad <<endl;
    listaMostrar(listaReales);
    listaBorrarPosicion(listaReales, 4);
    //listaBorrarInicio(listaReales);
    cout << endl << endl;
    cout <<"Cantidad 3:" << listaReales->cantidad <<endl;
    listaMostrar(listaReales);
    
    listaBorrarInicio(listaReales);
    //listaBorrarInicio(listaReales);
    cout << endl << endl;
    cout <<"Cantidad 4:" << listaReales->cantidad <<endl;
    listaMostrar(listaReales);

    listaLimpiar(listaReales);
    listaEliminar(listaReales);
    free(listaReales);
    getch();
    return 0;
}