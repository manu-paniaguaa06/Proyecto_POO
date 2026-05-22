#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
private:
    int numPuertas;

public:
    Auto();
    Auto(std::string placas, std::string modelo, std::string color, int numPuertas);

    int getNumPuertas() const;

    void mostrarInfo() const override;
};

#endif
