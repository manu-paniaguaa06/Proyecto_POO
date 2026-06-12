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

Consta de un menú con las opciones iniciales y corre sobre consola.

## Casos que harían que el proyecto deje de funcionar

Estos son los casos límite que rompen la lógica del programa y que el
usuario del sistema debe evitar:

1. **Teclear letras en un campo numérico de un alta o cobro** (edad,
   saldo, monto, número de puertas o cilindraje): `cin` queda en estado
   de error permanente y el menú se cicla infinitamente agregando
   registros con datos basura; hay que cerrar el programa (Ctrl+C).
2. **Teclear letras en "Elige una opcion"**: la lectura fallida deja la
   opción en 0, por lo que el programa se cierra como si se hubiera
   elegido Salir y se pierde todo lo capturado.
3. **Terminar la entrada con Ctrl+D (EOF) sin elegir la opción 0**: la
   última opción leída se repite infinitamente porque ya no hay nada
   que leer.
4. **Cobrar un monto negativo**: la validación `monto <= saldo` se
   cumple con números negativos, por lo que el "cobro" aumenta el saldo
   del usuario (cobrar -50 con saldo de $100 lo deja en $150).
5. **Registrar dos personas con el mismo id o dos vehículos con las
   mismas placas**: el programa no valida duplicados, por lo que las
   búsquedas (consultar saldo, cobrar, asignar y eliminar) solo
   encuentran al primero que coincida.
6. **Capturar valores negativos en las altas** (edad, saldo inicial,
   número de puertas o cilindraje): los constructores no validan rangos,
   por lo que los datos inválidos se guardan e imprimen tal cual; un
   saldo inicial negativo deja al usuario sin poder pagar ningún viaje.

Otros casos límite sí están cubiertos por el código: pagar más que el
saldo disponible imprime "Saldo insuficiente" sin dejar el saldo
negativo, eliminar un vehículo que está asignado a un conductor se lo
quita antes de borrarlo (el conductor queda "sin vehiculo asignado"), y
al llegar al límite `MAX` de registros se avisa que ya no hay espacio.

## Clases abstractas

`Persona` y `Vehiculo` son **clases abstractas**: declaran `to_string()` como
función virtual pura (`= 0`), por lo que no pueden instanciarse directamente y
obligan a cada subclase a implementar su propia versión. Las subclases concretas
(`Usuario`, `Conductor`, `Auto`, `Moto`) sobrescriben `to_string()`. Esto permite el
comportamiento polimórfico al imprimir la información de cada objeto.

## Consideraciones

El programa solo corre en consola y está escrito en **C++ estándar** sin dependencias externas, por lo que compila y corre en
cualquier sistema operativo.

Todo el código está dentro de los archivos `.h` (`persona.h`, `vehiculo.h`
y `plataforma.h`) y hay un solo `main.cpp` con el menú.

compilar con: `g++ main.cpp -o sistema`

correr en linux/macOS: `./sistema`

correr en windows: `sistema.exe`

