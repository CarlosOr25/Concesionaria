#include <iostream> 
#include <string>
#include <fstream> 
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;    

string linea;
string texto;
string dato;
string id, fabricante, modelo, año, vendido_a, comprado_a, vendido_por, comprado_por;

int main (){
    
    ifstream archivo("cars_data.csv");

    while (getline(archivo, linea)){
        texto= texto + linea+ "\n";
    }
    archivo.close();

    bool opcionvalida = false;
    int opcion;

    do {
        cout << "Que desea hacer?" << "\n"
             << "1. Agregar un dato."   << "\n"
             << "2. Eliminar un dato."  << "\n"  
             << "3. Modificar un dato." << "\n";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3) {
            opcionvalida = true;
        } else {
            cout << "Opcion invalida. Por favor, ingrese un numero valido." << endl;
        }
    } 
    while (!opcionvalida);

    ofstream archivo2; 
    string temp_id;
    ifstream archivo_temp;
    ofstream archivo_temp_out;

    switch (opcion){
        case 1:
            cout << "Ingrese el ID: ";
            cin >> id;

            cout << "Ingrese el fabricante: ";
            cin >> fabricante;

            cout << "Ingrese el modelo: ";
            cin >> modelo;

            cout << "Ingrese el año: ";
            cin >> año;

            cout << "Ingrese a quien se vendio: ";
            cin >> vendido_a;

            cout << "Ingrese de quién se compro: ";
            cin >> comprado_a;

            cout << "Ingrese el precio de venta: ";
            cin >> vendido_por;

            cout << "Ingrese el precio de compra: ";
            cin >> comprado_por;

            archivo2.open("cars_data.csv", ios::app);
            archivo2 << id << ";" << fabricante << ";" << modelo << ";" << año << ";" << vendido_a << ";" << comprado_a << ";" << vendido_por << ";" << comprado_por << endl;
            archivo2.close(); 
            break;

        case 2:
            archivo_temp.open("cars_data.csv");
            archivo_temp_out.open("temp.csv");
            cout << "ingrese el id del registro que desea eliminar:" << endl;
            cin >> temp_id; 

            while (getline(archivo_temp, linea)) {
                size_t pos = linea.find (';');
                string current_id = linea.substr(0, pos);
                if (current_id != temp_id){
                    archivo_temp_out << linea << endl;
                }
            }
            archivo_temp.close();
            archivo_temp_out.close();

            remove("cars_data.csv");
            rename("temp.csv", "cars_data.csv");
            break;

        case 3:
            cout << "Por implementar." << endl; // Mensaje temporal
            break;

        default:
            break;  
    }
}










