#pragma once
#include <string>
#include <regex>

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
    static const std::regex regex_pattern(
        R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"
    );
    return std::regex_match(email, regex_pattern);
}


inline bool FechaPosteriorMinimoDosDias(const Fecha& fecha) {
    // Obtener la fecha actual
    time_t tiempoActual = time(NULL);
    struct tm* tmActual = localtime(&tiempoActual);

    // Crear una estructura tm para la fecha futura (dos días después)
    struct tm fechaFutura = *tmActual;
    fechaFutura.tm_mday += 2; // Sumar dos días

    // Convertir ambas fechas a time_t para compararlas
    time_t tiempoActualConDiasSumados = mktime(&fechaFutura);

    // Crear una estructura tm para la fecha ingresada
    struct tm fechaIngresada = {0}; // Iniciamos en 0 para no recibir valores basura
    fechaIngresada.tm_year = fecha.getAnio() - 1900;
    fechaIngresada.tm_mon = fecha.getMes() - 1;
    fechaIngresada.tm_mday = fecha.getDia();

    time_t tiempoIngresado = mktime(&fechaIngresada);

    // Comparar las fechas
    return difftime(tiempoIngresado, tiempoActualConDiasSumados) > 0;
}

