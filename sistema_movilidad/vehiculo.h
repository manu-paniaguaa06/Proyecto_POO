#ifndef VEHICULO_H_
#define VEHICULO_H_
#include <string>
#include <sstream>

using namespace std;

//Declaracion de clase Vehiculo que es abstracta
class Vehiculo {

  //Declaro variables de instancia protegidas, visibles para las clases hijas
  protected:
    string placas;
    string modelo;
    string color;
    string tipo;

  //Declaro los metodos que va a tener el objeto
  public:
    Vehiculo() : placas(""), modelo(""), color(""), tipo("") {}; //constructor por default
    Vehiculo(string plac, string mod, string col, string tip) :
      placas(plac), modelo(mod), color(col), tipo(tip) {};
    virtual ~Vehiculo() {}; //destructor virtual para poder borrar con apuntadores a la base

    //Getters
    string get_placas() {
      return placas;
    }
    string get_modelo() {
      return modelo;
    }
    string get_color() {
      return color;
    }
    string get_tipo() {
      return tipo;
    }
    virtual string to_string() = 0; //metodo abstracto
};

//Declaro objeto Auto que hereda de Vehiculo
class Auto : public Vehiculo {

  //Variables de instancia privadas del objeto
  private:
    int num_puertas;

  //Metodos publicos del objeto
  public:
    Auto() : Vehiculo("", "", "", "auto"), num_puertas(0) {};
    Auto(string placas, string modelo, string color, int puertas) :
      Vehiculo(placas, modelo, color, "auto"), num_puertas(puertas) {};

    int get_num_puertas() {
      return num_puertas;
    }
    string to_string();
};

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Auto::to_string() {

  stringstream aux;
  aux << "Placas " << placas << " tipo " << tipo << " modelo " << modelo <<
    " color " << color << " numero de puertas " << num_puertas << "\n";
  return aux.str();
}

//Declaro objeto Moto que hereda de Vehiculo
class Moto : public Vehiculo {

  //Variables de instancia privadas del objeto
  private:
    int cilindraje;

  //Metodos publicos del objeto
  public:
    Moto() : Vehiculo("", "", "", "moto"), cilindraje(0) {};
    Moto(string placas, string modelo, string color, int cilin) :
      Vehiculo(placas, modelo, color, "moto"), cilindraje(cilin) {};

    int get_cilindraje() {
      return cilindraje;
    }
    string to_string();
};

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Moto::to_string() {

  stringstream aux;
  aux << "Placas " << placas << " tipo " << tipo << " modelo " << modelo <<
    " color " << color << " cilindraje " << cilindraje << "cc" << "\n";
  return aux.str();
}

#endif
