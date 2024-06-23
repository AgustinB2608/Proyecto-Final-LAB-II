#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Fecha.h"
using namespace std;

Fecha::Fecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}

int Fecha::getDia() const { return _dia; }
int Fecha::getMes() const { return _mes; }
int Fecha::getAnio() const { return _anio; }

void Fecha::setDia(int dia) {
    if(dia > 0 && dia < 32) {
        _dia = dia;
    } else {
        cout << "Dia ingresado no valido" << endl;
    }
}

void Fecha::setMes(int mes) {
    if(mes > 0 && mes < 13) {
        _mes = mes;
    } else {
        cout << "Mes ingresado no valido" << endl;
    }
}

void Fecha::setAnio(int anio) {
    if(anio > 1899 && anio < 2025) {
        _anio = anio;
    } else {
        cout << "Anio ingresado no valido" << endl;
    }
}

void Fecha::CargarFecha() {
    bool fechaValida = false;
    while (!fechaValida) {
        cout << "Dia: ";
        cin >> _dia;
        cout << "Mes: ";
        cin >> _mes;
        cout << "Anio: ";
        cin >> _anio;

        if (ValidarFecha()) {
            fechaValida = true;
        } else {
            cout << "La fecha ingresada no es valida. Por favor, ingrese una fecha valida." << endl;
        }
    }
}

bool Fecha::ValidarFecha() const {
    // Obtener la fecha actual
    time_t tiempo;
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    // Comparar la fecha ingresada con la fecha actual
    if (_anio < 1900 + tmPtr->tm_year) {
        return true; // La fecha ingresada es anterior a la fecha actual
    } else if (_anio == 1900 + tmPtr->tm_year) {
        if (_mes < tmPtr->tm_mon + 1) {
            return true; // La fecha ingresada es anterior al mes actual del año actual
        } else if (_mes == tmPtr->tm_mon + 1) {
            if (_dia <= tmPtr->tm_mday) {
                return true; // La fecha ingresada es anterior o igual al día actual del mes actual y año actual
            }
        }
    }

    return false; // La fecha ingresada no es válida
}

void Fecha::MostrarFecha() const {
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}
