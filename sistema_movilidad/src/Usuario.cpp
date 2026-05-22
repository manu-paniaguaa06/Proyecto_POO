#include "Usuario.h"

Usuario::Usuario() : Persona(), saldo(0.0) {}

Usuario::Usuario(std::string nombre, int edad, std::string id, double saldo)
    : Persona(nombre, edad, id), saldo(saldo) {}

void Usuario::realizarPago(double monto) {
    if (monto <= saldo) {
        saldo -= monto;
        std::cout << "Pago de $" << monto
                  << " realizado. Saldo restante: $" << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente para realizar el pago." << std::endl;
    }
}

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

void Usuario::mostrarInfo() const {
    std::cout << "--- Usuario ---" << std::endl;
    Persona::mostrarInfo();
    std::cout << "Saldo: $" << saldo << std::endl;
}
