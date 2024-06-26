#include "ReservasManager.h"
#include <iostream>
#include <string>
#include <cstring>
#include "../Funciones\FuncionesGraficas\globales.h"
using namespace std;
    Reserva ReservaManager::Crear(){
    int Numero, NumeroMesa, NumeroPersonas, IDCliente, IDProducto;
    Fecha fecha;
    do{
    cout<<"Ingrese numero de reserva: "<<endl;
    cin>>Numero;
    if (ResArch.buscar(Numero)>-1)cout<<"Ya existe una reserva con ese numero"<<endl;
    Res.setNumero(Numero);
    if (Res.getNumero() == -1)cout<<"El numero ingresado es invalido"<<endl;
    }while(Res.getNumero() == -1 || ResArch.buscar(Numero)>-1);
    do{
    cout<<"Ingrese numero de personas: "<<endl;
    cin>>NumeroPersonas;
    Res.setNumeroPersonas(NumeroPersonas);
    if (Res.getNumeroPersonas() == -1)cout<<"La cantidad ingresada es invalida"<<endl;
    }while(Res.getNumeroPersonas() == -1);

    cout<<"Ingrese Fecha de la reserva: "<<endl;
    fecha.CargarFecha(true);

    do{
    cout<<"Ingrese numero de mesa: "<<endl; ///deberiamos hacer una validacion para ver si la mesa está disponible aprovechando que ya hay una funcion que va a buscar las mesas disponibles
    cin>>NumeroMesa;

    if(VerificarMesaDisp(NumeroMesa,fecha)==false){
        cout<<"En la fecha ingresada, la mesa "<<NumeroMesa<<" no esta disponible"<<endl;
    }

    Res.setNumeroMesa(NumeroMesa);
    if (Res.getNumeroMesa() == -1)cout<<"La numero ingresado es invalido"<<endl;
    }while(Res.getNumeroMesa() == -1 || VerificarMesaDisp(NumeroMesa,fecha)==false);

    do{
    cout<<"Ingrese numero de ID del cliente: "<<endl;
    cin>>IDCliente;
    Res.setIDCliente(IDCliente);
    if (Res.getIDCliente() == -1)cout<<"El ID ingresado es invalido"<<endl;
    }while(Res.getIDCliente() == -1);
    do{
    cout<<"Ingrese ID del producto: "<<endl;
    cin>>IDProducto;
    Res.setIDProducto(IDProducto);
    if (Res.getIDProducto() == -1)cout<<"El ID ingresado es invalido"<<endl;
    }while(Res.getIDProducto() == -1);


    Res.setFecha(fecha);

    Res.setEstado(true);

    return(Res);
}

bool ReservaManager::VerificarMesaDisp(int NumeroM, Fecha &fecha){
    Fecha f;
    int cantreg = ResArch.getCantidadRegistros();
    for (int i=0;i<cantreg;i++){
            Res = ResArch.leer(i);
            if(Res.getEstado()){
                f = Res.getFecha();
                if(f.getMes() == fecha.getMes()&& f.getDia()==fecha.getDia()){
                        if(f.getAnio() == fecha.getAnio()){
                                if(Res.getNumeroMesa()==NumeroM){
                                    return false;
                                }
                    }
            }
            }

    }
    return true;
}


void ReservaManager::Cargar(){
    Reserva x;
    x = Crear();
    if(ResArch.guardar(x)){
        cout<<"Reserva guardada con exito :D"<<endl;
    }
    else{cout<<"No pudo guardarse la reserva D:"<<endl;}

    system("pause");
}
void ReservaManager::bajaLogica(){
    Reserva x;
    int Numero, pos;
    cout<<"Ingrese numero de reserva a eliminar: "<<endl;
    cin>>Numero;

    pos = ResArch.buscar(Numero);

    if (pos >= 0) {
        Reserva x = ResArch.leer(pos);
        if(x.getNumero()==-1){
            cout<<"No se pudo abrir el archivo"<<endl;
            return;
        }
        x.setEstado(false);
        if(ResArch.Modificar(x,pos)){
            cout<<"Elimando correctamente."<<endl;
        }
        else  cout<<"No se ha eliminado la reserva."<<endl;
    }
    else{cout<<"No se pudo eliminar, la reserva no existe."<<endl;}

}
void ReservaManager::Listar(){
    Reserva x;
    int cantreg = ResArch.getCantidadRegistros();

    for(int i=0;i<cantreg;i++){
        x = ResArch.leer(i);
        cout<<"--------------------------------------------------"<<endl;
        Mostrar(x);
    }
}
void ReservaManager::Mostrar(Reserva x){
  if ((x.getEstado())==true){
    cout << "Numero de reserva: " << x.getNumero() << endl;
    cout << "Numero de mesa: " << x.getNumeroMesa() << endl;
    cout << "Numero de personas: " << x.getNumeroPersonas() << endl;
    cout << "ID del cliente: " << x.getIDCliente() << endl;
    cout << "ID del producto: " << x.getIDProducto() << endl;
    Fecha fecha = x.getFecha();
    cout << "Fecha: " <<endl;
    fecha.MostrarFecha();
    }



}
void ReservaManager::Buscar(){
    Fecha fecha;
    Fecha f;
    cout<<"Ingrese una fecha: "<<endl;
    fecha.CargarFecha(true);
    int cantreg = ResArch.getCantidadRegistros();
    for (int i=0;i<cantreg;i++){
        Res = ResArch.leer(i);
        f = Res.getFecha();
        if (f.getAnio()==fecha.getAnio() && f.getMes()==fecha.getMes()){
            if(f.getDia()==fecha.getDia()&& Res.getEstado()==true){
                   Mostrar(Res);
                   cout<<"---------------------------------------"<<endl;
            }
        }

    }

}


