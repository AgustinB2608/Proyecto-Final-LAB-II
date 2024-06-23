#include "Reservas.h"
Reserva::Reserva(){
    _Numero = 0;
    Fecha x;
    _Fecha = x; ///Hay que hacer que en el constructor se ponga la fecha actual automaticamente
    _NumeroMesa = 0;
    _NumeroPersonas = 0;
    _IDCliente = 0;
    _IDProducto = 0;
    _Estado = false;
}
Reserva::Reserva(int Numero,Fecha fecha, int NumeroMesa, int NumeroPersonas, int IDCliente,  int IDProducto, bool Estado){
    _Numero = Numero;
    _Fecha = fecha;
    _NumeroMesa = NumeroMesa;
    _NumeroPersonas = NumeroPersonas;
    _IDCliente = IDCliente;
    _IDProducto = IDProducto;
    _Estado = Estado;

}

void Reserva::setNumero(int Numero){
    if(Numero>=1 && Numero<=35){
        _Numero = Numero;
}
else _Numero =-1;
}
void Reserva::setFecha(Fecha Fecha){
    _Fecha = Fecha;
}
void Reserva::setNumeroMesa(int NumeroMesa){
    if(NumeroMesa>=1 && NumeroMesa<=50){
        _NumeroMesa = NumeroMesa;
    }
    _NumeroMesa = -1;
}
void Reserva::setNumeroPersonas(int NumeroPersonas){
    if(NumeroPersonas>=1 && NumeroPersonas<=12){
        _NumeroPersonas = NumeroPersonas;
    }
    else _NumeroPersonas = -1;
}
void Reserva::setIDCliente(int IDCliente){ ///Aca habría que verificar que el IDCliente existe en el archivo de clientes, pero no se haría dentro del set creo yo, esa verificacion hay que hacerla antes, CUANDO SE PIDA EL ID CLIENTE EN LA CARGA
        _IDCliente = IDCliente;
}
void Reserva::setIDProducto(int IDProducto){
    _IDProducto = IDProducto;
}
void Reserva::setEstado(bool Estado){
    _Estado = Estado;
}

int Reserva::getNumero(){return _Numero;}
Fecha Reserva::getFecha(){return _Fecha;}
int Reserva::getNumeroMesa(){return _NumeroMesa;}
int Reserva::getNumeroPersonas(){return _NumeroPersonas;}
int Reserva::getIDCliente(){return _IDCliente;}
int Reserva::getIDProducto(){return _IDProducto;}
bool Reserva::getEstado(){return _Estado;}
