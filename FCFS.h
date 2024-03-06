//  PROYECTO PRIMER PARCIAL EQUIPO 6 SISTEMAS OPERATIVOS
// Created by Oscar on 24/02/24

#ifndef SISTEMAS_OPERATIVOS__FCFS_H
#define SISTEMAS_OPERATIVOS__FCFS_H
using namespace std;

// Librerias

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// Estructura
struct procesos{
    string nombre;      // Nombre del proceso
    int llegada = 0;    // Tiempo de llegada
    int duracion = 0;   // Duración del proceso
};

// Funciones

float promedio(vector<procesos> lista){ // Función para calcular el promedio de duración de los procesos
    float promedio = 0;
    for (const auto& proceso : lista) {
        promedio += proceso.duracion;
    }
    printf("El promedio de duración de los procesos es: %.2f\n", promedio / lista.size());
    return promedio / lista.size();
}

// Función para comparar dos procesos por su tiempo de llegada
bool compararPorLlegada(const procesos& a, const procesos& b) {
    return a.llegada < b.llegada;
}

// Función para comparar dos procesos por su duración
bool compararPorDuracion(const procesos& a, const procesos& b) {
    return a.llegada < b.llegada;
}

// Función para poblar la lista de procesos
vector<procesos> poblar(int num){
    vector<procesos> lista; 
    //Se repite el numero de veces de processos que hay
    for (int i = 0; i < num; ++i) {
        // crear un  nueva estructura y llenar los datos (nombre, llegada, duración)
        procesos Nuevo; 
        cout << "Dame en nombre el " << i+1 << " proceso: " << endl;
        cin >> Nuevo.nombre;
        do{
            cout << "Dame la llegada del proceso " << Nuevo.nombre << endl;
            cin >> Nuevo.llegada;
        }while(Nuevo.llegada < 0);
        do{
            cout << "Dame la duración del proceso " << Nuevo.nombre << endl;
            cin >> Nuevo.duracion;
            if(Nuevo.duracion > 15 || Nuevo.duracion < 0){
                cout << " La duracción tiene que estar entre 15 y 0" << endl;
            }
        } while (Nuevo.duracion > 15 || Nuevo.duracion < 0);

        // Agregar el proceso a la lista de procesos
        lista.push_back(Nuevo);
    }

    // Verificar que la suma de las duraciones no sea mayor a 15
    int aux = 0;
    for (const auto& proceso : lista) {
        aux += proceso.duracion;
    }

    // Si la suma de las duraciones es mayor a 15, volver a poblar la lista
    if( aux > 15 ){
        cout << "El número maximo de rafagas es de 15 " << endl;
        lista = poblar(num);
    }
    return lista;
}

// Función para ejecutar el algoritmo FCFS (First Come First Served, Primero en llegar, primero en ser atendido)
void FCFS(int num  ){
    vector<procesos> lista; 
    lista = poblar(num);

    // Ordenar el vector por llegada utilizando la función anterior
    std::sort(lista.begin(), lista.end(), compararPorLlegada);

    // Mostrar la lista ordenada por llegada
    std::cout << "\nOrden de Procesos:\n";
    for (const auto& proceso : lista) {
        std::cout << "Nombre: " << proceso.nombre << ", Llegada: " << proceso.llegada
                  << ", Duración: " << proceso.duracion << std::endl;
    }
    promedio(lista);
}

// Función para ejecutar el algoritmo SJF (Shortest Job First, Trabajo más corto primero)   
void SJF(int num){
    vector<procesos> lista; 
    lista = poblar(num);

    // Ordenar el vector por duración utilizando la función anterior
    std::sort(lista.begin(), lista.end(), compararPorDuracion);
    std::cout << "\nLista de Orden :\n";

    // Mostrar la lista ordenada por duración
    for (const auto& proceso : lista) {
        std::cout << "Nombre: " << proceso.nombre << ", Llegada: " << proceso.llegada
                  << ", Duración: " << proceso.duracion << std::endl;
    }
    promedio(lista);
}

// Función para ejecutar el algoritmo RR (Round Robin)
void RR(int num, int quantum){
    vector<procesos> lista;
    lista = poblar(num);

    // Ordenar el vector por llegada utilizando la función anterior
    std::sort(lista.begin(), lista.end(), compararPorLlegada);
    std::vector<procesos> cola = lista; // Copia la lista original
    int tiempo = 0;

    // Mientras haya procesos
    while (!cola.empty()) {

        // Obtener el primer proceso de la cola y eliminarlo, simulando que se está ejecutando
        procesos proceso_actual = cola.front();
        cola.erase(cola.begin());

        // Mostrar el proceso que se está ejecutando
        std::cout << "Ejecutando " << proceso_actual.nombre << " por " << quantum << " unidades de tiempo.\n";

        // Actualizar el tiempo y la duración del proceso 
        if (proceso_actual.duracion > quantum){
            proceso_actual.duracion -= quantum;
            tiempo += quantum;

        // Si el proceso dura menos que el quantum, se termina
        }else{
            tiempo += proceso_actual.duracion;
            proceso_actual.duracion = 0;
        }

        // Mostrar el tiempo actual y la duración restante del proceso y si ha terminado o no
        if (proceso_actual.duracion > 0) {
            // Si el proceso no ha terminado, vuelve a ponerlo en la cola
            cola.push_back(proceso_actual);
        } else {
            std::cout << "Proceso " << proceso_actual.nombre << " completado en el tiempo " << tiempo << ".\n";
        }
    }
    promedio(lista);
}

#endif //SISTEMAS_OPERATIVOS__FCFS_H
