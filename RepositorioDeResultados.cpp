//
// Created by andy on 29/10/20.
//

#include <string>
#include "RepositorioDeResultados.h"

void RepositorioDeResultados::agregarResultado(std::string resultado) {
    std::mutex mutex;
    std::lock_guard<std::mutex> lck(mutex);
    this-> resultados.push(resultado);
}

void RepositorioDeResultados::imprimirResultados() {
    while (!this-> resultados.empty()) {
        std::string resultado = this-> resultados.front();
        printf("%s\n", resultado.c_str());
        this-> resultados.pop();
    }
}
