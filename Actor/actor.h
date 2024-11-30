#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "../Tarea/tarea.h"
#include <string>

class Actor {
private:
    std::string id;
    std::string descripcion;
    std::vector<Tarea> lista_tareas;

public:
    Actor(const std::string& idActor, const std::string& desc);
    std::string obtener_id() const;
    std::string obtener_descripcion() const;
    int aniadir_tarea(const Tarea& nuevaTarea);
    int obtener_duraciontotal() const;
    std::string toString() const;
};

#endif // ACTOR_H