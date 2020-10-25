#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include "Parser.h"


int main(int argc, char** argv) {
    if (!argv[1])
        return 1;
    std::string nombre_archivo = argv[1];
    Parser parser = Parser();
    printf("%s ", nombre_archivo.c_str());
    parser.evaluarArchivo(nombre_archivo);
}
