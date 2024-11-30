#include "crud.h"
#include <iostream>
#include <algorithm>

// Función que orquesta las operaciones CRUD
void Crud::iniciarCrud() {
    // Crear algunos actores para ejemplo
    crearActor("1", "Director General");
    crearActor("2", "Asistente Personal");

    // Listar los actores creados
    std::cout << "\nLista de actores:\n";
    listarActores();

    // Leer un actor
    std::cout << "\nLeyendo actor con ID 1:\n";
    leerActor("1");

    // Actualizar un actor
    actualizarActor("2", "Asistente Ejecutivo");

    // Listar nuevamente los actores después de la actualización
    std::cout << "\nLista de actores despues de actualizacion:\n";
    listarActores();

    // Borrar un actor
    borrarActor("1");

    // Listar nuevamente los actores después del borrado
    std::cout << "\nLista de actores despues de borrado:\n";
    listarActores();
}

// Crear un actor
void Crud::crearActor(const std::string& id, const std::string& descripcion) {
    Actor nuevoActor(id, descripcion);
    actores.push_back(nuevoActor);
    std::cout << "Actor con ID " << id << " creado exitosamente." << std::endl;
}

// Leer un actor por ID
void Crud::leerActor(const std::string& id) const {
    auto it = std::find_if(actores.begin(), actores.end(), [&id](const Actor& actor) {
        return actor.obtener_id() == id;
    });

    if (it != actores.end()) {
        std::cout << "Actor encontrado: " << it->obtener_descripcion() << std::endl;
    } else {
        std::cout << "Actor con ID " << id << " no encontrado." << std::endl;
    }
}

// Actualizar un actor (por ID)
void Crud::actualizarActor(const std::string& id, const std::string& nuevaDescripcion) {
    auto it = std::find_if(actores.begin(), actores.end(), [&id](const Actor& actor) {
        return actor.obtener_id() == id;
    });

    if (it != actores.end()) {
        // Actualiza la descripción del actor
        it->~Actor();  // Elimina el actor actual
        new (&(*it)) Actor(id, nuevaDescripcion); // Reemplaza el actor en el mismo lugar de memoria
        std::cout << "Actor con ID " << id << " actualizado exitosamente." << std::endl;
    } else {
        std::cout << "Actor con ID " << id << " no encontrado." << std::endl;
    }
}

// Borrar un actor por ID
void Crud::borrarActor(const std::string& id) {
    auto it = std::find_if(actores.begin(), actores.end(), [&id](const Actor& actor) {
        return actor.obtener_id() == id;
    });

    if (it != actores.end()) {
        actores.erase(it);
        std::cout << "Actor con ID " << id << " borrado exitosamente." << std::endl;
    } else {
        std::cout << "Actor con ID " << id << " no encontrado." << std::endl;
    }
}

// Listar todos los actores
void Crud::listarActores() const {
    if (actores.empty()) {
        std::cout << "No hay actores registrados." << std::endl;
    } else {
        for (const auto& actor : actores) {
            std::cout << "ID: " << actor.obtener_id() << ", Descripcion: " << actor.obtener_descripcion() << std::endl;
        }
    }
}
