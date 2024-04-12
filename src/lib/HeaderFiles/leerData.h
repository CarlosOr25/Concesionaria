#pragma once

#include "cliente.h"
#include "carro.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

// funciones para leer los datos de los archivos

void ReadClientData(const string &filename, Cliente catalog[], int &catalogSize);
void ReadCarData(const string &filename, Carro catalog[], int &catalogSize);
