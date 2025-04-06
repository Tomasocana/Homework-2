#pragma once

#include <iostream>

using namespace std;

void menu();

class Banco{
    public:
        Banco(string titularCuenta) : titularCuenta(titularCuenta) {} // Constructor
        void depositar(double cant); // Función para depositar
        virtual double retirar(double cant) = 0; // Función para retirar
    private:
        virtual void mostrarInfo() = 0; // Función para mostrar información de la cuenta
    protected:
        double balance = 0; // El balance de la cuenta de banco
        string titularCuenta; // El titular de la cuenta de banco
};


class CajaDeAhorro : public Banco {
    public:
        CajaDeAhorro(string titularCuenta) : Banco(titularCuenta) {} // Constructor
        double retirar(double cant) override;
        void mostrarInfo() override;
};

// En este caso hago que en el constructor se pase una referencia a la caja de ahorro asociada al mismo titular
// para poder acceder a esa cuenta en caso de que no haya dinero suficiente en la cuenta corriente para retirar
class CuentaCorriente : public Banco{
    public: 
        CuentaCorriente(string titularCuenta, CajaDeAhorro* caja) : Banco(titularCuenta), cajaAhorro(caja) {} 
        double retirar(double cant) override;
        void mostrarInfo() override;
    private:
        CajaDeAhorro* cajaAhorro;
};