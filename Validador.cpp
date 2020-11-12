//
// Created by andy on 29/10/20.
//

#include <string>
#include <iostream>
#include "Validador.h"
#include "Parser.h"

#define GRAFO_VALIDO 0
#define GRAFO_CICLICO 1
#define INSTRUCCIONES_SIN_USAR 2

Validador::Validador() = default;

Validador::~Validador()= default;

void Validador::run() {}

void Validador::validarArchivo(RepositorioDeArchivos& repo_arch,
                               RepositorioDeResultados& repo_res) {
    Grafo grafo = Grafo();
    Parser parser = Parser(grafo);
    std::string nombre_archivo = repo_arch.getProximoArchivo();
    bool val_parseo = parser.parsearArchivo(nombre_archivo);
    if (val_parseo != 0)
        return;

    int resultado_validacion = this->detector.evaluarGrafo(grafo);
    std::string resultado_a_imprimir = procesarResultadoDeValidacion(
            resultado_validacion, nombre_archivo);
    repo_res.agregarResultado(resultado_a_imprimir);
}

std::string Validador::procesarResultadoDeValidacion(int resultado_validacion,
                                            const std::string& nombre_archivo){
    std::string resultado_a_imprimir;
    switch (resultado_validacion) {
        case GRAFO_VALIDO:
            resultado_a_imprimir = nombre_archivo + " GOOD";
            break;
        case GRAFO_CICLICO:
            resultado_a_imprimir = nombre_archivo + " FAIL: cycle detected";
            break;
        case INSTRUCCIONES_SIN_USAR:
            resultado_a_imprimir = nombre_archivo +
                    " FAIL: unused instructions detected";
            break;
        default:
            break;
    }
    return resultado_a_imprimir;
}


