#pragma once
#include <string>
class Producto{
private:
    int _ID;
    char _Nombre[30];
    char _Descripcion[70];
    int _Cantidad;
    bool _Disponible;
    float _Precio;
    char _Categoria[10];
public:
    Producto();
    Producto(int ID, std::string Nombre, std::string Descripcion, int Cantidad, bool Disponible, float Precio, std::string Categoria);
    ///setters
    void setID(int ID);
    void setNombre(std::string Nombre);
    void setDescripcion(std::string Descripcion);
    void setCantidad(int Cantidad);
    void setDisponible(bool Disponible);
    void setPrecio(float Precio);
    void setCategoria(std::string Categoria);
    ///getters
    int getID();
    std::string getNombre();
    std::string getDescripcion();
    int getCantidad();
    bool getDisponible();
    float getPrecio();
    std::string getCategoria();

};
