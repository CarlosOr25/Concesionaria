#include "controlador.h"

Controlador c;

void Controlador::ReadClientData(const string &filename, Cliente catalog[], int &catalogSize)
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

void Controlador::ReadCarData(const string &filename, Carro catalog[], int &catalogSize)
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

void Controlador::casoUno(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente)
{
    i.mostrarOpcionIngresoID("cliente");
    cin >> id;

    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

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

void Controlador::casoDos(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente)
{
    i.mostrarOpcionIngresoID("cliente");
    cin >> id;

    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

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

void Controlador::casoTres(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente)
{
    i.mostrarOpcionIngresoID("cliente");
    cin >> id;

    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

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

void Controlador::casoCuatro(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &nombre_cliente, string &apellido_cliente)
{
    i.mostrarOpcionIngresoID("cliente");
    cin >> id;

    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

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

void Controlador::casoCinco(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo)
{
    i.mostrarOpcionIngresoID("carro");
    cin >> id;

    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
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

void Controlador::casoSeis(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo)
{
    i.mostrarOpcionIngresoID("carro");
    cin >> id;

    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

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

void Controlador::casoSiete(int id, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por)
{
    i.mostrarOpcionIngresoID("carro");
    cin >> id;

    c.ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
    c.ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

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

void Controlador::casoOchoClientes(int opcion, Cliente &cliente)
{
    i.mostrarOpcionesModificar();
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

void Controlador::casoOchoCarros(int opcion, Carro &carro)
{
    i.mostrarOpcionesModificar();
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

void Controlador::casoOcho(int opcion2, int opcion3, int opcion4, Cliente &cliente, Carro &carro)
{
    do
    {
        i.mostrarOpcionOcho();
        cin >> opcion2;
        if (opcion2 == 1)
        {
            c.casoOchoClientes(opcion3, cliente);
        }
        else if (opcion2 == 2)
        {
            c.casoOchoCarros(opcion4, carro);
        }
        else
        {
            cout << "Opcion invalida" << endl;
        }
    } while (opcion2 > 2 || opcion2 < 1);
}

void Controlador::menuPrincipal(int &opcion, int &opcion2, int &opcion3, int &opcion4, int &id, Cliente &cliente, Carro &carro, Cliente clientCatalog[], int &clientCatalogSize, Carro carCatalog[], int &carCatalogSize, int &carCount, string &nombre_cliente, string &apellido_cliente, string &carro_fabricante, string &carro_modelo, int &carro_comprado_por, int &carro_vendido_por, bool &run)
{
    i.mostrarMenuPrincipal();
    cin >>
        opcion;

    switch (opcion)
    {
    case 1:
        c.casoUno(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carCount, nombre_cliente, apellido_cliente);
        break;
    case 2:
        c.casoDos(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carCount, nombre_cliente, apellido_cliente);
        break;
    case 3:
        c.casoTres(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, nombre_cliente, apellido_cliente);
        break;
    case 4:
        c.casoCuatro(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, nombre_cliente, apellido_cliente);
        break;
    case 5:
        c.casoCinco(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo);
        break;
    case 6:
        c.casoSeis(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo);
        break;
    case 7:
        c.casoSiete(id, clientCatalog, clientCatalogSize, carCatalog, carCatalogSize, carro_fabricante, carro_modelo, carro_comprado_por, carro_vendido_por);
        break;
    case 8:
        c.casoOcho(opcion2, opcion3, opcion4, cliente, carro);
        break;
    case 9:
        i.mostrarOpcionNueve();
        run = false;
        break;
    default:
        cout << "Opcion invalida" << endl;
    }
}

void Controlador::runProgram(Concesionaria &concesionaria)
{
    while (concesionaria.run)
    {
        menuPrincipal(concesionaria.opcion, concesionaria.opcion2, concesionaria.opcion3, concesionaria.opcion4, concesionaria.id, concesionaria.cliente, concesionaria.carro, concesionaria.clientCatalog, concesionaria.clientCatalogSize, concesionaria.carCatalog, concesionaria.carCatalogSize, concesionaria.carCount, concesionaria.nombre_cliente, concesionaria.apellido_cliente, concesionaria.carro_fabricante, concesionaria.carro_modelo, concesionaria.carro_comprado_por, concesionaria.carro_vendido_por, concesionaria.run);
    }
}