#pragma once

#include <iostream>

using namespace std;

void menu();

class Numero{
    public:
        virtual Numero* suma(const Numero& num) = 0;
        virtual Numero* resta(const Numero& num) = 0;
        virtual Numero* multiplicación(const Numero& num) = 0;
        virtual Numero* division(const Numero& num) = 0;
        virtual string toString() = 0;
};

class Entero : public Numero{
    public:
        int entero; 
        Entero(int n) : entero(n) {}
        Numero* suma(const Numero& num) override;
        Numero* resta(const Numero& num) override;
        Numero* multiplicación(const Numero& num) override;
        Numero* division(const Numero& num) override;
        string toString() override;
};

class Real : public Numero{
    public:
        double real;
        Real(double n) : real(n) {}
        Numero* suma(const Numero& num) override;
        Numero* resta(const Numero& num) override;
        Numero* multiplicación(const Numero& num) override;
        Numero* division(const Numero& num) override;
        string toString() override;
};

class Complejo : public Numero{
    public:
        double real, imaginario;
        Complejo(double r, double i) : real(r), imaginario(i) {}
        Numero* suma(const Numero& num) override;
        Numero* resta(const Numero& num) override;
        Numero* multiplicación(const Numero& num) override;
        Numero* division(const Numero& num) override;
        string toString() override;
};