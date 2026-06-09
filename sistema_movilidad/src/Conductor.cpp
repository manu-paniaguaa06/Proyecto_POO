#include "Conductor.h"

// HERENCIA: el constructor delega en el constructor de base Persona para
// inicializar los atributos heredados.
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

// SOBREESCRITURA: redefine mostrarInfo de Persona y reutiliza la version base.
void Conductor::mostrarInfo() const {
    std::cout << "--- Conductor ---" << std::endl;
    Persona::mostrarInfo();
    std::cout << "Licencia: " << licencia << std::endl;
    if (vehiculoAsignado != nullptr) {
        std::cout << "Vehiculo asignado:" << std::endl;
        // POLIMORFISMO: la llamada se hace sobre un puntero a la base Vehiculo,
        // pero en ejecucion ejecuta el mostrarInfo de Auto o de Moto.
        vehiculoAsignado->mostrarInfo();
    } else {
        std::cout << "Sin vehiculo asignado." << std::endl;
    }
}
