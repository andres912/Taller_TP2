//
// Created by andy on 12/11/20.
//

#include <atomic>
#include <string>
#include "VerificadorEBPF.h"
#include "RepositorioDeArchivos.h"
#include "RepositorioDeResultados.h"
#include "Validador.h"

VerificadorEBPF::VerificadorEBPF() : cantidad_de_hilos(0) {}

void VerificadorEBPF::manejarProcesoDeValidacion(int argc, char **argv) {
    char* aux;
    this-> cantidad_de_hilos = strtol(argv[1], &aux, 10);
    RepositorioDeArchivos repo_archivos;
    RepositorioDeResultados repo_resultados;

    guardarArchivos(argc, argv, repo_archivos);
    inicializarValidadores();
    validarArchivos(repo_archivos, repo_resultados);
    imprimirYFinalizar(repo_resultados);
}

void VerificadorEBPF::guardarArchivos(int argc, char** argv,
                                      RepositorioDeArchivos& repositorio) {
    for (int i = 0; i < argc-2; ++i) {
        std::string nombre_archivo = argv[i+2];
        repositorio.guardarArchivo(nombre_archivo);
    }
}

void VerificadorEBPF::inicializarValidadores() {
    for (int i = 0; i < this-> cantidad_de_hilos; ++i) {
        auto *validador = new Validador();
        this-> validadores.push_back(validador);
        validador->start();
    }
}

void VerificadorEBPF::validarArchivos(RepositorioDeArchivos& repo_archivos,
                                      RepositorioDeResultados& repo_resultados){
    std::atomic_int contador(0);
    while (repo_archivos.tieneArchivosSinProcesar()) {
        size_t pos_arreglo = contador%this-> cantidad_de_hilos;
        if (!repo_archivos.tieneArchivosSinProcesar())
            break;
        Validador* validador = this-> validadores[pos_arreglo];
        validador->validarArchivo(repo_archivos, repo_resultados);
        contador++;
    }

    for (int i = 0; i < cantidad_de_hilos; ++i) {
        this-> validadores[i]->join();
    }
}

void VerificadorEBPF::imprimirYFinalizar(RepositorioDeResultados&
    repo_resultados) {
    repo_resultados.imprimirResultados();

    for (int i = 0; i < this-> cantidad_de_hilos; ++i) {
        delete this-> validadores[i];
    }
}
