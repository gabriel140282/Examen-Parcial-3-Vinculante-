#include "actor.h"
#include <iostream>
#include <sstream> //Para usar ostringstream en lugar de iomanip

//Creamos un constructor que establece el id y la descripción del actor
Actor::Actor(const std::string& idActor, const std::string& desc)
    : id(idActor), descripcion(desc) {}

//Obtenemos el id del Actor
std::string Actor::obtener_id() const {
    return id;
}

//Obtenemos la descripción del Actor
std::string Actor::obtener_descripcion() const {
    return descripcion;
}

//Añadimos un método para agregar una tarea al Actor y que me devuelva el número total de tareas
int Actor::aniadir_tarea(const Tarea& nuevaTarea) {
    lista_tareas.push_back(nuevaTarea);
    return static_cast<int>(lista_tareas.size());
}

//Añadimos un método que calcula la duración total de todas las tareas del Actor
int Actor::obtener_duraciontotal() const {
    int sumaDuraciones = 0;
    for (const auto& tarea : lista_tareas) {
        sumaDuraciones += tarea.obtener_duraciontotal();
    }
    return sumaDuraciones;
}

//Añadimos un último método que genera una representación en texto del Actor y sus tareas
std::string Actor::toString() const {
    std::ostringstream resultado; // Usamos ostringstream para construir la salida
    resultado << "ID del Actor: " << id << "\nDescripción: " << descripcion << "\n";

    if (lista_tareas.empty()) {
        resultado << "No hay tareas asignadas.\n";
    } else {
        for (size_t index = 0; index < lista_tareas.size(); ++index) {
            resultado << "  Tarea " << (index + 1) << ": " << lista_tareas[index].toString() << "\n";
        }
    }

    return resultado.str();
}