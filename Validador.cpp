//
// Created by andy on 29/10/20.
//

#include <string>
#include <functional>
#include "Validador.h"
#include "Parser.h"

Validador::Validador() {}

Validador::~Validador(){}

void Validador::run() { }

void Validador::evaluarResultado(RepositorioDeArchivos& repo_arch,
                                 RepositorioDeResultados& repo_res) {
    std::string nombre_archivo = repo_arch.getProximoArchivo();
    Parser parser = Parser();
    std::string resultado = parser.evaluarArchivo(nombre_archivo);
    std::string resultado_a_imprimir = nombre_archivo + " " + resultado;
    repo_res.agregarResultado(resultado_a_imprimir);
}
