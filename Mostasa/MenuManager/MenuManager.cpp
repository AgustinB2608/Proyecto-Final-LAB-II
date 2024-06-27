#include "../MenuManager\MenuManager.h"
#include "../Funciones\FuncionesGraficas\rlutil.h"
#include "../Funciones\FuncionesGraficas\globales.h"
#include <iostream>

using namespace std;

void MenuManager::Menu() {
    int opcion = 1;
    do {
        rlutil::cls();
        rlutil::hidecursor();
        MostrarMenuPrincipal(opcion);

        int Key = rlutil::getkey();

        switch (Key) {
            case rlutil::KEY_UP:
                opcion--;
                if (opcion < 1) opcion = 5;
                break;
            case rlutil::KEY_DOWN:
                opcion++;
                if (opcion > 5) opcion = 1;
                break;
            case rlutil::KEY_ENTER:
                switch (opcion) {
                    case 1:
                        rlutil::cls();
                        ProdManager.Menu();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        ClientManager.Menu();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        ReservaManager.Menu();
                        rlutil::anykey();
                        break;
                    case 4:
                        rlutil::cls();
                        //MostrarMenuInformacion();
                        rlutil::anykey();
                        break;
                    case 5:
                        rlutil::cls();
                        MostrarConfirmacion("Saliendo de Mostasa. :)",12);
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