void ReservaManager::CopiaSeguridad() {
    char opcion;
    int X = ObtenerPosicionXCentro("Realmente quiere realizar una copia de seguridad? Presione S/Si o N/No");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha realizado con exito.");
    int X2 = ObtenerPosicionXCentro("No se pudo realizar la copia de seguridad.");
    int X3 = ObtenerPosicionXCentro("No se ha realizado la copia.");
    rlutil::locate(X,2);
    std::cout << "Realmente quiere realizar una copia de seguridad? Presione S/Si o N/No" << std::endl;
    do {
        opcion = rlutil::getkey();
        opcion = toupper(opcion); // Convertir a mayúsculas para facilitar la comparación
    } while (opcion != 'S' && opcion != 'N');
    rlutil::cls();
    if (opcion == 'S') {
        if (ResArch.realizarCopia("Reservas.bak")) {
                rlutil::locate(X1,2);
            std::cout << "La copia de seguridad se ha realizado con exito." << std::endl;
        } else {
            rlutil::locate(X2,2);
            std::cout << "No se pudo realizar la copia de seguridad." << std::endl;
        }
    } else {
        rlutil::locate(X3,2);
        std::cout << "No se ha realizado la copia." << std::endl;
    }
    rlutil::anykey(); // Esperar a que se presione cualquier tecla para continuar
    rlutil::cls();    // Limpiar la pantalla nuevamente si es necesario
}
void ReservaManager::RestaurarCopiaSeguridad() {
    char opcion;
    int X = ObtenerPosicionXCentro("Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No");
    int X1 = ObtenerPosicionXCentro("La copia de seguridad se ha restaurado con exito.");
    int X2 = ObtenerPosicionXCentro("No se pudo restaurar la copia de seguridad.");
    int X3 = ObtenerPosicionXCentro("No se ha restaurado la copia.");
    rlutil::locate(X,2);
    std::cout << "Realmente quiere restaurar la copia de seguridad? Presione S/Si o N/No" << std::endl;
    do {
        opcion = rlutil::getkey();
        opcion = toupper(opcion);
    } while (opcion != 'S' && opcion != 'N');
    rlutil::cls();
    if (opcion == 'S') {
        if (ResArch.restaurarCopia("Reservas.bak")) {
            rlutil::locate(X1,2);
            std::cout << "La copia de seguridad se ha restaurado con exito." << std::endl;
        } else {
            rlutil::locate(X2,2);
            std::cout << "No se pudo restaurar la copia de seguridad." << std::endl;
        }
    } else {
        rlutil::locate(X3,2);
        std::cout << "No se ha restaurado la copia." << std::endl;
    }
    rlutil::anykey();
    rlutil::cls();
}
void ReservaManager::BuscarMesasXFecha(){
    Fecha fecha;
    cout<<"Ingrese una fecha: "<<endl;
    fecha.CargarFecha(true);
    ListarMesas(fecha);


}
void ReservaManager::ListarMesas(Fecha fecha){
    bool Mesas[49]={false};
    int cantreg = ResArch.getCantidadRegistros();
    Fecha f;
    for(int i=0;i<cantreg;i++){
            Res = ResArch.leer(i);
            f = Res.getFecha();
            if(f.getMes() == fecha.getMes()&&f.getDia()==fecha.getDia()){
                    if(f.getAnio() == fecha.getAnio()){
                            Mesas[Res.getNumeroMesa()-1]=true;
                    }
            }
    }
    cout<<"La mesas disponibles la fecha ";
    fecha.MostrarFecha();
    cout<<" son: "<<endl;
    for(int x=0;x<49;x++){
            if(Mesas[x]==false){
                cout<<"Mesa "<< x+1 <<endl;
            }

    }

}
void ReservaManager::Modificar(){
    Reserva x;
    int Numero, pos,IDprod;
    cout<<"Ingrese numero de reserva a modificar: "<<endl;
    cin>>Numero;

    pos = ResArch.buscar(Numero);

    if (pos >= 0) {
        x = ResArch.leer(pos);
        if(x.getEstado()==false){
                cout<<"La reserva esta dado de baja"<<endl;
                system("pause");
                return;
        }

    cout<<"Ingrese el ID del nuevo producto: "<<endl;
    cin>>IDprod;
    x.setIDProducto(IDprod);
    if(ResArch.Modificar(x,pos)){
            cout<<"Se ha modificado correctamente"<<endl;
        }
        else  cout<<"No se puedo modificar el producto"<<endl;
    }
    else{cout<<"No se pudo modificar, el producto no existe"<<endl;}

}

void ReservaManager::Menu(){
    int Opcion;
    while(true){
        system("cls");
        cout<<"---- MENU ----"<<endl;
        cout<<"1 - CARGAR RESERVA"<<endl;
        cout<<"2 - DAR DE BAJA RESERVA"<<endl;
        cout<<"3 - LISTAR RESERVAS"<<endl;
        cout<<"4 - MODIFICAR PRODUCTO RESERVADO"<<endl;
        cout<<"6 - LISTAR MESAS DISPONIBLES"<<endl;
        cout<<"5 - BUSCAR RESERVA POR FECHA"<<endl; ///HAY QUE ARREGLAR ESTO PARA QUE SE MUESTREN TODAS LAS RESERVAS QUE HAY PARA LA FECHA
        cout<<"6 - LISTAR MESAS DISPONIBLES"<<endl;
        cout<<"7 - REALIZAR COPIA DE SEGURUIDAD"<<endl;
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
                BuscarMesasXFecha();
                break;

            case 7:
                CopiaSeguridad();
                break;
            case 8:
                RestaurarCopiaSeguridad();
                break;
            case 0:
                return;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
            }

            system("pause");
}
}
