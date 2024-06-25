#include "ReservasArchivo.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
ReservaArchivo::ReservaArchivo(){
    _Filename = "Reservas.dat";
    abrirA("ab");
}

ReservaArchivo::ReservaArchivo(string Filename){
     _Filename=Filename;
     abrirA("ab");
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
int ReservaArchivo::buscar(int Numero){ ///BUSCA POR NUMERO DE RESERVA
    Reserva x;
    int pos=0;
     if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return -1;
    }
    while(fread(&x,sizeof(Reserva),1,_p)){
        if(x.getNumero()==Numero){
            break;
        }
        pos++;
    }
    cerrarA();
    if(x.getNumero() == Numero){
        return pos;
    }
    else{return -1;}

}
int ReservaArchivo::buscar(Fecha fecha){ ///BUSCA resrva POR FECHA DE RESERVA
    Reserva x;
    Fecha f;
    int pos=0;
     if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return -1;
    }
    while(fread(&x,sizeof(Reserva),1,_p)){
        f = x.getFecha();
        if(f.getAnio()==fecha.getAnio()){
                if(f.getMes()==fecha.getMes()&&f.getDia()==fecha.getDia()){
                        break;
                }
        }
        pos++;
    }
    cerrarA();
    if(f.getAnio()==fecha.getAnio()){
            if(f.getMes()==fecha.getMes()&&f.getDia()==fecha.getDia()){
                    return pos;
                }
        }
    else{return -1;}

}
bool ReservaArchivo::guardar(Reserva x){
    if(abrirA("ab")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    bool grabo = fwrite(&x,sizeof(Reserva),1,_p);
    cerrarA();
    return grabo;
}
bool ReservaArchivo::Modificar(Reserva x,int pos){
   bool guardado;
   if (abrirA("rb+")==false){
    cout<<"No se encontró el archivo."<<endl;
    return false;
   }
   fseek(_p,sizeof(Reserva)*pos,0);
   guardado = fwrite (&x,sizeof(Reserva),1,_p);
   cerrarA();
   return guardado;
}
Reserva ReservaArchivo::leer(int pos){
    Reserva x;
    if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        x.setNumero(-1);
        return x;
    }
    fseek(_p,sizeof (Reserva)*pos,0);
    fread(&x,sizeof(Reserva),1,_p);
    cerrarA();
    return x;
}
int ReservaArchivo::getCantidadRegistros(){
    if (abrirA("rb")==false){
            cout<<"No se pudo abrir el archivo correctamente"<<endl;
            return 0;
    }
    fseek(_p,0,2);
    int cantbyte = ftell(_p);
    int cantreg = cantbyte/sizeof(Reserva);

    cerrarA();
    return cantreg;

}

bool ReservaArchivo::realizarCopia(const std::string& filename) {
    FILE* pBak;
    Reserva x;

    // Abre el archivo de copia de seguridad en modo escritura
    pBak = fopen(filename.c_str(), "wb");
    if (pBak == nullptr) {
        std::cerr << "No se pudo crear la copia de seguridad: " << filename << std::endl;
        return false;
    }

    int cantreg = getCantidadRegistros();
    for (int i = 0; i < cantreg; i++) {
        x = leer(i);
        if (fwrite(&x, sizeof(Reserva), 1, pBak) != 1) {
            std::cerr << "Error al escribir en la copia de seguridad." << std::endl;
            fclose(pBak);
            return false;
        }
    }

    fclose(pBak); // Cierra el archivo de copia de seguridad
    return true;
}


bool ReservaArchivo::restaurarCopia(const std::string& filename) {
    Reserva x;
    ReservaArchivo archibak(filename.c_str());

    // Abre el archivo principal en modo escritura binaria
    if (!abrirA("wb")) {
        std::cerr << "No se pudo abrir el archivo principal para restaurar." << std::endl;
        return false;
    }

    int cantreg = archibak.getCantidadRegistros();
    for (int i = 0; i < cantreg; i++) {
        x = archibak.leer(i);
        if (fwrite(&x, sizeof(Reserva), 1, _p) != 1) {
            std::cerr << "Error al escribir en el archivo." << std::endl;
            cerrarA();
            return false;
        }
    }

    cerrarA(); // Cierra el archivo principal
    return true;
}
