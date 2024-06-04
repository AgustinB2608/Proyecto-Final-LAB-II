#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

const char* capturarContrasena(char* cad);

int main(){
    char password[10];

    cout << "Ingrese su contrasena: ";
    //ocultarContrasenia(password);
    cin>>password;

    cout << "\nLa contrasena ingresada es: " << password << endl;

    return 0;
}

