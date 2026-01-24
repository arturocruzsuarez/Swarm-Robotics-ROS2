#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "ProblemaOptim.h"
#include <vector>
#include <iostream>
#include <random>

using Range = std::pair<double, double>;

class Individuo {
public:
    Individuo(ProblemaOptim* p, int precision);
    Individuo(int precision);
    Individuo();

    void insuflar(ProblemaOptim* p, int precision);
    void iniciaInfo(ProblemaOptim* p, int precision);
    //void insuflar(int precision);
    void decodificar();
    //void x2cromosoma(ProblemaOptim* p);
    void x2cromosoma();
    void copiar(Individuo* source);
    void imprimeIndi(std::ostream& salida);

    std::vector<unsigned> cromo;    // cadena binaria del cromosoma del individuo.
    int chromoSize;                 // longitud del cromosoma del individuo
    std::vector<unsigned> geneSizes; // longitud de cada gene del cromosoma.
    std::vector<double> x;           // Decodificación del cromosoma (fenotipo)
    std::vector<Range> xRanges;      // intervalo de las variables.
    double    aptitud;      // aptitud del individuo
    double    eval;         // resultado de evaluar la función objetivo
    std::vector<double> cons;      // valor de cada una de las restricciones que pueda tener el problema a resolver
    double    valesp;       // valor esperado de la aptitud del individuo
    int       xsite1;       // punto de cruza
    int       nMutaciones;  // inidica si se realizó una mutación
    int       padres[2];    // los padres del individuo

private:
    static std::mt19937 twister;     // Mersenne-Twister random number engine
};

#endif
