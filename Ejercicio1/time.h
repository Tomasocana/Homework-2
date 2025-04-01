#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    private:
        int hours;
        int minutes;
        int seconds;
        string period;
    public:
        Time(int hh = 0, int mm = 0, int ss = 0, string p = "a.m.");
        void showTime();
        void format();
        void funcionality();
        void funcionalityContinue(int hh = 0, int mm = 0, int ss = 0, string p = "a.m.");
};