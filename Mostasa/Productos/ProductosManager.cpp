#include "../Productos/ProductosManager.h"
#include "../Funciones/ValidacionesGlobales.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "../Funciones\FuncionesGraficas\globales.h"

void ProductoManager::MenuCategorias(){
    int iAUX;
    int X = ObtenerCentroConsola();
    int Y = 7;
     while (true){
        MostrarOpcionMenu("Seleccione categoria: ",Y);
        MostrarOpcionMenu("1 - Pastas ",Y+1);
        MostrarOpcionMenu("2 - Carnes ",Y+2);
        MostrarOpcionMenu("3 - Bebidas ",Y+3);
        MostrarOpcionMenu("4 - Postres ",Y+4);
        MostrarOpcionMenu("  5 - Ensaladas ",Y+5);
        MostrarOpcionMenu(" 6 - Entradas ",Y+6);
        rlutil::locate(X, Y + 8);
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
            break;}}}

Producto ProductoManager::Crear(){
    int ID, Cantidad;
    string Nombre,Descripcion,Categoria;
    float Precio;
    int Y = 7;
    int X2 = ObtenerCentroConsola();

    DibujarTitulo("PRODUCTO NUEVO", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X2-8,2,16,3);
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("PRODUCTO NUEVO", 3);
        MostrarOpcionMenu("Ingrese ID:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>ID;
        if (ProdArch.buscar(ID)>-1)MostrarError("Ya existe un producto con el ID ingresado",12);
        Prod.setID(ID);
        if (Prod.getID() == -1)MostrarError("El ID ingresado es invalido",12);
    }while(Prod.getID() == -1 || ProdArch.buscar(ID)>-1);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("PRODUCTO NUEVO", 3);
        MostrarOpcionMenu("Ingrese nombre:", Y);
        rlutil::locate(X2, Y + 2);
        cin.ignore();
        getline(cin,Nombre);
        Prod.setNombre(Nombre);
        if (Prod.getNombre() == " ")MostrarError("El nombre ingresado es invalido",12);
    }while(Prod.getNombre() == " ");

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("PRODUCTO NUEVO", 3);
        MostrarOpcionMenu("Ingrese descripción:", Y);
        rlutil::locate(X2, Y + 2);
        //cin.ignore();
        getline(cin,Descripcion);
        Prod.setDescripcion(Descripcion);
        if (Prod.getDescripcion() == " ")MostrarError("La descripcion ingresada es invalida",12);
    }while(Prod.getDescripcion() == " ");

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("PRODUCTO NUEVO", 3);
        MostrarOpcionMenu("Ingrese cantidad del producto:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>Cantidad;
        Prod.setCantidad(Cantidad);
    if (Prod.getCantidad() == -1)MostrarError("La cantidad ingresada es invalida",12);
    }while(Prod.getCantidad() == -1);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("PRODUCTO NUEVO", 3);
        MostrarOpcionMenu("Ingrese precio:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>Precio;
        Prod.setPrecio(Precio);
        if (Prod.getPrecio() == -1)MostrarError("El precio ingresado es invalido",12);
    }while(Prod.getPrecio() == -1);

    rlutil::cls();
    DibujarTitulo("PRODUCTO NUEVO", 3);
    DibujarRecuadro(X2-23,Y-1,46,12);
    MenuCategorias();

    Categoria = Prod.getCategoria();
    Prod.setDisponible(true);
    return(Prod);
}

void ProductoManager::Cargar(){
    Producto x;
    x = Crear();

    if(ProdArch.guardar(x)){
        MostrarConfirmacion("Producto guardado con exito :D",18);
    }
    else{MostrarError("No se pudo guardar el producto",18);}
}

