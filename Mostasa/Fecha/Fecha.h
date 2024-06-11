#pragma once
#include <iostream>
#include <string.h>
class Fecha
{
  private:
    int _dia;
    int _mes;
    int _anio;

  public:
    Fecha(int dia=0,int mes=0,int anio=0);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    void CargarFecha();
    void MostrarFecha();
    bool ValidarFecha();

};
