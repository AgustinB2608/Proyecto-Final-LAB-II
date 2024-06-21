#include "ReservasManager.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void ReservaManager::Menu(){
    int Opcion;
    while(true){
        system("cls");
        cout<<"---- MENU ----"<<endl;
        cout<<"0 - SALIR"<<endl;
        cin>>Opcion;
            switch(Opcion){
            case 0:
                return;
                break;

            }
            system("pause");
}
}
