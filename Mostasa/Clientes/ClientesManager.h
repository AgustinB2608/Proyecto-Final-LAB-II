#pragma once

#include "../Fecha/Fecha.h"
#include "../Clientes/Clientes.h"
#include "../Clientes/ClientesArchivo.h"

class ClienteManager{
private:
    Cliente cliente;
    ClienteArchivo ClienteArc;
    void bajaLogica();

public:
    void Menu();
    Cliente Crear();
    void Cargar();
    void ListarClientes();
    void Mostrar(Cliente x);
    void Modificar();
    void Buscar();
    void Listar();



};
