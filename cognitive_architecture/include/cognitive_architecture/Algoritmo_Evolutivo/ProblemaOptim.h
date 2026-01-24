#ifndef PROBLEMAOPTIM_H
#define PROBLEMAOPTIM_H

#include <vector>
#include <utility>
#include <string>

// Un alias para la clase pair.
using Range = std::pair<double, double>;

class ProblemaOptim {
public:
    ProblemaOptim(const char *name, int numVars, int numRestr = 0);
    virtual ~ProblemaOptim();

    // Método principal de la clase, es la que evalúa la función.
    // Esta versión es para problemas SIN restricciones.
    virtual void evaluateFun(std::vector<double> const &x, double &fun);

    // Método virtual PURO (con =0), es decir, es forzoso implementarlo en la clase derivada.
    virtual void evaluateFun(std::vector<double> const &x, double &fun, std::vector<double> &cons) const = 0;

    const int numVariables() const;
    const int numRestricciones() const;
    std::vector<Range> xRanges() const;

    std::string nombre;           /* Nombre para identificar el problema. */


protected:
    /* Atributos */
    int nVariables;          /* Número de variables del problema. */
    int nRestricciones;      /* Número de restricciones del problema. */
    std::vector<Range> varRanges; /* Intervalo para los valores de las variables. */
};

#endif
