#include "bancos.h"

// Clase Banco

void Banco::depositar(double cant){balance += cant;}

// Clase Caja de Ahorro

CajaDeAhorro::CajaDeAhorro(string titularCuenta) : Banco(titularCuenta) {}

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
    cout << "El titular de la cuenta es:" << titularCuenta << "." << endl;
    cout << "Y tiene " << balance << "$ en su cuenta." << endl;
}

// Clase Cuenta Corriente

double CuentaCorriente::retirar(double cant){
    if(balance < cant){
        CajaDeAhorro::retirar(cant);
    }
    balance -= cant;
    return cant;
}