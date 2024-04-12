#include "cliente.h"
#include "carro.h"

void Cliente::modificarDatosc()
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

void Cliente::eliminarDatosc()
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

void Cliente::agregarDatosc()
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

