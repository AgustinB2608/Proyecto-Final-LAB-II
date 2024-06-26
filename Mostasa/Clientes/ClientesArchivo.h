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
    int buscarPorDNI(const std::string& DNI);
    bool realizarCopia(const std::string& filename);
    bool restaurarCopia(const std::string& filename);
};
