#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
protected:
    std::string placas;
    std::string modelo;
    std::string color;

public:
    Vehiculo();
    Vehiculo(std::string placas, std::string modelo, std::string color);
    virtual ~Vehiculo();

    std::string getPlacas() const;
    std::string getModelo() const;
    std::string getColor() const;

    virtual void mostrarInfo() const;
};

#endif
