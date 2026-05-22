#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"

class Usuario : public Persona {
private:
    double saldo;

public:
    Usuario();
    Usuario(std::string nombre, int edad, std::string id, double saldo);

    void realizarPago(double monto);
    void realizarPago(double monto, std::string concepto);

    double getSaldo() const;

    void mostrarInfo() const override;
};

#endif
