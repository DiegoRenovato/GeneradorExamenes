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

//---------------- Archivos ----------------//

void guardarExamen(string nombreArchivo, pNodo inicio); // guardar examen en un archivo
void cargarArchivo(archivo**, int*); 
void guardarArchivo(archivo**, int);

//---------------- Lista Doble ----------------//

bool empty(pNodo inicio); // verificar si esta vacia
void insertarFinal(pNodo &inicio, pNodo &fin, reactivo nuevo); // agrgar reactivo al final

//---------------- Reactivos ----------------//

reactivo capturarReactivo(int); // crear reactivo

//---------------- Visual ----------------//

void mostrarProgreso(double);
void pausa();
void cicloProgreso();

#endif //FUNCIONESGENERADOR_H