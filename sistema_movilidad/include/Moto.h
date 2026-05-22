#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

class Moto : public Vehiculo {
private:
    int cilindraje;

public:
    Moto();
    Moto(std::string placas, std::string modelo, std::string color, int cilindraje);

    int getCilindraje() const;

    void mostrarInfo() const override;
};

#endif
