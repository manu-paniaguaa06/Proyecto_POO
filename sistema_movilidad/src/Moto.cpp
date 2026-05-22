#include "Moto.h"

Moto::Moto() : Vehiculo(), cilindraje(0) {}

Moto::Moto(std::string placas, std::string modelo, std::string color, int cilindraje)
    : Vehiculo(placas, modelo, color), cilindraje(cilindraje) {}

int Moto::getCilindraje() const { return cilindraje; }

void Moto::mostrarInfo() const {
    std::cout << "--- Moto ---" << std::endl;
    Vehiculo::mostrarInfo();
    std::cout << "Cilindraje: " << cilindraje << "cc" << std::endl;
}
