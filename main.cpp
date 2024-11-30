#include "./Launcher/launcher.h"
#include "./Crud/crud.h"

int main() {
    Launcher launcher;
    Crud crud;
    launcher.ejecutar();
    crud.iniciarCrud();
    return 0;
}
