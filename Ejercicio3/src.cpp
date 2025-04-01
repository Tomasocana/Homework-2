#include "numeros.h"

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