#ifndef PERSONA_H_
#define PERSONA_H_
#include <string>
#include <sstream>
#include <iostream>
#include "vehiculo.h"

using namespace std;

//Declaracion de clase Persona que es abstracta
class Persona {

  //Declaro variables de instancia protegidas, visibles para las clases hijas
  protected:
    string id;
    string nombre;
    int edad;
    string tipo;

  //Declaro los metodos que va a tener el objeto
  public:
    Persona() : id(""), nombre(""), edad(0), tipo("") {}; //constructor por default
    Persona(string id_p, string nom, int ed, string tip) :
      id(id_p), nombre(nom), edad(ed), tipo(tip) {}; //constructor con parametros
    virtual ~Persona() {}; //destructor virtual para poder borrar con apuntadores

    // Getters
    string get_id() {
      return id;
    }
    string get_nombre() {
      return nombre;
    }
    int get_edad() {
      return edad;
    }
    string get_tipo() {
      return tipo;
    }
    virtual string to_string() = 0; //metodo abstracto
};

//Declaro objeto Usuario que hereda de Persona
class Usuario : public Persona {

  //Variable de instancia privada, el saldo solo se modifica con los metodos
  private:
    double saldo;

  //Metodos publicos del objeto
  public:
    Usuario() : Persona("", "", 0, "usuario"), saldo(0) {}; //Constructor por default
    Usuario(string id, string nombre, int edad, double sal) :
      Persona(id, nombre, edad, "usuario"), saldo(sal) {}; //Constructor con parametros

    double get_saldo() {
      return saldo;
    }
    void realizar_pago(double monto);
    void realizar_pago(double monto, string concepto); //sobrecarga del metodo
    string to_string();
};

/**
 * realizar_pago descuenta un monto del saldo del usuario
 *
 * verifica que el saldo alcance, si alcanza lo descuenta y muestra el
 * saldo restante, si no alcanza avisa que no se pudo hacer el pago.
 *
 * @param double monto a pagar
 * @return
 */
void Usuario::realizar_pago(double monto) {

  if (monto <= saldo) {
    saldo = saldo - monto;
    cout << "Pago de " << monto << " realizado. Saldo restante $" << saldo << "\n";
  } else {
    cout << "Saldo insuficiente para realizar el pago.\n";
  }
}

/**
 * realizar_pago descuenta un monto del saldo indicando el concepto
 *
 * es la sobrecarga del metodo realizar_pago, hace lo mismo pero ademas
 * imprime el concepto del viaje que se esta cobrando.
 *
 * @param double monto a pagar, string concepto del pago
 * @return
 */
void Usuario::realizar_pago(double monto, string concepto) {

  if (monto <= saldo) {
    saldo = saldo - monto;
    cout << "Pago de " << monto << " por " << concepto <<
      ". Saldo restante $" << saldo << "\n";
  } else {
    cout << "Saldo insuficiente para " << concepto << ".\n";
  }
}

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Usuario::to_string() {

  stringstream aux;
  aux << "Id " << id << " tipo " << tipo << " su nombre es " << nombre <<
    " edad " << edad << " su saldo es $" << saldo << "\n";
  return aux.str();
}

//Declaro objeto Conductor que hereda de Persona
class Conductor : public Persona {

  //Variables de instancia privadas del objeto
  private:
    string licencia;
    Vehiculo *vehiculo_asignado; //apuntador a la base para usar polimorfismo

  //Metodos publicos del objeto
  public:
    Conductor() : Persona("", "", 0, "conductor"), licencia(""),
      vehiculo_asignado(nullptr) {}; //Constructor por default
    Conductor(string id, string nombre, int edad, string lic) :
      Persona(id, nombre, edad, "conductor"), licencia(lic),
      vehiculo_asignado(nullptr) {}; //Constructor con parametros

      // Getters
    string get_licencia() {
      return licencia;
    }
    Vehiculo* get_vehiculo() {
      return vehiculo_asignado;
    }
    void asignar_vehiculo(Vehiculo *v) {
      vehiculo_asignado = v;
    }
    string to_string();
};

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser
 * impreso, si el conductor tiene vehiculo asignado tambien agrega la
 * informacion del vehiculo usando su propio to_string().
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Conductor::to_string() {

  stringstream aux;
  aux << "Id " << id << " tipo " << tipo << " su nombre es " << nombre <<
    " edad " << edad << " licencia " << licencia << "\n";
  if (vehiculo_asignado != nullptr)
    aux << "   vehiculo asignado: " << vehiculo_asignado->to_string();
  else
    aux << "   sin vehiculo asignado\n";
  return aux.str();
}

#endif 