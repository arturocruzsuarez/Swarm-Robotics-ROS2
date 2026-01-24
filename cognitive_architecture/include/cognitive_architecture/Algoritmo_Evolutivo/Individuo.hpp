#include "Individuo.h"
#include <cmath>
#include <random>
#include <iostream>

using namespace std;

std::mt19937 Individuo::twister{};

Individuo::Individuo(ProblemaOptim* p, int precision) {
    chromoSize = 0;
    aptitud = 0.0;
    eval = 0.0;

    // Variables para llevar estadísticas.
    xsite1 = 0;
    nMutaciones = 0;
    padres[0] = 0;
    padres[1] = 0;

    std::random_device rd;
    twister.seed(rd());

    insuflar(p, precision);
}

Individuo::Individuo() {
    chromoSize = 0;
    aptitud = 0.0;
    eval = 0.0;

    // Variables para llevar estadísticas.
    xsite1 = 0;
    nMutaciones = 0;
    padres[0] = 0;
    padres[1] = 0;

    std::random_device rd;
    twister.seed(rd());
}

/* Para este individuo, crea su cromosoma aleatorio, el tamaño de cada gene, y
 * el vector de variables decodificadas x.
 */
void Individuo::insuflar(ProblemaOptim* p, int precision) {
    
    // xRanges = p ->xRanges();
    // x.assign(p->numVariables(), 0.0);
    // cons.assign(p->numRestricciones(), 0.0);

    // double numValores;
    // int numBits;

    // geneSizes.clear();
    // chromoSize = 0;
    // //std::cerr << "voy a entrar al for" << std::endl;
    // for (auto r : xRanges) {
    //     numValores = 1 + (r.second - r.first) * pow(10, precision);
    //     numBits = ceil(log2(numValores));
    //     geneSizes.push_back(numBits);
    //     chromoSize += numBits;
    // }

    iniciaInfo(p,precision);

    static std::uniform_int_distribution<int> unif{0, 1};
    //cromo.assign(chromoSize, 0);
    //std::cerr << "voy a entrar al otro for" << std::endl;
    for (int k = 0; k < chromoSize; k++)
        cromo[k] = unif(twister); // Pone 0 o 1 aleatoriamente.

    //std::cerr << "sali del otro for" << std::endl;
    decodificar();
}

void Individuo::iniciaInfo(ProblemaOptim* p, int precision){
    
    xRanges = p ->xRanges();
    x.assign(p->numVariables(), 0.0);
    cons.assign(p->numRestricciones(), 0.0);

    double numValores;
    int numBits;

    geneSizes.clear();
    chromoSize = 0;
    //std::cerr << "voy a entrar al for" << std::endl;
    for (auto r : xRanges) {
        numValores = 1 + (r.second - r.first) * pow(10, precision);
        numBits = ceil(log2(numValores));
        geneSizes.push_back(numBits);
        chromoSize += numBits;
    }

    cromo.assign(chromoSize, 0);


}

void Individuo::copiar(Individuo* source) {
    cromo = source->cromo;
    x = source->x;
    aptitud = source->aptitud;
    eval = source->eval;
    cons = source->cons;
    xRanges = source->xRanges;
}

void Individuo::decodificar() {
    //std::cerr << "entre a decodificar" << std::endl;
    double entero;
    long double factor;
    int finGene, inicioGene = 0;

    // Decodificar cada gene para obtener su valor x real.
    for (unsigned i = 0; i < x.size(); ++i) {
        //std::cerr << i << "i" << std::endl;
        factor = 1.0;
        entero = 0.0;
        //std::cerr << geneSizes[i] << " genesize "<< i <<std::endl;
        finGene = inicioGene + geneSizes[i] - 1;
        for (int j = finGene; j >= inicioGene; j--) {

            if (cromo[j] == 1)
                entero += factor;

            factor *= 2.0; // Se incrementa como 1, 2, 4, 8,...
        }
        //std::cerr << "sali del for j" << std::endl;

        Range r = xRanges[i];
        x[i] = r.first +
               ((r.second - r.first) * entero) / (pow(2, geneSizes[i]) - 1.0);

        inicioGene += geneSizes[i];
    }
    //std::cerr << "sali de los for" << std::endl;
}

/*
 * Convierte el vector x del individuo que tiene representación
 * real (vector<double> x) a su codificación binaria, dejando el
 * resultado en su cromosoma interno (vector<unsigned> cromo).
 */
void Individuo::x2cromosoma() {
    double d;    // representación real del entero.
    int entero;  // redondeo del valor d.
    int finGene, inicioGene = 0;
    //std::cerr << cromo.size() << std::endl;
    for (size_t i = 0; i < x.size(); i++) {
        Range r = xRanges[i];

        d = (pow(2, geneSizes[i]) - 1.0) *
            ((x[i] - r.first) / (r.second - r.first));

        
        //std::cerr << "d " << d << std::endl;
        int entero = round(d);
        //std::cerr << "entero " << entero << std::endl;

        // Convertir el entero a binario para guardarlo en el cromosoma
        finGene = inicioGene + geneSizes[i] - 1;
        //std::cerr << "oju" << i  <<std::endl;

        for (int j = finGene; entero != 0; j--) {
            //std::cerr << "oju2" << j  <<std::endl;
            if (j >= inicioGene) {
                cromo[j] = entero % 2;
                entero = entero / 2;
            } else {
                std::cerr << "codificación de x: se necesitaban más bits y no debía."
                          << std::endl;
                exit(0);
            }
            //std::cerr << "entero " << entero  <<std::endl;
            //std::cerr <<cromo[j] << " ";
            //std::cerr << std::endl;
            
        }
        //std::cerr << std::endl;
        inicioGene += geneSizes[i];
    }
}

void Individuo::imprimeIndi(std::ostream& salida) {
    for (auto alelo : cromo)
        salida << alelo;

    salida << "   ";

    for (auto valor : x)
        salida << valor;

    salida << "   ";

    salida << aptitud << "   " << valesp;
}
