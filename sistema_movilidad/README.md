# TC1030 Sistema de Movilidad Urbana

Este proyecto está hecho para la clase de POO (TC1030) y simula la operación
lógica de una plataforma de movilidad urbana tipo Uber. Trata sobre una
empresa de transporte que necesita administrar a las personas que
intervienen en cada viaje, por lo que genera una estructura de clases para
poder manejar a sus tipos de personas y a los vehículos que se les asignan.
Las personas se separan en **Usuarios** (pasajeros, que pagan por viajar) y
**Conductores** (que manejan un vehículo). Los vehículos se separan en
**Autos** (con número de puertas) y **Motos** (con cilindraje). Solo los
Conductores tienen un vehículo asignado; los Usuarios únicamente realizan
pagos contra su saldo.

## Funcionalidad

El programa permite el alta de nuevos usuarios, conductores y vehículos,
así como la asignación dinámica de un vehículo a un conductor y el cobro
de viajes al saldo del usuario:

- registro de usuario (con saldo inicial)
- registro de conductor (con licencia)
- registro de auto (con número de puertas)
- registro de moto (con cilindraje)
- asignación / reasignación de vehículo a un conductor
- pago de viaje (sobrecargado: solo monto, o monto + concepto)
- impresión polimórfica de la información de cada objeto

Consta de un `main` de demostración que corre sobre consola y ejecuta cada
una de estas operaciones de manera secuencial.

## Casos que harían que el proyecto deje de funcionar

Estos son los casos límite que rompen la lógica del programa y que el
usuario del sistema debe evitar:

1. **Llamar `mostrarInfo()` sobre un conductor sin vehículo** y suponer
   que imprime datos del vehículo: la clase ya valida `vehiculoAsignado
   != nullptr` e imprime "Sin vehiculo asignado.", pero si se modifica el
   código quitando esa validación se obtiene un `nullptr dereference` y
   el programa se cae.
2. **Pagar más que el saldo disponible** (`realizarPago(monto)` con
   `monto > saldo`): el saldo del usuario queda negativo. La regla de
   negocio se rompe a menos que se valide el monto contra el saldo.
3. **Crear un Auto o Moto con número de puertas o cilindraje negativos**:
   los constructores no validan rangos, por lo que datos inválidos se
   imprimen tal cual.

## Clases abstractas

`Persona` y `Vehiculo` son **clases abstractas**: declaran `mostrarInfo()` como
función virtual pura (`= 0`), por lo que no pueden instanciarse directamente y
obligan a cada subclase a implementar su propia versión. Las subclases concretas
(`Usuario`, `Conductor`, `Auto`, `Moto`) sobrescriben `mostrarInfo()` y reutilizan
la parte común llamando explícitamente a la implementación de la base
(`Persona::mostrarInfo()` / `Vehiculo::mostrarInfo()`). Esto permite el
comportamiento polimórfico al imprimir la información de cada objeto.

## Consideraciones

El programa solo corre en consola y está escrito en **C++ estándar sin dependencias externas, por lo que compila y corre en
cualquier sistema operativo.

Los archivos `.h` se encuentran en `include/` y los `.cpp` en `src/`.

compilar con: `g++ -std=c++17 -Iinclude src/*.cpp -o sistema`

correr en linux/macOS: `./sistema`

correr en windows: `sistema.exe`

