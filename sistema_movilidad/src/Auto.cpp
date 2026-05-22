#include "Auto.h"

Auto::Auto() : Vehiculo(), numPuertas(0) {}

Auto::Auto(std::string placas, std::string modelo, std::string color, int numPuertas)
    : Vehiculo(placas, modelo, color), numPuertas(numPuertas) {}

int Auto::getNumPuertas() const { return numPuertas; }

void Auto::mostrarInfo() const {
    std::cout << "--- Auto ---" << std::endl;
    Vehiculo::mostrarInfo();
    std::cout << "Numero de puertas: " << numPuertas << std::endl;
}
