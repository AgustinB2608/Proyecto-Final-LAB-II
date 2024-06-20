#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED
#include "../Interfaz/rlutil.h"

int ObtenerPosicionXCentro(const std::string& texto) {
    int anchoConsola = rlutil::tcols();
    int longitudTexto = static_cast<int>(texto.length());

    int posXCentro = (anchoConsola - longitudTexto) / 2;

    return posXCentro;
}

void MostrarMenuClientes(int opcion) {
    rlutil::setColor(rlutil::COLOR::WHITE);
    int posXTitulo = ObtenerPosicionXCentro("MOSTASA CLIENTES");
    rlutil::locate(posXTitulo, 3);
    cout << "MOSTASA CLIENTES" << endl << endl;

    int posY = 6;
    int posXCentro = ObtenerPosicionXCentro("1 - AGREGAR CLIENTE");

    rlutil::setColor(opcion == 1 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY);
    cout << "1 - AGREGAR CLIENTE" << endl;

    rlutil::setColor(opcion == 2 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 1);
    cout << "2 - ELIMINAR CLIENTE" << endl;

    rlutil::setColor(opcion == 3 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 2);
    cout << "3 - MODIFICAR DATOS DE CLIENTE" << endl;

    rlutil::setColor(opcion == 4 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 3);
    cout << "4 - LISTAR CLIENTES" << endl;

    rlutil::setColor(opcion == 5 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 4);
    cout << "5 - BUSCAR POR ID" << endl;

    rlutil::setColor(opcion == 6 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 5);
    cout << "6 - BUSCAR CLIENTE POR DNI" << endl;

    rlutil::setColor(opcion == 7 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 6);
    cout << "7 - OPCION 7" << endl;

    rlutil::setColor(opcion == 8 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 7);
    cout << "8 - OPCION 8" << endl;

    rlutil::setColor(opcion == 9 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 8);
    cout << "9 - SALIR" << endl;
}

#endif // GLOBALES_H_INCLUDED
