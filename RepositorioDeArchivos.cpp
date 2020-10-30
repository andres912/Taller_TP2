//
// Created by andy on 29/10/20.
//


#include <string>
#include "RepositorioDeArchivos.h"

void RepositorioDeArchivos::guardarArchivo(const std::string& nombre) {
    this-> nombres_de_archivos.push(nombre);
}

std::string RepositorioDeArchivos::getProximoArchivo() {
    std::condition_variable cv;
    std::string nombre_archivo = obtenerArchivo(cv);
    abrirPuerta(cv);
    return nombre_archivo;
}

bool RepositorioDeArchivos::tieneArchivosSinProcesar() {
    return !this->nombres_de_archivos.empty();
}

std::string RepositorioDeArchivos::obtenerArchivo(std::condition_variable& cv) {
    std::unique_lock<std::mutex> lck(this->mutex);
    std::string nombre_archivo;
    if (this->nombres_de_archivos.empty()) {
        nombre_archivo = "";
    } else {
        nombre_archivo = this-> nombres_de_archivos.front();
        this->nombres_de_archivos.pop();
    }
    return nombre_archivo;
}

void RepositorioDeArchivos::abrirPuerta(std::condition_variable& cv) {
    std::unique_lock<std::mutex> lock(this->mutex);
    this-> gate_open = true;
    cv.notify_all();
}
