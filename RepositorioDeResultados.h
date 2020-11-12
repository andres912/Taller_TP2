//
// Created by andy on 29/10/20.
//

#ifndef UNTITLED_REPOSITORIODERESULTADOS_H
#define UNTITLED_REPOSITORIODERESULTADOS_H


#include <string>
#include <queue>
#include <mutex>

class RepositorioDeResultados {
public:
    void agregarResultado(const std::string& resultado);
    void imprimirResultados();
    
private:
    std::queue<std::string> resultados;
    std::mutex m;
};


#endif //UNTITLED_REPOSITORIODERESULTADOS_H
