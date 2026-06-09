#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

// HERENCIA: Auto hereda de Vehiculo (es un tipo de Vehiculo).
class Auto : public Vehiculo {
// MODIFICADOR DE ACCESO private: atributo exclusivo de Auto.
private:
    int numPuertas;

public:
    Auto();
    Auto(std::string placas, std::string modelo, std::string color, int numPuertas);

    int getNumPuertas() const;

    // SOBREESCRITURA: redefine el metodo virtual heredado de Vehiculo.
    void mostrarInfo() const override;
};

#endif
