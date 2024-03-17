#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

// Definición de las estructuras clientes y carros
struct clientes
{
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;
};

struct carros
{
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
void modificarRegistroc();

// funciones para leer los datos de los archivos

void ReadClientData(const string &filename, clientes catalog[], int &catalogSize);
void ReadCarData(const string &filename, carros catalog[], int &catalogSize);

int main()
{
    int opcion, opcion2, opcion3, opcion4;
    int id;
    carros carCatalog[2000];
    int carCatalogSize;
    clientes clientCatalog[2000];
    int clientCatalogSize;
    int carCount = 0;
    bool run = true;
    string linea, nombre_cliente, apellido_cliente, email_cliente;
    carros a;
    clientes c;
    ifstream archivo_cars;          // Declaración de archivo_cars fuera del switch
    int total_carros_comprados = 0; // Declaración de total_carros_comprados fuera del switch
     cout << "Bienvenido a la Consecionaria" << endl;
    while (run)  {
        cout << "Que necesita hacer?" << endl
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

            ReadClientData("clients.csv", clientCatalog, clientCatalogSize);

            ReadCarData("cars_data.csv", carCatalog, carCatalogSize);

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

            cout << "El cliente " << nombre_cliente <<" "<<apellido_cliente <<" ha comprado " << carCount << " carros.\n";
            getch();

            break;
        }
        case 2:
            // Aquí debes implementar la lógica para la opción 2
            break;
        case 3:
            // Aquí debes implementar la lógica para la opción 3
            break;
        case 4:
            // Aquí debes implementar la lógica para la opción 4
            break;
        case 5:
            // Aquí debes implementar la lógica para la opción 5
            break;
        case 6:
            // Aquí debes implementar la lógica para la opción 6
            break;
        case 7:
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
                        modificarRegistroc();
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

void ReadClientData(const string &filename, clientes catalog[], int &catalogSize)
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

void ReadCarData(const string &filename, carros catalog[], int &catalogSize)
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

void modificarRegistroc()
{
    clientes c;
    cout << "Ingrese el id del cliente que desea modificar: ";
    cin >> c.id;

    ofstream temp("temp.csv");
    ifstream archivo_clientes("clients_data.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        stringstream ss(linea);
        string id_str;
        getline(ss, id_str, ';');
        int id_actual;
        ss >> id_actual;

        if (id_actual == c.id)
        {
            cout << "Ingrese el id: ";
            cin >> c.id;
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

    remove("clients_data.csv");
    rename("temp.csv", "clients_data.csv");
    cout << "Datos modificados correctamente." << endl;
}

void eliminarDatosc()
{
    clientes c;
    cout << "Ingrese el id del cliente que desea eliminar: ";
    cin >> c.id;
    ofstream temp("temp.csv");
    ifstream archivo_clientes("clients_data.csv");
    string linea;

    while (getline(archivo_clientes, linea))
    {
        stringstream ss(linea);
        string id_str;
        getline(ss, id_str, ';');
        int id_actual;
        ss >> id_actual;

        if (id_actual != c.id)
        {
            temp << linea << endl;
        }
    }

    archivo_clientes.close();
    temp.close();

    remove("clients_data.csv");
    rename("temp.csv", "clients_data.csv");
    cout << "Datos eliminados correctamente." << endl;
}

void agregarDatosc()
{
    ofstream archivo_clientes("clients_data.csv", ios::app);
    clientes c;

    cout << "Ingrese el id: ";
    cin >> c.id;
    cout << "Ingrese el nombre: ";
    cin >> c.nombre;
    cout << "Ingrese el apellido: ";
    cin >> c.apellido;
    cout << "Ingrese el email: ";
    cin >> c.email;
    cout << "Ingrese la edad: ";
    cin >> c.edad;

    archivo_clientes << c.id << ";" << c.nombre << ";" << c.apellido << ";" << c.email << ";" << c.edad << endl;
    archivo_clientes.close();
}

void modificarDatosa()
{
    carros a;
    cout << "Ingrese el id del carro que desea modificar: ";
    cin >> a.id;

    ofstream temp("temp.csv");
    ifstream archivo_carros("cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea))
    {
        stringstream ss(linea);
        string id_str;
        getline(ss, id_str, ';');
        int id_actual;
        ss >> id_actual;

        if (id_actual == a.id)
        {
            cout << "Ingrese el id: ";
            cin >> a.id;
            cout << "Ingrese el fabricante: ";
            cin >> a.fabricante;
            cout << "Ingrese el modelo: ";
            cin >> a.modelo;
            cout << "Ingrese el anio: ";
            cin >> a.anio;
            cout << "Ingrese el vendido_a: ";
            cin >> a.vendido_a;
            cout << "Ingrese el comprado_a: ";
            cin >> a.comprado_a;
            cout << "Ingrese el vendido_por: ";
            cin >> a.vendido_por;
            cout << "Ingrese el comprado_por: ";
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

    remove("cars_data.csv");
    rename("temp.csv", "cars_data.csv");
    cout << "Datos modificados correctamente." << endl;
}

void eliminarDatosa()
{
    carros a;
    cout << "Ingrese el id del carro que desea eliminar: ";
    cin >> a.id;
    ofstream temp("temp.csv");
    ifstream archivo_carros("cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea))
    {
        stringstream ss(linea);
        string id_str;
        getline(ss, id_str, ';');
        int id_actual;
        ss >> id_actual;

        if (id_actual != a.id)
        {
            temp << linea << endl;
        }
    }

    archivo_carros.close();
    temp.close();

    remove("cars_data.csv");
    rename("temp.csv", "cars_data.csv");
    cout << "Datos eliminados correctamente." << endl;
}

void agregarDatosa()
{
    ofstream archivo_carros("cars_data.csv", ios::app);
    carros a;

    cout << "Ingrese el id: ";
    cin >> a.id;
    cout << "Ingrese el fabricante: ";
    cin >> a.fabricante;
    cout << "Ingrese el modelo: ";
    cin >> a.modelo;
    cout << "Ingrese el anio: ";
    cin >> a.anio;
    cout << "Ingrese el vendido_a: ";
    cin >> a.vendido_a;
    cout << "Ingrese el comprado_a: ";
    cin >> a.comprado_a;
    cout << "Ingrese el vendido_por: ";
    cin >> a.vendido_por;
    cout << "Ingrese el comprado_por: ";
    cin >> a.comprado_por;

    archivo_carros << a.id << ";" << a.fabricante << ";" << a.modelo << ";" << a.anio << ";" << a.vendido_a << ";" << a.comprado_a << ";" << a.vendido_por << ";" << a.comprado_por << endl;
    archivo_carros.close();
}
