#include "Conductor.h"

Conductor::Conductor()
    : Persona(), licencia(""), vehiculoAsignado(nullptr) {}

Conductor::Conductor(std::string nombre, int edad, std::string id, std::string licencia)
    : Persona(nombre, edad, id), licencia(licencia), vehiculoAsignado(nullptr) {}

void Conductor::asignarVehiculo(Vehiculo* v) {
    vehiculoAsignado = v;
    std::cout << "Vehiculo asignado al conductor " << nombre << "." << std::endl;
}

std::string Conductor::getLicencia() const     { return licencia; }
Vehiculo* Conductor::getVehiculoAsignado() const { return vehiculoAsignado; }

void Conductor::mostrarInfo() const {
    std::cout << "--- Conductor ---" << std::endl;
    Persona::mostrarInfo();
    std::cout << "Licencia: " << licencia << std::endl;
    if (vehiculoAsignado != nullptr) {
        std::cout << "Vehiculo asignado:" << std::endl;
        vehiculoAsignado->mostrarInfo();
    } else {
        std::cout << "Sin vehiculo asignado." << std::endl;
    }
}
