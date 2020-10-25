//
// Created by andy on 24/10/20.
//

#include "Parser.h"

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <fstream>
#include <unistd.h>

template <class Container>
void split(const std::string& str, Container& cont) {
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(cont));
}

void Parser::nombrarLineaActual(std::string nombre) {
    this->nombre_linea_actual = nombre;
}

void Parser::obtenerInstruccionesDeLinea(std::string linea) {
    split(linea, this->vector_de_instrucciones);
}

void Parser::evaluarLinea(std::string linea) {
    obtenerInstruccionesDeLinea(linea);
    std::string primera_instruccion = this->vector_de_instrucciones[0];
    std::string nombre_etiqueta;
    if (primera_instruccion.find(":") != std::string::npos) {
        nombre_etiqueta = primera_instruccion.substr(0,
                                              primera_instruccion.size()-1);
        this->vector_de_instrucciones.erase(vector_de_instrucciones.begin());
    } else {
        nombre_etiqueta = std::to_string(this->cant_lineas+1);
    }
    nombrarLineaActual(nombre_etiqueta);
    evaluarInstruccionesdeLinea();
    this->cant_lineas++;
    this->ultima_etiqueta = nombre_linea_actual;
    this->vector_de_instrucciones.clear();
}

void Parser::evaluarInstruccionesdeLinea() {
    grafo.agregarVertice(this->nombre_linea_actual);
    if (this-> flujo_normal && this->cant_lineas > 0)
        grafo.agregarArista(this-> ultima_etiqueta, nombre_linea_actual);
    std::string primera_instruccion = this->vector_de_instrucciones[0];
    if (primera_instruccion.find("j") == 0)
        evaluarInstruccionDeSalto();
    else if (primera_instruccion.compare("ret") == 0)
        this->flujo_normal = false;
}

void Parser::evaluarInstruccionDeSalto() {
    if (this->vector_de_instrucciones.size() <= 3) {
        std::string instr_1 = this->vector_de_instrucciones[0];
        if (instr_1== "jmp")
            agregarConexion(this->vector_de_instrucciones[1], false);
        else if (instr_1 == "ja")
            agregarConexion(this->vector_de_instrucciones[1], true);
        else
            agregarConexion(this->vector_de_instrucciones[2], true);
    } else {
        std::string nombre_adyacente_1 = this->vector_de_instrucciones[2];
        nombre_adyacente_1 = nombre_adyacente_1.substr(0,nombre_adyacente_1.size
                ()-1);
        std::string nombre_adyacente_2 = this->vector_de_instrucciones[3];
        agregarConexion(nombre_adyacente_1, false);
        agregarConexion(nombre_adyacente_2, false);
    }
}

void Parser::agregarConexion(std::string nombre_adyacente, bool flujo_normal) {
    grafo.agregarArista(this->nombre_linea_actual, nombre_adyacente);
    this->flujo_normal = flujo_normal;
}

void Parser::evaluarArchivo(std::string nombre_archivo) {
    std::ifstream infile(nombre_archivo);
    std::string linea;
    size_t contador = 0;
    if (!infile) {
        return;
    }
    while (getline(infile, linea)) {
        if (linea == "")
            continue;
        evaluarLinea(linea);
        if (contador == 0)
            grafo.setVerticeInicial(this->nombre_linea_actual);
        contador++;
    }
    this->validador.validarCodigo(this->grafo);
}
