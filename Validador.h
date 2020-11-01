//
// Created by andy on 29/10/20.
//

#ifndef UNTITLED_VALIDADOR_H
#define UNTITLED_VALIDADOR_H


#include <string>
#include "Thread.h"
#include "RepositorioDeArchivos.h"
#include "RepositorioDeResultados.h"
#include "DetectorDFS.h"
#include "Parser.h"

class Validador : public Thread{
public:
    Validador();
    ~Validador();
    void run() override;
    void validarArchivo(RepositorioDeArchivos& repo_arch,
                        RepositorioDeResultados& repo_res);
private:
    DetectorDFS detector;
};

#endif //UNTITLED_VALIDADOR_H
