#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include "Individuo.h"
#include "ProblemaOptim.h"
#include <vector>

using namespace std;
/*
* Conjunto de funciones para llevar estadísticas, y otras funciones de ayuda.
*/

class EstadisticasGA {
public:
   EstadisticasGA();
   ~EstadisticasGA();
   void reset(ProblemaOptim* p, int precision);
   void statistics(Individuo* pop, int popSize);
   void initial_report(ostream&, int, int, double, double);
   void report(ostream &, Individuo*, Individuo*, int, int);
   void shortReport(ostream &, Individuo*, Individuo*, int, int);
   
   void shortWritepop1(ostream &output, Individuo*, int);
   void shortWritepop2(ostream &output, Individuo*, int);
   void writepop1(ostream &output, Individuo*, int);
   void writepop2(ostream &output, Individuo*, int);
   void writeVariables(ostream &, Individuo*, int popSize);
   void writeEvaluation(ostream &, Individuo*, int popSize);
   bool dirExists(const char *path);

   double maxApt;                 /* aptitud máxima de la población */
   double minApt;                 /* aptitud mínima de la población */
   double avgApt;                 /* promedio de la aptitud de la población */
   int    nmutaciones;         /* número de mutaciones totales */
   int    ncruzas;             /* número de cruzas totales */
   long   nevals;              /* número de evaluaciones */
   vector<unsigned> localmax;  /* cromosoma del mejor individuo local */
   Individuo bestfit;         /* el mejor individuo encontrado al momento */
   int positionBestFit;
   int generationBestFit;
};

#endif
