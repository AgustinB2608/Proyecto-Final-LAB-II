#include "../Clientes/ClientesManager.h"
#include "../Funciones/ValidacionesGlobales.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#include "../Funciones\FuncionesGraficas\globales.h"


Cliente ClienteManager::Crear() {
    int ID;
    std::string Nombre, Email, Telefono, DNI;
    Fecha fecha;
    Cliente cliente;
    int Y = 1;
    int X = ObtenerPosicionXCentro("|--------------------------------------|");
    int X2 = ObtenerCentroConsola();
    DibujarTitulo("- DATOS DEL CLIENTE NUEVO -");
    RecuadroDatos(X,Y+1,'-','|');
    do {
        MostrarOpcionMenu("Ingresar el ID:", Y);
        rlutil::locate(X2,Y+3);
        std::cin >> ID;
        if (ClienteArc.buscar(ID) > -1) {
            std::cout << "Ya existe un cliente con ese ID" << std::endl;
        }
        cliente.setIDCliente(ID);
    } while (cliente.getIDCliente() == -1 || ClienteArc.buscar(ID) > -1);

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

void ClienteManager::MostrarALL(Cliente C) {
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
void ClienteManager::Mostrar(Cliente C) {
    if (C.getActivo()) {
        int X = ObtenerCentroConsola()- 12;
        int Y = 4;

        int XX = ObtenerPosicionXCentro("MOSTRANDO CLIENTE ID: ");
        rlutil::locate(XX,3);
        cout<<"MOSTRANDO CLIENTE ID: "<< C.getIDCliente()<<endl;

        rlutil::locate(X,Y+1);
        cout << "-----------------------------" << endl;
        rlutil::locate(X,Y+2);
        cout << "Nombre: " << C.getNombreCliente() << endl;
        rlutil::locate(X,Y+4);
        cout << "Email: " << C.getEmailCliente() << endl;
        rlutil::locate(X,Y+6);
        cout << "Telefono: " << C.getTelefonoCliente() << endl;
        rlutil::locate(X,Y+8);
        cout << "DNI: " << C.getDNICliente() << endl;
        rlutil::locate(X,Y+10);
        cout << "Fecha de Registro: ";
        rlutil::locate(X,Y+12);
        C.getFechaCreacion().MostrarFecha();
        rlutil::locate(X,Y+14);
        cout << "Activo: " << (C.getActivo() ? "Si" : "No") << endl;
        rlutil::locate(X,Y+15);
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
    rlutil::hidecursor();
    int X = ObtenerPosicionXCentro("BUSQUEDA POR ID");
    int X2 = ObtenerPosicionXCentro("Ingrese el ID del Cliente.");
    int X3 = ObtenerCentroConsola();
    int X4 = ObtenerPosicionXCentro("ID Dado de baja");
    int X5 = ObtenerPosicionXCentro("No se encontro el ID");
    rlutil::locate(X,1);
    cout<<"BUSQUEDA POR ID";
    rlutil::locate(X2,3);
    cout << "Ingrese el ID del Cliente." << endl;
    rlutil::locate(X3,5);
    cin >> ID;
    rlutil::cls();
    pos = ClienteArc.buscar(ID);
    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            Mostrar(C);
        } else {
            rlutil::locate(X4,3);
            cout << "ID Dado de baja" << endl;
        }
    } else {
        rlutil::locate(X5,3);
        cout << "No se encontro el ID" << endl;
    }
    int XX = ObtenerPosicionXCentro("Presione cualquier tecla para volver al Menu Principal.");
    rlutil::locate(XX,29);
    cout << "Presione cualquier tecla para volver al Menu Principal.";
    rlutil::anykey();
}

void ClienteManager::BuscarPorDNI() {
    std::string DNI;
    int pos;
    Cliente C;
    rlutil::hidecursor();
    int X = ObtenerPosicionXCentro("BUSQUEDA POR DNI");
    int X1 = ObtenerPosicionXCentro("XXXXXXXX");
    int X2 = ObtenerPosicionXCentro("Ingrese el DNI del Cliente.");
    int X3 = ObtenerPosicionXCentro("El DNI XXXXXXXX Coincide con el ID: ");
    int X4 = ObtenerPosicionXCentro("Cliente encontrado pero dado de baja");
    int X5 = ObtenerPosicionXCentro("No se encontró ningun cliente con ese DNI");
    rlutil::locate(X,1);
    cout<<"BUSQUEDA POR DNI";
    rlutil::locate(X2,3);
    cout << "Ingrese el DNI del Cliente.";
    rlutil::locate(X1-2,5);
    cout <<(char)175;
    rlutil::locate(X1+9,5);
    cout <<(char)174;
    rlutil::locate(X1,5);
    cin >> DNI;
    pos = ClienteArc.buscarPorDNI(DNI);
    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            rlutil::locate(X3,3);
            cout << "El DNI "<<DNI<<" Coincide con el ID: "<<C.getIDCliente() << endl;
        } else {
            rlutil::locate(X4,3);
            cout << "Cliente encontrado pero dado de baja" << endl;
        }
    } else {
        rlutil::locate(X5,3);
        cout << "No se encontro ningun cliente con ese DNI" << endl;
    }

    int XX = ObtenerPosicionXCentro("Presione cualquier tecla para volver al Menu Principal.");
    rlutil::locate(XX,29);
    cout << "Presione cualquier tecla para volver al Menu Principal.";
    rlutil::anykey();
}

