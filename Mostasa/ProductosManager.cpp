#include "ProductosManager.h"
#include <iostream>
#include <string>
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
void ProductoManager::Cargar(){
    int iAUX;
    string sAUX;
    float fAUX;
    do{
    cout<<"Ingrese ID: "<<endl;
    cin>>iAUX;
    Prod.setID(iAUX);
    }while(Prod.getID() == -1);//mas adelante en el programa va a hacer falta poner mas validaciones, como para saber si el producto está dado de baja o si ya existe
    do{
    cout<<"Ingrese nombre: "<<endl;
    cin.ignore();
    getline(cin,sAUX);
    Prod.setNombre(sAUX);
    }while(Prod.getNombre() == " ");
    do{
    cout<<"Ingrese descripcion: "<<endl;
    cin.ignore();
    getline(cin,sAUX);
    Prod.setDescripcion(sAUX);
    }while(Prod.getDescrpcion() == " ");
    do{
    cout<<"Ingrese cantidad: "<<endl;
    cin>>iAUX;
    Prod.setCantidad(iAUX);
    }while(Prod.getCantidad() == -1);
    do{
    cout<<"Ingrese precio: "<<endl;
    cin>>fAUX;
    Prod.setPrecio(fAUX);
    }while(Prod.getPrecio() == -1);

    MenuCategorias();

    cout<<"PRUEBA PARA VER SI SE GUARDA BIEN LA CATEGORIA: "<<Prod.getCategoria()<<endl;
    system("pause");
    Prod.setDisponible(true);
}

void ProductoManager::Menu(){
    int Opcion;
    system("cls");
    while(true){
    cout<<"---- MENU ----"<<endl;
    cout<<"1 - CARGAR PRODUCTO"<<endl;
    cout<<"0 - SALIR"<<endl;
    cin>>Opcion;
    switch(Opcion){
    case 1:
        Cargar();
        break;
    case 0:
        return;
        break;

    }
     system("pause");
}
}
