#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include <fstream>
#include <vector>
#include <limits>
#include "usuarios.h"

using namespace std;

class seguridad //clase seguridad la cual es encargada del proceso de registrar logear y mostrar usuarios
{
public:
    seguridad();
    virtual ~seguridad();
//Se declaran los metodos para sistemas de seguridad
    void registrarUsuario();
    void ingresarUsuario();
    void mostrarUsuarios();
    std::string getUsuarioActual() const { return usuarioActual; }

private:
    string archivoUsuarios = "usuarios.bin";
    string usuarioActual = "";
};

#endif // SEGURIDAD_H
