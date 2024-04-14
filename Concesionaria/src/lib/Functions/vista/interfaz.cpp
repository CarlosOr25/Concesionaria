#include "interfaz.h"
#include <iostream>

using namespace std;

Interfaz i;

void Interfaz::mostrarMenuPrincipal()
{
    cout << "\nQue necesita hacer?" << endl
         << "1. Ver cantidad de carros comprados por clientes." << endl
         << "2. Ver cantidad de carros vendidos por clientes." << endl
         << "3. Lista de carros comprados por clientes." << endl
         << "4. Lista de carros vendidos por clientes." << endl
         << "5. Ver datos del comprador de un carro." << endl
         << "6. Ver datos del vendedor de un carro." << endl
         << "7. Mostrar Balance de un carro." << endl
         << "8. Modificar datos." << endl
         << "9. Salir." << endl;
}

void Interfaz::mostrarOpcionIngresoID(const string &tipo)
{
    cout << "\nIngrese el ID del " << tipo << ": ";
}

void Interfaz::mostrarOpcionOcho()
{
    cout << "Cual archivo desea modificar?" << endl
         << "1. Clientes" << endl
         << "2. Carros" << endl;
}

void Interfaz::mostrarOpcionNueve()
{
    cout << "Gracias por preferirnos" << endl;
}

void Interfaz::mostrarOpcionesModificar()
{
    cout << "Que desea hacer?" << endl
         << "1. Agregar datos" << endl
         << "2. Eliminar datos" << endl
         << "3. Modificar datos" << endl;
}

void Interfaz::mostrarBienvenida()
{
    cout << "Bienvenido a la Consecionaria" << endl;
}