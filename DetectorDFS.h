//
// Created by andy on 23/10/20.
//

#include "Grafo.h"

#ifndef UNTITLED_DETECTORDFS_H
#define UNTITLED_DETECTORDFS_H


class DetectorDFS {
public:
    int validarCodigo(Grafo& grafo);

private:
    int recorrerGrafo(Grafo& grafo);
    bool tiene_ciclos = false;
    bool tiene_instrucciones_sin_visitar = false;
};


#endif //UNTITLED_DETECTORDFS_H
