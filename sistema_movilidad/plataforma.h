#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_
#include <string>
#include <iostream>
#include <sstream>
#include "persona.h"
#include "vehiculo.h"

using namespace std;

const int MAX = 100; //Maximo de personas y vehiculos que se pueden registrar en la plataforma

class Plataforma {
  //Declaro las variables privadas de instancia
  private:

    Persona *personas[MAX]; //se definen como apuntadores para usar polimorfismo
    int num_personas;
    Vehiculo *vehiculos[MAX];
    int num_vehiculos;

  //Declaro constructor por default y metodos publicos
  public:

    Plataforma() : num_personas(0), num_vehiculos(0) {}; //constructor por default
    ~Plataforma(); //destructor, libera la memoria que se pidio

    void agrega_usuario(string id, string nombre, int edad, double saldo);
    void agrega_conductor(string id, string nombre, int edad, string licencia);
    void agrega_auto(string placas, string modelo, string color, int puertas);
    void agrega_moto(string placas, string modelo, string color, int cilindraje);
    void muestra_personas();
    void muestra_personas(string tipo);
    void muestra_vehiculos();
    void muestra_vehiculos(string tipo);
    void consulta_saldo(string id);
    void cobra_viaje(string id, double monto);
    void cobra_viaje(string id, double monto, string concepto);
    void asigna_vehiculo(string id, string placas);
    void elimina_persona(string id, string tipo);
    void elimina_vehiculo(string placas);
};

/**
 * ~Plataforma libera la memoria de todos los objetos
 *
 * recorre los arreglos de personas y vehiculos haciendo delete de cada
 * objeto que se creo con new, se ejecuta solo cuando termina el programa
 * y se destruye la Plataforma.
 *
 * @param
 * @return
 */
Plataforma::~Plataforma() {

  for (int i = 0; i < num_personas; i++)
    delete personas[i];
  for (int i = 0; i < num_vehiculos; i++)
    delete vehiculos[i];
}

/**
 * agrega_usuario crea un objeto Usuario y lo agrega al arreglo de personas
 *
 * crea un objeto Usuario y lo agrega al arreglo de personas usando como
 * indice el numero de personas, el cual despues incrementa en 1.
 *
 * @param string id, string nombre, int edad y double saldo inicial.
 * @return
 */
void Plataforma::agrega_usuario(string id, string nombre, int edad, double saldo) {

  if (num_personas < MAX) {
    //new crea el objeto para usar polimorfismo
    personas[num_personas] = new Usuario(id, nombre, edad, saldo);
    num_personas++;
    cout << "Usuario agregado.\n";
  } else {
    cout << "Ya no hay espacio para mas personas.\n";
  }
}

/**
 * agrega_conductor crea un objeto Conductor y lo agrega al arreglo
 * de personas
 *
 * crea un objeto Conductor y lo agrega al arreglo de personas usando como
 * indice el numero de personas, el cual despues incrementa en 1.
 *
 * @param string id, string nombre, int edad y string licencia.
 * @return
 */
void Plataforma::agrega_conductor(string id, string nombre, int edad, string licencia) {

  if (num_personas < MAX) {
    //new crea el objeto para usar polimorfismo
    personas[num_personas] = new Conductor(id, nombre, edad, licencia);
    num_personas++;
    cout << "Conductor agregado.\n";
  } else {
    cout << "Ya no hay espacio para mas personas.\n";
  }
}

/**
 * agrega_auto crea un objeto Auto y lo agrega al arreglo de vehiculos
 *
 * crea un objeto Auto y lo agrega al arreglo de vehiculos usando como
 * indice el numero de vehiculos, el cual despues incrementa en 1.
 *
 * @param string placas, string modelo, string color e int puertas.
 * @return
 */
void Plataforma::agrega_auto(string placas, string modelo, string color, int puertas) {

  if (num_vehiculos < MAX) {
    //new crea el objeto para usar polimorfismo
    vehiculos[num_vehiculos] = new Auto(placas, modelo, color, puertas);
    num_vehiculos++;
    cout << "Auto agregado.\n";
  } else {
    cout << "Ya no hay espacio para mas vehiculos.\n";
  }
}

/**
 * agrega_moto crea un objeto Moto y lo agrega al arreglo de vehiculos
 *
 * crea un objeto Moto y lo agrega al arreglo de vehiculos usando como
 * indice el numero de vehiculos, el cual despues incrementa en 1.
 *
 * @param string placas, string modelo, string color e int cilindraje.
 * @return
 */
