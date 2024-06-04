#include "Productos.h"
#include <iostream>
#include <string>
#include<cstring>
using namespace std;

void Producto::setID(int ID){
    if(ID>0&&ID<100000){
        _ID = ID;
    }
    else _ID = -1;
}
void Producto::setNombre(string Nombre){
    if(strlen(Nombre.c_str())<30){
            strcpy(_Nombre,Nombre.c_str());
    }
    else strcpy(_Nombre, " ");

}
void Producto::setDescripcion(string Descripcion){
    if(strlen(Descripcion.c_str())<70){
            strcpy(_Descripcion,Descripcion.c_str());
    }
    else strcpy(_Descripcion," ");
}
void Producto::setCantidad(int Cantidad){
    if(Cantidad>0){
            _Cantidad = Cantidad;
    }
    else _Cantidad = -1;

}
void Producto::setDisponible(bool Disponible){ _Disponible = Disponible; }


void Producto::setPrecio(float Precio){
    if(Precio>0){
            _Precio = Precio;

    }
    else _Precio = -1;

}
void Producto::setCategoria(string Categoria){
    string CategoriaPosible[6]={"Pastas","Carnes","Postres","Bebidas","Ensaladas","Entradas"};
    for(int i=0;i<6;i++){
            if (Categoria == CategoriaPosible[i]){
                strcpy(_Categoria, Categoria.c_str());
                return;
            }

    }
    strcpy(_Nombre," ");
    }

int Producto::getID(){return _ID;}
string Producto::getNombre(){return _Nombre;}
string Producto::getDescrpcion(){return _Descripcion;}
int Producto::getCantidad(){return _Cantidad;}
bool Producto::getDisponible(){return _Disponible;}
float Producto::getPrecio(){return _Precio;}
string Producto::getCategoria(){return _Categoria;}


