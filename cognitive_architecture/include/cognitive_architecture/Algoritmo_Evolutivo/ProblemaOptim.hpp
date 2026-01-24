#include "ProblemaOptim.h"

ProblemaOptim::ProblemaOptim(const char *name, int numVars, int numRestr) {
    nombre.assign(name);
    nVariables = numVars;
    nRestricciones = numRestr;
    varRanges.assign(nVariables, std::make_pair(0.0, 1.0));
}

ProblemaOptim::~ProblemaOptim() {}

/* Versión para problemas que no tienen restricciones. */
void ProblemaOptim::evaluateFun(std::vector<double> const &x, double &fun) {
    static std::vector<double> dummy;
    evaluateFun(x, fun, dummy);
}

const int ProblemaOptim::numVariables() const {
    return nVariables;
}

const int ProblemaOptim::numRestricciones() const {
    return nRestricciones;
}

std::vector<Range> ProblemaOptim::xRanges() const {   
    return varRanges;
}
