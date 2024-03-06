#include <iostream>
#include <windows.h> // Para la función Sleep()
#include "FCFS.h"

using namespace std;

void acentos() {
  #ifdef _WIN32
  // Establecer la página de códigos de salida de la consola en UTF-8
  SetConsoleOutputCP(CP_UTF8);
  #else
  // Establecer la configuración regional para todos los locales en "es_ES.UTF-8"
  setlocale(LC_ALL, "es_ES.UTF-8");
  #endif
}

int main() {
  acentos(); // Configurar la consola para mostrar acentos y caracteres especiales

  // Variables para el menú
  int opc = -1;
  int aux = -1;
  int quantum = -1;

  // Bucle principal del menú
  do {
    system("cls"); // Limpiar la pantalla

    // Mostrar el menú
    cout << "***********************************" << endl;
    cout << "** PROYECTO PRIMER PARCIAL EQUIPO 6 **" << endl;
    cout << "** SISTEMAS OPERATIVOS             **" << endl;
    cout << "***********************************" << endl;
    cout << endl;
    cout << "1. First Come First Served (FCFS)" << endl;
    cout << "2. Round Robin (RR)" << endl;
    cout << "3. Shortest Job First (SJF)" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    cout << "Digite la opción deseada: ";
    cin >> opc;

    // Validar la entrada del usuario
    while (opc < 1 || opc > 4) {
      cout << "Opción inválida. Digite un número entre 1 y 4: ";
      cin >> opc;
    }

    // Seleccionar la opción del menú
    switch (opc) {
      case 1:
        // FCFS
        do {
          cout << "¿Cuántos procesos van a ser? (Máximo 5): ";
          cin >> aux;
        } while (aux < 1 || aux > 5);
        FCFS(aux);
        break;
      case 2:
        // RR
        do {
          cout << "¿Cuántos procesos van a ser? (Máximo 5): ";
          cin >> aux;
        } while (aux < 1 || aux > 5);
        do {
          cout << "¿Cuál va a ser el quantum? (2, 3 o 4): ";
          cin >> quantum;
        } while (quantum < 2 || quantum > 4);
        RR(aux, quantum);
        break;
      case 3:
        // SJF
        do {
          cout << "¿Cuántos procesos van a ser? (Máximo 5): ";
          cin >> aux;
        } while (aux < 1 || aux > 5);
        SJF(aux);
        break;
      case 4:
        // Salir
        cout << "Hasta luego!" << endl;
        Sleep(1000); // Esperar 1 segundo antes de salir
        break;
    }

    // Mostrar un mensaje de confirmación y esperar a que el usuario presione una tecla para continuar con el menú
    cout << endl;
    cout << "Presione cualquier tecla para continuar..." << endl;
    cin.ignore();
    cin.get();

  } while (opc != 4);

  return 0;
}
