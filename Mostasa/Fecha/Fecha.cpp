#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Fecha.h"
using namespace std;
Fecha::Fecha(int dia,int mes,int anio){
  _dia=dia;
  _mes=mes;
  _anio=anio;
}
int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}
void Fecha::setDia(int dia){
    if(dia>0&&dia<32){
       _dia=dia;
    }
    else cout<<"Dia ingresado no valido"<<endl; return;
}
void Fecha::setMes(int mes){
    if(mes<13&&mes>0){
        _mes=mes;
    }
    else cout<<"Mes ingresado no valido"<<endl; return;
}
void Fecha::setAnio(int anio){
    if(anio>1899&&anio<2025){
        _anio=anio;
    }
    else cout<<"Año ingresado no valido"<<endl; return;
}



 void Fecha::CargarFecha() {
    bool fechaValida = false;
    while (!fechaValida) {
        std::cout << "Dia: ";
        std::cin >> _dia;
        std::cout << "Mes: ";
        std::cin >> _mes;
        std::cout << "Anio: ";
        std::cin >> _anio;

        if (ValidarFecha()) {
            fechaValida = true;
        } else {std::cout << "La fecha ingresada no es valida. Por favor, ingrese una fecha valida." << std::endl;}}}

bool Fecha::ValidarFecha() {
    /// Obtener la fecha actual 14/5
    time_t tiempo;
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    /// Comparar la fecha ingresada con la fecha actual (Con solo un True ya la fecha pasa como valida)
    if (_anio < 1900 + tmPtr->tm_year) {
        return true; /// La fecha ingresada es anterior a la fecha actual!
    } else if (_anio == 1900 + tmPtr->tm_year) {
        if (_mes < tmPtr->tm_mon + 1) {
            return true; /// fecha ingresada es anterior al mes actual del año actual
        } else if (_mes == tmPtr->tm_mon + 1) {
            if (_dia <= tmPtr->tm_mday) {
                return true; /// La fecha ingresada es anterior o igual al día actual del mes actual y año actual!
                }
            }
        }


    return false; /// La fecha ingresada no es Valida.
}





 void Fecha::MostrarFecha(){
     cout<<"Dia: "<<getDia()<<endl;
     cout<<"Mes: "<<getMes()<<endl;
     cout<<"Año: "<<getAnio()<<endl;

 }
