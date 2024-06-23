#pragma once
#include <iostream>
#include <string>
#include "../Fecha/Fecha.h"
class Reserva{
private:
    int  _Numero;//del 1 al 35
    Fecha _Fecha; ///habria que ver como hacerle una validacion a la fecha
    int  _NumeroMesa;// del 1 al 50
    int _NumeroPersonas;// de 1 a 12
    int _IDCliente;
    int _IDProducto; ///estaria buenop ver una manera para que con un vector dinamico puedas poner la cantidad de productos que se quieren reservar y dewspues poner los productos reservados por id
    bool _Estado;
public:
    Reserva();
    Reserva(int Numero,Fecha fecha, int NumeroMesa, int NumeroPersonas, int IDCliente,  int IDProducto, bool Estado);
    ///setters
    void setNumero(int Numero);
    void setFecha(Fecha Fecha);
    void setNumeroMesa(int NumeroMesa);
    void setNumeroPersonas(int NumeroPersonas);
    void setIDCliente(int IDCliente);
    void setIDProducto(int IDProducto);
    void setEstado(bool Estado);
    ///getters
    int getNumero();
    Fecha getFecha();
    int getNumeroMesa();
    int getNumeroPersonas();
    int getIDCliente();
    int getIDProducto();
    bool getEstado();

};
