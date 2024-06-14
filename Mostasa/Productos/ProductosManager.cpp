#include "../Productos/ProductosManager.h"
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
Producto ProductoManager::Crear(){
    int ID, Cantidad;
    string Nombre,Descripcion,Categoria;
    float Precio;
    do{
    cout<<"Ingrese ID: "<<endl;
    cin>>ID;
    if (ProdArch.buscar(ID)>-1)cout<<"Ya existe un producto con esa ID"<<endl;
    Prod.setID(ID);
    if (Prod.getID() == -1)cout<<"El ID ingresado es invalido"<<endl;
    }while(Prod.getID() == -1 || ProdArch.buscar(ID)>-1);//mas adelante en el programa va a hacer falta poner mas validaciones, como para saber si el producto está dado de baja o si ya existe
    do{
    cout<<"Ingrese nombre: "<<endl;
    cin.ignore();
    getline(cin,Nombre);
    Prod.setNombre(Nombre);
    if (Prod.getNombre() == " ")cout<<"El nombre ingresado es invalido"<<endl;
    }while(Prod.getNombre() == " ");
    do{
    cout<<"Ingrese descripcion: "<<endl;
    //cin.ignore();
    getline(cin,Descripcion);
    Prod.setDescripcion(Descripcion);
    if (Prod.getDescripcion() == " ")cout<<"La descripcion ingresada es invalido"<<endl;
    }while(Prod.getDescripcion() == " ");
    do{
    cout<<"Ingrese cantidad: "<<endl;
    cin>>Cantidad;
    Prod.setCantidad(Cantidad);
    if (Prod.getCantidad() == -1)cout<<"La cantidad ingresada es invalido"<<endl;
    }while(Prod.getCantidad() == -1);
    do{
    cout<<"Ingrese precio: "<<endl;
    cin>>Precio;
    Prod.setPrecio(Precio);
    if (Prod.getPrecio() == -1)cout<<"El precio ingresado es invalido"<<endl;
    }while(Prod.getPrecio() == -1);
    MenuCategorias();
    Categoria = Prod.getCategoria();
    Prod.setDisponible(true);
    //Producto x(ID,Nombre,Descripcion,Cantidad,true,Precio,Categoria);
    return(Prod);
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
void ProductoManager::Listar(){
    Producto x;
    int cantreg = ProdArch.getCantidadRegistros();

    for(int i=0;i<cantreg;i++){
        x = ProdArch.leer(i);
        cout<<"--------------------------------------------------"<<endl;
        Mostrar(x);
    }
}
void ProductoManager::Mostrar(Producto x){
  if ((x.getDisponible())==true){
    cout << "ID: " << x.getID() << endl;
    cout << "Nombre: " << x.getNombre() << endl;
    cout << "Descripcion: " << x.getDescripcion() << endl;
    cout << "Cantidad: " << x.getCantidad() << endl;
    cout << "Precio: " << x.getPrecio() << endl;
    cout << "Categoria: " << x.getCategoria() << endl;
    }


}
void ProductoManager::Modificar(){
    Producto x;
    int ID, pos,cantP;
    cout<<"Ingrese ID del producto a modificar: "<<endl;
    cin>>ID;

    pos = ProdArch.buscar(ID);

    if (pos >= 0) {
        x = ProdArch.leer(pos);
        if(x.getDisponible()==false){
                cout<<"El producto esta dado de baja"<<endl;
                system("pause");
                return;
        }

    cout<<"Ingrese la nueva cantidad del producto: "<<endl;
    cin>>cantP;
    x.setCantidad(cantP);
    if(ProdArch.Modificar(x,pos)){
            cout<<"Se ha modificado correctamente"<<endl;
        }
        else  cout<<"No se puedo modificar el producto"<<endl;
    }
    else{cout<<"No se pudo modificar, el producto no existe"<<endl;}

}
void ProductoManager::Buscar(){
    int pos,ID;
    Producto x;
    cout<<"Ingrese el ID del producto a buscar: "<<endl;
    cin>>ID;
    pos = ProdArch.buscar(ID);
    if(pos>=0){
        x=ProdArch.leer(pos);
        if (x.getDisponible()){
        Mostrar(x);
        }
        else{ cout<<"El municipio está dado de baja"<<endl;}

    }
    else{ cout<<"El municipio no se encuentra"<<endl;}

}
void ProductoManager::ListarOrdenado() {
    int cant = ProdArch.getCantidadRegistros();
    Producto* Vprod = new Producto[cant];
    if (Vprod == nullptr) {
        cout << "Fallo en la creación de variable" << endl;
        return;
    }

    // Copiar registros del archivo al array
    ProdArch.CopiarRegVec(Vprod, cant);

    // Ordenar productos por precio
    ordenarporPrecio(Vprod, cant);

    // Mostrar productos ordenados
    for (int i = 0; i < cant; i++) {
        Mostrar(Vprod[i]);
        cout << "-------------------------------" << endl;
    }

    delete[] Vprod;
}


void ProductoManager::ordenarporPrecio(Producto* v, int cant) {
    int i, j, posmin;
    Producto AUX;
    for (i = 0; i < cant - 1; i++) {
        posmin = i;
        for (j = i + 1; j < cant; j++) {
            if (v[j].getPrecio() < v[posmin].getPrecio()) {
                posmin = j;
            }
        }
        if (posmin != i) {
            AUX = v[i];
            v[i] = v[posmin];
            v[posmin] = AUX;
        }
    }
}

 void ProductoManager::copiaSeguridad(){
    bool hacercopia;
    cout<<"¿Realmente quiere realizar una copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>hacercopia;
    if(hacercopia){
        if(ProdArch.realizarCopia("Productos.bkp")){
            cout<<"La copia de seguridad se ha realizado con exito"<<endl;
        }
        else cout<<"No se pudo realizar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha realizado la copia"<<endl;
}

void ProductoManager::restaurarCopiaSeguridad(){
    bool restcopia;
    cout<<"¿Realmente quiere restaurar la copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>restcopia;
    if(restcopia){
        if(ProdArch.restaurarCopia("Productos.bkp")){
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }
        else cout<<"No se pudo restaurar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha restaurado la copia"<<endl;

}

void ProductoManager::Menu(){
    int Opcion;
    while(true){
        system("cls");
        cout<<"---- MENU ----"<<endl;
        cout<<"1 - CARGAR PRODUCTO"<<endl;
        cout<<"2 - DAR DE BAJA PRODUCTO"<<endl;
        cout<<"3 - LISTAR STOCK"<<endl;
        cout<<"4 - MODIFICAR CANTIDAD DEL PRODUCTO"<<endl;
        cout<<"5 - BUSCAR PRODUCTO POR ID"<<endl;
        cout<<"6 - LISTAR PRODUCTOS DE MENOR A MAYOR PRECIO"<<endl;
        cout<<"7 - REALIZAR COPIA DE SEGURIDAD"<<endl;
        cout<<"8 - RESTAURAR COPIA DE SEGURIDAD"<<endl;
        cout<<"0 - SALIR"<<endl;
        cin>>Opcion;
            switch(Opcion){
            case 1:
                Cargar();
                break;
            case 2:
                bajaLogica();
                break;
            case 3:
                Listar();
                break;
            case 4:
                Modificar();
                break;
            case 5:
                Buscar();
                break;
            case 6:
                ListarOrdenado();
                break;
            case 7:
                copiaSeguridad();
                break;
            case 8:
                restaurarCopiaSeguridad();
               break;
            case 0:
                return;
                break;

            }
            system("pause");
}
}
