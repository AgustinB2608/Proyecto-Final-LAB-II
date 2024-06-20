#pragma once

#include "../Productos/ProductosManager.h"
#include "../Clientes\ClientesManager.h"

class MenuManager{

private:
    ProductoManager ProdManager;
    ClienteManager ClientManager;


public:
    void menu();



};
