#ifndef FUNCIONESGENERADOR_H
#define FUNCIONESGENERADOR_H

#include <string>
#include <cstring>
#include <cctype>
#include <time.h>
#include <vector>
#include <iostream>
#include <windows.h>
#include <limits> //investigacion en referencias
#include <fstream> //investigacion en referencias
#include <conio.h> //investigacion en referencias

using namespace std;

typedef struct Reactivo{
    int num;
    string pregunta;
    string op1;
    string op2;
    string op3;
    string op4;
    char respuestaCorrecta;
    float puntos;
}reactivo;

typedef struct Nodo{
    reactivo fucky;

    Nodo* siguiente;
    Nodo* anterior;
}nodo;

typedef struct Archivo{
    string nombreArchivo;
}archivo;

typedef nodo *pNodo;

//--------------- Prototipos ---------------//

//---------------- Menú Principal ----------------//

void menu(archivo**, int*);

void generar(archivo**, int*); // Crear examen nuevo (archivo)
void modificar(archivo**, int*); // Modificar examen existente

//---------------- Archivos ----------------//

void cargarExamen(string nombreArchivo, pNodo &inicio, pNodo &fin); // cargar examen desde un archivo
void guardarExamen(string nombreArchivo, pNodo inicio); // guardar examen en un archivo
int listarExamenes(archivo**, int*); // mostrar examenes existentes
void cargarArchivo(archivo**, int*);
void guardarArchivo(archivo**, int*);

//---------------- Lista Doble ----------------//

bool empty(pNodo inicio); // verificar si esta vacia
void insertarFinal(pNodo &inicio, pNodo &fin, reactivo nuevo); // agrgar reactivo al final
pNodo siguienteReactivo(pNodo& actual); // ddesplazar al siguiente reactivo
pNodo anteriorReactivo(pNodo& actual); // desplazar al reactivo anterior
void navegarReactivos(pNodo&); // recorrer lista de reactivos

//---------------- Reactivos ----------------//

reactivo capturarReactivo(int); // crear reactivo
void mostrarReactivo(pNodo actual); // mostrar informacion de un reactivo
void editarReactivo(pNodo actual); // modificar informacion de un reactivo


//---------------- Visual ----------------//

void mostrarProgreso(double);
void pausa();
void cicloProgreso();

#endif //FUNCIONESGENERADOR_H