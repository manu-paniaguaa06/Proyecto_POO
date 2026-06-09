#include "Usuario.h"

// HERENCIA: el constructor invoca al constructor de la base Persona para
// inicializar los atributos heredados.
Usuario::Usuario() : Persona(), saldo(0.0) {}

Usuario::Usuario(std::string nombre, int edad, std::string id, double saldo)
    : Persona(nombre, edad, id), saldo(saldo) {}

// SOBRECARGA: version que recibe solo el monto del pago.
void Usuario::realizarPago(double monto) {
    if (monto <= saldo) {
        saldo -= monto;
        std::cout << "Pago de $" << monto
                  << " realizado. Saldo restante: $" << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente para realizar el pago." << std::endl;
    }
}

// SOBRECARGA: mismo nombre, distintos parametros.
void Usuario::realizarPago(double monto, std::string concepto) {
    if (monto <= saldo) {
        saldo -= monto;
        std::cout << "Pago de $" << monto << " por '" << concepto
                  << "'. Saldo restante: $" << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente para '" << concepto << "'." << std::endl;
    }
}

double Usuario::getSaldo() const { return saldo; }

// SOBREESCRITURA: redefine mostrarInfo de Persona.
void Usuario::mostrarInfo() const {
    std::cout << "--- Usuario ---" << std::endl;
    Persona::mostrarInfo();
    std::cout << "Saldo: $" << saldo << std::endl;
}
