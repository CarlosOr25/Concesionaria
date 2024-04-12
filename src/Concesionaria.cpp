#include "lib/HeaderFiles/carro.h"
#include "lib/HeaderFiles/leerData.h"
#include "lib/HeaderFiles/cliente.h"

int main()
{
    int opcion, opcion2, opcion3, opcion4;
    int id, id2, id3, id4;
    Carro carCatalog[2000];
    int carCatalogSize;
    Cliente clientCatalog[2000];
    int clientCatalogSize;
    int carro_comprado_por, carro_vendido_por, balance_carro;
    string carro_fabricante, carro_modelo;
    int carCount = 0;
    bool run = true;
    string linea, nombre_cliente, apellido_cliente, email_cliente, edad_cliente;
    Carro a;
    Cliente c;
    ifstream archivo_cars;          // Declaración de archivo_cars fuera del switch
    int total_carros_comprados = 0; // Declaración de total_carros_comprados fuera del switch
    cout << "Bienvenido a la Consecionaria" << endl;
    while (run)
    {
        cout << "\nQue necesita hacer?" << endl
             << "1. Ver cantidad de carros comprados por clientes." << endl
             << "2. Ver cantidad de carros vendidos por clientes." << endl
             << "3. Lista de carros comprados por clienttes." << endl
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
            break;
        }
        case 2:
        {
            cout << " \nIngrese el ID del cliente: ";
            cin >> id2;

            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].vendido_a == id2)
                {
                    carCount++;
                }
            }

            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id2)
                {
                    nombre_cliente = clientCatalog[i].nombre;
                    apellido_cliente = clientCatalog[i].apellido;
                }
            }

            cout << "El cliente " << nombre_cliente << " " << apellido_cliente << " ha vendido " << carCount << " carros.\n";
            getch();

            carCount = 0;
            break;
        }
        case 3:
        {
            cout << " \nIngrese el ID del cliente: ";
            cin >> id3;

            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id3)
                {
                    nombre_cliente = clientCatalog[i].nombre;
                    apellido_cliente = clientCatalog[i].apellido;
                }
            }
            cout << "Los carros comprados por el cliente " << nombre_cliente << " " << apellido_cliente << " son: \n";
            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].comprado_a == id3)
                {
                    cout << "\nID: " << carCatalog[i].id << "\nFabricante: " << carCatalog[i].fabricante << "\nModelo: " << carCatalog[i].modelo << "\nAnio: " << carCatalog[i].anio << endl;
                }
            }
        }
        break;
        case 4:
        {
            cout << " \nIngrese el ID del cliente: ";
            cin >> id3;

            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);

            for (int i = 0; i < clientCatalogSize; i++)
            {
                if (clientCatalog[i].id == id3)
                {
                    nombre_cliente = clientCatalog[i].nombre;
                    apellido_cliente = clientCatalog[i].apellido;
                }
            }
            cout << "Los carros vendidos por el cliente " << nombre_cliente << " " << apellido_cliente << " son: \n";
            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].vendido_a == id3)
                {
                    cout << "\nID: " << carCatalog[i].id << "\nFabricante: " << carCatalog[i].fabricante << "\nModelo: " << carCatalog[i].modelo << "\nAnio: " << carCatalog[i].anio << endl;
                }
            }
        }
        break;
        case 5:
            cout << " \nIngrese el ID del carro: ";
            cin >> id3;

            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);
            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].id == id3)
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
            // Aquí debes implementar la lógica para la opción 5
            break;
        case 6:
            cout << " \nIngrese el ID del carro: ";
            cin >> id4;

            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].id == id4)
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
            // Aquí debes implementar la lógica para la opción 6
            break;
        case 7:
            cout << "\nIngrese el ID del carro: " << endl;
            cin >> id4;

            ReadCarData("data/cars_data.csv", carCatalog, carCatalogSize);
            ReadClientData("data/clients.csv", clientCatalog, clientCatalogSize);

            for (int i = 0; i < carCatalogSize; i++)
            {
                if (carCatalog[i].id == id4)
                {
                    carro_fabricante = carCatalog[i].fabricante;
                    carro_modelo = carCatalog[i].modelo;
                    carro_comprado_por = carCatalog[i].comprado_por;
                    carro_vendido_por = carCatalog[i].vendido_por;

                    balance_carro = carro_vendido_por - carro_comprado_por;

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
            // Aquí debes implementar la lógica para la opción 7
            break;
        case 8:
            do
            {
                cout << "Cual archivo desea modificar?" << endl
                     << "1. Clientes" << endl
                     << "2. Carros" << endl;
                cin >> opcion2;
                if (opcion2 == 1)
                {
                    cout << "Que desea hacer?" << endl
                         << "1. Agregar datos" << endl
                         << "2. Eliminar datos" << endl
                         << "3. Modificar datos" << endl;
                    cin >> opcion3;
                    switch (opcion3)
                    {
                    case 1:
                        agregarDatosc();
                        break;
                    case 2:
                        eliminarDatosc();
                        break;
                    case 3:
                        modificarDatosc();
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                    }
                }
                else if (opcion2 == 2)
                {
                    cout << "Que desea hacer?" << endl
                         << "1. Agregar datos" << endl
                         << "2. Eliminar datos" << endl
                         << "3. Modificar datos" << endl;
                    cin >> opcion4;
                    switch (opcion4)
                    {
                    case 1:
                        agregarDatosa();
                        break;
                    case 2:
                        eliminarDatosa();
                        break;
                    case 3:
                        modificarDatosa();
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                    }
                }
                else
                {
                    cout << "Opcion invalida" << endl;
                }
            } while (opcion2 > 2 || opcion2 < 1);

            break;

        case 9:
            cout << "Gracias por preferirnos" << endl;
            run = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    }
    return 0;
}
