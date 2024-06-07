#pragma once
#include "Productos.h"
#include "ProductosArchivo.h"
class ProductoManager{
private:
    Producto Prod;
    ProductoArchivo ProdArch;
    void bajaLogica();
public:
    void Menu();
    void MenuCategorias();
    Producto Crear();
    void Cargar();


};
