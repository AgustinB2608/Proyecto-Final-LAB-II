#pragma once
#include <iostream>
#include "Productos.h"
class ProductoArchivo{
    private:
    bool abrirA(std::string modo = "rb");
    void cerrarA();
    FILE *_p;
    std::string _Filename;
public:
    ProductoArchivo();
    ProductoArchivo(std::string Filename);
    bool guardar(Producto x);
    int buscar(int numE);
    Producto leer(int pos);
    int getCantidadRegistros();
    bool Modificar(Producto x,int pos);

    bool realizarCopia(std::string filename = "Productos.bak");
    bool restaurarCopia(std::string filename = "Productos.bak");

    bool ListarOrdenado();
    void CopiarRegVec(Producto v, int cant);
    void ordenarporhabitantes(Producto v,int cant);



};
