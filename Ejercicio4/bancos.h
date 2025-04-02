#pragma once

#include <iostream>

using namespace std;

class Banco{
    public:
        Banco(string titularCuenta) : titularCuenta(titularCuenta) {}
        void depositar(double cant);
        virtual double retirar(double cant) = 0;
    
    private:
        double balance;
        virtual void mostrarInfo() = 0;

    protected:
        string titularCuenta;
};


class CajaDeAhorro : public Banco {
    public:
        CajaDeAhorro(string titularCuenta) : Banco(titularCuenta) {}
        double retirar(double cant) override {}
        void mostrarInfo() override {}
    private:
        double balance;
};


class CuentaCorriente : public Banco{
    public: 
        CuentaCorriente(string titularCuenta) : Banco(titularCuenta) {}
        double retirar(double cant) override;
        friend class CajaDeAhorro;
    private:
        double balance;
};