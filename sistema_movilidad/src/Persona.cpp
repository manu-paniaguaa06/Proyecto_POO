#include "Persona.h"

Persona::Persona() : nombre(""), edad(0), id("") {}

Persona::Persona(std::string nombre, int edad, std::string id)
    : nombre(nombre), edad(edad), id(id) {}

Persona::~Persona() {}

std::string Persona::getNombre() const { return nombre; }
int Persona::getEdad() const           { return edad; }
std::string Persona::getId() const     { return id; }

void Persona::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\n"
              << "Edad:   " << edad   << "\n"
              << "ID:     " << id     << std::endl;
}
