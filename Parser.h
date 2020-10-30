//
// Created by andy on 24/10/20.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H


#include <string>
#include <list>
#include <vector>
#include "Grafo.h"
#include "DetectorDFS.h"

class Parser {
public:
    std::string evaluarArchivo(std::string nombre_archivo);

private:
    void evaluarLinea(const std::string& linea);
    void obtenerInstruccionesDeLinea(const std::string& linea);
    void evaluarInstruccionesdeLinea();
    void evaluarInstruccionDeSalto();
    void agregarConexion(std::string nombre_adyacente, bool flujo_normal);
    void nombrarLineaActual(const std::string& nombre);

    std::vector<std::string> vector_de_instrucciones;
    int cant_lineas;
    Grafo grafo;
    std::string ultima_etiqueta = "";
    std::string nombre_linea_actual;
    bool flujo_normal = true;
    DetectorDFS validador;
};


#endif //UNTITLED_PARSER_H
