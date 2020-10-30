//
// Created by andy on 29/10/20.
//

#include <string>
#include <functional>
#include "Validador.h"
#include "Parser.h"

Validador::Validador(int num_thread, RepositorioDeArchivos* repo_arch,
                     RepositorioDeResultados* repo_res) {
    this->num_thread = num_thread;
    this->repositorio_archivos = repo_arch;
    this->repositorio_resultados = repo_res;
}

Validador::~Validador(){}

void Validador::run() { }

void Validador::evaluarResultado() {
    std::string nombre_archivo = repositorio_archivos->getProximoArchivo();
    Parser parser = Parser();
    std::string resultado = parser.evaluarArchivo(nombre_archivo);
    this-> repositorio_resultados-> agregarResultado(resultado);
}
