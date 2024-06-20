#ifndef VALIDACIONES_GLOBALES_H
#define VALIDACIONES_GLOBALES_H

#include <string>
#include <regex>

bool tieneDigitos(const std::string& str);
bool validarEmail(const std::string& email);


bool tieneDigitos(const std::string& str) {
    for (char c : str) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool validarEmail(const std::string& email) {
    static const std::regex regex_pattern(
        R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"
    );
    return std::regex_match(email, regex_pattern);
}

#endif // VALIDACIONES_GLOBALES_H
