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
    explicit Parser(Grafo& grafo);
    int parsearArchivo(const std::string& nombre_archivo);

private:
    void parsearLinea(const std::string& linea);
    void obtenerInstruccionesDeLinea(const std::string& linea);
    void evaluarInstruccionesdeLinea();
    void evaluarInstruccionDeSalto();
    void agregarConexion(const std::string& nombre_adyacente, bool flujo_ok);
    void nombrarLineaActual(const std::string& nombre);

    std::vector<std::string> vector_de_instrucciones;
    int cant_lineas = 0;
    Grafo& grafo;
    std::string ultima_etiqueta;
    std::string nombre_linea_actual;
    bool flujo_normal = true;
};


#endif //UNTITLED_PARSER_H
