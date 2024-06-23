#include "ReservasArchivo.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
ReservaArchivo::ReservaArchivo(){
    _Filename = "Reservas.dat";
}

ReservaArchivo::ReservaArchivo(string Filename){
     _Filename=Filename;
}


bool ReservaArchivo::abrirA(string modo){
    _p = fopen(_Filename.c_str(), modo.c_str());
    if(_p==nullptr){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    else{return true;}
}
void ReservaArchivo::cerrarA(){
    fclose(_p);

}
