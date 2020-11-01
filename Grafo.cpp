//
// Created by andy on 23/10/20.
//

#include <utility>
#include <string>
#include <set>
#include "Grafo.h"

int Grafo::agregarVertice(std::string nombre_vertice) {
    if (this->relaciones.count(nombre_vertice) > 0)
        return 1;

    std::set<std::string> nuevo_set;
    this->relaciones.insert(std::pair<std::string, std::set<std::string>>
                                                (nombre_vertice, nuevo_set));
    this->cant_vertices++;
    return 0;
}

int Grafo::agregarArista(std::string vertice_1, std::string vertice_2) {
    this->relaciones.at(vertice_1).insert(vertice_2);
    this->cant_aristas++;
    return 0;
}

std::set<std::string> Grafo::obtenerAdyacentes(std::string vertice) {
    return this->relaciones.at(vertice);
}

std::string Grafo::getVerticeInicial() {
    return this->vertice_inicial;
}

void Grafo::setVerticeInicial(std::string nombre_vertice_inicial) {
    this->vertice_inicial = nombre_vertice_inicial;
}

size_t Grafo::getOrden() {
    return this->relaciones.size();
}

void Grafo::imprimir() {
    for (auto par : this->relaciones) {
        std::string vertice = par.first;
        printf("%s: ", vertice.c_str());
        std::set<std::string> adyacentes = this->relaciones.at(vertice);
        for (auto adyacente : this->relaciones.at(vertice))
            printf("%s - ", adyacente.c_str());
        printf("\n");
    }
}
