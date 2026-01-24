#include "Estadisticas.h"
#include <iostream>
#include <iomanip>
#include "fmt/core.h"
#include "fmt/ranges.h"
#include <sys/stat.h>
#include <fstream>   
#include <iostream>

using namespace std;

EstadisticasGA::EstadisticasGA() {
   maxApt = 0.0;
   minApt = 0.0;
   avgApt = 0.0;
   nmutaciones = 0;
   ncruzas = 0;
   nevals = 0;
   generationBestFit = 0;
   positionBestFit = 0;
}

EstadisticasGA::~EstadisticasGA() {}

void EstadisticasGA::reset(ProblemaOptim* p, int precision) {
   bestfit.insuflar(p, precision);
   localmax.assign(bestfit.chromoSize, 0);
}

/* Calcula las estadísticas respecto a la aptitud de la población */
void EstadisticasGA::statistics(Individuo* pop, int popSize)
{
   minApt = pop[0].aptitud;
   maxApt = pop[0].aptitud;
   localmax = pop[0].cromo;

   for (int j=0; j < popSize; j++ ) {
      if ( pop[j].aptitud > maxApt ) {
         maxApt = pop[j].aptitud; /* Este es el máximo local */
         localmax = pop[j].cromo;
      }

      if (pop[j].aptitud < minApt)
         minApt = pop[j].aptitud;     /* Este el mínimo local */
   }

   /* Sumar la aptitud */
   double sumaptitud = 0.0;
   for (int j=0; j < popSize; j++ )
      sumaptitud = sumaptitud + pop[j].aptitud;

   /* Calcular el promedio de la aptitud */
   avgApt = sumaptitud/popSize;

   /* Calcular el valor esperado de los individuos */
   for (int j=0; j < popSize; j++) {
      if ( avgApt != 0.0 )
         pop[j].valesp = pop[j].aptitud / avgApt;
      else
         pop[j].valesp = 0.0f;
   }
}

/* Impresión para reportar los parámetros iniciales dados por el usuario */
void EstadisticasGA::initial_report(ostream &output,
                                    int popsize,
                                    int Gmax,
                                    double Pc,
                                    double Pm)
{

   output << "\n      Parámetros que se usarán en el algoritmo genético  \n";
   output << fmt::format(" Tamaño de la población         =    {}\n", popsize);
   output << fmt::format(" Longitud total del cromosoma   =    {}\n", bestfit.chromoSize);
   output << fmt::format(" Número máximo de generaciones  =    {}\n", Gmax);
   output << fmt::format(" Probabilidad de cruza          =    {:.3f}\n", Pc);
   output << fmt::format(" Probabilidad de mutación       =    {:.3f}\n", Pm);
   output << "\n\n";
}


