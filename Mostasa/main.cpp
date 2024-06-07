#include <iostream>
#include <cstring>
#include <conio.h>
#include "ProductosManager.h"

using namespace std;

const char* capturarContrasena(char* cad);

int main(){
    ProductoManager prodman;
    prodman.Menu();
    char password[10];

    cout << "Ingrese su contrasena: ";
    //ocultarContrasenia(password);
    cin>>password;

    cout << "\nLa contrasena ingresada es: " << password << endl;

    return 0;
}
/*
#include <iostream>
#include "Clientes\Clientes.h"

int main() {
    Cliente cliente1;
    int id;

    std::cout << "ID: ";
    std::cin >> id;
    cliente1.setIDCliente(id);
    cliente1.setNombreCliente("Agustin Bernal");
    cliente1.setEmailCliente("agustin@gmail.com");
    cliente1.setTelefonoCliente("123456789");

    std::cout << "ID: " << cliente1.getIDCliente() << std::endl;
    std::cout << "Nombre: " << cliente1.getNombreCliente() << std::endl;
    std::cout << "Email: " << cliente1.getEmailCliente() << std::endl;
    std::cout << "Telefono: " << cliente1.getTelefonoCliente() << std::endl;

    return 0;
}

*/
