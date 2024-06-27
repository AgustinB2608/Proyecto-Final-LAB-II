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
    int Y = 7; // Eje Y
    int X2 = ObtenerCentroConsola();

    DibujarTitulo("CLIENTE NUEVO", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General

    // Ingreso de ID
    do {
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
        DibujarTitulo("CLIENTE NUEVO", 3);
        MostrarOpcionMenu("Ingresar el ID:", Y);
        rlutil::locate(X2, Y + 2);
        std::cin >> ID;
        std::cin.ignore(); // Limpiar el buffer de entrada
        if (ClienteArc.buscar(ID) > -1) {
            MostrarError("Ya existe un cliente con ese ID.", Y + 5);}
        cliente.setIDCliente(ID);
    } while (cliente.getIDCliente() == -1 || ClienteArc.buscar(ID) > -1);

    // Ingreso de Nombre
    do {
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
        DibujarTitulo("CLIENTE NUEVO", 3);
        MostrarOpcionMenu("Ingresar el Nombre:", Y);
        rlutil::locate(X2, Y + 2);
        std::getline(std::cin, Nombre);
        if (Nombre.length() > 30 || tieneDigitos(Nombre) || Nombre.empty()) {
            MostrarError("Nombre invalido. Debe tener menos de 30 caracteres, no contener digitos y no estar vacio.", Y + 5);}
    } while (Nombre.length() > 30 || tieneDigitos(Nombre) || Nombre.empty());
    cliente.setNombreCliente(Nombre);

    // Ingreso de CORREO
    do {
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
        DibujarTitulo("CLIENTE NUEVO", 3);
        MostrarOpcionMenu("Ingresar el Email:", Y);
        rlutil::locate(X2, Y + 2);
        std::getline(std::cin, Email);
        if (!validarEmail(Email) || Email.empty()) {
            MostrarError("Email invalido. Debe ser example@example.com", Y + 5);}
    } while (!validarEmail(Email) || Email.empty());
    cliente.setEmailCliente(Email);

    // Ingreso de CELULAR
    do {
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
        DibujarTitulo("CLIENTE NUEVO", 3);
        MostrarOpcionMenu("Ingresar el Numero de Telefono:", Y);
        rlutil::locate(X2, Y + 2);
        std::getline(std::cin, Telefono);
        if (Telefono.length() < 10 || Telefono.length() > 15 || Telefono.empty()) {
            MostrarError("Numero de Telefono invalido. Debe tener entre 10 y 15 digitos y no estar vacio.", Y + 5);}
    } while (Telefono.length() < 10 || Telefono.length() > 15 || Telefono.empty());
    cliente.setTelefonoCliente(Telefono);

    // Ingreso de DNI
    do {
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
        DibujarTitulo("CLIENTE NUEVO", 3);
        MostrarOpcionMenu("Ingresar el DNI:", Y);
        rlutil::locate(X2, Y + 2);
        std::getline(std::cin, DNI);
        cliente.setDNICliente(DNI);
        if (DNI.length() != 8 || DNI.empty() || cliente.getDNICliente() == "Sin DNI") {
            MostrarError("DNI invalido. Debe tener 8 digitos y no estar vacio.", Y + 5);}
    } while (DNI.length() != 8 || DNI.empty() || cliente.getDNICliente() == "Sin DNI");

    // Ingreso de FECHA
        rlutil::cls();
        MostrarOpcionMenu("Ingresar la Fecha:", Y);
        fecha.CargarFechaCliente();
        cliente.setFechaCreacion(fecha);

    cliente.setActivo(true);//Dar de alta CLIENTE

    return cliente;
}

void ClienteManager::Cargar() {
    Cliente C = Crear();
    if (ClienteArc.guardar(C)) {
    MostrarConfirmacion("Cliente dado de alta Correctamente.", 12);}
    else {MostrarError("No se pudo dar de alta al Cliente.", 12);}
}

