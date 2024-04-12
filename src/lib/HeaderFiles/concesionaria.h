#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H

#include "carro.h"
#include "cliente.h"

struct Concesionaria
{
    Cliente cliente;
    Carro carro;
    int opcion, opcion2, opcion3, opcion4;
    int id;
    Carro carCatalog[2000];
    int carCatalogSize;
    Cliente clientCatalog[2000];
    int clientCatalogSize;
    int carro_comprado_por, carro_vendido_por, balance_carro;
    string carro_fabricante, carro_modelo;
    int carCount;
    bool run;
    string nombre_cliente, apellido_cliente, email_cliente;
};

#endif