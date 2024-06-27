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
    void Mostrar(Reserva x, int X, int &Y);
    void Modificar();
    void Buscar();

    void ListarOrdenado();
    void CopiaSeguridad();
    void RestaurarCopiaSeguridad();

    void ListarMesas(Fecha Fecha);
    void BuscarMesasXFecha();
    bool VerificarMesaDisp(int NumeroM, Fecha &fecha);


};
