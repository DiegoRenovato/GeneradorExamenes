#include "FuncionesGenerador.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    archivo *archivos = NULL;
    int cantidad = 0;

    cicloProgreso();

    //1. Cargar archivo (puede que no haya datos previos, o datos cargados correctamente)
    cargarArchivo(&archivos, &cantidad);
    cout << "Presione ENTER para continuar...";
    getchar();

    //2. Llamar al menu
    menu(&archivos, &cantidad);

    //3. Liberar memoria
    free(archivos);

    getchar(); getchar();

    return 0;
}