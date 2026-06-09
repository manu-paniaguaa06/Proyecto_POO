#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Persona.h"
#include "Vehiculo.h"

// HERENCIA: Conductor hereda de Persona.
class Conductor : public Persona {
// MODIFICADOR DE ACCESO private: atributos exclusivos de Conductor.
private:
    std::string licencia;
    // POLIMORFISMO: puntero a la clase base Vehiculo; puede apuntar a un Auto
    // o a una Moto.
    Vehiculo* vehiculoAsignado;

public:
    Conductor();
    Conductor(std::string nombre, int edad, std::string id, std::string licencia);

    void asignarVehiculo(Vehiculo* v);

    std::string getLicencia() const;
    Vehiculo* getVehiculoAsignado() const;

    // SOBREESCRITURA: redefine el metodo virtual heredado de Persona.
    void mostrarInfo() const override;
};

#endif
