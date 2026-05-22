#include "Vehiculo.h"

Vehiculo::Vehiculo() : placas(""), modelo(""), color("") {}

Vehiculo::Vehiculo(std::string placas, std::string modelo, std::string color)
    : placas(placas), modelo(modelo), color(color) {}

Vehiculo::~Vehiculo() {}

std::string Vehiculo::getPlacas() const { return placas; }
std::string Vehiculo::getModelo() const { return modelo; }
std::string Vehiculo::getColor() const  { return color;  }

void Vehiculo::mostrarInfo() const {
    std::cout << "Placas: " << placas << "\n"
              << "Modelo: " << modelo << "\n"
              << "Color:  " << color  << std::endl;
}
