#pragma once

#include "../Fecha/Fecha.h"
#include "../Clientes/Clientes.h"

class ClienteManager{
private:
    Cliente cliente;

    //void bajaLogica();

public:
    void Menu();
    Cliente Crear();
    void Cargar();
    void ListarClientes();


};
