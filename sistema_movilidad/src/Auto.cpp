#include "Auto.h"

// HERENCIA: el constructor invoca al constructor de base Vehiculo.
Auto::Auto() : Vehiculo(), numPuertas(0) {}

Auto::Auto(std::string placas, std::string modelo, std::string color, int numPuertas)
    : Vehiculo(placas, modelo, color), numPuertas(numPuertas) {}

int Auto::getNumPuertas() const { return numPuertas; }

// SOBREESCRITURA: redefine mostrarInfo de Vehiculo y reutiliza la version base.
void Auto::mostrarInfo() const {
    std::cout << "--- Auto ---" << std::endl;
    Vehiculo::mostrarInfo();
    std::cout << "Numero de puertas: " << numPuertas << std::endl;
}
