#include "../MenuManager\MenuManager.h"

#include <iostream>

using namespace std;

void MenuManager::menu(){

    int op;
    bool t=true;
    while(t){
        system ("cls");
        cout<<"--------- MENU PRINCIPAL --------"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"(1) - PRODUCTOS "<<endl;
        cout<<"(2) - CLIENTES"<<endl;
        cout<<"(3) - RESERVAS"<<endl;
        cout<<"(4) - CONFIGURACION"<<endl;
        cout<<"(5) - XXX"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"(0) - SALIR "<<endl;
        cout<<"---------------------------------"<<endl;
        cin>>op;

        system("cls");
        switch(op){
        case 1:
            ProdManager.Menu();
            break;
        case 2:
            ClientManager.Menu();
            break;
        case 3:
            ReservaManager.Menu();
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 0:
            t=false;
            break;

        default:
            cout<<"---"<<endl;
            break;

        }
        system("pause");
    }
}
