#include <iostream>
#include <ctime>
#include "Fecha.h"
#include "../Funciones\ValidacionesGlobales.h"

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

bool Fecha::ValidarFecha() const {
    if (_anio < 1900 || _anio > 2024 || _mes < 1 || _mes > 12 || _dia < 1 || _dia > 31) {
        return false;
    }

    // Días máximos por mes (no considerando años bisiestos)
    int diasMaximos[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajuste para años bisiestos
    if (_mes == 2) {
        if ((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0)) {
            diasMaximos[1] = 29;
        }
    }

    if (_dia > diasMaximos[_mes - 1]) {
        return false;
    }

    return true;
}

void Fecha::MostrarFecha() const {
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}
