#pragma once

#include <string>
#include <cstring>

#include "../Fecha/Fecha.h"


class Cliente{
private:
    int _ID;
    char _Nombre[30];
    char _Email[30];
    char _Telefono[15];
    char _DNI[9];
    Fecha _FechaRegistro;
    bool _Activo;
public:
    Cliente();
    Cliente(int ID, const std::string& Nombre, const std::string& Email, const std::string& Telefono, const std::string& DNI, const Fecha& FechaRegistro, bool Activo);//Con parametros

    ///Setters
    void setIDCliente(int ID);
    void setNombreCliente(const std::string& Nombre);
    void setEmailCliente(const std::string& Email);
    void setTelefonoCliente(const std::string& Telefono);
    void setDNICliente(const std::string& DNI);
    void setFechaCreacion(const Fecha& FechaRegistro);
    void setActivo(bool activo);

    ///Getters
    int getIDCliente() const;
    std::string getNombreCliente() const;
    std::string getEmailCliente() const;
    std::string getTelefonoCliente() const;
    std::string getDNICliente()const;
    Fecha getFechaCreacion() const;
    bool getActivo() const;
};

