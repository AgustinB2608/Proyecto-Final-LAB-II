#include "../Clientes\ClientesArchivo.h"
#include <iostream>
using namespace std;

ClienteArchivo::ClienteArchivo() {
    _Filename = "Clientes.dat";
}

ClienteArchivo::ClienteArchivo(string Filename) {
    _Filename = Filename;
}

bool ClienteArchivo::abrirA(const char* modo) {
    _p = fopen(_Filename.c_str(), modo);
    if (_p == nullptr) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        return false;
    }
    return true;
}

void ClienteArchivo::cerrarA() {
    if (_p) {
        fclose(_p);
        _p = nullptr;
    }
}

bool ClienteArchivo::guardar(Cliente x) {
    if (!abrirA("ab")) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        return false;
    }
    bool grabo = fwrite(&x, sizeof(Cliente), 1, _p) == 1;
    cerrarA();
    return grabo;
}

int ClienteArchivo::buscar(int numE) { // Busca Cliente por ID
    Cliente x;
    int pos = 0;
    if (!abrirA("rb")) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        return -1;
    }
    while (fread(&x, sizeof(Cliente), 1, _p)) {
        if (x.getIDCliente() == numE) {
            cerrarA();
            return pos;
        }
        pos++;
    }
    cerrarA();
    return -1;
}

Cliente ClienteArchivo::leer(int pos) {
    Cliente x;
    if (!abrirA("rb")) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        x.setIDCliente(-1);  // Devuelve un cliente con ID -1 si no se puede abrir el archivo
        return x;
    }
    fseek(_p, sizeof(Cliente) * pos, SEEK_SET);
    fread(&x, sizeof(Cliente), 1, _p);
    cerrarA();
    return x;
}

int ClienteArchivo::getCantidadRegistros() {
    if (!abrirA("rb")) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        return 0;
    }
    fseek(_p, 0, SEEK_END);
    int cantbyte = ftell(_p);
    cerrarA();
    return cantbyte / sizeof(Cliente);
}

bool ClienteArchivo::Modificar(Cliente x, int pos) {
    if (!abrirA("rb+")) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        return false;
    }
    fseek(_p, sizeof(Cliente) * pos, SEEK_SET);
    bool guardado = fwrite(&x, sizeof(Cliente), 1, _p) == 1;
    cerrarA();
    return guardado;
}

bool ClienteArchivo::realizarCopia(std::string filename) {
    FILE *pBak;
    Cliente x;

    pBak = fopen(filename.c_str(), "wb");
    if (pBak == nullptr) {
        return false;
    }

    int cantreg = getCantidadRegistros();
    for (int i = 0; i < cantreg; i++) {
        x = leer(i);
        fwrite(&x, sizeof(Cliente), 1, pBak);
    }
    fclose(pBak);
    return true;
}

bool ClienteArchivo::restaurarCopia(std::string filename) {
    Cliente x;
    ClienteArchivo archibak(filename.c_str());

    if (!abrirA("wb")) {
        return false;
    }

    int cantreg = archibak.getCantidadRegistros();
    for (int i = 0; i < cantreg; i++) {
        x = archibak.leer(i);
        fwrite(&x, sizeof(Cliente), 1, _p);
    }
    cerrarA();
    return true;
}
