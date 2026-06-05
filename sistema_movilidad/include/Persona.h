#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    std::string nombre;
    int edad;
    std::string id;

public:
    Persona();
    Persona(std::string nombre, int edad, std::string id);
    virtual ~Persona();

    std::string getNombre() const;
    int getEdad() const;
    std::string getId() const;

    virtual void mostrarInfo() const = 0;
};

#endif
