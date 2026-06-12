#include <iostream>  
#include "vehiculo.h"
#include "persona.h"
#include "plataforma.h"

using namespace std;

int main() {

  int opcion = -1;
  string temp_id;
  string temp_nombre; 
  string temp_licencia; 
  string temp_placas; 
  string temp_modelo;
  string temp_color; 
  string temp_concepto;
  int temp_edad;
  int temp_puertas;
  int temp_cilindraje;
  double temp_saldo;
  double temp_monto;

  //apuntador: el objeto principal se crea con new en memoria dinamica
  Plataforma *plataforma = new Plataforma();

  //Ciclo del menu, se repite hasta que se elige la opcion 0
  do {
    cout << "\n MENU \n";
    cout << "1. Agregar usuario\n";
    cout << "2. Agregar conductor\n";
    cout << "3. Agregar auto\n";
    cout << "4. Agregar moto\n";
    cout << "5. Asignar vehiculo a conductor\n";
    cout << "6. Consultar todas las personas\n";
    cout << "7. Consultar usuarios\n";
    cout << "8. Consultar conductores\n";
    cout << "9. Consultar todos los vehiculos\n";
    cout << "10. Consultar autos\n";
    cout << "11. Consultar motos\n";
    cout << "12. Consultar saldo de un usuario\n";
    cout << "13. Cobrar viaje a un usuario\n";
    cout << "14. Eliminar usuario\n";
    cout << "15. Eliminar conductor\n";
    cout << "16. Eliminar vehiculo\n";
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {

      case 1: //alta de usuario
        cout << "Id: ";
        getline(cin, temp_id);
        cout << "Nombre: ";
        getline(cin, temp_nombre);
        cout << "Edad: ";
        cin >> temp_edad;
        cout << "Saldo inicial: ";
        cin >> temp_saldo;        
        plataforma->agrega_usuario(temp_id, temp_nombre, temp_edad, temp_saldo);
        break;

      case 2: //alta de conductor
        cout << "Id: ";
        getline(cin, temp_id);
        cout << "Nombre: ";
        getline(cin, temp_nombre);
        cout << "Licencia: ";
        getline(cin, temp_licencia);
        cout << "Edad: ";
        cin >> temp_edad;        
        plataforma->agrega_conductor(temp_id, temp_nombre, temp_edad, temp_licencia);
        break;

      case 3: //alta de auto
        cout << "Placas: ";
        getline(cin, temp_placas);
        cout << "Modelo: ";
        getline(cin, temp_modelo);
        cout << "Color: ";
        getline(cin, temp_color);
        cout << "Numero de puertas: ";
        cin >> temp_puertas;        
        plataforma->agrega_auto(temp_placas, temp_modelo, temp_color, temp_puertas);
        break;

      case 4: //alta de moto
        cout << "Placas: ";
        getline(cin, temp_placas);
        cout << "Modelo: ";
        getline(cin, temp_modelo);
        cout << "Color: ";
        getline(cin, temp_color);
        cout << "Cilindraje: ";
        cin >> temp_cilindraje;        
        plataforma->agrega_moto(temp_placas, temp_modelo, temp_color, temp_cilindraje);
        break;

      case 5: //asignar vehiculo a conductor
        cout << "Id del conductor: ";
        getline(cin, temp_id);
        cout << "Placas del vehiculo: ";
        getline(cin, temp_placas);
        plataforma->asigna_vehiculo(temp_id, temp_placas);
        break;

      case 6: //consultar todas las personas
        plataforma->muestra_personas();
        break;

      case 7: //consultar solo usuarios
        plataforma->muestra_personas("usuario");
        break;

      case 8: //consultar solo conductores
        plataforma->muestra_personas("conductor");
        break;

      case 9: //consultar todos los vehiculos
        plataforma->muestra_vehiculos();
        break;

      case 10: //consultar solo autos
        plataforma->muestra_vehiculos("auto");
        break;

      case 11: //consultar solo motos
        plataforma->muestra_vehiculos("moto");
        break;

      case 12: //consultar saldo de un usuario
        cout << "Id del usuario: ";
        getline(cin, temp_id);
        plataforma->consulta_saldo(temp_id);
        break;

      case 13: //cobrar un viaje a un usuario
        cout << "Id del usuario: ";
        getline(cin, temp_id);
        cout << "Monto del viaje: ";
        cin >> temp_monto;        
        cin.ignore(); 
        cout << "Concepto (enter para omitir): ";
        getline(cin, temp_concepto);
        //sobrecarga: sin concepto se usa la version de dos parametros,
        //con concepto se usa la version de tres parametros
        if (temp_concepto == "")
          plataforma->cobra_viaje(temp_id, temp_monto);
        else
          plataforma->cobra_viaje(temp_id, temp_monto, temp_concepto);
        break;

      case 14: //eliminar usuario
        cout << "Id del usuario: ";
        getline(cin, temp_id);
        plataforma->elimina_persona(temp_id, "usuario");
        break;

      case 15: //eliminar conductor
        cout << "Id del conductor: ";
        getline(cin, temp_id);
        plataforma->elimina_persona(temp_id, "conductor");
        break;

      case 16: //eliminar vehiculo
        cout << "Placas del vehiculo: ";
        getline(cin, temp_placas);
        plataforma->elimina_vehiculo(temp_placas);
        break;

      case 0: //salir del programa
        cout << "Gracias\n";
        break;

      default:
        cout << "Opcion no valida, intenta de nuevo.\n";
    }
  } while (opcion != 0);

  delete plataforma; //libero la memoria del objeto principal, llama a su destructor

  return 0;
}
