#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

void menu(); // Función para abrir el menu para interactuar con el usuario
void menuContinue(int hh = 0, int mm = 0, int ss = 0, string p = "a.m."); // Función para continuar con el menu de interacción con el usuario

class Time{
    private:
        int hours;
        int minutes;
        int seconds;
        string period;
    public:
        Time(int hh = 0, int mm = 0, int ss = 0, string p = "a.m.");
        void showTime(); // Función que muestra la hora 
        void format(); // Función para cambiar el formato de la hora
};