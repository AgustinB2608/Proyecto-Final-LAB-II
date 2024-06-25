#pragma once
#include "../Funciones\FuncionesGraficas\rlutil.h"


/*--------------------*/
///Prototipos Coordenadas
int ObtenerCentroConsola();

inline int ObtenerPosicionXCentro(const std::string& texto) {
    int anchoConsola = rlutil::tcols();
    int longitudTexto = static_cast<int>(texto.length());

    int posXCentro = (anchoConsola - longitudTexto) / 2;

    return posXCentro;
}

inline void DibujarLineas(int x1, int y1, int x2, int y2, char symbol) {
    //Genera Lineas, siendo x1 La linea principal del Eje X
	for (int x = x1; x <= x2; x++) {//x2 Siendo el punto final de la linea x1
		for (int y = y1; y <= y2; y++) { //y1 Seria La linea del eje Y
			rlutil::locate(x, y);//y2 Siendo el punto final de la linea y2
			std::cout << symbol;//DIbujando el caracter seleccionado
		}
	}
}

inline void RecuadroDatos(int x, int y, char symbolHorizontal, char symbolVertical) {
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

inline void Titulo(){
    int X = 20;
    int Y = 2;
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(X,Y);
    std::cout << "::::    ::::   ::::::::   ::::::::  :::::::::::     :::      ::::::::      :::     " << std::endl;
    rlutil::locate(X,Y+1);
    std::cout << "+:+:+: :+:+:+ :+:    :+: :+:    :+:     :+:       :+: :+:   :+:    :+:   :+: :+:   " << std::endl;
    rlutil::locate(X,Y+2);
    std::cout << "+:+ +:+:+ +:+ +:+    +:+ +:+            +:+      +:+   +:+  +:+         +:+   +:+  " << std::endl;
    rlutil::locate(X,Y+3);
    std::cout << "+#+  +:+  +#+ +#+    +:+ +#++:++#++     +#+     +#++:++#++: +#++:++#++ +#++:++#++: " << std::endl;
    rlutil::locate(X,Y+4);
    std::cout << "+#+       +#+ +#+    +#+        +#+     +#+     +#+     +#+        +#+ +#+     +#+ " << std::endl;
    rlutil::locate(X,Y+5);
    std::cout << "#+#       #+# #+#    #+# #+#    #+#     #+#     #+#     #+# #+#    #+# #+#     #+# " << std::endl;
    rlutil::locate(X,Y+6);
    std::cout << "###       ###  ########   ########      ###     ###     ###  ########  ###     ### " << std::endl;

}

inline void MostrarMenuPrincipal (int opcion) {
    Titulo();
    rlutil::setColor(rlutil::COLOR::WHITE);
    int posXTitulo = ObtenerPosicionXCentro("###       ###  ########   ########      ###     ###     ###  ########  ###     ### ");

    int posY = 14;
    int posXCentro = ObtenerPosicionXCentro("1 - AGREGAR CLIENTE");

    rlutil::setColor(opcion == 1 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY - 1);
    std::cout << "MENU PRODUCTOS" << std::endl;

    rlutil::setColor(opcion == 2 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 1);
    std::cout << "MENU CLIENTES" << std::endl;

    rlutil::setColor(opcion == 3 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 3);
    std::cout << "MENU RESERVAS" << std::endl;

    rlutil::setColor(opcion == 4 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 5);
    std::cout << "MENU CONFIGURACION" << std::endl;

    rlutil::setColor(opcion == 5 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 7);
    std::cout << "XXXXXXXXXXXXXXXXXX" << std::endl;

    rlutil::setColor(opcion == 6 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 9);
    std::cout << "SALIR" << std::endl;

    rlutil::setColor(rlutil::COLOR::GREY);
    rlutil::locate(108, 30);
    std::cout << "25/06/2024";


}

inline void MostrarMenuClientes(int opcion) {
    rlutil::setColor(rlutil::COLOR::WHITE);
    int posXTitulo = ObtenerPosicionXCentro("MOSTASA CLIENTES");
    rlutil::locate(posXTitulo, 3);
    std::cout << "MOSTASA CLIENTES" << std::endl << std::endl;

    int posY = 10;
    int posXCentro = ObtenerPosicionXCentro("1 - AGREGAR CLIENTE");

    rlutil::setColor(opcion == 1 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY);
    std::cout << "AGREGAR CLIENTE" << std::endl;

    rlutil::setColor(opcion == 2 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 2);
    std::cout << "ELIMINAR CLIENTE" << std::endl;

    rlutil::setColor(opcion == 3 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 4);
    std::cout << "MODIFICAR DATOS DE CLIENTE" << std::endl;

    rlutil::setColor(opcion == 4 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 6);
    std::cout << "LISTAR CLIENTES" << std::endl;

    rlutil::setColor(opcion == 5 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 8);
    std::cout << "BUSCAR POR ID" << std::endl;

    rlutil::setColor(opcion == 6 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 10);
    std::cout << "BUSCAR CLIENTE POR DNI" << std::endl;

    rlutil::setColor(opcion == 7 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 12);
    std::cout << "REALIZAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 8 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 14);
    std::cout << "RESTAURAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 9 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 16);
    std::cout << "SALIR" << std::endl;
}

inline int ObtenerCentroConsola() {
    return rlutil::tcols() / 2;
}
inline void DibujarTitulo(const std::string& titulo) {
    int centroX = ObtenerCentroConsola();
    rlutil::locate(centroX - titulo.length() / 2, 1);
    std::cout << titulo << std::endl;
}
inline void DibujarRecuadroDatos(int ancho) {
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



inline void MostrarOpcionMenu(const std::string& opcion, int numeroOpcion) {
    int centroX = ObtenerCentroConsola();
    rlutil::locate(centroX - opcion.length() / 2, 3);
    std::cout << opcion << std::endl;
}



