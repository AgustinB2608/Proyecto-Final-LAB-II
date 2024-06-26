#pragma once
#include "../Productos/Productos.h"
#include "../Productos/ProductosArchivo.h"
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
    void Listar();
    void Mostrar(Producto x, int X, int &Y);
    void Modificar();
    void Buscar();

    void ListarOrdenado();
    void CopiarRegVec(Producto v, int cant);
    void ordenarporPrecio(Producto *v,int cant);
    void copiaSeguridad();
    void restaurarCopiaSeguridad();

};
