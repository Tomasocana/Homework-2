#include "bancos.h"

// Clase Banco

void Banco::depositar(double cant){balance += cant;}

// Clase Caja de Ahorro

double CajaDeAhorro::retirar(double cant){
    if(balance < cant) { // Si se intenta sacar mas dinero del que hay en el balance, muestra un error y devuelve 0$
        cout << "Error: Dinero insuficiente en la cuenta" << endl;
        return 0;
    }
    cout << "Dinero retirado con éxito." << endl;
    balance -= cant; // Sino retira el dinero y disminuye el balance
    return cant;
}

void CajaDeAhorro::mostrarInfo(){
    static int i = 0; // Static int para mantener la cuenta de cuantas veces se muestra la información para descontar 20$ cuando se muestra 2 veces o más
    if (i >= 2) balance -= (double)20;
    cout << "El titular de la caja de ahorro es: " << titularCuenta << ".";
    cout << " Y tiene " << balance << "$ en su cuenta." << endl;
    i++;
}

// Clase Cuenta Corriente

double CuentaCorriente::retirar(double cant){
    if(balance < cant){ // Si se intenta retirar mas dinero del que hay en el balance, intenta retirar esa suma de dinero en la cja de ahorro
        cout << "Dinero insuficiente en la cuenta corriente. Accediendo a la caja de ahorro..." << endl;
        if(cajaAhorro){ // Ver si existe una caja de ahorro asociada
            cajaAhorro->retirar(cant);
        }
        else cout << "No hay caja de ahorro asociada. Imposible retirar dinero." << endl;
        return 0;
    }
    cout << "Dinero retirado con éxito." << endl;
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
    c.depositar(400);
    c.mostrarInfo();
    cout << endl;

    cout << "Creando una cuenta corriente:" << endl;
    CuentaCorriente b((string)"Tomas", &c);
    b.mostrarInfo();
    cout << "Depositando 200 pesos..." << endl;
    b.depositar(200);
    b.mostrarInfo();
    cout << endl;

    cout << "Intenando retirar 300 pesos de la cuenta corriente:" << endl;
    b.retirar(300);
    b.mostrarInfo();
    c.mostrarInfo();
    cout << "Se puede ver que disminuyó el balance de la caja de ahorro." << endl; 
    cout << endl;

    cout << "Además como se mostró 2 veces la caja de ahorro, se descuentan 20 pesos, y asi sucesivamente..." << endl;
    c.mostrarInfo();
    c.mostrarInfo();
}