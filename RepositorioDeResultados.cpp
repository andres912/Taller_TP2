//
// Created by andy on 29/10/20.
//

#include <string>
#include "RepositorioDeResultados.h"

void RepositorioDeResultados::agregarResultado(const std::string& resultado) {
    m.lock();
    this-> resultados.push(resultado);
    m.unlock();
}

void RepositorioDeResultados::imprimirResultados() {
    while (!this-> resultados.empty()) {
        std::string resultado = this-> resultados.front();
        printf("%s\n", resultado.c_str());
        this-> resultados.pop();
    }
}
