#ifndef GENETICO_H
#define GENETICO_H

/*
 *genetico.h
 * Contiene la declaración de la clase GeneticoSimple que define la
 * la interfaz de un algoritmo genético simple con:
 *  - representación binaria.
 *  - cruza de un punto.
 *  - mutación uniforme.
 *  - selección por ruleta.
 */

#include "Individuo.hpp"
#include "ProblemaOptim.hpp"
#include "Estadisticas.hpp"
#include <fstream>
#include <vector>
#include <random>
#include <thread>


#define SIN_VALOR -1

using namespace std;
using Cromosoma = vector<unsigned int>;

typedef struct {
   int popSize=20;                /* tamaño de la población */
   int    Gmax=200;                /* número máximo de generaciones */
   double  Pc=0.7;                 /* porcentaje de cruza */
   double  Pm=0.3;                 /* porcentaje de mutación */
   int precision=5;              /* dígitos de precisión */
} ParamsGA;


class GeneticoSimple {
public:

//    struct Less {
//         Less(const GeneticoSimple& c) : myClass(c) {}
//         const GeneticoSimple& myClass;
//
//         bool operator ()( const int & a, const int & b) {
//             return myClass.valores[a] > myClass.valores[b];
//         }
//
//     };


   GeneticoSimple(ProblemaOptim*, ParamsGA&, int id_, int task_);
   ~GeneticoSimple();
   void optimizar();

   vector<double> valores;
   //bool operator () (const int &a, const int &b);
   void migrar();


private:
   void inicalizarPob();
   void reporteInicial();
   bool dirExists(string path);
   bool fileExists(string path);
   void evaluarPoblacion(Individuo*);
   double aleatorio();
   void seleccionPadres(Individuo*);
   int seleccionRuleta(Individuo*);
   void mutacion(Individuo*);
   int mutacionUniforme(Cromosoma&);
   void cruza(Individuo*, Individuo*);
   int cruza1Punto(Cromosoma&, Cromosoma&, Cromosoma&, Cromosoma&);
   int calcularTamCromosoma();
   void calcularValEsperado(Individuo*);
   void elitismo(Individuo* pop, int g);
   int flip(double prob);

   int id;                      /*identificador del genetico*/
   int task;

   ProblemaOptim* problema;    /* el problema que se resolverá */
   Individuo* oldpop;         /* última generación de individuos */
   Individuo* newpop;         /* siguiente generación de individuos */
   vector<int> padres;         /* lista de padres seleccionados. */

   int popSize;                /* tamaño de la población */
   int    Gmax;                /* número máximo de generaciones */
   double  Pc;                 /* porcentaje de cruza */
   double  Pm;                 /* porcentaje de mutación */
   double auxPm;                /* para el caso en el que se quiera usar una Pm diferente en algún momento */
   int precision;              /* dígitos de precisión */

   int chromoSize;             /* longitud del cromosoma de caa individuo */
   int geneSize;               /* longitud de cada gene en el cromosoma */
   double sumAptitud;          /* suma de la aptitud de toda la población */

   string outputDir;
   string inputDir;            /* sirve en el caso de que previamente exista un controlador entrenado del que se deba derivar la poblacion*/
   string trainDir;
   ofstream archVariables;
   ofstream archEvaluacion;

   double sumvalesp;           /* suma de los valores esperados de la población */
   int    gen;                 /* número de la generación actual */
   EstadisticasGA stats;
   mt19937 rng;                // Mersenne-Twister random number engine
   
   double tiempoMaximo;        // PEOR tiempo en terminar la carrera en TORCS.

   vector<string> comandos;
   vector<thread> threads;

};


#endif
