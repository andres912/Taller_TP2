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

int main(int argc, char** argv) {
    RepositorioDeArchivos repositorio_arch;
    RepositorioDeResultados repositorio_res;
    std::vector<Validador*> validadores;
    int cantidad_de_hilos = atoi(argv[1]);
    for (int i = 0; i < argc-2; ++i) {
        std::string nombre_archivo = argv[i+2];
        repositorio_arch.guardarArchivo(nombre_archivo);
    }
    for (int i = 0; i < cantidad_de_hilos; ++i) {
        Validador* validador = new Validador();
        validadores.push_back(validador);
    }

    for (int i = 0; i < cantidad_de_hilos; ++i) {
        validadores[i]->start();
    }

    std::atomic_int contador(0);

    while (repositorio_arch.tieneArchivosSinProcesar()) {
        size_t pos = contador%cantidad_de_hilos;
        if (!repositorio_arch.tieneArchivosSinProcesar())
            break;
        Validador* validador = validadores[pos];
        validador->evaluarResultado(repositorio_arch, repositorio_res);
        contador++;
    }

    for (int i = 0; i < cantidad_de_hilos; ++i) {
        validadores[i]->join();
    }
    repositorio_res.imprimirResultados();

    for (int i = 0; i < cantidad_de_hilos; ++i) {
        delete validadores[i];
    }
}
