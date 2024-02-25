//
// Created by Oscar on 24/02/24.
//

#ifndef SISTEMAS_OPERATIVOS__FCFS_H
#define SISTEMAS_OPERATIVOS__FCFS_H
using namespace std;
#include <iostream>
#include <vector>
#include <string>
struct procesos{
    string nombre;
    int llegada = 0;
    int duracion = 0;
};
bool compararPorLlegada(const procesos& a, const procesos& b) {
    return a.llegada < b.llegada;
}
bool compararPorDuracion(const procesos& a, const procesos& b) {
    return a.llegada < b.llegada;
}
vector<procesos> poblar(int num){
    vector<procesos> lista;
    //Se repite el numero de veces de processos que hay
    for (int i = 0; i < num; ++i) {
        // crear un  nueva estructura y llenar los datos
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
        lista.push_back(Nuevo);
    }
    int aux = 0;
    for (const auto& proceso : lista) {
        aux += proceso.duracion;
    }
    if( aux > 15 ){
        cout << "El número maximo de regagas es de 15 " << endl;
        lista = poblar(num);
    }
    return lista;
}
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
}
void SJF(int num){
    vector<procesos> lista;
    lista = poblar(num);


    std::sort(lista.begin(), lista.end(), compararPorDuracion);
    std::cout << "\nLista de Orden :\n";

    for (const auto& proceso : lista) {
        std::cout << "Nombre: " << proceso.nombre << ", Llegada: " << proceso.llegada
                  << ", Duración: " << proceso.duracion << std::endl;
    }
}

void RR(int num, int quantum){
    vector<procesos> lista;
    lista = poblar(num);
    std::sort(lista.begin(), lista.end(), compararPorLlegada);
    std::vector<procesos> cola = lista; // Copia la lista original
    int tiempo = 0;

    while (!cola.empty()) {
        procesos proceso_actual = cola.front();
        cola.erase(cola.begin());

        std::cout << "Ejecutando " << proceso_actual.nombre << " por " << quantum << " unidades de tiempo.\n";

        if (proceso_actual.duracion > quantum){
            proceso_actual.duracion -= quantum;
            tiempo += quantum;
        }else{
            tiempo += proceso_actual.duracion;
            proceso_actual.duracion = 0;
        }

        if (proceso_actual.duracion > 0) {
            // Si el proceso no ha terminado, vuelve a ponerlo en la cola
            cola.push_back(proceso_actual);
        } else {
            std::cout << "Proceso " << proceso_actual.nombre << " completado en el tiempo " << tiempo << ".\n";
        }
    }
}





#endif //SISTEMAS_OPERATIVOS__FCFS_H
