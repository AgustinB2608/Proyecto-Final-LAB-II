#include "ReservasManager.h"
#include <iostream>
#include <string>
#include <cstring>
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
    do{
    cout<<"Ingrese numero de mesa: "<<endl; ///deberiamos hacer una validacion para ver si la mesa está disponible aprovechando que ya hay una funcion que va a buscar las mesas disponibles
    cin>>NumeroMesa;
    Res.setNumeroMesa(NumeroMesa);
    if (Res.getNumeroMesa() == -1)cout<<"La numero ingresado es invalido"<<endl;
    }while(Res.getNumeroMesa() == -1);
    do{
    cout<<"Ingrese numero de ID del cliente: "<<endl;
    cin>>IDCliente;
    Res.setIDCliente(IDCliente);
    if (Res.getIDCliente() == -1)cout<<"El ID ingresado es invalido"<<endl;
    }while(Res.getIDCliente() == -1);
    do{
    cout<<"Ingrese ID del producto: "<<endl; ///Me gustaría hacer que se puedan reservar varios productos con un vector dinamico, no se si se pueda
    cin>>IDProducto;
    Res.setIDProducto(IDProducto);
    if (Res.getIDProducto() == -1)cout<<"El ID ingresado es invalido"<<endl;
    }while(Res.getIDProducto() == -1);

    cout<<"Ingrese Fecha de la reserva: "<<endl; ///no lo puse en el informe pero tambien podriamos hacer una validacion, buscar si para esa fecha hay mesas disponibles
    ///de hecho voy a hacer que en la funcion de buscar mesas disponibles se tenga que ingresar una fecha y buscar en esa fecha las mesas, así lo podemos usar acá
    fecha.CargarFecha();
    Res.setFecha(fecha);

    Res.setEstado(true);

    return(Res);
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
    int pos;
    Fecha fecha;
    Reserva x;
    cout<<"Ingrese el fecha de la reserva a buscar: "<<endl;
    fecha.CargarFecha();
    pos = ResArch.buscar(fecha);
    if(pos>=0){
        x=ResArch.leer(pos);
        if (x.getEstado()){
        Mostrar(x);
        }
        else{ cout<<"La reserva esta dada de baja"<<endl;}

    }
    else{ cout<<"la reserva no se encuentra"<<endl;}

}
void ReservaManager::Menu(){
    int Opcion;
    while(true){
        system("cls");
        cout<<"---- MENU ----"<<endl;
        cout<<"1 - CARGAR RESERVA"<<endl;
        cout<<"2 - DAR DE BAJA RESERVA"<<endl;
        cout<<"3 - LISTAR RESERVAS"<<endl;
        // modificar
        cout<<"5 - BUSCAR RESERVA POR FECHA"<<endl;
        //listar mesas disponibles (no reservadas).  Esto dejamelo porfis que quiero intentar algo
        ///7 - REALIZAR COPIA
        ///8 - RESTAURAR COPIA
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
                break;
            case 5:
                Buscar();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
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
