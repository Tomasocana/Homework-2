#include "time.h"

using namespace std;

Time::Time(int hh, int mm, int ss, string n){
    switch(verificador(hh, mm, ss, n)){
        case 0:
            horas = hh;
            minutos = mm;
            segundos = ss;
            m = n;
            return;
        case 1:
            cout << "Hora invalida, estableciendo valores en 0." << endl;
            horas = 0;
            minutos = mm;
            segundos = ss;
            m = n;
            return;
        case 2:
            cout << "Minutos invalidos, estableciendo valores en 0." << endl;
            horas = hh;
            minutos = 0;
            segundos = ss;
            m = n;
            return;
        case 3:
            cout << "Segundos invalidos, estableciendo valores en 0." << endl;
            horas = hh;
            minutos = mm;
            segundos = 0;
            m = n;
            return;
        case 4:
            cout << "Periodo invalido, estableciendo valores predeteminados." << endl;
            horas = hh;
            minutos = mm;
            segundos = ss;
            m = "a.m.";
            return;

    }
};

void Time::showTime(){ cout << setfill('0') << setw(2) << horas << "h, " << setw(2) << minutos << "m, " << setw(2) << segundos << "s, " << m << endl;};

// f
int Time::verificador(int hh, int mm, int ss, string n){
    if(hh < 0 || hh > 23) return 1;
    if(mm < 0 || mm > 59) return 2;
    if(ss < 0 || ss > 59) return 3;
    if(n != "a.m." && n != "p.m.") return 4;
    return 0;
}

// g
void Time::interfaz(){
    int option;
    cout << "Que desea hacer?" << endl;
    cout << "1. Leer hora" << endl;
    cout << "2. Leer minutos" << endl;
    cout << "3. Leer segundos" << endl;
    cout << "4. Leer periodo" << endl;
    cout << "5. Leer todo" << endl;
    cout << "6. Salir" << endl;
    cin >> option;
    switch(option){
        case 1:
            cout << setfill('0') << setw(2) << horas << "h" << endl;
            return;
        case 2:
            cout << setfill('0') << setw(2) << minutos << "m" << endl;
            return;
        case 3:
            cout << setfill('0') << setw(2) << segundos << "s" << endl;
            return;
        case 4:
            cout << m << endl;
            return;
        case 5:
            showTime();
            return;
        case 6:
            return;
    }
}



