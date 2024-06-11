#include "ClientesManager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Cliente ClienteManager::Crear() {
    int ID;
    string Nombre, Email, Telefono;
    Fecha fecha;

    do {
        cout << "Ingrese ID: " << endl;
        cin >> ID;
        cliente.setIDCliente(ID);
    } while (cliente.getIDCliente() == -1);

    cin.ignore();
    do {
        cout << "Ingresar el Nombre: " << endl;
        getline(cin, Nombre);
        cliente.setNombreCliente(Nombre);
    } while (cliente.getNombreCliente().empty());

    do {
        cout << "Ingresar el Email: " << endl;
        getline(cin, Email);
        cliente.setEmailCliente(Email);
    } while (cliente.getEmailCliente().empty());

    do {
        cout << "Ingresar el Número de Teléfono: " << endl;
        getline(cin, Telefono);
        cliente.setTelefonoCliente(Telefono);
    } while (cliente.getTelefonoCliente().empty());

    cout << "Fecha: " << endl;
    fecha.CargarFecha();
    cliente.setFechaCreacion(fecha);

    cliente.setActivo(true);


    return cliente;
}

/*void ClienteManager::ListarClientes() {

    cliente.setActivo(false);

    if(cliente.getActivo()==true){

    for(int i=0; i < 5; i++){
        cout << "ID: " << cliente.getIDCliente() << endl;
        cout << "Nombre: " << cliente.getNombreCliente() << endl;
        cout << "Email: " << cliente.getEmailCliente() << endl;
        cout << "Telefono: " << cliente.getTelefonoCliente() << endl;
        cliente.getFechaCreacion().MostrarFecha();
        cout << "Activo: " << (cliente.getActivo() ? "Si" : "No") << endl;
        cout << "-----------------------------" << endl;
    }
    }

}*/


void ClienteManager::Menu() {
    int Op;
    system("cls");
    while (true) {
        cout << "---- MENU CLIENTES ----" << endl;
        cout << "1 - AGREGAR CLIENTE" << endl;
        cout << "2 - ELIMINAR CLIENTE" << endl;
        cout << "3 - MODIFICAR" << endl;
        cout << "4 - LISTAR CLIENTES" << endl;
        cout << "5 - BUSCAR POR ID" << endl;
        cout << "0 - VOLVER" << endl;
        cin >> Op;
        switch (Op) {
        case 1:
            Crear();
            break;
        case 2:
            // bajaLogica();
            break;
        case 3:
            // modificar();
            break;
        case 4:
            //ListarClientes();
            break;
        case 5:
            // buscarPorID();
            break;
        case 0:
            return;
        }
        system("pause");
        system("cls");
    }
}
