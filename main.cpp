//  PROYECTO PRIMER PARCIAL EQUIPO 6 SISTEMAS OPERATIVOS
#include "FCFS.h"

int main() {
    int opc = -1;
    int aux = -1;
    int quantum = -1;
    setlocale(LC_ALL,"");
    do{
        do{
            cout << "Menú" << endl;
            cout << "1. First Come First Sirve" << endl;
            cout << "2. RR " << endl;
            cout << "3. SJF " << endl;
            cout << "4. Salir" << endl;
            cout << "Dame la opción deseada" << endl;
            cin >> opc;
        }while(opc < 0 || opc > 4);
        switch (opc) {
            case 1:
                do{
                    cout << "¿Cuántos processos van a ser? " << endl;
                    cin >> aux;
                }while(aux < 0 || aux >5 );
                FCFS(aux);
                break;
            case 2:
                do{
                    cout << "¿Cuántos processos van a ser?(maximo 5)  " << endl;
                    cin >> aux;
                }while(aux < 0 || aux >5 );
                do {
                    cout << "¿Cuál va a ser el quantum?(2 , 3 o 4) " << endl;
                    cin >> quantum;
                }while(quantum < 2 || quantum > 4);
                RR(aux, quantum );
                break;
            case 3:
                do{
                    cout << "¿Cuántos processos van a ser? " << endl;
                    cin >> aux;
                }while(aux < 0 || aux >5 );
                SJF(aux);
                break;
            default:
                cout << "Hasta luego" << endl;
        }
    } while (opc != 4);

    return 0;
}
