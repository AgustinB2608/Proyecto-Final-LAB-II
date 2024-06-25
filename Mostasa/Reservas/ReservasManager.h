#pragma once
#include "../Reservas/Reservas.h"
#include "../Reservas/ReservasArchivo.h"
class ReservaManager{
private:
    Reserva Res;
    ReservaArchivo ResArch;
    void bajaLogica();
public:
    void Menu();
    void MenuCategorias();
    Reserva Crear();
    void Cargar();
    void Listar();
    void Mostrar(Reserva x);
    void Modificar();
    void Buscar();

    void ListarOrdenado();
    void CopiaSeguridad();
    void RestaurarCopiaSeguridad();


};
