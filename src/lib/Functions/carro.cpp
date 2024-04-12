#include "carro.h"
#include "cliente.h"

void Carro::modificarDatosa()
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

void Carro::eliminarDatosa()
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

void Carro::agregarDatosa()
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