void Plataforma::agrega_moto(string placas, string modelo, string color, int cilindraje) {

  if (num_vehiculos < MAX) {
    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    vehiculos[num_vehiculos] = new Moto(placas, modelo, color, cilindraje);
    num_vehiculos++;
    cout << "Moto agregada.\n";
  } else {
    cout << "Ya no hay espacio para mas vehiculos.\n";
  }
}

/**
 * muestra_personas imprime todas las personas
 *
 * utiliza el arreglo personas[] y el numero de personas, para recorrer todo
 * el arreglo imprimiendo cada uno de los objetos con su metodo to_string().
 *
 * @param
 * @return
 */
void Plataforma::muestra_personas() {

  if (num_personas == 0)
    cout << "No hay personas registradas.\n";
  //Ciclo que recorre el array e imprime cada objeto.
  for (int i = 0; i < num_personas; i++)
    cout << personas[i]->to_string();
}

/**
 * muestra_personas imprime las personas que coinciden con tipo
 *
 * utiliza el array personas[] y el numero de personas, para recorrer todo
 * el aaray imprimiendo cada uno de los objetos que coinciden con el
 * string tipo ("usuario" o "conductor").
 *
 * @param string tipo debe ser: 'usuario' o 'conductor'
 * @return
 */
void Plataforma::muestra_personas(string tipo) {

  int encontrados = 0;
  //Ciclo que recorre el array e imprime cada objeto.
  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == tipo) {
      cout << personas[i]->to_string();
      encontrados++;
    }
  }
  if (encontrados == 0)
    cout << "No hay registros de tipo " << tipo << ".\n";
}

/**
 * muestra_vehiculos imprime todos los vehiculos
 *
 * utiliza el arreglo vehiculos[] y el numero de vehiculos, para recorrer
 * todo el arreglo imprimiendo cada uno de los objetos con su to_string().
 *
 * @param
 * @return
 */
void Plataforma::muestra_vehiculos() {

  if (num_vehiculos == 0)
    cout << "No hay vehiculos registrados.\n";
  //Ciclo que recorre el array e imprime cada objeto.
  for (int i = 0; i < num_vehiculos; i++)
    cout << vehiculos[i]->to_string();
}

/**
 * muestra_vehiculos imprime los vehiculos que coinciden con tipo
 *
 * utiliza el array vehiculos[] y el numero de vehiculos, para recorrer
 * todo el array imprimiendo cada uno de los objetos que coinciden con
 * el string tipo ("auto" o "moto").
 *
 * @param string tipo debe ser: 'auto' o 'moto'
 * @return
 */
void Plataforma::muestra_vehiculos(string tipo) {

  int encontrados = 0;
  //Ciclo que recorre el array e imprime cada objeto.
  for (int i = 0; i < num_vehiculos; i++) {
    if (vehiculos[i]->get_tipo() == tipo) {
      cout << vehiculos[i]->to_string();
      encontrados++;
    }
  }
  if (encontrados == 0)
    cout << "No hay registros de tipo " << tipo << ".\n";
}

/**
 * consulta_saldo busca un usuario por id e imprime su saldo
 *
 * recorre el arreglo de personas buscando un objeto de tipo "usuario"
 * cuyo id coincida, si lo encuentra imprime su saldo y si no avisa
 * que no existe.
 *
 * @param string id del usuario a consultar
 * @return
 */
void Plataforma::consulta_saldo(string id) {

  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == "usuario" && personas[i]->get_id() == id) {
      //convierto el apuntador de la base a Usuario para poder ver su saldo
      Usuario *u = (Usuario*) personas[i];
      cout << "El saldo de " << u->get_nombre() << " es $" << u->get_saldo() << "\n";
      return;
    }
  }
  cout << "No se encontro un usuario con id " << id << ".\n";
}

/**
 * cobra_viaje busca un usuario por id y le cobra un monto
 *
 * recorre el arreglo de personas buscando un objeto de tipo "usuario"
 * cuyo id coincida, si lo encuentra le descuenta el monto de su saldo
 * con realizar_pago() y si no avisa que no existe.
 *
 * @param string id del usuario, double monto a cobrar
 * @return
 */
void Plataforma::cobra_viaje(string id, double monto) {

  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == "usuario" && personas[i]->get_id() == id) {
      //convierto el apuntador de la base a Usuario para poder cobrarle
      Usuario *u = (Usuario*) personas[i];
      u->realizar_pago(monto);
      return;
    }
  }
  cout << "No se encontro un usuario con el id " << id << ".\n";
}

