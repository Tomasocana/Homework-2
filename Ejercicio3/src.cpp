#include "numeros.h"

// Clase Entero

Numero* Entero::suma(const Numero& num){
    const Entero* ent = dynamic_cast<const Entero*>(&num); // Hago la conversión del objeto Numero num, 
    if(ent) return new Entero(entero + ent->entero);       // a Entero ent para trabajar con las operaciónes de enteros.
    else return nullptr;                                   // Y lo mismo para el resto de operaciones.
}
Numero* Entero::resta(const Numero& num){
    const Entero* ent = dynamic_cast<const Entero*>(&num);
    if(ent) return new Entero(entero - ent->entero); // Si se logró hacer la conversión, devuelve un puntero al resultado de la operación
    else return nullptr;                             // Sino devuelve nullptr
}                                                    // Y lo mismo para el resto de operaciones.
Numero* Entero::multiplicación(const Numero& num){
    const Entero* ent = dynamic_cast<const Entero*>(&num);
    if(ent) return new Entero(entero * ent->entero);
    else return nullptr;
}
Numero* Entero::division(const Numero& num){
    const Entero* ent = dynamic_cast<const Entero*>(&num);
    if (ent && ent->entero != 0) return new Entero(entero / ent->entero);
    return nullptr;
}
string Entero::toString(){
    return to_string(entero);
}

// Clase Real

Numero* Real::suma(const Numero& num){
    const Real* re = dynamic_cast<const Real*>(&num);
    if(re) return new Real(real + re->real);
    else return nullptr;
}
Numero* Real::resta(const Numero& num){
    const Real* re = dynamic_cast<const Real*>(&num);
    if(re) return new Real(real - re->real);
    else return nullptr;
}
Numero* Real::multiplicación(const Numero& num){
    const Real* re = dynamic_cast<const Real*>(&num);
    if(re) return new Real(real * re->real);
    else return nullptr;
}
Numero* Real::division(const Numero& num){
    const Real* re = dynamic_cast<const Real*>(&num);
    if (re && re->real != 0) return new Real(real / re->real);
    else return nullptr;
}
string Real::toString(){
    return to_string(real);
}

// Clase Complejo

Numero* Complejo::suma(const Numero& num){
    const Complejo* c = dynamic_cast<const Complejo*>(&num);
    if (c) return new Complejo(real + c->real, imaginario + c->imaginario);
    else return nullptr;
}
Numero* Complejo::resta(const Numero& num){
    const Complejo* c = dynamic_cast<const Complejo*>(&num);
    if (c) return new Complejo(real - c->real, imaginario + c->imaginario);
    else return nullptr;
}
Numero* Complejo::multiplicación(const Numero& num){
    const Complejo* c = dynamic_cast<const Complejo*>(&num);    
    if (c){                                                     // Hago la distribución entre los numeros reales e imaginarios
        double r = real * c->real - imaginario * c->imaginario; // Calculo de la parte real, ya que como i^2 = -1, se termina convirtiendo en real
        double i = real * c->imaginario + imaginario * c->real; // Calculo de la parte imagianria
        return new Complejo(r,i);
    } else return nullptr;
}
Numero* Complejo::division(const Numero& num){
    const Complejo* c = dynamic_cast<const Complejo*>(&num);
    if (c) {
        double denominador = c->real * c->real + c->imaginario * c->imaginario; //Multiplico el denominador por su conjugado
        if (denominador == 0) { // Si es 0 devuelva nullptr
            return nullptr; 
        }
        double r = (real * c->real + imaginario * c->imaginario) / denominador; // Calculo la multiplicación de la parte real del numerador con el conjugado del denominador
        double i = (imaginario * c->real - real * c->imaginario) / denominador; // Calculo la multiplicación de la parte imaginaria del numerador.
        return new Complejo(r, i);
    }
    return nullptr;
}
string Complejo::toString(){
    string to_return = to_string(real);
    if(imaginario >= 0){ // Separo en si la parte imaginaria es negativa o no
        to_return += " + " + to_string(imaginario) + "i";
    }
    else{ 
        to_return += " - " + to_string(-imaginario) + "i";
    }
    return to_return;
}


void menu(){
    Entero n1(10);
    Entero n2(5);
    Numero* result;
    cout << "Los numeros que se usarán serán: " << n1.entero << " y " << n2.entero << endl;
    cout << endl;
    cout << "Operación de números enteros: " << endl;
    result = n1.suma(n2);
    cout << "   Suma de Enteros = " << n1.entero << " + " << n2.entero << " = " << result->toString() << endl;
    result = n1.resta(n2);
    cout << "   Resta de enteros = " << n1.entero << " - " << n2.entero << " = " << result->toString() << endl;
    result = n1.multiplicación(n2);
    cout << "   Multipliación de enteros = " << n1.entero << " * " << n2.entero << " = " << result->toString() << endl;
    result = n1.division(n2);
    cout << "   División de enteros = " << n1.entero << " / " << n2.entero << " = " << result->toString() << endl;
    cout << endl;
    cout << "Operación de números reales: " << endl;
    Real r1((double)10);
    Real r2((double)5);
    result = r1.suma(r2);
    cout << "   Suma de reales = " << r1.real << " + " << r2.real << " = " << result->toString() << endl;
    result = r1.resta(r2);
    cout << "   Resta de reales = " << r1.real << " - " << r2.real << " = " << result->toString() << endl;
    result = r1.multiplicación(r2);
    cout << "   Multiplicación de reales = " << r1.real << " * " << r2.real << " = " << result->toString() << endl;
    result = r1.division(r2);
    cout << "   División de reales = " << r1.real << " / " << r2.real << " = " << result->toString() << endl;
    cout << endl;
    cout << "Operación con numeros complejos: " << endl;
    Complejo c1((double)10, (double)5);
    Complejo c2((double)10, (double)5);
    result = c1.suma(c2);
    cout << "   Suma de complejos = (" << c1.real << " + " << c1.imaginario << "i) + (" << c2.real << " + " << c2.imaginario << "i) = " << result->toString() << endl;
    result = c1.resta(c2);
    cout << "   Resta de complejos = (" << c1.real << " + " << c1.imaginario << "i) + (" << c2.real << " - " << c2.imaginario << "i) = " << result->toString() << endl;
    result = c1.multiplicación(c2);
    cout << "   Multipliación de complejos = (" << c1.real << " + " << c1.imaginario << "i) + (" << c2.real << " * " << c2.imaginario << "i) = " << result->toString() << endl;
    result = c1.division(c2);
    cout << "   División de complejos = (" << c1.real << " + " << c1.imaginario << "i) + (" << c2.real << " / " << c2.imaginario << "i) = " << result->toString() << endl;
}

