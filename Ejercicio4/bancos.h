#pragma once

#include <iostream>

using namespace std;

void menu();

class Banco{
    public:
        Banco(string titularCuenta) : titularCuenta(titularCuenta) {}
        void depositar(double cant);
        virtual double retirar(double cant) = 0;
    private:
        virtual void mostrarInfo() = 0;
        double balance;
        
    protected:
        string titularCuenta;
};


class CajaDeAhorro : public Banco {
    public:
        CajaDeAhorro(string titularCuenta) : Banco(titularCuenta) {}
        double retirar(double cant) override;
        void mostrarInfo() override;
    private:
        double balance;
};


class CuentaCorriente : public Banco{
    public: 
        CuentaCorriente(string titularCuenta, CajaDeAhorro* caja) : Banco(titularCuenta), cajaAhorro(caja), balance(0) {}
        double retirar(double cant) override;
        void mostrarInfo() override;
        friend class CajaDeAhorro;
    private:
        CajaDeAhorro* cajaAhorro;
        double balance;
};