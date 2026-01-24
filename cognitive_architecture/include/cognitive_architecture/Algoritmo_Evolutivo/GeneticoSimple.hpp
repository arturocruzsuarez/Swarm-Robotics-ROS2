#include <rclcpp/rclcpp.hpp> // Incluye la biblioteca ROS 2
#include <ctime>
#include <cmath>
#include <limits>
#include <algorithm>
#include <sys/stat.h>
#include "GeneticoSimple.h" // Incluye la definición de clases y funciones relacionadas con el algoritmo genético

// Definición de la clase GeneticoSimple
// Constructor de la clase
GeneticoSimple::GeneticoSimple(ProblemaOptim *p, ParamsGA &params, int id_, int task_)
{
    // Inicialización de parámetros y variables
    problema = p;
    popSize = params.popSize;
    Gmax = params.Gmax;
    Pc = params.Pc;
    Pm = params.Pm;
    precision = params.precision;
    task = task_;
    id = id_;

    random_device rd;
    rng = mt19937(random_device{}());
    rng.seed(rd());

    oldpop = new Individuo[popSize];
    newpop = new Individuo[popSize];
    padres.assign(popSize, 0);
    stats.reset(problema, precision);

    valores = {5, 2, 10, 1, 4};

    //"pesos_eval_{:02d}.txt";
    outputDir = "./";
    trainDir = fmt::format("./pesos_eval_{:02d}.txt", id);
    inputDir = "./archivo_pesos_"+ to_string(id) +"_"+ to_string(task)+".txt";

    // Comprobación y creación del directorio de salida
    if (!dirExists(outputDir))
    {
        const int dir_err = mkdir(outputDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (dir_err == -1)
        {
            cerr << "\nNo se pudo crear el directorio de salida " << outputDir << "\n\n";
            exit(1);
        }
    }

    // dev/null es para que no se imprima en terminal
    comandos ={
            "ros2 run cognitive_architecture cpp_exe 1 1 1 > /dev/null",
            "ros2 run cognitive_architecture Controlador_individuo.py 1 1 1 > /dev/null"};


    if (task != 1)  //en caso de que sea necesario agregar dummies
    {
        system("ros2 launch cognitive_architecture dummys.launch.py num_bots:=1 > /dev/null");


        // Crear un hilo para los comandos
        for (auto comando : comandos)
        {
            threads.emplace_back([this, comando]()
                                 { system(comando.c_str()); });
        }

        for (auto &thread : threads)
        {
            thread.detach();
        }
        
    }
    // Evaluación de la población inicial y aplicación del elitismo
    // evaluarPoblacion(oldpop);
    // elitismo(oldpop, gen);

    // Optimización del algoritmo genético
    // optimizar();
}

// Destructor de la clase
GeneticoSimple::~GeneticoSimple()
{
    delete[] newpop;
    delete[] oldpop;
}

// Método para verificar si un directorio existe
bool GeneticoSimple::dirExists(string path)
{
    struct stat info;

    if (stat(path.c_str(), &info) != 0)
        return false;
    else if (info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}

bool GeneticoSimple::fileExists(string path)
{
    struct stat info;
    return (stat(path.c_str(), &info) == 0 && !(info.st_mode & S_IFDIR)); // comprueba la existencia de un archivo, no de un directorio
}

// Método principal para la optimización utilizando el algoritmo genético
void GeneticoSimple::optimizar()
{
    Individuo *temp;
    // Reporte inicial de estadísticas
    // stats.initial_report(this->get_logger(), popSize, Gmax, Pc, Pm);
    // cerr << "entre a optimizar" << endl;
    // Inicialización de la población
    gen = 1;
    inicalizarPob();
    evaluarPoblacion(oldpop);
    elitismo(oldpop, gen);
    stats.statistics(oldpop, popSize);

    //  Bucle principal de optimización
    for (gen = 2; gen <= Gmax; gen++)
    {
        seleccionPadres(oldpop);
        cruza(oldpop, newpop);
        mutacion(newpop);
        evaluarPoblacion(newpop);
        elitismo(newpop, gen);
        stats.statistics(newpop, popSize);
        stats.shortReport(cout, oldpop, newpop, popSize, gen);
        //  Intercambio de poblaciones
        temp = oldpop;
        oldpop = newpop;
        newpop = temp;
    }


    // Escritura de resultados en archivos de salida
    ofstream archVariables(outputDir + "/pesos_pob.txt", ofstream::out);
    ofstream archEvaluacion(outputDir + "/eval_pob.txt", ofstream::out);

    stats.writeVariables(archVariables, oldpop, popSize);
    stats.writeEvaluation(archEvaluacion, oldpop, popSize);

    archVariables.close();
    archEvaluacion.close();

    // terminate();
}

// Método para inicializar la población
void GeneticoSimple::inicalizarPob()
{

    if (fileExists(trainDir))
    {
        for (int j = 0; j < popSize; j++)
        {
            oldpop[j].iniciaInfo(problema, precision);
            newpop[j].iniciaInfo(problema, precision);
        }

        ifstream weightsFile;
        weightsFile.open(inputDir, ifstream::in);

        char buffer[7];
        weightsFile.getline(buffer, 7);

        double peso;
        unsigned k = 0;
        while (weightsFile >> peso)
        {
            oldpop[0].x[k] = peso;
            newpop[0].x[k] = peso;
            k++;
        }

        weightsFile.close();

        oldpop[0].x2cromosoma();
        
        for (int j = 1; j < popSize; j++)
        {
            oldpop[j].copiar(&oldpop[0]);
            newpop[j].copiar(&oldpop[0]);
        }

        auxPm = Pm;
        Pm = 0.5; /* mutación para la derivación del original*/
        mutacion(oldpop);
        Pm = auxPm;
    }

    else
    {
        for (int j = 0; j < popSize; j++)
        {
            oldpop[j].insuflar(problema, precision);
            newpop[j].insuflar(problema, precision);
        }
    }

    // Si Pm no tiene un valor asignado, se calcula como 1 dividido por el tamaño del cromosoma
    if (Pm == SIN_VALOR)
        Pm = 1.0 / oldpop[0].chromoSize;
}

// Método para evaluar la población
void GeneticoSimple::evaluarPoblacion(Individuo *pop)
{
    for (int i = 0; i < popSize; ++i)
    {
        problema->evaluateFun(pop[i].x, pop[i].eval, pop[i].cons);
        stats.nevals++;

        pop[i].aptitud = 1.0 / (1 + pop[i].eval);
    }
}

// Método para seleccionar los padres utilizando el método de la ruleta
void GeneticoSimple::seleccionPadres(Individuo *pop)
{
    calcularValEsperado(pop);

    for (int i = 0; i < popSize; i++)
        padres[i] = seleccionRuleta(pop);
}

// Método para seleccionar un padre utilizando el método de la ruleta
int GeneticoSimple::seleccionRuleta(Individuo *pop)
{
    double suma, ale;
    int j;
    uniform_real_distribution<> rdis(0.0, sumvalesp);

    ale = rdis(rng);
    suma = 0.0;
    j = 0;

    do
    {
        suma += pop[j].valesp;
        j++;
    } while (suma < ale && j < popSize);

    return j - 1;
}

// Método para realizar la cruza entre los individuos de la población
void GeneticoSimple::cruza(Individuo *oldpop, Individuo *newpop)
{
    int mate1, mate2, pcruza;

    for (int j = 0; j < popSize - 1; j += 2)
    {
        mate1 = padres[j];
        mate2 = padres[j + 1];

        pcruza = cruza1Punto(oldpop[mate1].cromo, oldpop[mate2].cromo, newpop[j].cromo, newpop[j + 1].cromo);

        newpop[j].xsite1 = pcruza;
        newpop[j + 1].xsite1 = pcruza;
        newpop[j].padres[0] = mate1 + 1;
        newpop[j].padres[1] = mate2 + 1;
        newpop[j + 1].padres[0] = mate1 + 1;
        newpop[j + 1].padres[1] = mate2 + 1;

    }
}

// Método para realizar la cruza de un punto entre dos cromosomas
int GeneticoSimple::cruza1Punto(Cromosoma &padre1, Cromosoma &padre2, Cromosoma &hijo1, Cromosoma &hijo2)
{
    int pcruza, j;
    int chromoSize = padre1.size();
    uniform_int_distribution<int> unif(0, chromoSize - 1);
    // uniform_int_distribution<int>* unif = new uniform_int_distribution<int>(0, chromoSize-1);

    if (flip(Pc))
    {
        pcruza = unif(rng);
        for (j = (chromoSize - 1); j >= (chromoSize - pcruza); j--)
        {
            hijo1[j] = padre1[j];
            hijo2[j] = padre2[j];
        }

        for (j = (chromoSize - pcruza) - 1; j >= 0; j--)
        {
            hijo1[j] = padre2[j];
            hijo2[j] = padre1[j];
        }

        stats.ncruzas++;
    }
    else
    {
        hijo1 = padre1;
        hijo2 = padre2;
        pcruza = 0;
    }
    //delete unif;
    return pcruza;
}

// Método para realizar la mutación de la población
void GeneticoSimple::mutacion(Individuo *pop)
{
    for (int j = 0; j < popSize; j++)
    {
        pop[j].nMutaciones = mutacionUniforme(pop[j].cromo);
        pop[j].decodificar();

        if (pop[j].nMutaciones > 0)
        {
            stats.nmutaciones++;
        }
    }

    uniform_int_distribution<int> unif(0, popSize - 1);
    int ale = unif(rng);
    pop[ale].copiar(&stats.bestfit);
    stats.positionBestFit = ale + 1;
}

// Método para realizar la mutación uniforme en un cromosoma
int GeneticoSimple::mutacionUniforme(Cromosoma &cromo)
{
    int numMutations = 0;
    for (unsigned k = 0; k < cromo.size(); k++)
    {
        if (flip(Pm))
        {
            numMutations++;
            cromo[k] = (cromo[k] == 0) ? 1 : 0;
        }
    }

    return numMutations;
}

// Método para calcular el valor esperado de cada individuo de la población
void GeneticoSimple::calcularValEsperado(Individuo *pop)
{
    double sumaptitud = 0.0;

    for (int j = 0; j < popSize; j++)
        sumaptitud += pop[j].aptitud;

    stats.avgApt = sumaptitud / popSize;

    sumvalesp = 0.0;

    for (int j = 0; j < popSize; j++)
    {
        if (stats.avgApt != 0.0) pop[j].valesp = pop[j].aptitud / stats.avgApt;
        else pop[j].valesp = 0.0f;
        
        sumvalesp += pop[j].valesp;
    }
}

// Método para aplicar elitismo en la población
void GeneticoSimple::elitismo(Individuo *pop, int gen)
{
    for (int j = 0; j < popSize; j++)
    {
        if (pop[j].aptitud >= stats.bestfit.aptitud)
        {   
            stats.bestfit.copiar(&pop[j]);
            stats.generationBestFit = gen;
            stats.positionBestFit = j + 1;
        }
    }
}

// Método para realizar un flip basado en una probabilidad
int GeneticoSimple::flip(double prob)
{
    uniform_real_distribution<> rdis(0.0, 1.0);

    if (rdis(rng) <= prob)
        return true; //
    else
        return false;
}
