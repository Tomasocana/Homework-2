#pragma once

#include <iostream>

using namespace std;

class Banco{
    public:
        Banco();
        void depositar();
        void retirar();
    
    private:
        double balance;
        double balance();
        void mostrarInfo();

    protected:
        string titularCuenta();
};


class CajaDeAhorro : private Banco {
    public:
        CajaDeAhorro();
        void retirar();
    
    private:
        double balance;
        void mostrarInfo();
};


class CuentaCorriente : private Banco{
    public: 
        CuentaCorriente();
        void retirar();

};