void ClienteManager::bajaLogica() {
    Cliente C;
    int ID, pos;
    int X2 = ObtenerCentroConsola();

        rlutil::setColor(4);
        DibujarRecuadro(X2-11,2,21,3);//Recuadro Opcion DAR DE BAJA
        rlutil::setColor(15);
        DibujarTitulo("DAR DE BAJA CLIENTE", 3);

        DibujarRecuadro(X2-23,6,46,6);//Recuadro General
        DibujarTitulo("Ingresar ID:", 7);
        rlutil::locate(X2,9);
        cin >> ID;

    pos = ClienteArc.buscar(ID);

    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        C.setActivo(false);
        if (ClienteArc.Modificar(C, pos)) {
            MostrarConfirmacion("Cliente dado de baja Correctamente.", 12);
        } else {
            MostrarError("No se pudo dar de baja al Cliente.", 12);
        }
    } else {
        MostrarError("Este cliente no existe.", 12);
    }
}

void ClienteManager::OrdenarClientesPorID(Cliente* clientes, int cantreg) {
    for (int i = 0; i < cantreg - 1; i++) { ///Controla el num de pasadas necesarias para ordenar el vector./cantreg - 1 veces porque después de cantreg - 1 pasadas, estara yodo ordenado
        ///*Ciclo interno* que recorre desde el inicio hasta el ultimo elemento no ordenado
        for (int j = 0; j < cantreg - i - 1; j++) {
            if (clientes[j].getIDCliente() > clientes[j + 1].getIDCliente()) {
                /// Si ID actual es mayor que el siguiente, intercambiar los dos elementos
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}

void ClienteManager::Listar() {
    int cantreg = ClienteArc.getCantidadRegistros();
    if (cantreg == 0) {
        MostrarError("No hay registros para mostrar.",2);
        return;
    }

    Cliente* clientes = new Cliente[cantreg];

    // Cargar todos los registros en el vector dinámico
    for (int i = 0; i < cantreg; i++) {
        clientes[i] = ClienteArc.leer(i);
    }

    // Ordenar de menor a mayor con la función
    OrdenarClientesPorID(clientes, cantreg);

    // Contar la cantidad de registros activos
    int activos = 0;
    for (int i = 0; i < cantreg; i++) {
        if (clientes[i].getActivo()) {
            activos++;
        }
    }

    int registrosPorPagina = 2; // Configuración para mostrar X cantidad de registros (2 entran bien)
    int paginaActual = 0;
    int totalPaginas = (activos + registrosPorPagina - 1) / registrosPorPagina; // Redondear hacia arriba

    while (true) {
        // Limpiar la pantalla
        rlutil::cls();

        // Mostrar la página actual de registros
        int X = ObtenerCentroConsola() - 12;
        int Y = 4;
        int inicio = paginaActual * registrosPorPagina;
        int fin = std::min(inicio + registrosPorPagina, activos);
        int registrosMostrados = 0;
        int registrosActivosMostrados = 0;

        for (int i = 0; i < cantreg && registrosActivosMostrados < fin; i++) {
            if (clientes[i].getActivo()) {
                if (registrosActivosMostrados >= inicio && registrosActivosMostrados < fin) {
                    MostrarALL(clientes[i], X, Y);
                    Y += 9;
                    registrosMostrados++;
                }
                registrosActivosMostrados++;
            }
        }

        // Mostrar la cantidad de registros activos
        int XXX = ObtenerPosicionXCentro("MOSTRANDO X CLIENTES");
        rlutil::locate(XXX, 2);
        std::cout << "MOSTRANDO " << activos << "  CLIENTES";
        rlutil::setColor(4);
        DibujarRecuadro(XXX-1,1,23,3);//Recuadro Opcion MOSTRANDO CLIENTES
        rlutil::setColor(15);



        // Mostrar información de la página
        int XX = ObtenerPosicionXCentro("Pagina X/X - Use las flechas para navegar");
        rlutil::locate(XX, rlutil::trows() - 2); //trows es de rlutil, es para que te devuelva la cantidad de filas de la consola
        std::cout << "Pagina " << (paginaActual + 1) << " de " << totalPaginas;
        rlutil::locate(XX, rlutil::trows() - 1);
        std::cout << "Use las flechas para navegar. ESC para salir.";

        // entrada del usuario
        int key = rlutil::getkey();
        if (key == rlutil::KEY_RIGHT && paginaActual < totalPaginas - 1) {
            paginaActual++;
        } else if (key == rlutil::KEY_LEFT && paginaActual > 0) {
            paginaActual--;
        } else if (key == rlutil::KEY_ESCAPE) {
            break; // Salir si se presiona ESC
        }
    }

    delete[] clientes;
}

void ClienteManager::MostrarALL(Cliente C, int X, int &Y) {
    rlutil::locate(X, Y + 1);
    cout << "ID: " << C.getIDCliente() << endl;
    rlutil::locate(X, Y + 2);
    cout << "Nombre: " << C.getNombreCliente() << endl;
    rlutil::locate(X, Y + 3);
    cout << "Email: " << C.getEmailCliente() << endl;
    rlutil::locate(X, Y + 4);
    cout << "Telefono: " << C.getTelefonoCliente() << endl;
    rlutil::locate(X, Y + 5);
    cout << "DNI: " << C.getDNICliente() << endl;
    rlutil::locate(X, Y + 6);
    cout << "Fecha de Registro: ";
    C.getFechaCreacion().MostrarFecha();
    rlutil::locate(X, Y + 7);
    cout << "Activo: " << (C.getActivo() ? "Si" : "No") << endl;
    rlutil::locate(X, Y + 8);
    cout << "-----------------------------" << endl;

    Y += 0; // Incrementar Y para la siguiente entrada
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
    int ID, pos;
    int Y = 7; // Eje Y
    int X2 = ObtenerCentroConsola();

    rlutil::cls();
    rlutil::setColor(4);
    DibujarRecuadro(X2-13,2,25,3);
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);
    DibujarTitulo("MODIFICAR DATOS CLIENTE", 3);
    MostrarOpcionMenu("Ingresar ID:", Y);
    rlutil::locate(X2, Y + 2);
    std::cin >> ID;
    std::cin.ignore();
    pos = ClienteArc.buscar(ID);

    if (pos >= 0) {
        C = ClienteArc.leer(pos);

        std::string Nombre, Email, Telefono, DNI;
        Fecha fecha;

        do {
            rlutil::cls();
            rlutil::setColor(4);
            DibujarRecuadro(X2-13,2,25,3);
            rlutil::setColor(15);
            DibujarRecuadro(X2-23,Y-1,46,6);
            DibujarTitulo("MODIFICAR DATOS CLIENTE", 3);
            MostrarOpcionMenu("Modificar Nombre (actual: " + C.getNombreCliente() + "):", Y);
            rlutil::locate(X2, Y + 2);
            std::getline(std::cin, Nombre);
            if (Nombre.length() > 30 || tieneDigitos(Nombre) || Nombre.empty()) {
                MostrarError("Nombre invalido. Debe tener menos de 30 caracteres, no contener digitos y no estar vacio.", Y + 5);}
        } while (Nombre.length() > 30 || tieneDigitos(Nombre) || Nombre.empty());
        C.setNombreCliente(Nombre);

        do {
            rlutil::cls();
            rlutil::setColor(4);
            DibujarRecuadro(X2-13,2,25,3);
            rlutil::setColor(15);
            DibujarRecuadro(X2-23,Y-1,46,6);
            DibujarTitulo("MODIFICAR DATOS CLIENTE", 3);
            MostrarOpcionMenu("Modificar Email (actual: " + C.getEmailCliente() + "):", Y);
            rlutil::locate(X2, Y + 2);
            std::getline(std::cin, Email);
            if (!validarEmail(Email) || Email.empty()) {
                MostrarError("Email invalido. Debe ser example@example.com", Y + 5);}
        } while (!validarEmail(Email) || Email.empty());
        C.setEmailCliente(Email);

        do {
            rlutil::cls();
            rlutil::setColor(4);
            DibujarRecuadro(X2-13,2,25,3);
            rlutil::setColor(15);
            DibujarRecuadro(X2-23,Y-1,46,6);
            DibujarTitulo("MODIFICAR DATOS CLIENTE", 3);
            MostrarOpcionMenu("Modificar Telefono (actual: " + C.getTelefonoCliente() + "):", Y);
            rlutil::locate(X2, Y + 2);
            std::getline(std::cin, Telefono);
            if (Telefono.length() < 10 || Telefono.length() > 15 || Telefono.empty()) {
                MostrarError("Numero de Telefono invalido. Debe tener entre 10 y 15 digitos y no estar vacio.", Y + 5);}
        } while (Telefono.length() < 10 || Telefono.length() > 15 || Telefono.empty());
        C.setTelefonoCliente(Telefono);

        do {
            rlutil::cls();
            rlutil::setColor(4);
            DibujarRecuadro(X2-13,2,25,3);
            rlutil::setColor(15);
            DibujarRecuadro(X2-23,Y-1,46,6);
            DibujarTitulo("MODIFICAR DATOS CLIENTE", 3);
            MostrarOpcionMenu("Modificar DNI (actual: " + C.getDNICliente() + "):", Y);
            rlutil::locate(X2, Y + 2);
            std::getline(std::cin, DNI);
            if (DNI.length() != 8 || DNI.empty()) {
                MostrarError("DNI invalido. Debe tener 8 digitos y no estar vacio.", Y + 5);}
        } while (DNI.length() != 8 || DNI.empty());
        C.setDNICliente(DNI);

        rlutil::cls();
        MostrarOpcionMenu("Modificar Fecha:", Y);
        fecha.CargarFechaCliente();
        C.setFechaCreacion(fecha);

        if (ClienteArc.Modificar(C, pos)) {
            MostrarConfirmacion("Modificado correctamente", Y + 5);
        } else {
            MostrarError("No se pudo modificar", Y + 5);
        }
    } else {
        MostrarError("No se pudo modificar, el cliente no existe", Y + 5);
    }
}


void ClienteManager::Buscar() {
    int pos, ID;
    Cliente C;

    int X = ObtenerCentroConsola();

    DibujarTitulo("BUSQUEDA POR ID", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X-9,2,17,3);//Recuadro Opcion BUSCAR POR ID
    rlutil::setColor(15);


    DibujarRecuadro(X-23,6,46,6);//Recuadro General
    rlutil::locate(X,1);

    DibujarTitulo("Ingrese el ID del Cliente:", 7);
    rlutil::locate(X, 9);
    cin >> ID;

    rlutil::cls();
    pos = ClienteArc.buscar(ID);
    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            Mostrar(C);
        } else {
            MostrarError("Este ID esta dado de Baja.",12);
        }
    } else {
        MostrarError("No se encontro el ID.",12);
    }
}

void ClienteManager::BuscarPorDNI() {
    std::string DNI;
    int pos;
    Cliente C;

    int X = ObtenerCentroConsola();

    DibujarTitulo("BUSQUEDA POR DNI", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X-9,2,18,3);//Recuadro Opcion BUSCAR POR ID
    rlutil::setColor(15);

    DibujarRecuadro(X-23,6,46,6);//Recuadro General

    DibujarTitulo("Ingrese el DNI del Cliente:",7);
    rlutil::locate(X,9);
    cin >> DNI;

    pos = ClienteArc.buscarPorDNI(DNI);
    if (pos >= 0) {
        C = ClienteArc.leer(pos);
        if (C.getActivo()) {
            rlutil::setColor(2);
            cout << "El DNI "<<DNI<<" Coincide con el ID: "<<C.getIDCliente() << endl;
            rlutil::setColor(15);
        } else {
            MostrarError("Cliente encontrado pero dado de baja",12);
        }
        } else {
            MostrarError("No se encontro ningun cliente con ese DNI",12);
        }
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
                        MostrarConfirmacion("Saliendo del Menu Clientes...",12);
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


