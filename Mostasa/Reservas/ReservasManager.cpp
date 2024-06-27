#include "ReservasManager.h"
#include <iostream>
#include <string>
#include <cstring>
#include "../Funciones\FuncionesGraficas\globales.h"
using namespace std;
    Reserva ReservaManager::Crear(){
    Reserva res2;
    int Numero, NumeroMesa, NumeroPersonas, IDCliente, IDProducto;
    Fecha fecha;
    int Y = 7; // Eje Y
    int X2 = ObtenerCentroConsola();

    DibujarTitulo("RESERVA NUEVA", 3);
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
        DibujarTitulo("RESERVA NUEVA", 3);
        MostrarOpcionMenu("Ingrese numero de reserva:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>Numero;
        if (ResArch.buscar(Numero)>-1)MostrarError("Ya existe una reserva con ese numero",12);
        res2.setNumero(Numero);
        if (res2.getNumero() == -1)MostrarError("El numero ingresado es invalido",12);
    }while(res2.getNumero() == -1 || ResArch.buscar(Numero)>-1);

      rlutil::anykey();

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("RESERVA NUEVA", 3);
        MostrarOpcionMenu("Ingrese numero de personas:", Y);
        rlutil::locate(X2, Y + 2);

        cin>>NumeroPersonas;
         res2.setNumeroPersonas(NumeroPersonas);
        if (res2.getNumeroPersonas() == -1)MostrarError("La cantidad ingresada es invalida",12);
    }while(res2.getNumeroPersonas() == -1);

    rlutil::cls();
    rlutil::setColor(4);
    DibujarRecuadro(X2-8,2,16,3);
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);
    DibujarTitulo("RESERVA NUEVA", 3);
    MostrarOpcionMenu("Ingrese fecha:", Y);
    fecha.CargarFecha(true);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("RESERVA NUEVA", 3);
        MostrarOpcionMenu("Ingrese numero de mesa: ", Y);
        rlutil::locate(X2, Y + 2);
        cin>>NumeroMesa;

        if(VerificarMesaDisp(NumeroMesa,fecha)==false){
            MostrarError("En la fecha ingresada, la mesa ingresada no esta disponible",12);
        }

        res2.setNumeroMesa(NumeroMesa);
        if (res2.getNumeroMesa() == -1)MostrarError("La numero ingresado es invalido",12);
    }while(res2.getNumeroMesa() == -1 || VerificarMesaDisp(NumeroMesa,fecha)==false);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("RESERVA NUEVA", 3);
        MostrarOpcionMenu("Ingrese numero de ID del cliente:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>IDCliente;
        res2.setIDCliente(IDCliente);
        if (res2.getIDCliente() == -1)MostrarError("El ID ingresado es invalido",12);
    }while(res2.getIDCliente() == -1);

    do{
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-8,2,16,3);
        rlutil::setColor(15);
        DibujarRecuadro(X2-23,Y-1,46,6);
        DibujarTitulo("RESERVA NUEVA", 3);
        MostrarOpcionMenu("Ingrese ID del producto:", Y);
        rlutil::locate(X2, Y + 2);
        cin>>IDProducto;
        res2.setIDProducto(IDProducto);
        if (res2.getIDProducto() == -1)MostrarError("El ID ingresado es invalido",12);
    }while(res2.getIDProducto() == -1);


    res2.setFecha(fecha);

    res2.setEstado(true);




    return(res2);
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
        MostrarConfirmacion("Reserva guardada con exito :D",12);
    }
    else MostrarError("No pudo guardarse la reserva D:",12);


    system("pause");
}
void ReservaManager::bajaLogica(){
    Reserva x;
    int Numero, pos;
    int X2 = ObtenerCentroConsola();
    rlutil::setColor(4);
    DibujarRecuadro(X2-11,2,21,3);
    rlutil::setColor(15);
    DibujarTitulo("DAR DE BAJA RESERVA", 3);

    DibujarRecuadro(X2-23,6,46,6);
    DibujarTitulo("Ingrese numero de reserva a eliminar:", 7);
    rlutil::locate(X2,9);
    cin>>Numero;

    pos = ResArch.buscar(Numero);

    if (pos >= 0) {
        Reserva x = ResArch.leer(pos);
        if(x.getNumero()==-1){
            MostrarError("No se pudo abrir el archivo",12);
            return;
        }
        x.setEstado(false);
        if(ResArch.Modificar(x,pos)){
            MostrarConfirmacion("Elimando correctamente.",12);
        }
        else  MostrarError("No se ha eliminado la reserva.",12);
    }
    else MostrarError("No se pudo eliminar, la reserva no existe.",12);

}
void ReservaManager::Listar(){
    Reserva x;
    int Activos=0;
    int cantreg = ResArch.getCantidadRegistros();

    for(int i=0;i<cantreg;i++){
        x = ResArch.leer(i);
        if(x.getEstado())
        Activos++;
    }
    int registrosPorPagina = 2;
    int paginaActual = 0;
    int totalPaginas = (Activos + registrosPorPagina - 1) / registrosPorPagina;

    while(true){
        rlutil::cls();
        int X = ObtenerCentroConsola() - 12;
        int Y = 4;
        int inicio = paginaActual * registrosPorPagina;
        int fin = std::min(inicio + registrosPorPagina, Activos);
        int registrosMostrados = 0;
        int registrosActivosMostrados = 0;

        for(int i=0;i<cantreg;i++){
            x = ResArch.leer(i);
            if(x.getEstado()){
                if (registrosActivosMostrados >= inicio && registrosActivosMostrados < fin){
                    Mostrar(x,X,Y);
                    Y += 9;
                    registrosMostrados++;
                    }
                    registrosActivosMostrados++;
            }
    }
        int XXX = ObtenerPosicionXCentro("MOSTRANDO RESERVAS");
        rlutil::locate(XXX, 2);
        std::cout << "MOSTRANDO " << Activos << "  RESERVAS";
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
void ReservaManager::Mostrar(Reserva x){
  if ((x.getEstado())==true){
        int X = ObtenerCentroConsola()- 12;
        int Y = 4;
        int XX = ObtenerPosicionXCentro("MOSTRANDO RESERVA NUMERO: ");
        rlutil::locate(XX,3);
        cout<<"MOSTRANDO RESERVA NUMERO: "<< x.getNumero() <<endl;

        rlutil::locate(X, Y + 1);
        cout << "Numero de reserva: " << x.getNumero() << endl;
        rlutil::locate(X, Y + 2);
        cout << "Numero de mesa: " << x.getNumeroMesa() << endl;
        rlutil::locate(X, Y + 3);
        cout << "Numero de personas: " << x.getNumeroPersonas() << endl;
        rlutil::locate(X, Y + 4);
        cout << "ID del cliente: " << x.getIDCliente() << endl;
        rlutil::locate(X, Y + 5);
        cout << "ID del producto: " << x.getIDProducto() << endl;
        Fecha fecha = x.getFecha();
        rlutil::locate(X, Y + 6);
        cout << "Fecha: " <<endl;
        rlutil::locate(X+7, Y + 6);  ///ACOMODO LA FECHA AL LADO DE FECHA:
        fecha.MostrarFecha();
        rlutil::locate(X, Y + 7);
        cout<<"-----------------------"<<endl;
    }

}

void ReservaManager::Mostrar(Reserva x, int X, int &Y){
  if ((x.getEstado())==true){
        rlutil::locate(X, Y + 1);
        cout << "Numero de reserva: " << x.getNumero() << endl;
        rlutil::locate(X, Y + 2);
        cout << "Numero de mesa: " << x.getNumeroMesa() << endl;
        rlutil::locate(X, Y + 3);
        cout << "Numero de personas: " << x.getNumeroPersonas() << endl;
        rlutil::locate(X, Y + 4);
        cout << "ID del cliente: " << x.getIDCliente() << endl;
        rlutil::locate(X, Y + 5);
        cout << "ID del producto: " << x.getIDProducto() << endl;;
        rlutil::locate(X, Y + 6);
        Fecha fecha = x.getFecha();
        cout << "Fecha: " <<endl;
        rlutil::locate(X+7, Y + 6);  ///ACOMODO LA FECHA AL LADO DE FECHA:
        fecha.MostrarFecha();
        rlutil::locate(X, Y + 7);
        cout<<"-----------------------"<<endl;
    }


}

void ReservaManager::Buscar(){
    Fecha fecha;
    Fecha f;
    int X = ObtenerCentroConsola();
    int Y = 4;

    DibujarTitulo("BUSCAR POR FECHA", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X-9,2,18,3); // Recuadro Opción BUSCAR POR ID
    rlutil::setColor(15);

    DibujarRecuadro(X-23,6,46,6); // Recuadro General
    rlutil::locate(X,1);
    DibujarTitulo("Ingrese una fecha:", 7);
    rlutil::locate(X, 9);
    fecha.CargarFecha(true);

    rlutil::cls();
    DibujarTitulo("RESERVAS PARA LA FECHA INGRESADA", 3);

    bool hayfechas = false;
    int cantreg = ResArch.getCantidadRegistros();
    int totalResultados = 0;

    for (int i = 0; i < cantreg; i++) {
        Reserva res3 = ResArch.leer(i);
        f = res3.getFecha();
        if (f.getAnio() == fecha.getAnio() && f.getMes() == fecha.getMes() && f.getDia() == fecha.getDia()) {
            if (res3.getEstado() == true) {
                totalResultados++;
            }
        }
    }

    if (totalResultados == 0) {
        MostrarError("No se encontraron reservas", 12);
        rlutil::anykey();
        return;
    }

    int registrosPorPagina = 2;
    int paginaActual = 0;
    int totalPaginas = (totalResultados + registrosPorPagina - 1) / registrosPorPagina;

    while (true) {
        rlutil::cls();
        DibujarTitulo("RESERVAS PARA LA FECHA INGRESADA", 3);
        int Y = 4;
        int inicio = paginaActual * registrosPorPagina;
        int fin = std::min(inicio + registrosPorPagina, totalResultados);
        int registrosMostrados = 0;
        int registrosActivosMostrados = 0;

        for (int i = 0; i < cantreg; i++) {
            Reserva res3 = ResArch.leer(i);
            f = res3.getFecha();
            if (f.getAnio() == fecha.getAnio() && f.getMes() == fecha.getMes() && f.getDia() == fecha.getDia() && res3.getEstado() == true) {
                if (registrosActivosMostrados >= inicio && registrosActivosMostrados < fin) {
                    Mostrar(res3, ObtenerCentroConsola() - 12, Y);
                    Y += 9;
                    registrosMostrados++;
                }
                registrosActivosMostrados++;
            }
        }

        int XXX = ObtenerPosicionXCentro("Pagina X/X - Use las flechas para navegar");
        rlutil::locate(XXX, rlutil::trows() - 2); //trows es de rlutil, es para que te devuelva la cantidad de filas de la consola
        std::cout << "Pagina " << (paginaActual + 1) << " de " << totalPaginas;
        rlutil::locate(XXX, rlutil::trows() - 1);
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
    int Numero, pos, IDprod;
    int Y = 7; // Eje Y
    int X2 = ObtenerCentroConsola();

    DibujarTitulo("MODIFICAR RESERVA", 3);
    rlutil::setColor(4);
    DibujarRecuadro(X2-10, 2, 20, 3); // Recuadro Opción MODIFICAR RESERVA
    rlutil::setColor(15);
    DibujarRecuadro(X2-23,Y-1,46,6);//Recuadro General

    // Pedir el nmero de reserva a modificar
    MostrarOpcionMenu("Ingrese numero de reserva a modificar:", Y);
    rlutil::locate(X2, Y + 2);
    std::cin >> Numero;
    std::cin.ignore(); // Limpiar el buffer de entrada

    pos = ResArch.buscar(Numero);

    if (pos >= 0) {
        x = ResArch.leer(pos);
        if (x.getEstado() == false) {
            MostrarError("La reserva esta dada de baja", Y + 5);
            rlutil::anykey();
            return;
        }

        // Pedir el nuevo ID del producto
        rlutil::cls();
        rlutil::setColor(4);
        DibujarRecuadro(X2-10, 2, 20, 3); // Recuadro Opción MODIFICAR RESERVA
        rlutil::setColor(15);
        DibujarRecuadro(X2-23, Y-1, 46, 6); // Recuadro General
        DibujarTitulo("MODIFICAR RESERVA", 3);
        MostrarOpcionMenu("Ingrese el ID del nuevo producto:", Y);
        rlutil::locate(X2, Y + 2);
        std::cin >> IDprod;
        std::cin.ignore(); // Limpiar el buffer de entrada

        x.setIDProducto(IDprod);

        if (ResArch.Modificar(x, pos)) {
            MostrarConfirmacion("Se ha modificado correctamente", Y + 5);
        } else {
            MostrarError("No se pudo modificar el producto", Y + 5);
        }
    } else {
        MostrarError("No se pudo modificar, la reserva no existe", Y + 5);
    }
}

void ReservaManager::Menu(){
     int opcion = 1;
    do {
        rlutil::cls();
        rlutil::hidecursor();
        MostrarMenuReservas(opcion);

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
                        BuscarMesasXFecha();
                        rlutil::anykey();
                        break;
                    case 7:
                        rlutil::cls();
                        CopiaSeguridad();
                        rlutil::anykey();
                        break;
                    case 8:
                        rlutil::cls();
                        RestaurarCopiaSeguridad();
                        rlutil::anykey();
                        break;
                    case 9:
                        rlutil::cls();
                        MostrarConfirmacion("Saliendo del Menu Reservas...",12);
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
