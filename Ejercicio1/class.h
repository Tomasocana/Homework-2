#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    private:
        int horas;
        int minutos;
        int segundos;
        string m;
    public:
        Time(int hh = 0, int mm = 0, int ss = 0, string n = "a.m.");
};