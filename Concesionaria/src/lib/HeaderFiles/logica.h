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

struct Concesionaria
{
    Cliente cliente;
    Carro carro;
    int opcion, opcion2, opcion3, opcion4;
    int id;
    Carro *carCatalog;
    int carCatalogSize;
    Cliente *clientCatalog;
    int clientCatalogSize;
    int carro_comprado_por, carro_vendido_por, balance_carro;
    string carro_fabricante, carro_modelo;
    int carCount;
    bool run;
    string nombre_cliente, apellido_cliente, email_cliente;

    void init() {
        carCount = 0;
        run = true;
        carCatalog = new Carro[2000];
        clientCatalog = new Cliente[2000];
    }

    void cleanup() {
        delete[] carCatalog;
        delete[] clientCatalog;
    }
};