#include "lib/HeaderFiles/carro.h"
#include "lib/HeaderFiles/leerData.h"
#include "lib/HeaderFiles/cliente.h"
#include "lib/HeaderFiles/casos.h"
#include "lib/HeaderFiles/concesionaria.h"

int main()
{
    Concesionaria concesionaria;
    concesionaria.carCount = 0;
    concesionaria.run = true;

    cout << "Bienvenido a la Consecionaria" << endl;
    while (concesionaria.run)
    {
        menuPrincipal(concesionaria.opcion, concesionaria.opcion2, concesionaria.opcion3, concesionaria.opcion4, concesionaria.id, concesionaria.cliente, concesionaria.carro, concesionaria.clientCatalog, concesionaria.clientCatalogSize, concesionaria.carCatalog, concesionaria.carCatalogSize, concesionaria.carCount, concesionaria.nombre_cliente, concesionaria.apellido_cliente, concesionaria.carro_fabricante, concesionaria.carro_modelo, concesionaria.carro_comprado_por, concesionaria.carro_vendido_por, concesionaria.run);
    }
    return 0;
}