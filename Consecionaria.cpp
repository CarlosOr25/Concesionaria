#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct clientes {
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;
};

struct carros {
    int id;
    string fabricante;
    string modelo;
    int anio;
    int vendido_a;
    int comprado_a;
    int vendido_por;
    int comprado_por;
};
void agregarDatosc();
void eliminarDatosc();
void modificarRegistroc();

void agregarDatosa();
void eliminarDatosa();
void modificarDatosa();


//archivo carros
void agregarDatosa() {
    
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

void elminardatosa() {
    carros a;
    cout << "Ingrese el id del carro que desea eliminar: ";
    cin >> a.id;
    ofstream temp("temp.csv");
    ifstream archivo_carros("cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea)) {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual != a.id) {
            temp << linea << endl;
        }
    }

    archivo_carros.close();
    temp.close();

    remove("cars_data.csv");
    rename("temp.csv", "cars_data.csv");
    cout << "Datos eliminados correctamente." << endl;
}


    void modificarDatosa(){
    carros a;
    cout << "Ingrese el id del carro que desea modificar: ";
    cin >> a.id;

    ofstream temp("temp.csv");
    ifstream archivo_carros("cars_data.csv");
    string linea;

    while (getline(archivo_carros, linea)) {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual == a.id) {
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
        } else {
            temp << linea << endl;
        }
    }

    archivo_carros.close();
    temp.close();

    remove("cars_data.csv");
    rename("temp.csv", "cars_data.csv");
    cout << "Datos modificados correctamente." << endl;
}

//archivo clientes

void agregarDatosc() {
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

    void elminardatosc() {
    clientes c;
    cout << "Ingrese el id del cliente que desea eliminar: ";
    cin >> c.id;
    ofstream temp("temp.csv");
    ifstream archivo_clientes("clients_data.csv");
    string linea;

    while (getline(archivo_clientes, linea)) {
        int id_actual = atoi(linea.substr(0, linea.find(';')).c_str());
        if (id_actual != c.id) {
            temp << linea << endl;
        }
    }

    archivo_clientes.close();
    temp.close();

    remove("clients_data.csv");
    rename("temp.csv", "clients_data.csv");
    cout << "Datos eliminados correctamente." << endl;
}

int main() {
    int opcion, opcion2, opcion3, opcion4;

    do{
    cout<<"Bienvenido a la Consecionaria"<<endl;
    cout<< "Que necesita hacer?"<<endl
            << "1. Ver cantidad de carros comprados por clientes."<<endl
            << "2. Ver cantidad de carros vendidos por clientes."<<endl
            << "3. Lista de carros comprados por clienttes."<<endl
            << "4. Lista de carros vendidos por clientes."<<endl
            << "5. Ver datos del comprador de un carro."<<endl
            << "6. Ver datos del vendedor de un carro."<<endl
            << "7. Mostrar Balance de un carro."<<endl
            << "8. Modificar datos."<<endl;
            cin>>opcion;

    }while(opcion > 8 || opcion < 1);
    
    switch (opcion) {
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:     
        break;

    case 8:
    do{
        cout<<"Cual archivo desea modificar?"<<endl
            << "1. Clientes"<<endl
            << "2. Carros"<<endl;
            cin>>opcion2;
        if(opcion2 == 1){
            cout<<"Que desea hacer?"<<endl
            << "1. Agregar datos"<<endl
            << "2. Eliminar datos"<<endl
            << "3. Modificar datos"<<endl;
            cin>>opcion3;
        }else if(opcion2 == 2){
            cout<<"Que desea hacer?"<<endl
            << "1. Agregar datos"<<endl
            << "2. Eliminar datos"<<endl
            << "3. Modificar datos"<<endl;
            cin>>opcion4;
        }}while(opcion2 > 2 || opcion2 < 1);
            cout<<"Opcion invalida"<<endl;

        break;

    default:
        break;
    }

    switch (opcion3) {
    case 1:
        agregarDatosa();
        break;

    case 2:
        elminardatosa();
        break;

    case 3:
       modificarDatosa();
        break;

    return 0;
}
switch (opcion4) {

case 1:
    agregarDatosc();
    break;

case 2:
    elminardatosc();
    break;  

case 3:
    modificarRegistroc();
    break;
}
}