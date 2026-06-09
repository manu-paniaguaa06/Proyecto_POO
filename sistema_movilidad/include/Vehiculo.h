#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

// CLASE ABSTRACTA: Vehiculo no puede instanciarse (tiene una funcion virtual
// pura).
class Vehiculo {
// MODIFICADOR DE ACCESO protected: atributos accesibles por las hijas
// (Auto, Moto) pero ocultos al exterior.
protected:
    std::string placas;
    std::string modelo;
    std::string color;

public:
    Vehiculo();
    Vehiculo(std::string placas, std::string modelo, std::string color);
    // Destructor virtual para una correcta destruccion polimorfica.
    virtual ~Vehiculo();

    // MODIFICADOR DE ACCESO public: getters.
    std::string getPlacas() const;
    std::string getModelo() const;
    std::string getColor() const;

    // CLASE ABSTRACTA: funcion virtual pura (= 0) que cada
    // subclase debe redefinir.
    virtual void mostrarInfo() const = 0;
};

#endif
