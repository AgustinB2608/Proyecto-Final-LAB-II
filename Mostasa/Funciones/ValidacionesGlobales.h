#pragma once
#include <string>
#include <regex>
#include "../Fecha/Fecha.h"
//Prototipos
bool tieneDigitos(const std::string& str);
bool validarEmail(const std::string& email);
bool FechaPosteriorMinimoDosDias(const Fecha& fecha);
/*-*/

inline bool tieneDigitos(const std::string& str) {
    for (char c : str) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

inline bool validarEmail(const std::string& email) {
    static const std::regex regex_pattern(                     ///^ inicio de la cadena, $ final de la cadena
        R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"
    );
    return std::regex_match(email, regex_pattern);
}

inline bool FechaPosteriorMinimoDosDias(const Fecha& fecha) {
    //Tiempo actual en segundos
    time_t tiempoActual = time(NULL);
    //Convertir tiempoActual en una estructura tm que representa la hora xx/xx/xxxx
    struct tm* tmActual = localtime(&tiempoActual);

    // Crea una copia de la estructura tm actual para la fecha futura (2 doas despues)
    struct tm fechaFutura = *tmActual;
    fechaFutura.tm_mday += 2; // Sumar 2 dias al DIA actual en la estructura tm de fechaFutura

    // Normalizamos la fecha futura para ajustar días, meses y años si se excede los límites del mes o año
    mktime(&fechaFutura);//las modificaciones sean validas por ejemplo si hoy fuera 29/6 y =+2 no se verifica daria 31(no hay 31 dias) entonces es 1/7

    // Crear una estructura tm para la fecha ingresada
    struct tm fechaIngresada = {0}; // Inicializar en 0 para evitar valores basura
    fechaIngresada.tm_year = fecha.getAnio() - 1900;  // Ajustar el año en la estructura tm (restar 1900 porque tm_year es el año desde 1900)
    fechaIngresada.tm_mon = fecha.getMes() - 1;       // Ajustar el mes en la estructura tm (restar 1 porque tm_mon es de 0 a 11)
    fechaIngresada.tm_mday = fecha.getDia();           // Ajustar el día en la estructura tm
    fechaIngresada.tm_hour = fechaFutura.tm_hour;     // Ajustar la hora en la estructura tm (de la fecha futura)
    fechaIngresada.tm_min = fechaFutura.tm_min;       // Ajustar los minutos en la estructura tm (de la fecha futura)
    fechaIngresada.tm_sec = fechaFutura.tm_sec;       // Ajustar los segundos en la estructura tm (de la fecha futura)

    // Convertir ambas fechas a time_t para compararlas
    time_t tiempoIngresado = mktime(&fechaIngresada);   // Convertir la fecha ingresada a time_t
    time_t tiempoFutura = mktime(&fechaFutura);         // Convertir la fecha futura a time_t

    // Comparar las fechas usando difftime, que devuelve la diferencia en segundos entre dos time_t
    bool resultado = difftime(tiempoIngresado, tiempoFutura) >= 0;

    // Devolver el resultado de la comparación
    return resultado;
}


