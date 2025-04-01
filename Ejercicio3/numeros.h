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
        Numero* suma(const Numero& num) override {
            const Entero* ent = dynamic_cast<const Entero*>(&num);
            if(ent) return new Entero(entero + ent->entero);
            else return nullptr;
        }
        Numero* resta(const Numero& num) override {
            const Entero* ent = dynamic_cast<const Entero*>(&num);
            if(ent) return new Entero(entero - ent->entero);
            else return nullptr;
        }
        Numero* multiplicación(const Numero& num) override {
            const Entero* ent = dynamic_cast<const Entero*>(&num);
            if(ent) return new Entero(entero * ent->entero);
            else return nullptr;
        }
        Numero* division(const Numero& num) override {
            const Entero* ent = dynamic_cast<const Entero*>(&num);
            if (ent && ent->entero != 0) return new Entero(entero / ent->entero);
            return nullptr;
        }
        string toString() override {
            return to_string(entero);
        }
};

class Real : public Numero{
    public:
        double real;
        Real(double n) : real(n) {}
        Numero* suma(const Numero& num) override {
            const Real* re = dynamic_cast<const Real*>(&num);
            if(re) return new Real(real + re->real);
            else return nullptr;
        }
        Numero* resta(const Numero& num) override {
            const Real* re = dynamic_cast<const Real*>(&num);
            if(re) return new Real(real - re->real);
            else return nullptr;
        }
        Numero* multiplicación(const Numero& num) override {
            const Real* re = dynamic_cast<const Real*>(&num);
            if(re) return new Real(real * re->real);
            else return nullptr;
        }
        Numero* division(const Numero& num) override {
            const Real* re = dynamic_cast<const Real*>(&num);
            if (re && re->real != 0) return new Real(real / re->real);
            else return nullptr;
        }
        string toString() {
            return to_string(real);
        }
};

class Complejo : public Numero{
    public:
        double real, imaginario;
        Complejo(double r, double i) : real(r), imaginario(i) {}
        Numero* suma(const Numero& num) override {
            const Complejo* c = dynamic_cast<const Complejo*>(&num);
            if (c) return new Complejo(real + c->real, imaginario + c->imaginario);
            else return nullptr;
        }
        Numero* resta(const Numero& num) override {
            const Complejo* c = dynamic_cast<const Complejo*>(&num);
            if (c) return new Complejo(real - c->real, imaginario + c->imaginario);
            else return nullptr;
        }
        Numero* multiplicación(const Numero& num) override {
            const Complejo* c = dynamic_cast<const Complejo*>(&num);
            if (c){
                double r = real * c->real + imaginario * c->imaginario;
                double i = real * c->imaginario + imaginario * c->real;
                return new Complejo(r,i);
            } else return nullptr;
        }
        Numero* division(const Numero& num) override {
            const Complejo* c = dynamic_cast<const Complejo*>(&num);
            if (c) {
                double denominador = c->real * c->real + c->imaginario * c->imaginario;
                if (denominador == 0) {
                    return nullptr; 
                }
                double r = (real * c->real + imaginario * c->imaginario) / denominador;
                double i = (imaginario * c->real - real * c->imaginario) / denominador;
                return new Complejo(r, i);
            }
            return nullptr;
        }
        string toString() {
            string to_return = to_string(real);
            if(imaginario >= 0){
                to_return += " + " + to_string(imaginario) + "i";
            }
            else{
                to_return += " - " + to_string(-imaginario) + "i";
            }
            return to_return;
        }
};