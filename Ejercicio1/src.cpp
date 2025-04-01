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
        if (hours == 12 || hours == 0) h = 12;
        else h = 12 + hours;
        cout << "La hora en formato 24-horas es: " << setfill('0') << setw(2) << h << "hs, " <<  minutes << "m, " << seconds << "s." << endl;
    }
    else cout << "La hora en formato 24-horas es: " << setfill('0') << setw(2) << hours << "hs, " << minutes << "m, " << seconds << "s." << endl;
}

void Time::interfaceContinue(int hh, int mm, int ss, string p){
    int h = hh;
    int m = mm;
    int s = ss;
    string pp = p;
    bool cond = true;
    while(cond){
        Time T(hh, mm, ss, p);
        int opt;
        cout << "Que desea hacer?" << endl;
        cout << "1. Leer hora" << endl;
        cout << "2. Leer minutos" << endl;
        cout << "3. Leer segundos" << endl;
        cout << "4. Leer periodo" << endl;
        cout << "5. Leer todo" << endl;
        cout << "6. Cambiar hora" << endl;
        cout << "7. Cambiar minutos" << endl;
        cout << "8. Cambiar segundos" << endl;
        cout << "9. Cambiar periodo" << endl;
        cout << "10. Salir" << endl;
        cout << "Respuesta = ";
        cin >> opt;
        int option;
        switch(opt){
            case 1:{
                cout << setfill('0') << setw(2) << h << "h" << endl;
                break;
            }
            case 2:{
                cout << setfill('0') << setw(2) << m << "m" << endl;
                break;
            }
            case 3:{
                cout << setfill('0') << setw(2) << s << "s" << endl;
                break;
            }
            case 4:{
                cout << pp << endl;
                break;
            }
            case 5:{
                cout << "¿En que formato desea leerlo?" << endl;
                cout << "1. Formato 24-horas" << endl;
                cout << "2. Formato 12-horas" << endl;
                cout << "Respuesta = ";
                cin >> option;
                if (option == 1) T.format();
                else if (option == 2) T.showTime();
                else cout << "Opción no contemplada, terminando proceso." << endl; 
                break;
            }
            case 6:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
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
                h = option;
                break;
            }
            case 7:{
                cout << "Introduza los minutos deseados: ";
                cin >> mm;
                while (mm > 60){
                    cout << "Minutos fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
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
                m = option;
                break;
            }
            case 8:{
                cout << "Introduzca los segundos desados: ";
                cin >> ss;
                while (ss > 60){
                    cout << "Segundos fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:
                            cout << "Ingresar nuevo valor: ";
                            cin >> ss;
                            break;
                        case 2:
                            ss = 0;
                            return;
                    }
                }
                if(option == 2)break;
                s = option;
                break;
            }
            case 9:{
                string opti;
                cout << "Introduzca el periodo deseado: ";
                cin >> period;
                while (period != "p.m." && period != "a.m."){
                    cout << "Periodo no contemplado." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:
                            cout << "Ingresar nuevo valor: ";
                            cin >> period;
                            break;
                        case 2:
                            period = "a.m.";
                            return;
                    }
                }
                if(option == 2)break;
                pp = opti;
                break;
            }
            case 10:{
                return;
            }
            default:{
                cout << "Opción no contemplada" << endl;
                break;
            }
        }
    }
}


//i
void Time::interface(){
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
        int option;
        switch(opt){
            case 1:{
                interfaceContinue();
                break;
            }
            case 2:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
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
                interfaceContinue(hh);
                break;
            }
            case 3:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
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
                    cin >> option;
                    switch (option){
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
                interfaceContinue(hh, mm);
                break;
            }
            case 4:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
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
                    cin >> option;
                    switch (option){
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

                cout << "Introduzca los segundos desados: ";
                cin >> ss;
                while (ss > 60){
                    cout << "Segundos fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:
                            cout << "Ingresar nuevo valor: ";
                            cin >> ss;
                            break;
                        case 2:
                            ss = 0;
                            return;
                    }
                }
                if(option == 2)break;
                interfaceContinue(hh, mm, ss);
                break;
            }
            case 5:{
                cout << "Introduzca la hora deseada: ";
                cin >> hh;
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
                    cin >> option;
                    switch (option){
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

                cout << "Introduzca los segundos desados: ";
                cin >> ss;
                while (ss > 60){
                    cout << "Segundos fuera de rango." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:
                            cout << "Ingresar nuevo valor: ";
                            cin >> ss;
                            break;
                        case 2:
                            ss = 0;
                            return;
                    }
                }
                if(option == 2)break;
                
                cout << "Introduzca el periodo deseado: ";
                cin >> period;
                while (period != "p.m." && period != "a.m."){
                    cout << "Periodo no contemplado." << endl;
                    cout << "1. ¿Ingresar un nuevo valor?" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Respuesta = ";
                    cin >> option;
                    switch (option){
                        case 1:
                            cout << "Ingresar nuevo valor: ";
                            cin >> period;
                            break;
                        case 2:
                            period = "a.m.";
                            return;
                    }
                }
                if(option == 2)break;
                interfaceContinue(hh, mm, ss, period);
                break;
            }
        }
    }
}
