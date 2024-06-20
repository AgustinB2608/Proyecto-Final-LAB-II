#include "Clientes.h"
#include "../Fecha/Fecha.h"
#include <cstring>
#include <iostream>

// Constructor por defecto
Cliente::Cliente() : _ID(0), _FechaRegistro(1, 1, 1900), _Activo(1) { //ID=0,FechaRegistro=1/1/1900,Activo=SI.

    std::strncpy(_Nombre, "", sizeof(_Nombre));// Iniciaamos el nombre con una cadena vacia
    _Nombre[sizeof(_Nombre) - 1] = '\0';//Aseguramos que la cadena termine nulo

    std::strncpy(_Email, "", sizeof(_Email));
    _Email[sizeof(_Email) - 1] = '\0';

    std::strncpy(_Telefono, "", sizeof(_Telefono));
    _Telefono[sizeof(_Telefono) - 1] = '\0';

    std::strncpy(_DNI, "", sizeof(_DNI));
    _DNI[sizeof(_DNI) - 1] = '\0';
}

// Constructor con parámetros
Cliente::Cliente(int ID, const std::string& Nombre, const std::string& Email, const std::string& Telefono, const std::string& DNI, const Fecha& FechaRegistro, bool Activo)
    : _ID(ID), _FechaRegistro(FechaRegistro), _Activo(Activo) {

    std::strncpy(_Nombre, Nombre.c_str(), sizeof(_Nombre));// Copiamos el nombre del parámetro a la variable _Nombre
    _Nombre[sizeof(_Nombre) - 1] = '\0';//Aseguramos que la cadena termine nulo

    std::strncpy(_Email, Email.c_str(), sizeof(_Email));//Email a _Email
    _Email[sizeof(_Email) - 1] = '\0';

    std::strncpy(_Telefono, Telefono.c_str(), sizeof(_Telefono));//Telefono a _Telefono
    _Telefono[sizeof(_Telefono) - 1] = '\0';

    std::strncpy(_DNI, DNI.c_str(), sizeof(_DNI));//DNI a _DNI
    _DNI[sizeof(_DNI) - 1] = '\0';
}

// Setters
void Cliente::setIDCliente(int ID) {
    if (ID > 0 && ID < 100000) {//Validar que el ID no sea negativo y que no supere el limite.
        _ID = ID;
    } else {
        _ID = -1;//ID Invalido.
    }
}

void Cliente::setNombreCliente(const std::string& Nombre) {
    std::strncpy(_Nombre, Nombre.c_str(), sizeof(_Nombre));//Valida que el Nombre ingresado no supere el buffer y que siempre termine en nulo.
    _Nombre[sizeof(_Nombre) - 1] = '\0';
}

void Cliente::setEmailCliente(const std::string& Email) {
    std::strncpy(_Email, Email.c_str(), sizeof(_Email));
    _Email[sizeof(_Email) - 1] = '\0';
}

void Cliente::setTelefonoCliente(const std::string& Telefono) {
    bool valid = true;
    for (char c : Telefono) { //char c basicamente guarda un elemento de Telefono (c=1234567891)
        if (!isdigit(c)) { //usando la funcion isdigit de cstring para verificar que c sean solo digitos
            valid = false;//devuelve false si encuentra algun elemento que no sea digito.
            break;
        }
    }
    if (valid && Telefono.length() < sizeof(_Telefono)) {//Validamos que no supere el buffer y entonces copiamos a la variable
        std::strncpy(_Telefono, Telefono.c_str(), sizeof(_Telefono));
        _Telefono[sizeof(_Telefono) - 1] = '\0';
    } else {
        std::strncpy(_Telefono, "Sin Numero.", sizeof(_Telefono)); // Numero por defecto
        _Telefono[sizeof(_Telefono) - 1] = '\0';
    }
}

void Cliente::setDNICliente(const std::string& DNI) {
    bool valid = true;//Validaciones=Que sean digitos y que contenga 8digitos + caracter nulo.

    for (char d : DNI){if(!isdigit(d)) {valid = false;}}

    if (DNI.length() != 8) {valid = false;}

    if (valid) {
        std::strncpy(_DNI, DNI.c_str(), sizeof(_DNI));
        _DNI[sizeof(_DNI) - 1] = '\0';
    } else {
        std::strncpy(_DNI, "Sin DNI.", sizeof(_DNI));
        _DNI[sizeof(_DNI) - 1] = '\0';
    }
}

void Cliente::setFechaCreacion(const Fecha& FechaRegistro) {
    _FechaRegistro = FechaRegistro;
}

void Cliente::setActivo(bool activo) {
    _Activo = activo;
}

// Getters
int Cliente::getIDCliente() const {
    return _ID;
}

std::string Cliente::getNombreCliente() const {
    return std::string(_Nombre);
}

std::string Cliente::getEmailCliente() const {
    return std::string(_Email);
}

std::string Cliente::getTelefonoCliente() const {
    return std::string(_Telefono);
}

std::string Cliente::getDNICliente() const {
    return std::string(_DNI);
}

Fecha Cliente::getFechaCreacion() const {
    return _FechaRegistro;
}

bool Cliente::getActivo() const {
    return _Activo;
}
