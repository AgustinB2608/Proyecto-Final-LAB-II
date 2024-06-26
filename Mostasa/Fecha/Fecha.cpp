#include <iostream>
#include <ctime>
#include "Fecha.h"
#include "../Funciones\ValidacionesGlobales.h"
#include "../Funciones\FuncionesGraficas\rlutil.h"
#include "../Funciones\FuncionesGraficas\globales.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}

int Fecha::getDia() const { return _dia; }
int Fecha::getMes() const { return _mes; }
int Fecha::getAnio() const { return _anio; }

void Fecha::setDia(int dia) {
    if (dia > 0 && dia < 32) {
        _dia = dia;
    } else {
        cout << "Dia ingresado no valido" << endl;
    }
}

void Fecha::setMes(int mes) {
    if (mes > 0 && mes < 13) {
        _mes = mes;
    } else {
        cout << "Mes ingresado no valido" << endl;
    }
}

void Fecha::setAnio(int anio) {
    if (anio > 1899 && anio < 2025) {
        _anio = anio;
    } else {
        cout << "Anio ingresado no valido" << endl;
    }
}

void Fecha::CargarFecha(bool esReserva) {
    bool fechaValida = false;
    while (!fechaValida) {
        cout << "Dia: ";
        cin >> _dia;
        cout << "Mes: ";
        cin >> _mes;
        cout << "Anio: ";
        cin >> _anio;

        if (ValidarFecha() && (!esReserva || FechaPosteriorMinimoDosDias(*this))) {
            fechaValida = true;
        } else {
            cout << "La fecha ingresada no es valida";
            if (esReserva) {
                cout << " o no es al menos dos días posterior a la fecha actual.";
            }
            cout << " Por favor, ingrese una fecha valida." << endl;
        }
    }
}

void Fecha::CargarFechaCliente() {
    const int X = ObtenerCentroConsola();
    const int Y = 7;
    do {
        rlutil::cls(); // Limpiar toda la pantalla para mostrar el formulario limpio
        DibujarTitulo("CLIENTE NUEVO", 3);
        rlutil::setColor(4);
        DibujarRecuadro(X-8,2,15,3);//Recuadro Opcion CLIENTE NUEVO
        rlutil::setColor(15);
        DibujarRecuadro(X-23,Y-1,46,6);//Recuadro General
        MostrarOpcionMenu("Ingrese la Fecha (DD/MM/AAAA):", Y);
        rlutil::locate(X, Y + 2);
        std::cin >> _dia;
        rlutil::locate(X + 2, Y + 2);
        std::cout << "/";
        rlutil::locate(X + 3, Y + 2);
        std::cin >> _mes;
        rlutil::locate(X + 5, Y + 2);
        std::cout << "/";
        rlutil::locate(X + 6, Y + 2);
        std::cin >> _anio;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!ValidarFecha()) {
            MostrarError("Fecha invalida. Por favor, ingrese una fecha valida.", Y + 5);}
    } while (!ValidarFecha());
}

bool Fecha::ValidarFecha() const {
    const int ANIO_VALIDO = 2024;//Modificar a gusto
    if (_anio != ANIO_VALIDO || _mes < 1 || _mes > 12 || _dia < 1 || _dia > 31) {return false;}

    // Dis maximos por mes (no considera años bisiestos)
    int diasMaximos[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Años bisiestos
    if (_mes == 2) {
        if ((ANIO_VALIDO % 4 == 0 && ANIO_VALIDO % 100 != 0) || (ANIO_VALIDO % 400 == 0)) {diasMaximos[1] = 29;}
    }

    if (_dia > diasMaximos[_mes - 1]) {return false;}

    return true;
}

void Fecha::MostrarFecha() const {cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;}
