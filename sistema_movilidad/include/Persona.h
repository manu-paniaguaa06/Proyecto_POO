#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

// CLASE ABSTRACTA: Persona no puede instanciarse porque declara una funcion
// virtual pura (mostrarInfo).
class Persona {
// MODIFICADOR DE ACCESO protected: los atributos son visibles para las clases
// hijas (Usuario, Conductor) pero quedan ocultos al exterior.
protected:
    std::string nombre;
    int edad;
    std::string id;

public:
    Persona();
    Persona(std::string nombre, int edad, std::string id);
    // Destructor virtual: necesario para destruir correctamente objetos hijos
    // a traves de un puntero a la base.
    virtual ~Persona();

    // MODIFICADOR DE ACCESO public: getters que dan acceso de solo lectura
    // a los atributos protected.
    std::string getNombre() const;
    int getEdad() const;
    std::string getId() const;

    // CLASE ABSTRACTA: funcion virtual pura (= 0). Obliga a cada
    // subclase a implementar su propia version de mostrarInfo.
    virtual void mostrarInfo() const = 0;
};

#endif
