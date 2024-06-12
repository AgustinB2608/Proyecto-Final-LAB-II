#include "../Clientes/ClientesManager.h"
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

void ClienteManager::Cargar() {
    Cliente C = Crear();

    if (ClienteArc.guardar(C)) {
        cout << "Guardado" << endl;
    } else {
        cout << "No Guardado" << endl;
    }
}

void ClienteManager::bajaLogica() {
    Cliente C;
    int ID, pos;
    cout << "Ingresar ID: " << endl;
    cin >> ID;

    pos = ClienteArc.buscar(ID);

    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        C.setActivo(false);
        if (ClienteArc.Modificar(C, pos)) {
            cout << "Eliminado" << endl;
        } else {
            cout << "No eliminado" << endl;
        }
    } else {
        cout << "No existe." << endl;
    }
}

void ClienteManager::Listar() {
    Cliente C;
    int cantreg = ClienteArc.getCantidadRegistros();

    for (int i = 0; i < cantreg; i++) {
        C = ClienteArc.leer(i);
        Mostrar(C);
    }
}

void ClienteManager::Mostrar(Cliente C) {
    if (C.getActivo()) {
        cout << "ID: " << C.getIDCliente() << endl;
        cout << "Nombre: " << C.getNombreCliente() << endl;
        cout << "Email: " << C.getEmailCliente() << endl;
        cout << "Telefono: " << C.getTelefonoCliente() << endl;
        C.getFechaCreacion().MostrarFecha();
        cout << "Activo: " << (C.getActivo() ? "Si" : "No") << endl;
        cout << "-----------------------------" << endl;
    }
}

void ClienteManager::Modificar() {
    Cliente C;
    C.setActivo(false);
    int ID, pos;
    cout << "Ingresar ID: " << endl;
    cin >> ID;

    pos = ClienteArc.buscar(ID);

    if (pos >= 0) {
        C = ClienteArc.leer(pos);

        string Nombre, Email, Telefono;
        Fecha fecha;

        cout << "Modificar Nombre (actual: " << C.getNombreCliente() << "): " << endl;
        cin.ignore();
        getline(cin, Nombre);
        C.setNombreCliente(Nombre);

        cout << "Modificar Email (actual: " << C.getEmailCliente() << "): " << endl;
        getline(cin, Email);
        C.setEmailCliente(Email);

        cout << "Modificar Teléfono (actual: " << C.getTelefonoCliente() << "): " << endl;
        getline(cin, Telefono);
        C.setTelefonoCliente(Telefono);

        cout << "Fecha: " << endl;
        fecha.CargarFecha();
        C.setFechaCreacion(fecha);

        if (ClienteArc.Modificar(C, pos)) {
            cout << "Modificado correctamente" << endl;
        } else {
            cout << "No se pudo modificar" << endl;
        }
    } else {
        cout << "No se pudo modificar, el cliente no existe" << endl;
    }
}

void ClienteManager::Buscar() {
    int pos, ID;
    Cliente C;
    cout << "Ingresar el ID  " << endl;
    cin >> ID;
    pos = ClienteArc.buscar(ID);
    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            Mostrar(C);
        } else {
            cout << "Dado de baja" << endl;
        }
    } else {
        cout << "No se encuentra" << endl;
    }
}

void ClienteManager::Menu() {
    int Op;
    system("cls");
    Cliente c;
    c.setActivo(false);
    while (true) {
        cout << "---- MENU CLIENTES ----" << endl;
        cout << "\n" << endl;
        cout << "1 - AÑADIR CLIENTE" << endl;
        cout << "2 - ELIMINAR CLIENTE" << endl;
        cout << "3 - MODIFICAR DATOS DE CLIENTE" << endl;
        cout << "4 - LISTAR CLIENTES" << endl;
        cout << "5 - BUSCAR POR ID" << endl;
        cout << "0 - VOLVER" << endl;
        cout << "\n" << endl;
        cout << "-----------------------" << endl;
        cin >> Op;
        switch (Op) {
        case 1:
            Cargar();
            break;
        case 2:
            bajaLogica();
            break;
        case 3:
            Modificar();
            break;
        case 4:
            Listar();
            break;
        case 5:
            //Buscar();
             cout << "Activo: " << (c.getActivo() ? "Si" : "No") << endl;


            break;
        case 0:
            return;
        }
        system("pause");
        system("cls");
    }
}
