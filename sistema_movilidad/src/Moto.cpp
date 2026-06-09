#include "Moto.h"

// HERENCIA: el constructor invoca al constructor de base Vehiculo.
Moto::Moto() : Vehiculo(), cilindraje(0) {}

Moto::Moto(std::string placas, std::string modelo, std::string color, int cilindraje)
    : Vehiculo(placas, modelo, color), cilindraje(cilindraje) {}

int Moto::getCilindraje() const { return cilindraje; }

// SOBREESCRITURA: redefine mostrarInfo de Vehiculo y reutiliza la version base.
void Moto::mostrarInfo() const {
    std::cout << "--- Moto ---" << std::endl;
    Vehiculo::mostrarInfo();
    std::cout << "Cilindraje: " << cilindraje << "cc" << std::endl;
}
