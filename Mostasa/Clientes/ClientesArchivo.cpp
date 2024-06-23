#include "../Clientes\ClientesArchivo.h"

ClienteArchivo::ClienteArchivo() {
    _Filename = "Clientes.dat";
    // Asegurar que el archivo se cree si no existe
    abrirA("ab");
    cerrarA();
}

ClienteArchivo::ClienteArchivo(std::string Filename) {
    _Filename = Filename;
    // Asegurar que el archivo se cree si no existe
    abrirA("ab");
    cerrarA();
}

bool ClienteArchivo::abrirA(const char* modo) {
    _p = fopen(_Filename.c_str(), modo);
    if (_p == nullptr) {
        std::cerr << "No se pudo abrir el archivo correctamente: " << _Filename << std::endl;
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
        std::cerr << "No se pudo abrir el archivo correctamente para guardar" << std::endl;
        return false;
    }
    bool grabo = fwrite(&x, sizeof(Cliente), 1, _p) == 1;
    cerrarA();
    return grabo;
}

int ClienteArchivo::buscar(int numE) {
    Cliente x;
    int pos = 0;
    if (!abrirA("rb")) {
        std::cerr << "No se pudo abrir el archivo correctamente para buscar" << std::endl;
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

int ClienteArchivo::buscarPorDNI(const std::string& DNI) {
    Cliente x;
    int pos = 0;
    if (!abrirA("rb")) {
        std::cerr << "No se pudo abrir el archivo correctamente para buscar por DNI" << std::endl;
        return -1;
    }
    while (fread(&x, sizeof(Cliente), 1, _p)) {
        if (x.getDNICliente() == DNI) {
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
        std::cerr << "No se pudo abrir el archivo correctamente para leer" << std::endl;
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
        std::cerr << "No se pudo abrir el archivo correctamente para contar registros" << std::endl;
        return 0;
    }
    fseek(_p, 0, SEEK_END);
    int cantbyte = ftell(_p);
    cerrarA();
    return cantbyte / sizeof(Cliente);
}

bool ClienteArchivo::Modificar(Cliente x, int pos) {
    if (!abrirA("rb+")) {
        std::cerr << "No se pudo abrir el archivo correctamente para modificar" << std::endl;
        return false;
    }
    fseek(_p, sizeof(Cliente) * pos, SEEK_SET);
    bool guardado = fwrite(&x, sizeof(Cliente), 1, _p) == 1;
    cerrarA();
    return guardado;
}

bool ClienteArchivo::realizarCopia(const std::string& filename) {
    FILE* pBak;
    Cliente x;

    // Abre el archivo de copia de seguridad en modo escritura binaria
    pBak = fopen(filename.c_str(), "wb");
    if (pBak == nullptr) {
        std::cerr << "No se pudo crear la copia de seguridad: " << filename << std::endl;
        return false;
    }

    int cantreg = getCantidadRegistros(); // Obtiene la cantidad de registros de clientes
    for (int i = 0; i < cantreg; i++) {
        x = leer(i); // Lee el cliente en la posición i
        if (fwrite(&x, sizeof(Cliente), 1, pBak) != 1) {
            std::cerr << "Error al escribir en la copia de seguridad." << std::endl;
            fclose(pBak);
            return false;
        }
    }

    fclose(pBak); // Cierra el archivo de copia de seguridad
    return true;
}


bool ClienteArchivo::restaurarCopia(const std::string& filename) {
    Cliente x;
    ClienteArchivo archibak(filename.c_str()); // Crea una instancia para manejar el archivo de copia

    // Abre el archivo principal en modo escritura binaria
    if (!abrirA("wb")) {
        std::cerr << "No se pudo abrir el archivo principal para restaurar." << std::endl;
        return false;
    }

    int cantreg = archibak.getCantidadRegistros(); // Obtiene la cantidad de registros en la copia
    for (int i = 0; i < cantreg; i++) {
        x = archibak.leer(i); // Lee el cliente en la posición i de la copia
        if (fwrite(&x, sizeof(Cliente), 1, _p) != 1) {
            std::cerr << "Error al escribir en el archivo." << std::endl;
            cerrarA();
            return false;
        }
    }

    cerrarA(); // Cierra el archivo principal
    return true;
}

