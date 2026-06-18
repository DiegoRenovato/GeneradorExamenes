#include "FuncionesGenerador.h"

//---------------- Menú Principal ----------------//

void menu(archivo **archivos, int* cantidad){
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
            generar(archivos, cantidad);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            system("cls || clear");
            guardarArchivo(archivos, cantidad);
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

void generar(archivo** archivos, int* cantidad){

    reactivo nuevo;
    bool repetido = false;

    pNodo inicio = NULL;
    pNodo fin = NULL;

    int n;

    string nombre;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    do{
        system("cls || clear");
        repetido = false;
        cout << "Ingrese nombre de archivo: ";
        getline(cin, nombre);

        for(int i = 0; i < *cantidad; i++){
            if((*archivos + i)->nombreArchivo == (nombre + ".txt")){
                repetido = true;

                cout << "Nombre de archivo ya existente. Intente de nuevo";
                system("pause");
                break;
            }
        }
    }while(repetido);


    cout << "Ingrese numero de reactivos de examen: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        nuevo = capturarReactivo(i);
        insertarFinal(inicio, fin, nuevo);
    }

    guardarExamen(nombre + ".txt", inicio);

    archivo* nuevoArreglo = new archivo[*cantidad + 1];

    for(int i = 0; i < *cantidad; i++){
        nuevoArreglo[i] = (*archivos)[i];
    }

    

    if(nuevoArreglo == NULL){
        printf("Ocurrio un error al momento de reservar memoria");
        return;
    }

    delete[] *archivos;

    *archivos = nuevoArreglo;

    (*archivos)[*cantidad].nombreArchivo = nombre + ".txt";
    (*cantidad)++;
}


//---------------- Archivos ----------------//

void guardarExamen(string nombreArchivo, pNodo inicio){
    ofstream archivo(nombreArchivo.c_str());

    if(!archivo){
        cout << "Error al crear el archivo." << endl;
        return;
    }

    pNodo aux = inicio;

    while(aux != NULL){

        archivo << ":Reactivo;" << aux->fucky.num << endl;
        archivo << ":p;" << aux->fucky.pregunta << endl;
        archivo << ":a;" << aux->fucky.op1 << endl;
        archivo << ":b;" << aux->fucky.op2 << endl;
        archivo << ":c;" << aux->fucky.op3 << endl;
        archivo << ":d;" << aux->fucky.op4 << endl;
        archivo << ":r;" << aux->fucky.respuestaCorrecta << endl;
        archivo << ":p;" << aux->fucky.puntos << endl;
        archivo << string(50, '-') << endl;

        aux = aux->siguiente;
    }

    archivo.close();

    cicloProgreso();
    cout << "Examen guardado correctamente." << endl;
    system("pause");
}

void cargarArchivo(archivo **archivos, int *cantidad){

    FILE *f = fopen("examenesGuardados.dat", "rb");

    if(f == NULL){
        printf("No hay datos previos\n");
        *cantidad = 0;
        *archivos = NULL;
        return;
    }

    fread(cantidad, sizeof(int), 1, f);

    *archivos = new archivo[*cantidad];

    for(int i = 0; i < *cantidad; i++){

        int longitud;

        fread(&longitud, sizeof(int), 1, f);

        char* buffer = new char[longitud + 1];

        fread(buffer, sizeof(char), longitud, f);

        buffer[longitud] = '\0';

        (*archivos)[i].nombreArchivo = buffer;

        delete[] buffer;
    }

    fclose(f);

    printf("Datos cargados correctamente\n");
}

void guardarArchivo(archivo **archivos, int *cantidad){
    FILE* f = fopen("examenesGuardados.dat", "wb");

    fwrite(cantidad, sizeof(int), 1, f);

    for(int i = 0; i < *cantidad; i++){

    int longitud = (*archivos)[i].nombreArchivo.length();

    fwrite(&longitud, sizeof(int), 1, f);

    fwrite((*archivos)[i].nombreArchivo.c_str(),
           sizeof(char),
           longitud,
           f);
    }

    fclose(f);
}


//---------------- Lista Doble ----------------//

bool empty(pNodo inicio){
    return inicio == NULL;
}

void insertarFinal(pNodo &inicio, pNodo &fin, reactivo nuevo){
    pNodo aux = new nodo;
    aux->fucky = nuevo;
    aux->siguiente = NULL;

    if(empty(inicio)){
        inicio = aux;
        fin = aux;
    }else{
        fin->siguiente = aux;
        fin = aux;
    }
}


//---------------- Reactivos ----------------//

reactivo capturarReactivo(int i){
    reactivo aux;

    aux.num = i;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    cout << "Ingrese Pregunta: ";
    getline(cin, aux.pregunta);

    cout << "Ingrese opcion a): ";
    getline(cin, aux.op1);

    cout << "Ingrese opcion b): ";
    getline(cin, aux.op2);

    cout << "Ingrese opcion c): ";
    getline(cin, aux.op3);

    cout << "Ingrese opcion d): ";
    getline(cin, aux.op4);

    cout << "Ingrese respuesta correcta (a,b,c,d): ";
    cin >> aux.respuestaCorrecta;

    cout << "Ingrese puntos de reactivo: ";
    cin >> aux.puntos;

    return aux;
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