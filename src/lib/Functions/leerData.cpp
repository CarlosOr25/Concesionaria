#include "leerData.h"
#include "cliente.h"
#include "carro.h"

void ReadClientData(const string &filename, Cliente catalog[], int &catalogSize)
{
    ifstream clientFile(filename);
    string line;
    catalogSize = 0;

    getline(clientFile, line);

    while (getline(clientFile, line))
    {
        stringstream ss(line);

        ss >> catalog[catalogSize].id;
        ss.ignore();
        getline(ss, catalog[catalogSize].nombre, ';');
        getline(ss, catalog[catalogSize].apellido, ';');
        getline(ss, catalog[catalogSize].email, ';');
        ss >> catalog[catalogSize].edad;
        ss.ignore();

        catalogSize++;
    }
}

void ReadCarData(const string &filename, Carro catalog[], int &catalogSize)
{
    ifstream carFile(filename);
    string line;
    catalogSize = 0;

    getline(carFile, line);

    while (getline(carFile, line))
    {
        stringstream ss(line);

        ss >> catalog[catalogSize].id;
        ss.ignore();
        getline(ss, catalog[catalogSize].fabricante, ';');
        getline(ss, catalog[catalogSize].modelo, ';');
        ss >> catalog[catalogSize].anio;
        ss.ignore();
        ss >> catalog[catalogSize].vendido_a;
        ss.ignore();
        ss >> catalog[catalogSize].comprado_a;
        ss.ignore();
        ss >> catalog[catalogSize].vendido_por;
        ss.ignore();
        ss >> catalog[catalogSize].comprado_por;
        ss.ignore();

        catalogSize++;
    }
}
