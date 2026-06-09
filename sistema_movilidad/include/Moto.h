#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

// HERENCIA: Moto hereda de Vehiculo.
class Moto : public Vehiculo {
// MODIFICADOR DE ACCESO private: atributo exclusivo de Moto.
private:
    int cilindraje;

public:
    Moto();
    Moto(std::string placas, std::string modelo, std::string color, int cilindraje);

    int getCilindraje() const;

    // SOBREESCRITURA: redefine el metodo virtual heredado de Vehiculo.
    void mostrarInfo() const override;
};

#endif
