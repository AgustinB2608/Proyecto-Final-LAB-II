#pragma once

#include "../Productos/ProductosManager.h"
#include "../Clientes\ClientesManager.h"

//NO SUPE COMO AGREGAR EL INCLUDE DE RESERVASMANAGER :(

class MenuManager{

private:
    ProductoManager ProdManager;
    ClienteManager ClientManager;



public:
    void menu();



};
