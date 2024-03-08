#include <iostream> 
#include <string>
#include <fstream> 
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;    
struct clients{
    string id;
    string nombre;
    string apellido;
    string email;
    string edad;
};
struct carros{
    string id;
    string fabricante;
    string modelo;
    string año;
    string vendido_a;
    string comprado_a;
    string vendido_por;
    string comprado_por;
};
string linea;
string texto, texto2; 
string dato;

int main (){

    ifstream archivo("clients.csv");

    while (getline(archivo, linea)){
        texto2= texto2 + linea+ "\n";
        
    }
    

    archivo.close();

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
    carros c;

    switch (opcion){
        case 1:
            cout << "Ingrese el ID: ";
            cin >> c.id;

            cout << "Ingrese el fabricante: ";
            cin >> c.fabricante;

            cout << "Ingrese el modelo: ";
            cin >> c.modelo;

            cout << "Ingrese el año: ";
            cin >> c.año;

            cout << "Ingrese a quien se vendio: ";
            cin >> c.vendido_a;

            cout << "Ingrese de quién se compro: ";
            cin >> c.comprado_a;

            cout << "Ingrese el precio de venta: ";
            cin >> c.vendido_por;

            cout << "Ingrese el precio de compra: ";
            cin >> c.comprado_por;

            archivo2.open("cars_data.csv", ios::app);
            archivo2 << c.id << ";" 
            << c.fabricante << ";" 
            <<c.modelo << ";" 
            << c.año << ";" 
            << c.vendido_a << ";" 
            << c.comprado_a << ";" 
            << c.vendido_por << ";" 
            << c.comprado_por << endl;
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

           cout<< "Ingrese el numero de lista que quiere modificar: "<<endl;
    cin>> c.id;

    archivo_temp.open("cars_data.csv"); // Aquí está la corrección
    archivo_temp_out.open("temp.csv");

    while (getline(archivo_temp, linea)){
        size_t pos = linea.find(';');
        string current_id = linea.substr(0, pos);

        if (current_id == c.id){
            cout << "Ingrese el nuevo fabricante: ";
            cin >> c.fabricante;

            cout << "Ingrese el nuevo modelo: ";
            cin >> c.modelo;

            cout << "Ingrese el nuevo año: ";
            cin >> c.año;

            cout << "Ingrese a quien se vendio: ";
            cin >> c.vendido_a;

            cout << "Ingrese de quien se compro: ";
            cin >> c.comprado_a;

            cout << "Ingrese el precio de venta: ";
            cin >> c.vendido_por;

            cout << "Ingrese el precio de compra: ";
            cin >> c.comprado_por;

            archivo_temp_out << c.id << ";" 
            << c.fabricante << ";"
             << c.modelo << ";" 
             << c.año << ";" 
             << c.vendido_a << ";" 
             << c.comprado_a << ";" 
             << c.vendido_por << ";" 
             << c.comprado_por << endl;
        } else {
            archivo_temp_out << linea << endl;
        }
    }

    archivo_temp.close(); 
    archivo_temp_out.close(); 

    remove("cars_data.csv"); 
    rename("temp.csv", "cars_data.csv"); 

    cout<< "registro editado. "<<endl;
    break;

        default:
            break;  
    }
}







