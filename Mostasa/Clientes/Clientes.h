#include <string>
#include <cstring>
//#include "Fecha.h"


class Cliente{
private:
    int _ID;
    char _Nombre[30];
    char _Email[30];
    char _Telefono[15];
    //Añadir clase Fecha Fecha _FechaRegistro;
public:
    Cliente(); //Por defecto
    Cliente(int ID, const std::string& Nombre, const std::string& Email, const std::string& Telefono);//, const Fecha& FechaRegistro);//Con parametros

    ///Setters
    void setIDCliente(int ID);
    void setNombreCliente(const std::string& Nombre);
    void setEmailCliente(const std::string& Email);
    void setTelefonoCliente(const std::string& Telefono);
    //void setFechaCreacion(const Fecha& FechaRegistro);

    ///Getters
    int getIDCliente() const;
    std::string getNombreCliente() const;
    std::string getEmailCliente() const;
    std::string getTelefonoCliente() const;
    //Fecha getFechaCreacion() const;
};

