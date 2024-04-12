#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

class Carro
{
public:
    int id;
    string fabricante;
    string modelo;
    int anio;
    int vendido_a;
    int comprado_a;
    int vendido_por;
    int comprado_por;

    void agregarDatosa();
    void eliminarDatosa();
    void modificarDatosa();
};

// Funciones para el archivo carros  
