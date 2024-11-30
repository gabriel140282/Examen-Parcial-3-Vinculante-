#ifndef CRUD_H
#define CRUD_H

#include "../Actor/actor.h"
#include <vector>
#include <string>

class Crud {
private:
    std::vector<Actor> actores;

public:
    void iniciarCrud();  // Función que orquesta las operaciones CRUD
    void crearActor(const std::string& id, const std::string& descripcion);
    void leerActor(const std::string& id) const;
    void actualizarActor(const std::string& id, const std::string& nuevaDescripcion);
    void borrarActor(const std::string& id);
    void listarActores() const;
};

#endif // CRUD_H
