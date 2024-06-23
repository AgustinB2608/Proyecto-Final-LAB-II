#pragma once
#include "../Funciones\FuncionesGraficas\rlutil.h"


/*--------------------*/

int ObtenerPosicionXCentro(const std::string& texto) {
    int anchoConsola = rlutil::tcols();
    int longitudTexto = static_cast<int>(texto.length());

    int posXCentro = (anchoConsola - longitudTexto) / 2;

    return posXCentro;
}

void DibujarLineas(int x1, int y1, int x2, int y2, char symbol) {
    //Genera Lineas, siendo x1 La linea principal del Eje X
	for (int x = x1; x <= x2; x++) {//x2 Siendo el punto final de la linea x1
		for (int y = y1; y <= y2; y++) { //y1 Seria La linea del eje Y
			rlutil::locate(x, y);//y2 Siendo el punto final de la linea y2
			std::cout << symbol;//DIbujando el caracter seleccionado
		}
	}
}

void RecuadroDatos(int x, int y, char symbolHorizontal, char symbolVertical) {
    const int ANCHO = 40;
    const int ALTO = rlutil::trows() - 2; // Alto de la consola menos 2

    // Dibujar bordes horizontales superiores e inferiores
    DibujarLineas(x, y, x + ANCHO -1, y, symbolHorizontal); // Borde superior
    DibujarLineas(x, y + ALTO - 1, x + ANCHO - 1, y + ALTO - 1, symbolHorizontal); // Borde inferior

    // Dibujar bordes verticales izquierdo y derecho
    DibujarLineas(x, y + 1, x, y + ALTO - 2, symbolVertical); // Borde izquierdo
    DibujarLineas(x + ANCHO - 1, y + 1, x + ANCHO - 1, y + ALTO - 2, symbolVertical); // Borde derecho

    // Esquinas
    rlutil::locate(x, y-1); std::cout << symbolVertical; // Esquina superior izquierda
    rlutil::locate(x + ANCHO - 1, y-1); std::cout << symbolVertical; // Esquina superior derecha
    rlutil::locate(x, y + ALTO - 1); std::cout << symbolVertical; // Esquina inferior izquierda
    rlutil::locate(x + ANCHO - 1, y + ALTO - 1); std::cout << symbolVertical; // Esquina inferior derecha
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
    cout << "7 - REALIZAR COPIA DE SEGURIDAD" << endl;

    rlutil::setColor(opcion == 8 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 7);
    cout << "8 - RESTAURAR COPIA DE SEGURIDAD" << endl;

    rlutil::setColor(opcion == 9 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 8);
    cout << "9 - SALIR" << endl;
}

int ObtenerCentroConsola() {
    return rlutil::tcols() / 2;
}
void DibujarTitulo(const std::string& titulo) {
    int centroX = ObtenerCentroConsola();
    rlutil::locate(centroX - titulo.length() / 2, 1);
    std::cout << titulo << std::endl;
}
void DibujarRecuadroDatos(int ancho) {
    const int ALTO = 40 - 2; // Alto del recuadro, descontando 1 línea arriba y 1 línea abajo para el título

    int centroX = ObtenerCentroConsola();
    int inicioX = centroX - ancho / 2;
    int inicioY = rlutil::trows() / 2 - ALTO / 2;

    // Dibujar borde superior e inferior
    DibujarLineas(inicioX, inicioY, inicioX + ancho - 1, inicioY, '-'); // Borde superior
    DibujarLineas(inicioX, inicioY + ALTO - 1, inicioX + ancho - 1, inicioY + ALTO - 1, '-'); // Borde inferior

    // Dibujar bordes verticales izquierdo y derecho
    DibujarLineas(inicioX, inicioY + 1, inicioX, inicioY + ALTO - 2, '|'); // Borde izquierdo
    DibujarLineas(inicioX + ancho - 1, inicioY + 1, inicioX + ancho - 1, inicioY + ALTO - 2, '|'); // Borde derecho

    // Esquinas
    rlutil::locate(inicioX, inicioY); std::cout << '|'; // Esquina superior izquierda
    rlutil::locate(inicioX + ancho - 1, inicioY); std::cout << '|'; // Esquina superior derecha
    rlutil::locate(inicioX, inicioY + ALTO - 1); std::cout << '|'; // Esquina inferior izquierda
    rlutil::locate(inicioX + ancho - 1, inicioY + ALTO - 1); std::cout << '|'; // Esquina inferior derecha
}



void MostrarOpcionMenu(const std::string& opcion, int numeroOpcion) {
    int centroX = ObtenerCentroConsola();
    rlutil::locate(centroX - opcion.length() / 2, 3);
    std::cout << opcion << std::endl;
}



