//
// Created by andy on 29/10/20.
//

#ifndef UNTITLED_REPOSITORIODEARCHIVOS_H
#define UNTITLED_REPOSITORIODEARCHIVOS_H


#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class RepositorioDeArchivos {
public:
    void guardarArchivo(const std::string& nombre);
    std::string getProximoArchivo();
    bool tieneArchivosSinProcesar();

private:
    std::string obtenerArchivo(std::condition_variable& cv);
    void abrirPuerta(std::condition_variable& cv);
    std::queue<std::string> nombres_de_archivos;
    std::mutex mutex;
    bool gate_open = false;
};




#endif //UNTITLED_REPOSITORIODEARCHIVOS_H