void ProductoManager::bajaLogica(){
    Producto x;
    int ID, pos;
    int X2 = ObtenerCentroConsola();
    rlutil::setColor(4);
    DibujarRecuadro(X2-11,2,21,3);
    rlutil::setColor(15);
    DibujarTitulo("DAR DE BAJA PRODUCTO", 3);

    DibujarRecuadro(X2-23,6,46,6);
    DibujarTitulo("Ingrese ID:", 7);
    rlutil::locate(X2,9);
    cin>>ID;

    pos = ProdArch.buscar(ID);

    if (pos >= 0) {
        Producto x = ProdArch.leer(pos);
        x.setDisponible(false);
        if(ProdArch.Modificar(x,pos)){
            MostrarConfirmacion("Elimando correctamente.",12);
        }
        else  MostrarError("No se ha eliminado el producto.",12);
    }
    else MostrarError("No se pudo eliminar, el producto no existe.",12);

}
void ProductoManager::Listar(){
    Producto x;
    int cantreg = ProdArch.getCantidadRegistros();
    int activos = 0;
    for (int i = 0; i < cantreg; i++) {
            x = ProdArch.leer(i);
                if (x.getDisponible()) {
                    activos++;
        }
    }
    int registrosPorPagina = 2;
    int paginaActual = 0;
    int totalPaginas = (activos + registrosPorPagina - 1) / registrosPorPagina;

    while(true){
        rlutil::cls();
        int X = ObtenerCentroConsola() - 12;
        int Y = 4;
        int inicio = paginaActual * registrosPorPagina;
        int fin = std::min(inicio + registrosPorPagina, activos);
        int registrosMostrados = 0;
        int registrosActivosMostrados = 0;

        for(int i=0;i<cantreg;i++){
            x = ProdArch.leer(i);
            if(x.getDisponible()){
                if (registrosActivosMostrados >= inicio && registrosActivosMostrados < fin){
                    Mostrar(x,X,Y);
                    Y += 9;
                    registrosMostrados++;
                    }
                    registrosActivosMostrados++;
            }


        }
        int XXX = ObtenerPosicionXCentro("MOSTRANDO PRODUCTOS");
        rlutil::locate(XXX, 2);
        std::cout << "MOSTRANDO " << activos << "  PODUCTOS";
        rlutil::setColor(4);
        DibujarRecuadro(XXX-1,1,24,3);
        rlutil::setColor(15);

        int XX = ObtenerPosicionXCentro("Pagina X/X - Use las flechas para navegar");
        rlutil::locate(XX, rlutil::trows() - 2); //trows es de rlutil, es para que te devuelva la cantidad de filas de la consola
        std::cout << "Pagina " << (paginaActual + 1) << " de " << totalPaginas;
        rlutil::locate(XX, rlutil::trows() - 1);
        std::cout << "Use las flechas para navegar. ESC para salir.";

        // entrada del usuario
        int key = rlutil::getkey();
        if (key == rlutil::KEY_RIGHT && paginaActual < totalPaginas - 1) {
            paginaActual++;
        } else if (key == rlutil::KEY_LEFT && paginaActual > 0) {
            paginaActual--;
        } else if (key == rlutil::KEY_ESCAPE) {
            break; // Salir si se presiona ESC
        }
    }
}
void ProductoManager::Mostrar(Producto x, int X, int &Y){
  if ((x.getDisponible())==true){
    rlutil::locate(X, Y + 1);
    cout << "ID: " << x.getID() << endl;
    rlutil::locate(X, Y + 2);
    cout << "Nombre: " << x.getNombre() << endl;
    rlutil::locate(X, Y + 3);
    cout << "Descripcion: " << x.getDescripcion() << endl;
    rlutil::locate(X, Y + 4);
    cout << "Cantidad: " << x.getCantidad() << endl;
    rlutil::locate(X, Y + 5);
    cout << "Precio: " << x.getPrecio() << endl;
    rlutil::locate(X, Y + 6);
    cout << "Categoria: " << x.getCategoria() << endl;
    rlutil::locate(X, Y + 7);
    cout<<"-----------------------"<<endl;
    Y+=0;
    }

}

void ProductoManager::Mostrar(Producto x){
  if ((x.getDisponible())==true){
    int X = ObtenerCentroConsola()- 12;
    int Y = 4;

    int XX = ObtenerPosicionXCentro("MOSTRANDO PRODUCTO ID: ");
    rlutil::locate(XX,3);
    cout<<"MOSTRANDO PRODUCTO ID: "<< x.getID() <<endl;

    rlutil::locate(X, Y + 1);
    cout << "ID: " << x.getID() << endl;
    rlutil::locate(X, Y + 2);
    cout << "Nombre: " << x.getNombre() << endl;
    rlutil::locate(X, Y + 3);
    cout << "Descripcion: " << x.getDescripcion() << endl;
    rlutil::locate(X, Y + 4);
    cout << "Cantidad: " << x.getCantidad() << endl;
    rlutil::locate(X, Y + 5);
    cout << "Precio: " << x.getPrecio() << endl;
    rlutil::locate(X, Y + 6);
    cout << "Categoria: " << x.getCategoria() << endl;
    rlutil::locate(X, Y + 7);
    cout<<"-----------------------"<<endl;
    }
}

