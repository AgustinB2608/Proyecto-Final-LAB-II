#include "ProductosManager.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void ProductoManager::MenuCategorias(){
    int iAUX;
     while (true){
        cout<<"Seleccione categoria: "<<endl;
        cout<<"1 - Pastas "<<endl;
        cout<<"2 - Carnes "<<endl;
        cout<<"3 - Bebidas "<<endl;
        cout<<"4 - Postres "<<endl;
        cout<<"5 - Ensaladas "<<endl;
        cout<<"6 - Entradas "<<endl;
        cin>>iAUX;
            switch(iAUX){
        case 1:
            Prod.setCategoria("Pastas");
            return;
            break;
        case 2:
            Prod.setCategoria("Carnes");
            return;
            break;
        case 3:
            Prod.setCategoria("Bebidas");
            return;
            break;
        case 4:
            Prod.setCategoria("Postres");
            return;
            break;
        case 5:
            Prod.setCategoria("Ensaladas");
            return;
            break;
        case 6:
            Prod.setCategoria("Entradas");
            return;
            break;
        default:
            cout<<"Opcion invalida"<<endl;
            break;


    }

}
}
Producto ProductoManager::Crear(){ ///Tengo que modificar esto para que no tome productos ya existentes o dados de baja
    int ID, Cantidad;
    string Nombre,Descripcion,Categoria;
    float Precio;
    do{
    cout<<"Ingrese ID: "<<endl;
    cin>>ID;
    Prod.setID(ID);
    }while(Prod.getID() == -1);//mas adelante en el programa va a hacer falta poner mas validaciones, como para saber si el producto está dado de baja o si ya existe
    do{
    cout<<"Ingrese nombre: "<<endl;
    cin.ignore();
    getline(cin,Nombre);
    Prod.setNombre(Nombre);
    }while(Prod.getNombre() == " ");
    do{
    cout<<"Ingrese descripcion: "<<endl;
    cin.ignore();
    getline(cin,Descripcion);
    Prod.setDescripcion(Descripcion);
    }while(Prod.getDescrpcion() == " ");
    do{
    cout<<"Ingrese cantidad: "<<endl;
    cin>>Cantidad;
    Prod.setCantidad(Cantidad);
    }while(Prod.getCantidad() == -1);
    do{
    cout<<"Ingrese precio: "<<endl;
    cin>>Precio;
    Prod.setPrecio(Precio);
    }while(Prod.getPrecio() == -1);
    MenuCategorias();
    Categoria = Prod.getCategoria();

    cout<<"PRUEBA PARA VER SI SE GUARDA BIEN LA CATEGORIA: "<<Prod.getCategoria()<<endl;
    system("pause");
    Prod.setDisponible(true);
    Producto x(ID,Nombre,Descripcion,Cantidad,true,Precio,Categoria);
    return(x);
}
void ProductoManager::Cargar(){
    Producto x;
    x = Crear();

    if(ProdArch.guardar(x)){
        cout<<"Producto guardado con exito :D"<<endl;
    }
    else{cout<<"No pudo guardarse el producto D:"<<endl;}
}
void ProductoManager::bajaLogica(){
    Producto x;
    int ID, pos;
    cout<<"Ingrese ID de Producto a eliminar: "<<endl;
    cin>>ID;

    pos = ProdArch.buscar(ID);

    if (pos >= 0) {
        Producto x = ProdArch.leer(pos);
        x.setDisponible(false);
        if(ProdArch.Modificar(x,pos)){
            cout<<"Elimando correctamente."<<endl;
        }
        else  cout<<"No se ha eliminado el producto."<<endl;
    }
    else{cout<<"No se pudo eliminar, el producto no existe."<<endl;}

}

void ProductoManager::Menu(){
    int Opcion;
    system("cls");
    while(true){
    cout<<"---- MENU ----"<<endl;
    cout<<"1 - CARGAR PRODUCTO"<<endl;
    cout<<"2 - DAR DE BAJA PRODUCTO"<<endl;
    cout<<"0 - SALIR"<<endl;
    cin>>Opcion;
    switch(Opcion){
    case 1:
        Cargar();
        break;
    case 2:
        bajaLogica();
        break;
    case 0:
        return;
        break;

    }
     system("pause");
}
}
