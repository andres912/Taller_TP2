//
// Created by andy on 29/10/20.
//

#ifndef UNTITLED_VALIDADOR_H
#define UNTITLED_VALIDADOR_H


#include <string>
#include "Thread.h"
#include "RepositorioDeArchivos.h"
#include "RepositorioDeResultados.h"

class Validador : public Thread{
public:
    Validador();
    ~Validador();
    void run() override;
    void evaluarResultado(RepositorioDeArchivos& repo_arch,
                          RepositorioDeResultados& repo_res);
};



#endif //UNTITLED_VALIDADOR_H
