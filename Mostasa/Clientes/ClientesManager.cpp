#include "../Clientes/ClientesManager.h"
#include "../Validaciones/ValidacionesGlobales.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#include "../Interfaz/globales.h"


Cliente ClienteManager::Crear() {
    int ID;
    std::string Nombre, Email, Telefono, DNI;
    Fecha fecha;
    Cliente cliente;

    do {
        std::cout << "Ingrese ID: " << std::endl;
        std::cin >> ID;
        cliente.setIDCliente(ID);
    } while (cliente.getIDCliente() == -1); //Valido mientras no sea negativo ni supere los limites.

    std::cin.ignore();

    do {
        std::cout << "Ingresar el Nombre: " << std::endl;
        std::getline(std::cin, Nombre);
    } while (Nombre.length() > 30 || tieneDigitos(Nombre) || Nombre.empty());//Valido mientras tenga menos de 30, no tenga digitos y no sea vacio.
    cliente.setNombreCliente(Nombre);

    do {
        std::cout << "Ingresar el Email: " << std::endl;
        std::getline(std::cin, Email);
    } while (!validarEmail(Email) || Email.empty());
    cliente.setEmailCliente(Email);

    do {
        std::cout << "Ingresar el Numero de Telefono: " << std::endl;
        std::getline(std::cin, Telefono);
    } while (Telefono.length() < 10 || Telefono.length() > 15 || Telefono.empty());//Valido mientras tenga entre 10 y 15 digitos(Tipico numero argentino) y no sea vacio.
    cliente.setTelefonoCliente(Telefono);

    do {
        std::cout << "Ingresar el DNI: " << std::endl;
        std::getline(std::cin, DNI);
        cliente.setDNICliente(DNI);
    } while (DNI.length() != 8 || DNI.empty() || cliente.getDNICliente() == "Sin DNI");//Valido mientras tenga mas de 8 digitos y no sea vacio.

    std::cout << "Ingrese la Fecha: " << std::endl;
    fecha.CargarFecha();
    cliente.setFechaCreacion(fecha);

    cliente.setActivo(true);

    return cliente;
}

void ClienteManager::Cargar() {
    Cliente C = Crear();

    if (ClienteArc.guardar(C)) {
        cout << "Cargado :)" << endl;
    } else {
        cout << "No Guardado :(" << endl;
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
            cout << "Dado de baja Correctamente." << endl;
        } else {
            cout << "Error. No se pudo dar de baja." << endl;
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
        cout << "DNI: " << C.getDNICliente() << endl;
        cout << "Fecha de Registro: ";
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

        string Nombre, Email, Telefono, DNI;
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

        cout << "Modificar DNI (actual: " << C.getDNICliente() << "): " << endl;
        getline(cin, DNI);
        C.setDNICliente(DNI);

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
    cout << "Ingresar el ID: " << endl;
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

void ClienteManager::BuscarPorDNI() {
    std::string DNI;
    int pos;
    Cliente C;

    cout << "Ingresar el DNI: ";
    cin >> DNI;

    pos = ClienteArc.buscarPorDNI(DNI);

    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            cout << "El DNI ingresado coincide con el Cliente ID: " << C.getIDCliente() << endl;
        } else {
            cout << "Cliente encontrado pero dado de baja" << endl;
        }
    } else {
        cout << "No se encontró ningún cliente con ese DNI" << endl;
    }
}

void ClienteManager::Menu() {
    int opcion = 1;
    do {
        rlutil::cls();
        rlutil::hidecursor();
        MostrarMenuClientes(opcion);

        int Key = rlutil::getkey();

        switch (Key) {
            case rlutil::KEY_UP:
                opcion--;
                if (opcion < 1) opcion = 9;
                break;
            case rlutil::KEY_DOWN:
                opcion++;
                if (opcion > 9) opcion = 1;
                break;
            case rlutil::KEY_ENTER:
                switch (opcion) {
                    case 1:
                        rlutil::cls();
                        Cargar();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        bajaLogica();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        Modificar();
                        rlutil::anykey();
                        break;
                    case 4:
                        rlutil::cls();
                        Listar();
                        rlutil::anykey();
                        break;
                    case 5:
                        rlutil::cls();
                        Buscar();
                        rlutil::anykey();
                        break;
                    case 6:
                        rlutil::cls();
                        BuscarPorDNI();
                        rlutil::anykey();
                        break;
                    case 7:
                        rlutil::cls();
                        //Opcion7();
                        break;
                    case 8:
                        rlutil::cls();
                        //Opcion8();
                        break;
                    case 9:
                        rlutil::cls();
                        cout << "Saliendo del Menu Clientes..." << endl;
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        opcion = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

    } while (opcion != 0);
}


