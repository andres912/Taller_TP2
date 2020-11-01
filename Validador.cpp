//
// Created by andy on 29/10/20.
//

#include <string>
#include <functional>
#include <iostream>
#include "Validador.h"
#include "Parser.h"

Validador::Validador() {}

Validador::~Validador(){}

void Validador::run() { }

void Validador::validarArchivo(RepositorioDeArchivos& repo_arch,
                               RepositorioDeResultados& repo_res) {
    Grafo grafo = Grafo();
    Parser parser = Parser(grafo);
    std::string nombre_archivo = repo_arch.getProximoArchivo();
    bool val_parseo = parser.parsearArchivo(nombre_archivo);
    if (val_parseo != 0)
        return;
    std::string resultado = this-> detector.validarCodigo(grafo);
    std::string resultado_a_imprimir = nombre_archivo + " " + resultado;
    repo_res.agregarResultado(resultado_a_imprimir);
}


