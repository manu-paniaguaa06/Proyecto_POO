#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Persona.h"
#include "Vehiculo.h"

class Conductor : public Persona {
private:
    std::string licencia;
    Vehiculo* vehiculoAsignado;

public:
    Conductor();
    Conductor(std::string nombre, int edad, std::string id, std::string licencia);

    void asignarVehiculo(Vehiculo* v);

    std::string getLicencia() const;
    Vehiculo* getVehiculoAsignado() const;

    void mostrarInfo() const override;
};

#endif
