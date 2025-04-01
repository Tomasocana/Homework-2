#include "time.h"

using namespace std;

Time::Time(int hh, int mm, int ss, string p){
    hours = hh;
    minutes = mm;
    seconds = ss;
    period = p;
};


void Time::showTime(){ cout << setfill('0') << setw(2) << hours << "h, " << setw(2) << minutes << "m, " << setw(2) << seconds << "s, " << period << endl;};

// h
void Time::format(){
    if (period == "p.m."){
        int h;
        if (hours == 12) h = 12;
        else h = 12 + hours;
        cout << "La hora en formato 24-horas es: " << setfill('0') << setw(2) << h << "hs, " <<  minutes << "m, " << seconds << "s." << endl;
    }
    else cout << "La hora en formato 24-horas es: " << setfill('0') << setw(2) << hours << "hs, " << minutes << "m, " << seconds << "s." << endl;
}

//i
void Time::funcionality(){
    bool cond1 = true;
    while(cond1){
        int opt;
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Inicializar la hora sin parámetros" << endl;
        cout << "2. Inicializar solo con la hora" << endl;
        cout << "3. Iniializar con la hora y los minutos" << endl;
        cout << "4. Inicializar con la hora, los minutos y los segundos" << endl;
        cout << "5. Inicializar con todo" << endl;
        cin >> opt;
        int hh, mm, ss;
        string period;
        bool cond2 = true;
        switch(opt){
            case 1:{
                Time T();
                break;
            }
            case 2:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
                int option;
                while (hh > 12){
                    cout << "Hora fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:{
                            cout << "Ingresar nuevo valor: ";
                            cin >> hh;
                            break;
                        }
                        case 2:{
                            hh = 0;
                            break;
                        }
                    }
                    if(option == 2)break;
                }
                Time T(hh);
                break;
            }
            case 3:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
                int option;
                while (hh > 12){
                    cout << "Hora fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:{
                            cout << "Ingresar nuevo valor: ";
                            cin >> hh;
                            break;
                        }
                        case 2:{
                            hh = 0;
                            break;
                        }
                    }
                }
                if(option == 2)break;

                cout << "Introduza los minutos deseados: ";
                cin >> mm;
                while (mm > 60){
                    cout << "Minutos fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> opt;
                    switch (opt){
                        case 1:{
                            cout << "Ingresar nuevo valor: ";
                            cin >> mm;
                            break;
                        }
                        case 2:{
                            mm = 0;
                            break;
                        }
                    }
                }
                if(option == 2)break;
                Time T(hh,mm);
                break;
            }
            case 4:{

            }
        }
    }

    cout << "Introduzca los segundos desados: ";
    cin >> ss;
    if (ss >= 60){
        while (ss > 12){
            int opt;
            cout << "Segundos fuera de rango." << endl;
            cout << "1. ¿Ingresar un nuevo valor?" << endl;
            cout << "2. Salir" << endl;
            cout << "Respuesta = ";
            cin >> opt;
            switch (opt){
                case 1:
                    cout << "Ingresar nuevo valor: ";
                    cin >> ss;
                    break;
                case 2:
                    cout << "Saliendo del proceso." << endl;
                    return;
            }
        }
    }
    cout << "Introduzca el periodo deseado: ";
    cin >> period;
    if (period != "p.m." && period != "a.m."){
        while (period != "p.m." && period != "a.m."){
            int opt;
            cout << "Periodo no contemplado." << endl;
            cout << "1. ¿Ingresar un nuevo valor?" << endl;
            cout << "2. Salir" << endl;
            cout << "Respuesta = ";
            cin >> opt;
            switch (opt){
                case 1:
                    cout << "Ingresar nuevo valor: ";
                    cin >> period;
                    break;
                case 2:
                    cout << "Saliendo del proceso." << endl;
                    return;
            }
        }
    }
    int option;
    cout << "Que desea hacer?" << endl;
    cout << "1. Leer hora" << endl;
    cout << "2. Leer minutos" << endl;
    cout << "3. Leer segundos" << endl;
    cout << "4. Leer periodo" << endl;
    cout << "5. Leer todo" << endl;
    cout << "6. Salir" << endl;
    cout << "Respuesta = ";
    cin >> option;
    switch(option){
        case 1:
            cout << setfill('0') << setw(2) << hh << "h" << endl;
            break;
        case 2:
            cout << setfill('0') << setw(2) << mm << "m" << endl;
            break;
        case 3:
            cout << setfill('0') << setw(2) << ss << "s" << endl;
            break;
        case 4:
            cout << period << endl;
            break;
        case 5:
            int opt;
            cout << "¿En que formato desea leerlo?" << endl;
            cout << "1. Formato 24-horas" << endl;
            cout << "2. Formato 12-horas" << endl;
            cout << "Respuesta = ";
            cin >> opt;
            if (opt == 1) Time::format();
            else if (opt == 2) Time::showTime();
            else cout << "Opción no contemplada, terminando proceso." << endl; 
            break;
        case 6:
            return;
        default:
            cout << "Opción no contemplada, terminando proceso." << endl;
            break;

    }
}