void ProductoManager::Modificar() {
    Producto x;
    int ID, pos, cantP;
    int Y = 7; // Eje Y
    int X2 = ObtenerCentroConsola();

    DibujarTitulo("MODIFICAR PRODUCTO", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X2-10, 2, 20, 3); // Recuadro Opción MODIFICAR PRODUCTO
    rlutil::setColor(15);
    DibujarRecuadro(X2-23, Y, 46, 6); // Recuadro General

    rlutil::cls();
    rlutil::setColor(4);
    DibujarRecuadro(X2-10, 2, 20, 3); // Recuadro Opción MODIFICAR PRODUCTO
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
    DibujarTitulo("MODIFICAR PRODUCTO", 3);
    MostrarOpcionMenu("Ingrese ID del producto a modificar:", Y);

    rlutil::locate(X2, Y + 2);
    std::cin >> ID;
    std::cin.ignore(); // Limpiar el buffer de entrada
    pos = ProdArch.buscar(ID);

    if (pos >= 0) {
        x = ProdArch.leer(pos);
        if (x.getDisponible() == false) {
            MostrarError("El producto está dado de baja", Y + 5);
            rlutil::anykey();
            return;
        }
        // Modificar cantidad del producto
        do {
            rlutil::cls();
            rlutil::setColor(4);
            DibujarRecuadro(X2-10, 2, 20, 3); // Recuadro Opción MODIFICAR PRODUCTO
            rlutil::setColor(15);
            DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General
            DibujarTitulo("MODIFICAR PRODUCTO", 3);
            MostrarOpcionMenu("Ingrese la nueva cantidad del producto:", Y);

            rlutil::locate(X2, Y + 2);
            std::cin >> cantP;
            std::cin.ignore();
            if (cantP < 0) {
                MostrarError("Cantidad invalida. Debe ser un numero positivo.", Y + 5);
            }
        } while (cantP < 0);
        x.setCantidad(cantP);

        if (ProdArch.Modificar(x, pos)) {
            MostrarConfirmacion("Se ha modificado correctamente.", Y + 5);
        } else {
            MostrarError("No se pudo modificar el producto.", Y + 5);
        }
    } else {
        MostrarError("No se pudo modificar, el producto no existe.", Y + 5);
    }
}

void ProductoManager::Buscar(){
    int pos,ID;
    Producto x;
    int X = ObtenerCentroConsola();

    DibujarTitulo("BUSCAR POR ID", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X-9,2,17,3);//Recuadro Opcion BUSCAR POR ID
    rlutil::setColor(15);

    DibujarRecuadro(X-23,6,46,6);//Recuadro General
    rlutil::locate(X,1);
    DibujarTitulo("Ingrese el ID del producto:", 7);
    rlutil::locate(X, 9);
    cin >> ID;
    rlutil::cls();
    pos = ProdArch.buscar(ID);
    if(pos>=0){
        x=ProdArch.leer(pos);
        if (x.getDisponible()){
        Mostrar(x);
        }
        else MostrarError("El producto esta dado de baja",12);

    }
    else MostrarError("El producto no se encuentra",12);
}

