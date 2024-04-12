#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

// Definición de las clases Clientes y Carros

class Cliente
{
public:
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;
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
};

// Funciones para el archivo carros
void agregarDatosa();
void eliminarDatosa();
void modificarDatosa();

// Funciones para el archivo clientes

void agregarDatosc();
void eliminarDatosc();
void modificarDatosc();

// funciones para leer los datos de los archivos

void ReadClientData(const string &filename, Cliente catalog[], int &catalogSize);
void ReadCarData(const string &filename, Carro catalog[], int &catalogSize);

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

void modificarDatosc()
{
    Cliente c;
    cout << "Ingrese el id del cliente que desea modificar: ";
    cin >> c.id;

    ofstream temp("data/temp.csv");
    ifstream archivo_clientes("data/clients.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual == c.id)
        {
            cout << "Ingrese el nombre: ";
            cin >> c.nombre;
            cout << "Ingrese el apellido: ";
            cin >> c.apellido;
            cout << "Ingrese el email: ";
            cin >> c.email;
            cout << "Ingrese la edad: ";
            cin >> c.edad;
            temp << c.id << ";" << c.nombre << ";" << c.apellido << ";" << c.email << ";" << c.edad << endl;
        }
        else
        {
            temp << linea << endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("data/clients.csv");
    rename("data/temp.csv", "data/clients.csv");
    cout << "datos modificados con exito" << endl;
}

void eliminarDatosc()
{
    Cliente c;
    cout << "Ingrese el id del cliente que desea eliminar: ";
    cin >> c.id;
    ofstream temp("data/temp.csv");
    ifstream archivo_clientes("data/clients.csv");
    string linea;
    bool encontrado = false; // Variable para indicar si se encontró el cliente a eliminar

    while (getline(archivo_clientes, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        // Si se encuentra el cliente con el ID proporcionado, se marca como encontrado
        if (id_actual == c.id)
        {
            encontrado = true;
        }
        else
        {
            // Si el ID actual es mayor que el ID del cliente a eliminar, se reduce en 1
            if (encontrado)
            {
                int nuevo_id = id_actual - 1;
                // Modifica el ID en la línea actual
                linea.replace(0, linea.find(';'), to_string(nuevo_id));
            }
            // Escribe la línea en el archivo temporal
            temp << linea << endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("data/clients.csv");
    rename("data/temp.csv", "data/clients.csv");

    if (encontrado)
    {
        cout << "Cliente eliminado correctamente." << endl;
    }
    else
    {
        cout << "No se encontró ningún cliente con el ID proporcionado." << endl;
    }
}

void agregarDatosc()
{
    ofstream archivo_clientes("data/clients.csv", ios::app);
    ifstream archivo_clientes2("data/clients.csv");
    string linea;
    Cliente c;
    int idnew = 0;

    while (getline(archivo_clientes2, linea))
    {
        idnew++;
    }
    cout << "Ingrese el nombre: ";
    cin >> c.nombre;
    cout << "Ingrese el apellido: ";
    cin >> c.apellido;
    cout << "Ingrese el email: ";
    cin >> c.email;
    cout << "Ingrese la edad: ";
    cin >> c.edad;

    archivo_clientes << "\n"
                     << idnew << ";" << c.nombre << ";" << c.apellido << ";" << c.email << ";" << c.edad;
    archivo_clientes.close();
    archivo_clientes2.close();
}

void elminardatosc()
{
    Cliente c;
    cout << "Ingrese el id del cliente que desea eliminar: ";
    cin >> c.id;
    ofstream temp("data/temp.csv");
    ifstream archivo_clientes("data/clients.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual != c.id)
        {
            temp << linea << endl;
        }
    }
    archivo_clientes.close();
    temp.close();

    remove("data/clients.csv");
    rename("data/temp.csv", "data/clients.csv");
    cout << "Datos eliminados correctamente." << endl;
}

void modificarDatosa()
{
    Carro a;
    cout << "Ingrese el id del carro que desea modificar: ";
    cin >> a.id;

    ofstream temp("data/temp.csv");
    ifstream archivo_carros("data/cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual == a.id)
        {
            cout << "Ingrese el fabricante: ";
            cin >> a.fabricante;
            cout << "Ingrese el modelo: ";
            cin >> a.modelo;
            cout << "Ingrese el anio: ";
            cin >> a.anio;
            cout << "Ingrese el id del comprador: ";
            cin >> a.vendido_a;
            cout << "Ingrese el id del vendedor: ";
            cin >> a.comprado_a;
            cout << "Ingrese el precio de venta: ";
            cin >> a.vendido_por;
            cout << "Ingrese el precio de compra:";
            cin >> a.comprado_por;
            temp << a.id << ";" << a.fabricante << ";" << a.modelo << ";" << a.anio << ";" << a.vendido_a << ";" << a.comprado_a << ";" << a.vendido_por << ";" << a.comprado_por << endl;
        }
        else
        {
            temp << linea << endl;
        }
    }
    archivo_carros.close();
    temp.close();
    remove("data/cars_data.csv");
    rename("data/temp.csv", "data/cars_data.csv");
    cout << "Datos modificados correctamente." << endl;
}

void eliminarDatosa()
{
    Carro a;
    cout << "Ingrese el id del carro que desea eliminar: ";
    cin >> a.id;
    ofstream temp("data/temp.csv");
    ifstream archivo_carros("data/cars_data.csv");
    string linea;
    bool encontrado = false; // Variable para indicar si se encontró el cliente a eliminar

    while (getline(archivo_carros, linea))
    {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        // Si se encuentra el cliente con el ID proporcionado, se marca como encontrado
        if (id_actual == a.id)
        {
            encontrado = true;
        }
        else
        {
            // Si el ID actual es mayor que el ID del cliente a eliminar, se reduce en 1
            if (encontrado)
            {
                int nuevo_id = id_actual - 1;
                // Modifica el ID en la línea actual
                linea.replace(0, linea.find(';'), to_string(nuevo_id));
            }
            // Escribe la línea en el archivo temporal
            temp << linea << endl;
        }
    }
    archivo_carros.close();
    temp.close();

    remove("data/cars_data.csv");
    rename("data/temp.csv", "data/cars_data.csv");

    if (encontrado)
    {
        cout << "Cliente eliminado correctamente." << endl;
    }
    else
    {
        cout << "No se encontró ningún cliente con el ID proporcionado." << endl;
    }
}

void agregarDatosa()
{
    ofstream archivo_carros("data/cars_data.csv", ios::app);
    ifstream archivo_carros2("data/cars_data.csv");
    string linea;
    Carro a;
    int idnew = 0;

    while (getline(archivo_carros2, linea))
    {
        idnew++;
    }
    cout << "Ingrese el fabricante: ";
    cin >> a.fabricante;
    cout << "Ingrese el modelo: ";
    cin >> a.modelo;
    cout << "Ingrese el anio: ";
    cin >> a.anio;
    cout << "Ingrese id del comprador: ";
    cin >> a.vendido_a;
    cout << "Ingrese el id del vendedor: ";
    cin >> a.comprado_a;
    cout << "Ingrese el precio de venta: ";
    cin >> a.vendido_por;
    cout << "Ingrese el precio de compra: ";
    cin >> a.comprado_por;

    archivo_carros << "\n"
                   << idnew << ";" << a.fabricante << ";" << a.modelo << ";" << a.anio << ";" << a.vendido_a << ";" << a.comprado_a << ";" << a.vendido_por << ";" << a.comprado_por;
    archivo_carros.close();
}