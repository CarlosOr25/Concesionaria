#pragma once

#include "cliente.h"
#include "carro.h"
#include "leerData.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

void casoUno(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente);
void casoDos(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente);
void casoTres(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente);
void casoCuatro(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente);
void casoCinco(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo);
void casoSeis(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo);
void casoSiete(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por);
void casoOchoClientes(int opcion, Cliente &cliente);
void casoOchoCarros(int opcion, Carro &carro);
void casoOcho(int opcion2, int opcion3, int opcion4, Cliente &cliente, Carro &carro);
void menuPrincipal(int &opcion, int &opcion2, int &opcion3, int &opcion4, int &id, Cliente &cliente, Carro &carro, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por, bool &run);
