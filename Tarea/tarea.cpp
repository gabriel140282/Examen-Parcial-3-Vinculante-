#include "tarea.h"
#include <iostream>

Tarea::Tarea(const std::string& id, const std::string& descripcion, int duracion)
    : id(id), desc(descripcion), duracion(duracion) {}

std::string Tarea::obtener_id() const {
    return id;
}

std::string Tarea::obtener_descripcion() const {
    return desc;
}

std::string Tarea::toString() const {
    return "Descripcion de la tarea: " + desc + ", Tiempo estimado: " + std::to_string(duracion) + " minutos";
}

int Tarea::obtener_duracion() const {
    return duracion;
}

int Tarea::obtener_duraciontotal() const {
    return duracion;
}