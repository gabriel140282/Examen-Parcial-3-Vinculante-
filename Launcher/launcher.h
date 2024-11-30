#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "../Actor/actor.h"
#include "../Tarea/tarea.h"
#include <vector>

class Launcher {
public:
    void ejecutar();
private:
    std::vector<Tarea> crearTareas();
    std::vector<Actor> crearActores();
    void asignarTareas(std::vector<Actor>& actores, const std::vector<Tarea>& tareas);
};

#endif //LAUNCHER_H