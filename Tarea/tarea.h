#ifndef TAREA_H
#define TAREA_H

#include <string>

class Tarea {
private:
    std::string id;
    std::string desc;
    int duracion;

public:
    Tarea(const std::string& id, const std::string& descripcion, int duracion);
    std::string obtener_id() const;
    std::string obtener_descripcion() const;
    int obtener_duracion() const;
    std::string toString() const;

    int obtener_duraciontotal() const;
};

#endif // TAREA_H