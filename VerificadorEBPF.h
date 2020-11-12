//
// Created by andy on 12/11/20.
//

#ifndef UNTITLED_VERIFICADOREBPF_H
#define UNTITLED_VERIFICADOREBPF_H

#include <vector>
#include "RepositorioDeArchivos.h"
#include "Validador.h"

class VerificadorEBPF {
public:
    VerificadorEBPF();
    void manejarProcesoDeValidacion(int argc, char** argv);
private:
    long int cantidad_de_hilos;
    std::vector<Validador*> validadores;
    static void guardarArchivos(int argc, char** argv,
                         RepositorioDeArchivos& repositorio);
    void inicializarValidadores();
    void validarArchivos(RepositorioDeArchivos& repo_archivos,
                                RepositorioDeResultados& repo_resultados);
    void imprimirYFinalizar(RepositorioDeResultados& repo_resultados);
};


#endif //UNTITLED_VERIFICADOREBPF_H
