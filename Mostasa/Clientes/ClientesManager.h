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
    void MostrarALL(Cliente C, int X, int &Y);
    void Modificar();
    void Buscar();
    void OrdenarClientesPorID(Cliente* clientes, int cantreg);
    void Listar();
    void BuscarPorDNI();
    void CopiaSeguridad();
    void RestaurarCopiaSeguridad();



};
