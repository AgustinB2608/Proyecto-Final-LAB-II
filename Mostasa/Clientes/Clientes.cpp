#include "C:\Users\berna\OneDrive - frgp.utn.edu.ar\Escritorio\Proyecto-Final-LAB-II-master\Mostasa\Clientes\Clientes.h"
#include <cstring>
#include <iostream>


Cliente::Cliente() : _ID(0){//, _FechaRegistro(1, 1, 1900) {
    std::strncpy(_Nombre, "", sizeof(_Nombre));
    _Nombre[sizeof(_Nombre) - 1] = '\0';
    std::strncpy(_Email, "", sizeof(_Email));
    _Email[sizeof(_Email) - 1] = '\0';
    std::strncpy(_Telefono, "", sizeof(_Telefono));
    _Telefono[sizeof(_Telefono) - 1] = '\0';
}


Cliente::Cliente(int ID, const std::string& Nombre, const std::string& Email, const std::string& Telefono)//, const Fecha& FechaRegistro)
    : _ID(ID) { //, _FechaRegistro(FechaRegistro) {
    std::strncpy(_Nombre, Nombre.c_str(), sizeof(_Nombre));
    _Nombre[sizeof(_Nombre) - 1] = '\0';
    std::strncpy(_Email, Email.c_str(), sizeof(_Email));
    _Email[sizeof(_Email) - 1] = '\0';
    std::strncpy(_Telefono, Telefono.c_str(), sizeof(_Telefono));
    _Telefono[sizeof(_Telefono) - 1] = '\0';
}

// Setters
void Cliente::setIDCliente(int ID) {
    if(ID>0&&ID<100000){
        _ID = ID;
    }
    else _ID = -1;
}

void Cliente::setNombreCliente(const std::string& Nombre) {
    std::strncpy(_Nombre, Nombre.c_str(), sizeof(_Nombre));
    _Nombre[sizeof(_Nombre) - 1] = '\0';
}

void Cliente::setEmailCliente(const std::string& Email) {
    std::strncpy(_Email, Email.c_str(), sizeof(_Email));
    _Email[sizeof(_Email) - 1] = '\0';
}

void Cliente::setTelefonoCliente(const std::string& Telefono) {
    std::strncpy(_Telefono, Telefono.c_str(), sizeof(_Telefono));
    _Telefono[sizeof(_Telefono) - 1] = '\0';
}

/*void Cliente::setFechaCreacion(const Fecha& FechaRegistro) {
    _FechaRegistro = FechaRegistro;
}*/

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

/*Fecha Cliente::getFechaCreacion() const {
    return _FechaRegistro;
}*/
