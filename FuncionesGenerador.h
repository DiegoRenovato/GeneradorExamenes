#ifndef FUNCIONESGENERADOR_H
#define FUNCIONESGENERADOR_H

#include <string>
#include <cstring>
#include <cctype>
#include <time.h>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

typedef struct Reactivo{
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

typedef nodo *pNodo;

//--------------- Prototipos ---------------//

//---------------- Menú Principal ----------------//

void menu();

//---------------- Visual ----------------//

void mostrarProgreso(double);
void pausa();
void cicloProgreso();

#endif //FUNCIONESGENERADOR_H