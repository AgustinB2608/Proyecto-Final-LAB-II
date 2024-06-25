#pragma once

#include "../Productos/ProductosManager.h"
#include "../Clientes\ClientesManager.h"
#include "../Reservas/ReservasManager.h"

class MenuManager{

private:
    ProductoManager ProdManager;
    ClienteManager ClientManager;
    ReservaManager ReservaManager;
public:
    void Menu();
};
