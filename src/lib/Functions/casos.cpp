#include "leerData.h"
#include "cliente.h"
#include "carro.h"
#include "casos.h"

void casoUno(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente)
{
    cout << "\nIngrese el ID del cliente: ";
    cin >> id;

    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].comprado_a == id)
        {
            carCount++;
        }
    }

    for (int i = 0; i < clientCatalogSize; i++)
    {
        if (clientCatalog[i].id == id)
        {
            nombre_cliente = clientCatalog[i].nombre;
            apellido_cliente = clientCatalog[i].apellido;
        }
    }

    cout << "El cliente " << nombre_cliente << " " << apellido_cliente << " ha comprado " << carCount << " carros.\n";
    getch();

    carCount = 0;
}

void casoDos(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente)
{
    cout << " \nIngrese el ID del cliente: ";
    cin >> id;

    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].vendido_a == id)
        {
            carCount++;
        }
    }

    for (int i = 0; i < clientCatalogSize; i++)
    {
        if (clientCatalog[i].id == id)
        {
            nombre_cliente = clientCatalog[i].nombre;
            apellido_cliente = clientCatalog[i].apellido;
        }
    }

    cout << "El cliente " << nombre_cliente << " " << apellido_cliente << " ha vendido " << carCount << " carros.\n";
    getch();

    carCount = 0;
}

void casoTres(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente)
{
    cout << " \nIngrese el ID del cliente: ";
    cin >> id;

    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

    for (int i = 0; i < clientCatalogSize; i++)
    {
        if (clientCatalog[i].id == id)
        {
            nombre_cliente = clientCatalog[i].nombre;
            apellido_cliente = clientCatalog[i].apellido;
        }
    }
    cout << "Los carros comprados por el cliente " << nombre_cliente << " " << apellido_cliente << " son: \n";
    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].comprado_a == id)
        {
            cout << "\nID: " << carCatalog[i].id << "\nFabricante: " << carCatalog[i].fabricante << "\nModelo: " << carCatalog[i].modelo << "\nAnio: " << carCatalog[i].anio << endl;
        }
    }
}

void casoCuatro(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente)
{
    cout << " \nIngrese el ID del cliente: ";
    cin >> id;

    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

    for (int i = 0; i < clientCatalogSize; i++)
    {
        if (clientCatalog[i].id == id)
        {
            nombre_cliente = clientCatalog[i].nombre;
            apellido_cliente = clientCatalog[i].apellido;
        }
    }
    cout << "Los carros vendidos por el cliente " << nombre_cliente << " " << apellido_cliente << " son: \n";
    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].vendido_a == id)
        {
            cout << "\nID: " << carCatalog[i].id << "\nFabricante: " << carCatalog[i].fabricante << "\nModelo: " << carCatalog[i].modelo << "\nAnio: " << carCatalog[i].anio << endl;
        }
    }
}

void casoCinco(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo)
{
    cout << " \nIngrese el ID del carro: ";
    cin >> id;

    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].id == id)
        {
            carro_fabricante = carCatalog[i].fabricante;
            carro_modelo = carCatalog[i].modelo;
            cout << "Los datos del comprador del carro " << carro_modelo << " " << carro_fabricante << " son: " << endl;
            for (int u = 0; u < clientCatalogSize; u++)
            {
                if (carCatalog[i].comprado_a == clientCatalog[u].id)
                {
                    cout << "Nombre: " << clientCatalog[u].nombre << " Apellido: " << clientCatalog[u].apellido << " Edad: " << clientCatalog[u].edad << " Email: " << clientCatalog[u].email;
                }
            }
        }
    }
}

