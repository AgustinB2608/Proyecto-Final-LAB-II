#pragma once
#include "../Funciones\FuncionesGraficas\rlutil.h"


/*--------------------*/
///Prototipos
int ObtenerCentroConsola(); //Esta funcion devuelve el centro de la consola se usa asi: X = ObtenerCEntroConsola();
void DibujarRecuadro(int, int, int, int);//Esta funcion ya esta explicada
int ObtenerPosicionXCentro(const std::string&);//Esta funcion devuelve el centro del texto enviado, se usa asi: X = ObtenerPosicionXCentro("EJEMPLO);
void DibujarLineas(int, int, int, int, char);//Esta funcion ya esta explicada
void Titulo();//Esta funcion crea el Titulo principal MOSTASA
void MostrarMenuPrincipal(int);//Esta funcion muestra el MENU PRINCIPAL
//void MostrarMenuProductos(int);//Esta funcion muestra el MENU PRODUCTOS
void MostrarMenuClientes(int);//Esta funcion muestra el MENU CLIENTES


void MostrarError(const std::string&, int); //Esta funcion muestra un cout en el centro de la pantalla, se usa : MostrarError("Ejemplo",1); se muestra en la fila 1
void MostrarConfirmacion(const std::string&, int); //Esta funcion muestra un cout en el centro de la pantalla, se usa : MostrarError("Ejemplo",1); se muestra en la fila 1


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

inline void MostrarMenuProductos(int opcion) {
    rlutil::setColor(rlutil::COLOR::WHITE);
    int posXCentro = ObtenerPosicionXCentro("MOSTASA CLIENTES");
    int X = ObtenerCentroConsola();
    rlutil::locate(X-2, 3);
    std::cout << "MOSTASA PRODUCTOS" << std::endl << std::endl;

    int posY = 7;

    DibujarRecuadro(posXCentro-2,posY-1,32,11);

    rlutil::setColor(opcion == 1 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY);
    std::cout << "AGREGAR PRODUCTO" << std::endl;

    rlutil::setColor(opcion == 2 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 1);
    std::cout << "ELIMINAR PRODUCTO" << std::endl;

    rlutil::setColor(opcion == 3 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 2);
    std::cout << "LISTAR PRODUCTOS" << std::endl;

    rlutil::setColor(opcion == 4 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 3);
    std::cout << "MODIFICAR CANTIDAD" << std::endl;

    rlutil::setColor(opcion == 5 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 4);
    std::cout << "BUSCAR POR ID" << std::endl;

    rlutil::setColor(opcion == 6 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 5);
    std::cout << "LISTA DE MENOR A MAYOR PRECIO" << std::endl;

    rlutil::setColor(opcion == 7 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 6);
    std::cout << "REALIZAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 8 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 7);
    std::cout << "RESTAURAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 9 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 8);
    std::cout << "VOLVER" << std::endl;
}


inline void MostrarMenuClientes(int opcion) {
    rlutil::setColor(rlutil::COLOR::WHITE);
    int posXCentro = ObtenerPosicionXCentro("MOSTASA CLIENTES");
    int X = ObtenerCentroConsola();
    rlutil::locate(X-2, 3);
    std::cout << "MOSTASA CLIENTES" << std::endl << std::endl;

    int posY = 7;

    DibujarRecuadro(posXCentro-2,posY-1,32,11);

    rlutil::setColor(opcion == 1 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY);
    std::cout << "AGREGAR CLIENTE" << std::endl;

    rlutil::setColor(opcion == 2 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 1);
    std::cout << "ELIMINAR CLIENTE" << std::endl;

    rlutil::setColor(opcion == 3 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 2);
    std::cout << "MODIFICAR DATOS DE CLIENTE" << std::endl;

    rlutil::setColor(opcion == 4 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 3);
    std::cout << "LISTAR CLIENTES" << std::endl;

    rlutil::setColor(opcion == 5 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 4);
    std::cout << "BUSCAR POR ID" << std::endl;

    rlutil::setColor(opcion == 6 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 5);
    std::cout << "BUSCAR CLIENTE POR DNI" << std::endl;

    rlutil::setColor(opcion == 7 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 6);
    std::cout << "REALIZAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 8 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 7);
    std::cout << "RESTAURAR COPIA DE SEGURIDAD" << std::endl;

    rlutil::setColor(opcion == 9 ? rlutil::COLOR::DARKGREY : rlutil::COLOR::WHITE);
    rlutil::locate(posXCentro, posY + 8);
    std::cout << "VOLVER" << std::endl;
}

inline void MostrarError(const std::string& mensaje, int y) {
    int posXCentro = ObtenerPosicionXCentro(mensaje);
    rlutil::locate(posXCentro, y);
    rlutil::setColor(rlutil::RED);
    std::cout << mensaje << std::endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

inline void MostrarConfirmacion(const std::string& mensaje, int y) {
    int posXCentro = ObtenerPosicionXCentro(mensaje);
    rlutil::locate(posXCentro, y);
    rlutil::setColor(rlutil::GREEN);
    std::cout << mensaje << std::endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

inline int ObtenerCentroConsola() {
    return rlutil::tcols() / 2;
}
inline void DibujarTitulo(const std::string& titulo, int y) {
    int posXCentro = ObtenerPosicionXCentro(titulo);
    rlutil::locate(posXCentro, y);
    std::cout << titulo << std::endl;
}
inline void DibujarRecuadro(int inicioX, int inicioY, int ancho, int alto) {
    // Dibujar borde superior e inferior
    DibujarLineas(inicioX, inicioY, inicioX + ancho - 1, inicioY, '-'); // Borde superior
    DibujarLineas(inicioX, inicioY + alto - 1, inicioX + ancho - 1, inicioY + alto - 1, '-'); // Borde inferior

    // Dibujar bordes verticales izquierdo y derecho
    DibujarLineas(inicioX, inicioY + 1, inicioX, inicioY + alto - 2, '|'); // Borde izquierdo
    DibujarLineas(inicioX + ancho - 1, inicioY + 1, inicioX + ancho - 1, inicioY + alto - 2, '|'); // Borde derecho

    // Esquinas
    rlutil::locate(inicioX, inicioY); std::cout << '+'; // Esquina superior izquierda
    rlutil::locate(inicioX + ancho - 1, inicioY); std::cout << '+'; // Esquina superior derecha
    rlutil::locate(inicioX, inicioY + alto - 1); std::cout << '+'; // Esquina inferior izquierda
    rlutil::locate(inicioX + ancho - 1, inicioY + alto - 1); std::cout << '+'; // Esquina inferior derecha
}

inline void MostrarOpcionMenu(const std::string& texto, int y) {
    int posXCentro = ObtenerPosicionXCentro(texto);
    rlutil::locate(posXCentro, y);
    std::cout << texto << std::endl;
}



