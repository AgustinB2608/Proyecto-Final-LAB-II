#pragma once
#include <iostream>
#include "../Reservas/Reservas.h"
#include "Fecha.h"
class ReservaArchivo{
    private:
    bool abrirA(std::string modo = "rb");
    void cerrarA();
    FILE *_p;
    std::string _Filename;
public:
    ReservaArchivo();
    ReservaArchivo(std::string Filename);
    bool guardar(Reserva x);
   // int buscar(Fecha fecha);
    int buscar(int Numero);
    Reserva leer(int pos);
    int getCantidadRegistros();
    bool Modificar(Reserva x,int pos);

    bool realizarCopia(const std::string& filename = "Reservas.bak");
    bool restaurarCopia(const std::string& filename = "Reservas.bak");






};