/* Imprimir las estadísticas de la población en la generación actual */
void EstadisticasGA::report(ostream &output, Individuo* oldpop, Individuo* newpop, int popSize, int gen)
{
   int cSize = oldpop[0].chromoSize;
   int nVars = oldpop[0].x.size();
   int lengthPop = std::to_string(popSize).length();
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();

   //cout << "Cadena= " << (long) trunc(bestfit.aptitud) << ", longitud apt= " << lengthApt << "\n";

   output << fmt::format("{:^120}\n", "REPORTE DE LA POBLACIÓN");
   output << fmt::format("PADRES: Generación número {}\n", gen-1);
   output << fmt::format("{:^{}}  {:^{}}  {:^{}}  {:^{}}  {:^6}",
                         "Num", lengthPop+2, "Cromosoma", cSize, "Variables", nVars*10 + 1,
                         "Aptitud", lengthApt+4, "ValEsp");
   output << fmt::format("\n{:_<{}}\n", "", lengthPop+2 + cSize + nVars*7 + lengthApt + 19);

   writepop1(output, oldpop, popSize);

   output << fmt::format("\n\nHIJOS: Generación número {}\n", gen);
   output << fmt::format("{:^{}}  {: ^9}  {:^4}  {:^5}  {:^{}}  {:^{}}  {:^{}}  {:^6}",
                         "Num", lengthPop+2, "Padres", "X", "mut?",
                         "Cromosoma", cSize, " Variables", nVars*10 + 1,
                         "Aptitud", lengthApt+4, "ValEsp");
   output << fmt::format("\n{:_<{}}\n", "", lengthPop+2 + cSize + nVars*10 + lengthApt + 43);

   writepop2(output, newpop, popSize);

   output << fmt::format("\n{:_<{}}\n", "", lengthPop+2 + cSize + nVars*10 + lengthApt + 43);

   output << "\n\tEstadísticas ACUMULADAS hasta la generación " << gen << "\n";
   output << "La función f(x1,x2) se evaluó " << nevals << " veces.\n";
   output << "Cruzas totales= " << ncruzas << ", Mutaciones totales= " << nmutaciones << "\n";
   output << "Aptitud mínima = " << minApt << "\n";
   output << "Aptitud máxima = " << maxApt << "\n";
   output << "Aptitud promedio = " << avgApt << "\n";
   output << "El mejor individuo de la generación actual:\n";
   output << "   Cadena = ";
   output << fmt::format("{}", fmt::join(localmax, ""));
   output << "\n\n";
   output << "Mejor individuo global:\n";
   output << fmt::format("   Obtenido en la generacion núm: {}\n", generationBestFit);
   output << fmt::format("   Posición actual: {}\n", positionBestFit);
   output << "   Cadena = ";
   output << fmt::format("{}", fmt::join(bestfit.cromo, ""));
   output << "\n   Vector X = ";
   output << fmt::format("{:24.20f}", fmt::join(bestfit.x, " "));
   //output << fmt::format("{:5.0f}", fmt::join(bestfit.x, ", "));   
   output << "\n   Evaluación f(X) = " << bestfit.eval << "\n" << endl;
}

void EstadisticasGA::shortReport(ostream &output, Individuo* oldpop, Individuo* newpop, int popSize, int gen)
{
   int cSize = oldpop[0].chromoSize;
   int nVars = oldpop[0].x.size();
   int lengthPop = std::to_string(popSize).length();
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();


   output << fmt::format("\n\nHIJOS: Generación número {}\n", gen);

   if (newpop[0].cons.size() > 0)
      output << fmt::format("{:^{}}  {:^{}} {:^6}",
                         "Num", lengthPop+2, "Aptitud", lengthApt+4, "ValEsp");
   else
      output << fmt::format("{:^{}}  {:^{}} {:^6} {:^6}",
                         "Num", lengthPop+2, "Aptitud", lengthApt+4, "Restricción", "ValEsp");

   output << fmt::format("\n{:_<{}}\n", "", lengthPop+2 + lengthApt + 50);
   
   shortWritepop2(output, newpop, popSize);
   
   output << fmt::format("\n{:_<{}}\n", "", lengthPop+2 + lengthApt + 43);
   
   output << "\n\tEstadísticas ACUMULADAS hasta la generación " << gen << "\n";
   output << "La función f(x1,x2) se evaluó " << nevals << " veces.\n";
   output << "Cruzas totales= " << ncruzas << ", Mutaciones totales= " << nmutaciones << "\n";
   output << "Aptitud mínima = " << minApt << "\n";
   output << "Aptitud máxima = " << maxApt << "\n";
   output << "Aptitud promedio = " << avgApt << "\n";
   //output << "El mejor individuo de la generación actual:\n";
   //output << "   Cadena = ...";
   //output << fmt::format("{}", fmt::join(localmax, ""));
   output << "\n\n";
   output << "Mejor individuo global:\n";
   output << fmt::format("   Obtenido en la generacion núm: {}\n", generationBestFit);
   output << fmt::format("   Posición actual: {}\n", positionBestFit);
   output << "   Cadena = ...";
   //output << fmt::format("{}", fmt::join(bestfit.cromo, ""));
   output << "\n   Vector X = ";
   output << fmt::format("{:9.3f}", fmt::join(bestfit.x, " "));

   output << "\n   Evaluación f(X) = " << bestfit.eval << "\n" << endl;

   std::ofstream archivo("archivo_pesos_1_1.txt"); //std::ofstream archivo("archivo_pesos_" + std::to_string(1) + ".txt");

   archivo << "98 2 0\n";
        for (int i = 0; i < 196; i+=2)
        {
            archivo << bestfit.x[i] << " " << bestfit.x[i+1] << "\n";
        }


}