/**
 * cobra_viaje busca un usuario por id y le cobra un monto con concepto
 *
 * es la sobrecarga del metodo cobra_viaje, hace lo mismo pero usa la
 * version de realizar_pago() que tambien recibe el concepto del viaje.
 *
 * @param string id del usuario, double monto a cobrar, string concepto
 * @return
 */
void Plataforma::cobra_viaje(string id, double monto, string concepto) {

  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == "usuario" && personas[i]->get_id() == id) {
      //convierto el apuntador de la base a Usuario para poder cobrarle
      Usuario *u = (Usuario*) personas[i];
      u->realizar_pago(monto, concepto);
      return;
    }
  }
  cout << "No se encontro un usuario con id " << id << ".\n";
}

/**
 * asigna_vehiculo asigna un vehiculo registrado a un conductor
 *
 * busca un conductor por id en el arreglo de personas y un vehiculo por
 * placas en el arreglo de vehiculos, si encuentra los dos guarda el
 * apuntador del vehiculo dentro del conductor (puede ser Auto o Moto
 * porque se guarda como apuntador a la base Vehiculo).
 *
 * @param string id del conductor, string placas del vehiculo
 * @return
 */
void Plataforma::asigna_vehiculo(string id, string placas) {

  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == "conductor" && personas[i]->get_id() == id) {
      //convierto el apuntador de la base a Conductor para asignarle vehiculo
      Conductor *c = (Conductor*) personas[i];
      for (int j = 0; j < num_vehiculos; j++) {
        if (vehiculos[j]->get_placas() == placas) {
          c->asignar_vehiculo(vehiculos[j]);
          cout << "Vehiculo " << placas << " asignado a " << c->get_nombre() << ".\n";
          return;
        }
      }
      cout << "No se encontro un vehiculo con placas " << placas << ".\n";
      return;
    }
  }
  cout << "No se encontro un conductor con id " << id << ".\n";
}

/**
 * elimina_persona busca una persona por tipo e id y la elimina
 *
 * recorre el arreglo de personas buscando el objeto cuyo tipo e id
 * coincidan, si lo encuentra libera su memoria con delete y recorre los
 * elementos restantes un lugar a la izquierda para no dejar huecos.
 *
 * @param string id de la persona, string tipo 'usuario' o 'conductor'
 * @return
 */
void Plataforma::elimina_persona(string id, string tipo) {

  for (int i = 0; i < num_personas; i++) {
    if (personas[i]->get_tipo() == tipo && personas[i]->get_id() == id) {
      delete personas[i]; //objeto eliminado
      //recorro los elementos restantes para no dejar espacios en la numeracion y evitar que se rompa el codigo despues 
      for (int j = i; j < num_personas - 1; j++)
        personas[j] = personas[j + 1];
      num_personas--;
      cout << "Se elimino el " << tipo << " con id " << id << ".\n";
      return;
    }
  }
  cout << "No se encontro " << tipo << " con id " << id << ".\n";
}

/**
 * elimina_vehiculo busca un vehiculo por placas y lo elimina
 *
 * recorre el arreglo de vehiculos buscando el objeto cuyas placas
 * coincidan, antes de borrarlo se lo quita a los conductores que lo
 * tengan asignado para que no quede un apuntador invalido, despues
 * libera su memoria con delete y recorre los elementos restantes.
 *
 * @param string placas del vehiculo a eliminar
 * @return
 */
void Plataforma::elimina_vehiculo(string placas) {

  for (int i = 0; i < num_vehiculos; i++) {
    if (vehiculos[i]->get_placas() == placas) {
      //quito el vehiculo a los conductores que lo tengan asignado
      for (int j = 0; j < num_personas; j++) {
        if (personas[j]->get_tipo() == "conductor") {
          Conductor *c = (Conductor*) personas[j];
          if (c->get_vehiculo() == vehiculos[i])
            c->asignar_vehiculo(nullptr);
        }
      }
      delete vehiculos[i]; //libero la memoria del objeto eliminado
      //recorro los elementos restantes para no dejar espacios en la numeracion y evitar que se rompa el codigo despues 
      for (int j = i; j < num_vehiculos - 1; j++)
        vehiculos[j] = vehiculos[j + 1];
      num_vehiculos--;
      cout << "Se elimino el vehiculo con placas " << placas << ".\n";
      return;
    }
  }
  cout << "No se encontro un vehiculo con placas " << placas << ".\n";
}

#endif 
