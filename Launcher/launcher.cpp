#include "launcher.h"
#include <iostream>
#include <iomanip>

std::vector<Tarea> Launcher::crearTareas() {
    return {
        Tarea("A", "Realizar la reserva del vuelo", 20),
        Tarea("B", "Avisar a casa para que empiecen a empacar", 5),
        Tarea("C", "Empacar todas las maletas", 40),
        Tarea("D", "Gestionar el billete con la agencia", 10),
        Tarea("E", "Recoger el billete en la agencia", 5),
        Tarea("F", "Entregar el billete en la oficina", 10),
        Tarea("G", "Recoger las maletas en casa", 20),
        Tarea("H", "Transportar las maletas a la oficina", 25),
        Tarea("I", "Discutir sobre los documentos necesarios", 35),
        Tarea("J", "Dar instrucciones sobre la ausencia", 25),
        Tarea("K", "Compilar todos los documentos", 15),
        Tarea("L", "Clasificar los documentos", 5),
        Tarea("M", "Viajar al aeropuerto y hacer el check-in", 25)
    };
}

std::vector<Actor> Launcher::crearActores() {
    return {
        Actor("1", "Director General"),
        Actor("2", "Asistente Personal"),
        Actor("3", "Agencia de Viajes"),
        Actor("4", "Compañia de Transporte")
    };
}

void Launcher::asignarTareas(std::vector<Actor>& actores, const std::vector<Tarea>& tareas) {
    actores[0].aniadir_tarea(tareas[0]); // Director: Reservar el vuelo
    actores[1].aniadir_tarea(tareas[1]); // Asistente: Avisar a casa
    actores[1].aniadir_tarea(tareas[2]); // Asistente: Empacar las maletas
    actores[2].aniadir_tarea(tareas[3]); // Agencia: Gestionar el billete
    actores[2].aniadir_tarea(tareas[4]); // Agencia: Recoger el billete
    actores[3].aniadir_tarea(tareas[12]); // Transporte: Viajar al aeropuerto
}

void Launcher::ejecutar() {
    std::vector<Tarea> tareas = crearTareas();
    std::vector<Actor> actores = crearActores();

    asignarTareas(actores, tareas);

    int tiempoTotal = 0;
    std::cout << "=== Resumen de tareas asignadas a cada actor ===" << std::endl;

    for (const auto& actor : actores) {
        std::cout << "Actor: " << actor.obtener_descripcion() << std::endl;
        std::cout << actor.toString();
        tiempoTotal += actor.obtener_duraciontotal();
        std::cout << "Duracion total para " << actor.obtener_descripcion() << ": "
             << actor.obtener_duraciontotal() << " minutos" << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }

    std::cout << "=== Tiempo total estimado para completar todas las tareas ===" << std::endl;
    std::cout << "Tiempo total: " << tiempoTotal << " minutos" << std::endl;

    std::cout << "\n=== Evaluacion de tiempos ===" << std::endl;
    for (const auto& actor : actores) {
        if (actor.obtener_duraciontotal() > 100) {
            std::cout << "El actor " << actor.obtener_descripcion() << " No podra completar sus tareas a tiempo." << std::endl;
        } else {
            std::cout << "El actor " << actor.obtener_descripcion() << " Si podra completar sus tareas a tiempo." << std::endl;
        }
    }
}