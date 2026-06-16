#include "FuncionesGenerador.h"

//---------------- Menú Principal ----------------//

void menu(){
    int opc, n=0;

    do{
        system("cls || clear");
        system("color 0B");
        //system("color 02"); -> verde
        //system("color 03"); -> aqua
        //system("color 0A"); -> verde claro
        //system("color 0B"); -> aqua claro
        //system("color 0E"); -> amarillo claro
        cout << "╔══════════════════════════════════╗\n";
        cout << "║        Generador Examenes        ║\n";
        cout << "╠══════════════════════════════════╣\n";
        cout << "║  1) Generar Examen               ║\n";
        cout << "║  2) Modificar Examen             ║\n";
        cout << "║  3) Aplicar Examen               ║\n";
        cout << "║  4) Salir                        ║\n";
        cout << "╠══════════════════════════════════╣\n";
        cout << "║  Seleccione una opción:          ║\n";
        cout << "╚══════════════════════════════════╝\n";
        cout << "➜ ";
        scanf("%d", &opc);

        switch (opc){
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            system("cls || clear");
            cicloProgreso();
            printf("Saliendo...\n");
            system("pause");
            break;
        
        default:
            printf("Opcion no valida. Ingrese una opcion disponible nuevamente\n");
            break;
        }
    }while(opc != 4);
}


//---------------- Visual ----------------//

void mostrarProgreso(double progreso) {
    const int anchoBarra = 50;

    cout << "\r[";
    
    int posicion = progreso * anchoBarra;

    for (int i = 0; i < anchoBarra; i++) {
        if (i < posicion)
            cout << "=";
        else if (i == posicion)
            cout << ">";
        else
            cout << " ";
    }

    cout << "] " << int(progreso * 100) << "%";
    cout.flush();
}

void pausa() {
    for(long i = 0; i < 4000000; i++) {
        // ciclo vacío para retraso
    }
}

void cicloProgreso(){
    int total = 100;

    for (int i = 0; i <= total; i++) {
        double progreso = (double)i / total;
        mostrarProgreso(progreso);

        pausa();
    }

    cout << "\nProceso completado exitosamente.\n";
}