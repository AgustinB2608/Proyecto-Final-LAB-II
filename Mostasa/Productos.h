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
    std::string getDescrpcion();
    int getCantidad();
    bool getDisponible();
    float getPrecio();
    std::string getCategoria();
    //habria que ver que onda con que categoria sea char, hasta ahora lo veniamos haciendo numerico
    //si tenemos que buscar por categoria o hacer una cantidad definida de categorias va a estar jodido
    ///se me ocurre hacer un minimenú, para que cuando se cargue producto en la parte de categoría hayan opciones y no puedas meter cualquier cosa
};
