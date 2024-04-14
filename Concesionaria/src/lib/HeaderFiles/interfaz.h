#pragma once

#include "controlador.h"

class Interfaz
{
public:
    void mostrarMenuPrincipal();
    void mostrarOpcionIngresoID(const string &tipo);
    void mostrarOpcionOcho();
    void mostrarOpcionNueve();
    void mostrarOpcionesModificar();
    void mostrarBienvenida();
};

extern Interfaz i;

