#include "bancos.h"

// Clase Banco

void Banco::depositar(double cant){balance += cant;}

// Clase Caja de Ahorro

double CajaDeAhorro::retirar(double cant){
    if(balance < cant) {
        cout << "Error: Dinero insuficiente en la cuenta" << endl;
        return 0;
    }
    balance -= cant;
    return cant;
}

void CajaDeAhorro::mostrarInfo(){
    static int i = 0;
    if (i >= 2) balance -= (double)20;
    cout << "El titular de la caja de ahorro es: " << titularCuenta << ".";
    cout << " Y tiene " << balance << "$ en su cuenta." << endl;
    i++;
}

// Clase Cuenta Corriente

double CuentaCorriente::retirar(double cant){
    if(balance < cant){
        cout << "Dinero insuficiente en la cuenta corriente. Accediendo a la caja de ahorro..." << endl;
        if(cajaAhorro){
            cajaAhorro->retirar(cant);
        }
        else cout << "No hay caja de ahorro asociada. Imposible retirar dinero." << endl;
        return 0;
    }
    balance -= cant;
    return cant;
}

void CuentaCorriente::mostrarInfo(){
    cout << "El titular de la cuenta corriente es: " << titularCuenta << ".";
    cout << " Y tiene " << balance << "$ en su cuenta." << endl;
}

void menu(){
    cout << "Creando una caja de ahorro:" << endl;
    CajaDeAhorro c((string)"Tomas");
    cout << "Depositando 400 pesos..." << endl;
    c.mostrarInfo();
    cout << endl;
    cout << "Creando una cuenta corriente:" << endl;
    CuentaCorriente b((string)"Tomas", &c);
    b.mostrarInfo();
    cout << "Depositando 200 pesos..." << endl;
    b.depositar((double)200);
    b.mostrarInfo();
    cout << "Intenando retirar 300 pesos de la cuenta corriente:" << endl;
    b.retirar((double)300);
    b.mostrarInfo();
    c.mostrarInfo();
    cout << "Como se mostró 2 veces la caja de ahorro, se descuentan 20 pesos, y asi sucesivamente..." << endl;
    c.mostrarInfo();
    c.mostrarInfo();
}