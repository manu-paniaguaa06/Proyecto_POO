#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"

// HERENCIA: Usuario hereda de Persona.
class Usuario : public Persona {
// MODIFICADOR DE ACCESO private: el saldo solo se modifica desde la clase.
private:
    double saldo;

public:
    Usuario();
    Usuario(std::string nombre, int edad, std::string id, double saldo);

    // SOBRECARGA: mismo nombre de metodo, distintos parametros.
    // Una version recibe solo el monto y otra el monto mas un concepto.
    void realizarPago(double monto);
    void realizarPago(double monto, std::string concepto);

    double getSaldo() const;

    // SOBREESCRITURA: redefine el metodo virtual heredado de Persona.
    void mostrarInfo() const override;
};

#endif