void ClienteManager::CopiaSeguridad() {
    char opcion;
    int X = ObtenerPosicionXCentro("Realmente quiere realizar una copia de seguridad? Presione S/Si o N/No");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha realizado con exito.");
    int X2 = ObtenerPosicionXCentro("No se pudo realizar la copia de seguridad.");
    int X3 = ObtenerPosicionXCentro("No se ha realizado la copia.");
    rlutil::locate(X,2);
    std::cout << "Realmente quiere realizar una copia de seguridad? Presione S/Si o N/No" << std::endl;
    do {
        opcion = rlutil::getkey();
        opcion = toupper(opcion); // Convertir a mayúsculas para facilitar la comparación
    } while (opcion != 'S' && opcion != 'N');
    rlutil::cls();
    if (opcion == 'S') {
        if (ClienteArc.realizarCopia("Clientes.bkp")) {
                rlutil::locate(X1,2);
            std::cout << "La copia de seguridad se ha realizado con exito." << std::endl;
        } else {
            rlutil::locate(X2,2);
            std::cout << "No se pudo realizar la copia de seguridad." << std::endl;
        }
    } else {
        rlutil::locate(X3,2);
        std::cout << "No se ha realizado la copia." << std::endl;
    }
    rlutil::anykey(); // Esperar a que se presione cualquier tecla para continuar
    rlutil::cls();    // Limpiar la pantalla nuevamente si es necesario
}
void ClienteManager::RestaurarCopiaSeguridad() {
    char opcion;
    int X = ObtenerPosicionXCentro("Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha restaurado con exito.");
    int X2 = ObtenerPosicionXCentro("No se pudo restaurar la copia de seguridad.");
    int X3 = ObtenerPosicionXCentro("No se ha restaurado la copia.");
    rlutil::locate(X,2);
    std::cout << "Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No" << std::endl;
    do {
        opcion = rlutil::getkey();
        opcion = toupper(opcion);
    } while (opcion != 'S' && opcion != 'N');
    rlutil::cls();
    if (opcion == 'S') {
        if (ClienteArc.restaurarCopia("Clientes.bkp")) {
            rlutil::locate(X1,2);
            std::cout << "La copia de seguridad se ha restaurado con exito." << std::endl;
        } else {
            rlutil::locate(X2,2);
            std::cout << "No se pudo restaurar la copia de seguridad." << std::endl;
        }
    } else {
        rlutil::locate(X3,2);
        std::cout << "No se ha restaurado la copia." << std::endl;
    }
    rlutil::anykey();
    rlutil::cls();
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
                        CopiaSeguridad();
                        break;
                    case 8:
                        rlutil::cls();
                        RestaurarCopiaSeguridad();
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