void ProductoManager::ListarOrdenado() {
    int cant = ProdArch.getCantidadRegistros();
    Producto* Vprod = new Producto[cant];
    if (Vprod == nullptr) {
        cout << "Fallo en la creación de variable" << endl;
        return;
        }
    int activos = ProdArch.CopiarRegVec(Vprod, cant);/// Copiar registros del archivo al array
    ordenarporPrecio(Vprod, cant); /// Ordenar productos por precio

    int registrosPorPagina = 2;
    int paginaActual = 0;
    int totalPaginas = (activos + registrosPorPagina - 1) / registrosPorPagina;

    while (true) {
        rlutil::cls();

        int X = ObtenerCentroConsola() - 12;
        int Y = 4;
        int inicio = paginaActual * registrosPorPagina;
        int fin = std::min(inicio + registrosPorPagina, activos);
        int registrosMostrados = 0;
        int registrosActivosMostrados = 0;

        for (int i = 0; i < cant && registrosActivosMostrados < fin; i++) {
            if (Vprod[i].getDisponible()){
                    if (registrosActivosMostrados >= inicio && registrosActivosMostrados < fin){
                      Mostrar(Vprod[i],X,Y);
                      Y += 9;
                      registrosMostrados++;
                    }
                    registrosActivosMostrados++;

            }


        }
        int XXX = ObtenerPosicionXCentro("MOSTRANDO PRODUCTOS");
        rlutil::locate(XXX, 2);
        std::cout << "MOSTRANDO " << activos << "  PODUCTOS";
        rlutil::setColor(4);
        DibujarRecuadro(XXX-1,1,24,3);
        rlutil::setColor(15);

        int XX = ObtenerPosicionXCentro("Pagina X/X - Use las flechas para navegar");
        rlutil::locate(XX, rlutil::trows() - 2); //trows es de rlutil, es para que te devuelva la cantidad de filas de la consola
        std::cout << "Pagina " << (paginaActual + 1) << " de " << totalPaginas;
        rlutil::locate(XX, rlutil::trows() - 1);
        std::cout << "Use las flechas para navegar. ESC para salir.";

        // entrada del usuario
        int key = rlutil::getkey();
        if (key == rlutil::KEY_RIGHT && paginaActual < totalPaginas - 1) {
            paginaActual++;
        } else if (key == rlutil::KEY_LEFT && paginaActual > 0) {
            paginaActual--;
        } else if (key == rlutil::KEY_ESCAPE) {
            break; // Salir si se presiona ESC
        }




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
    char opcion;
    int X = ObtenerPosicionXCentro("¿Realmente quiere realizar una copia de seguridad? 1 - SI / 0 - NO");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha realizado con exito");
    int X2 = ObtenerPosicionXCentro("No se pudo realizar la copia de seguridad");
    int X3 = ObtenerPosicionXCentro("No se ha realizado la copia.");

    rlutil::locate(X,2);
    cout<<"¿Realmente quiere realizar una copia de seguridad? S - SI / N - NO"<<endl;
    do{
    opcion = rlutil::getkey();
    opcion = toupper(opcion);
    }while(opcion!='S' && opcion!='N');

    rlutil::cls();

    if(opcion=='S'){
        if(ProdArch.realizarCopia("Productos.bkp")){
            rlutil::locate(X1,2);
            cout<<"La copia de seguridad se ha realizado con exito"<<endl;
        }

        else{
            rlutil::locate(X2,2);
            cout<<"No se pudo realizar la copia de seguridad"<<endl;
        }
    }

    else{
        rlutil::locate(X3,2);
        cout<<"No se ha realizado la copia."<<endl;
    }
    rlutil::anykey();
}

void ProductoManager::restaurarCopiaSeguridad(){
    char opcion;
    int X = ObtenerPosicionXCentro("Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha restaurado con exito");
    int X2 = ObtenerPosicionXCentro("No se pudo restaurar la copia de seguridad");
    int X3 = ObtenerPosicionXCentro("No se ha restaurado la copia");
    rlutil::locate(X,2);
    std::cout << "Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No" << std::endl;
    do {
        opcion = rlutil::getkey();
        opcion = toupper(opcion);
    } while (opcion != 'S' && opcion != 'N');
    rlutil::cls();
    if(opcion=='S'){
        if(ProdArch.restaurarCopia("Productos.bkp")){
            rlutil::locate(X1,2);
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }

        else{
            rlutil::locate(X2,2);
            cout<<"No se pudo restaurar la copia de seguridad"<<endl;
       }
    }
    else{
        rlutil::locate(X3,2);
        cout<<"No se ha restaurado la copia"<<endl;
    }
    rlutil::anykey();
}

void ProductoManager::Menu(){
    int opcion = 1;
    do {
        rlutil::cls();
        rlutil::hidecursor();
        MostrarMenuProductos(opcion);

        int Key = rlutil::getkey();

        switch (Key) {
            case rlutil::KEY_UP:
                opcion--;
                if (opcion < 1) opcion = 9;
                break;
            case rlutil::KEY_DOWN:
                opcion++;
                if (opcion > 9) opcion = 1;
                break;
            case rlutil::KEY_ENTER:
                switch (opcion) {
                    case 1:
                        rlutil::cls();
                        Cargar();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        bajaLogica();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        Listar();
                        rlutil::anykey();
                        break;
                    case 4:
                        rlutil::cls();
                        Modificar();
                        rlutil::anykey();
                        break;
                    case 5:
                        rlutil::cls();
                        Buscar();
                        rlutil::anykey();
                        break;
                    case 6:
                        rlutil::cls();
                        ListarOrdenado();
                        rlutil::anykey();
                        break;
                    case 7:
                        rlutil::cls();
                        copiaSeguridad();
                        break;
                    case 8:
                        rlutil::cls();
                        restaurarCopiaSeguridad();
                        break;
                    case 9:
                        rlutil::cls();
                        MostrarConfirmacion("Saliendo del Menu Productos...",12);
                        rlutil::setColor(rlutil::COLOR::WHITE);
                        opcion = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    } while (opcion != 0);
}
