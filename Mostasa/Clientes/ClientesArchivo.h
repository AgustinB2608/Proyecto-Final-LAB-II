#pragma once

#include <string>
#include <cstdio>
#include "../Clientes\Clientes.h"

class ClienteArchivo {
private:
    FILE *_p;
    std::string _Filename;

    bool abrirA(const char* modo);
    void cerrarA();

public:
    ClienteArchivo();
    ClienteArchivo(std::string Filename);

    bool guardar(Cliente x);
    int buscar(int numE);
    Cliente leer(int pos);
    int getCantidadRegistros();
    bool Modificar(Cliente x, int pos);

    bool realizarCopia(std::string filename = "Clientes.bak");
    bool restaurarCopia(std::string filename = "Clientes.bak");
};