/* Impresión de los datos de la generación vieja */
void EstadisticasGA::writepop1(ostream &output, Individuo* pop, int popSize)
{
   int lengthPop = std::to_string(popSize).length();
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();

   for(int j=0; j<popSize; j++)
   {
      output << fmt::format("{:0{}}    ", j+1, lengthPop);

      // Imprimir cromosoma
      output << fmt::format("{}", fmt::join(pop[j].cromo, ""));
      output << "  ";

      // Imprimir vector x
      output << fmt::format("{:010.3f}", fmt::join(pop[j].x, " "));

      output << "  ";
      output << fmt::format("{:0{}.3f}  {:06.3f}", pop[j].aptitud, lengthApt+4, pop[j].valesp);
      //pop[j].imprimeIndi(output);
      output << "\n";
   }
}

/* Impresión de los datos de la generación nueva */
void EstadisticasGA::writepop2(ostream &output, Individuo* pop, int popSize)
{
   int lengthPop = std::to_string(popSize).length();
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();

   for(int j=0; j< popSize; j++)
   {
      output << fmt::format("{:0{}}    ", j+1, lengthPop);

      Individuo* pind = &pop[j];
      output << fmt::format("({:03},{:03})  ", pind->padres[0], pind->padres[1]);
      output << fmt::format("{: ^4}  ", pind->xsite1);

      char Mut = (pind->nMutaciones >= 1) ? 'S' : 'N';
      output << fmt::format("{:^5}  ", Mut);

      // Imprimir cromosoma
      output << fmt::format("{}", fmt::join(pop[j].cromo, ""));
      output << "  ";

      // Imprimir vector x
      output << fmt::format("{:010.3f}", fmt::join(pop[j].x, " "));

      output << "  ";
      output << fmt::format("{:0{}.3f}  {:06.3f}", pop[j].aptitud, lengthApt+4, pop[j].valesp);
      //pop[j].imprimeIndi(output);
      output << "\n";
   }
}

void EstadisticasGA::shortWritepop2(ostream &output, Individuo* pop, int popSize)
{
   int lengthPop = std::to_string(popSize).length();
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();
   
   for(int j=0; j< popSize; j++)
   {
      output << fmt::format("{:0{}}    ", j+1, lengthPop);
      output << "  ";
      if (pop[j].cons.size() > 0) {
        output << fmt::format("{:0{}.5f} {:0{}.5f} {:06.3f}", pop[j].aptitud, lengthApt+6,
                              pop[j].cons[0], 9,
                              pop[j].valesp);
      }
      else
        output << fmt::format("{:0{}.5f}  {:06.3f}", pop[j].aptitud, lengthApt+6, pop[j].valesp);

      //pop[j].imprimeIndi(output);
      output << "\n";
   }
}

void EstadisticasGA::writeVariables(ostream &output, Individuo* pop, int popSize) {
   for(int j=0; j< popSize; j++)
   {      
      // Imprimir vector x
      output << fmt::format("{:010.6f}", fmt::join(pop[j].x, " "));
      output << "\n";
   }
}

void EstadisticasGA::writeEvaluation(ostream &output, Individuo* pop, int popSize) {
   int lengthApt = std::to_string((long) trunc(bestfit.aptitud)).length();
   
   for(int j=0; j< popSize; j++)
   {     
      // Imprimir evaluación y restricciones (un vector)
      output << fmt::format("{:0{}.3f}  ", pop[j].eval, lengthApt+4);
      output << fmt::format("{:010.3f}", fmt::join(pop[j].cons, " "));
      output << "\n";
   }
}

bool EstadisticasGA::dirExists(const char *path) {
    struct stat info;

    if(stat( path, &info ) != 0)
        return false;
    else if(info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}
