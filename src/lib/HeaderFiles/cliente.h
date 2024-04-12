#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

class Cliente
{
public:
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;

    void agregarDatosc();
    void eliminarDatosc();
    void modificarDatosc();
};

// Funciones para el archivo clientes


