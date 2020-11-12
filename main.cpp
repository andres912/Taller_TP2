#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <atomic>
#include "Parser.h"
#include "RepositorioDeArchivos.h"
#include "RepositorioDeResultados.h"
#include "Validador.h"
#include "VerificadorEBPF.h"

int main(int argc, char** argv) {
    VerificadorEBPF manejador;
    manejador.manejarProcesoDeValidacion(argc, argv);
    return 0;
}