void casoSeis(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo)
{
    cout << " \nIngrese el ID del carro: ";
    cin >> id;

    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].id == id)
        {
            carro_fabricante = carCatalog[i].fabricante;
            carro_modelo = carCatalog[i].modelo;
            cout << "Los datos del vendedor del carro " << carro_modelo << " " << carro_fabricante << " son: " << endl;
            for (int u = 0; u < clientCatalogSize; u++)
            {
                if (carCatalog[i].vendido_a == clientCatalog[u].id)
                {
                    cout << "Nombre: " << clientCatalog[u].nombre << " Apellido: " << clientCatalog[u].apellido << " Edad: " << clientCatalog[u].edad << " Email: " << clientCatalog[u].email;
                }
            }
        }
    }
}

void casoSiete(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por)
{
    cout << "\nIngrese el ID del carro: " << endl;
    cin >> id;

    ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

    for (int i = 0; i < carCatalogSize; i++)
    {
        if (carCatalog[i].id == id)
        {
            carro_fabricante = carCatalog[i].fabricante;
            carro_modelo = carCatalog[i].modelo;
            carro_comprado_por = carCatalog[i].comprado_por;
            carro_vendido_por = carCatalog[i].vendido_por;

            int balance_carro = carro_vendido_por - carro_comprado_por;

            if (balance_carro < 0)
            {
                cout << "El carro" << carro_modelo << " " << carro_fabricante << " tiene una perdida de " << balance_carro;
            }
            else if (balance_carro > 0)
            {
                cout << "El carro " << carro_modelo << " " << carro_fabricante << " tiene una ganancia de " << balance_carro;
            }
        }
    }
}

void casoOchoClientes(int opcion, Cliente &cliente)
{
    cout << "Que desea hacer?" << endl
         << "1. Agregar datos" << endl
         << "2. Eliminar datos" << endl
         << "3. Modificar datos" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cliente.agregarDatosc();
        break;
    case 2:
        cliente.eliminarDatosc();
        break;
    case 3:
        cliente.modificarDatosc();
        break;
    default:
        cout << "Opcion invalida" << endl;
    }
}

void casoOchoCarros(int opcion, Carro &carro)
{
    cout << "Que desea hacer?" << endl
         << "1. Agregar datos" << endl
         << "2. Eliminar datos" << endl
         << "3. Modificar datos" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        carro.agregarDatosa();
        break;
    case 2:
        carro.eliminarDatosa();
        break;
    case 3:
        carro.modificarDatosa();
        break;
    default:
        cout << "Opcion invalida" << endl;
    }
}

void casoOcho(int opcion2, int opcion3, int opcion4, Cliente &cliente, Carro &carro)
{
    do
    {
        cout << "Cual archivo desea modificar?" << endl
             << "1. Clientes" << endl
             << "2. Carros" << endl;
        cin >> opcion2;
        if (opcion2 == 1)
        {
            casoOchoClientes(opcion3, cliente);
        }
        else if (opcion2 == 2)
        {
            casoOchoCarros(opcion4, carro);
        }
        else
        {
            cout << "Opcion invalida" << endl;
        }
    } while (opcion2 > 2 || opcion2 < 1);
}

void menuPrincipal(int &opcion, int &opcion2, int &opcion3, int &opcion4, int &id, Cliente &cliente, Carro &carro, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por, bool &run)
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
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        casoUno(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carCount, nombre_cliente, apellido_cliente);
        break;
    case 2:
        casoDos(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carCount, nombre_cliente, apellido_cliente);
        break;
    case 3:
        casoTres(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, nombre_cliente, apellido_cliente);
        break;
    case 4:
        casoCuatro(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, nombre_cliente, apellido_cliente);
        break;
    case 5:
        casoCinco(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo);
        break;
    case 6:
        casoSeis(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo);
        break;
    case 7:
        casoSiete(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo, carro_comprado_por, carro_vendido_por);
        break;
    case 8:
        casoOcho(opcion2, opcion3, opcion4, cliente, carro);
        break;
    case 9:
        cout << "Gracias por preferirnos" << endl;
        run = false;
        break;
    default:
        cout << "Opcion invalida" << endl;
    }
}
