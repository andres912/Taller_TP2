//
// Created by andy on 23/10/20.
//

#include <map>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include "DetectorDFS.h"

void agregarRecorrido(std::map<std::string, std::string> &visitados,
              const std::string& vertice_actual, const std::string& adyacente);
bool detectarCiclo(std::map<std::string, std::string>& visitados, const
                    std::string& vertice_actual, const std::string& adyacente);

int DetectorDFS::recorrerGrafo(Grafo& grafo) {
    std::stack<std::string> pila;
    std::string vertice_inicial = grafo.getVerticeInicial();
    pila.push(vertice_inicial);
    std::map<std::string, std::string> visitados;
    visitados.insert(std::pair<std:: string, std::string >(vertice_inicial,""));

    while (! pila.empty()) {
        std::string vertice = pila.top();
        pila.pop();
        std::set<std::string > adyacentes = grafo.obtenerAdyacentes(vertice);
        for (auto& adyacente : adyacentes) {
            if (visitados.count(adyacente) > 0) {
                if (visitados.at(adyacente) != vertice)
                    this->tiene_ciclos = detectarCiclo(visitados,
                                                       vertice, adyacente);
                continue;
            }
            agregarRecorrido(visitados, vertice, adyacente);
            pila.push(adyacente);
        }
    }
    this->tiene_instrucciones_sin_visitar = visitados.size() != grafo
                                                                .getOrden();
    return 0;
}

int DetectorDFS::validarCodigo(Grafo &grafo) {
    this->recorrerGrafo(grafo);
    if (tiene_ciclos)
        puts("FAIL: cycle detected");
    else if (tiene_instrucciones_sin_visitar)
        puts("FAIL: unused instructions detected");
    else
        puts("GOOD");
    return 0;
}

void agregarRecorrido(std::map<std::string, std::string> &visitados,
            const std::string& vertice_actual, const std::string& adyacente) {
    std::string cadena = vertice_actual + " - " + visitados.at(vertice_actual);
    visitados.insert(std::pair<std::string, std::string> (adyacente, cadena));
}

bool detectarCiclo(std::map<std::string, std::string>& visitados, const
                   std::string& vertice_actual, const std::string& adyacente) {
    std::string recorrido = visitados.at(vertice_actual);
    std::string cadena_1 = adyacente + " -";
    if (recorrido.find(cadena_1) != std::string::npos)
        return true;
    std::string cadena_2 = "- " +adyacente;
    if (recorrido.find(cadena_2) != std::string::npos)
        return true;
    return false;
}
