#include "Usuario.h"
#include "Conductor.h"
#include "Auto.h"
#include "Moto.h"

int main() {
    // Solo se instancian clases concretas.
    Usuario u("Manu", 19, "U001", 500.0);
    Conductor c("Carlos", 40, "C001", "LIC-9988");

    // SOBRECARGA: se llama a realizarPago con uno y dos parametros.
    u.realizarPago(120.50);
    u.realizarPago(80.0, "Viaje al centro");

    Auto a1("ABC-123", "Toyota Corolla", "Rojo", 4);
    Moto m1("XYZ-789", "Yamaha FZ", "Negro", 250);

    // POLIMORFISMO: al mismo conductor se le asigna primero un Auto
    // y luego una Moto; cada mostrarInfo imprime el tipo correcto
    // a traves del puntero a la base Vehiculo.
    c.asignarVehiculo(&a1);
    c.mostrarInfo();

    c.asignarVehiculo(&m1);
    c.mostrarInfo();

    std::cout << "\n";
    u.mostrarInfo();

    return 0;
}
