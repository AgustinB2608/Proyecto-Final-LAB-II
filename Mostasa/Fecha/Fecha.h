#pragma once
#include <iostream>
#include <string.h>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int dia = 0, int mes = 0, int anio = 0);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    void CargarFecha(bool esReserva);
    void CargarFechaCliente();
    void MostrarFecha() const;
    bool ValidarFecha() const;
};
