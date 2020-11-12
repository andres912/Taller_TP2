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
    ~Validador() override;
    void run() override;
    void validarArchivo(RepositorioDeArchivos& repo_arch,
                        RepositorioDeResultados& repo_res);
private:
    DetectorDFS detector;

    static std::string procesarResultadoDeValidacion(int resultado_validacion,
                                             const std::string& nombre_archivo);
};

#endif //UNTITLED_VALIDADOR_H
