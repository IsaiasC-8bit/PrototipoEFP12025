#include "seguridad.h"
#include "MenuGeneral.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <limits>
#include <vector>
//Modificado por Roli Cedillo
MenuGeneral opcion; // Se crea un objeto global de la clase MenuGeneral

seguridad::seguridad()
{

}

seguridad::~seguridad()
{

}

// Funci�n para registrar un nuevo usuario
void seguridad::registrarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para guardar el nombre y la contrase�a del usuario
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre de usuario: ";
    getline(cin,nombre);  // Captura el nombre del usuario Corregido por Isaias Cedillo para obtener nombre completo del usuario

    cout << "Ingrese contrasenia: ";
    char caracter;       // Variable para leer car�cter por car�cter la contrase�a

    // Captura la contrase�a con ocultamiento visual (solo muestra '*')
    while ((caracter = _getch()) != '\r') { // Mientras no se presione Enter
        if (caracter == '\b') {             // Si se presiona retroceso
            if (!contrasenia.empty()) {     // Si la contrase�a no est� vac�a
                cout << "\b \b";            // Borra un asterisco en pantalla
                contrasenia.pop_back();     // Elimina el �ltimo car�cter de la contrase�a
            }
        } else {
            contrasenia += caracter;        // Agrega el car�cter a la contrase�a
            cout << "*";                    // Muestra un asterisco
        }
    }
    cout << endl;  // Salto de l�nea al final de la contrase�a

    ofstream archivo(archivoUsuarios, ios::binary|ios::app|ios::out);  // Abre archivo para agregar usuarios
    if (archivo.is_open()) {
        size_t nombretamano = nombre.size();
        archivo.write(reinterpret_cast<const char*>(&nombretamano), sizeof(nombretamano));  // Guarda el usuario y contrase�a
        archivo.write(nombre.c_str(), nombretamano);
        size_t contratamano = contrasenia.size();
        archivo.write(reinterpret_cast<const char*>(&contratamano), sizeof(contratamano));  // Guarda el usuario y contrase�a
        archivo.write(contrasenia.c_str(), contratamano);
        archivo.close();                                  // Cierra el archivo
        cout << "Usuario registrado con exito." << endl;  // Mensaje de �xito
    } else {
        cout << "No se pudo abrir el archivo." << endl;   // Error al abrir archivo
    }
}

void seguridad::ingresarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para ingresar datos del usuario

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre de usuario: ";       // Captura el nombre
    getline(cin, nombre);
    cout << "Ingrese contrasenia: ";
    char caracter;

    // Captura oculta de contrase�a
    while ((caracter = _getch()) != '\r') {
        if (caracter == '\b') {
            if (!contrasenia.empty()) {
                cout << "\b \b";
                contrasenia.pop_back();
            }
        } else {
            contrasenia += caracter;
            cout << "*";
        }
    }
    cout << endl;

    ifstream archivo(archivoUsuarios, ios::binary);  // Abre el archivo en modo binario
    if (archivo.is_open()) {
        bool encontrado = false;

        while (true) {
            // Leer tama�o del nombre de usuario
            size_t tamUsuario;
            archivo.read(reinterpret_cast<char*>(&tamUsuario), sizeof(tamUsuario));
            if (archivo.eof()) break;

            // Leer nombre de usuario
            vector<char> usuarioBuffer(tamUsuario);
            archivo.read(usuarioBuffer.data(), tamUsuario);
            string usuario(usuarioBuffer.data(), tamUsuario);

            // Leer tama�o de la contrase�a
            size_t tamContrasenia;
            archivo.read(reinterpret_cast<char*>(&tamContrasenia), sizeof(tamContrasenia));

            // Leer contrase�a
            vector<char> contraseniaBuffer(tamContrasenia);
            archivo.read(contraseniaBuffer.data(), tamContrasenia);
            string contraseniaArchivo(contraseniaBuffer.data(), tamContrasenia);

            // Comparar credenciales
            if (usuario == nombre && contraseniaArchivo == contrasenia) {
                usuarioActual = nombre;
                cout << "Ingreso exitoso." << endl;
                encontrado = true;
                archivo.close();
                opcion.menu(usuario);
                return;
            }
        }

        archivo.close();
        if (!encontrado) {
            cout << "Nombre de usuario o contrasena incorrecta." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
void seguridad::mostrarUsuarios() {
    system("cls");  // Limpiar pantalla

    // 1. Abrir archivo binario
    ifstream archivo(archivoUsuarios, ios::binary);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
        system("pause");
        return;
    }

    cout << "============ LISTA DE USUARIOS ============\n\n";

    // 2. Leer cada usuario del archivo
    while (true) {
        // 2.1 Leer tama�o del nombre de usuario
        size_t tamUsuario;
        archivo.read((char*)&tamUsuario, sizeof(tamUsuario));

        // Si llegamos al final del archivo, salir
        if (archivo.eof()) break;

        // 2.2 Leer el nombre de usuario
        string usuario;
        usuario.resize(tamUsuario);
        archivo.read(&usuario[0], tamUsuario);

        // 2.3 Leer tama�o de la contrase�a
        size_t tamContrasenia;
        archivo.read((char*)&tamContrasenia, sizeof(tamContrasenia));

        // 2.4 Leer la contrase�a (pero no la guardamos)
        archivo.seekg(tamContrasenia, ios::cur);

        // 3. Mostrar la informaci�n
        cout << "Usuario: " << usuario << endl;
        cout << "Contrase�a: " << string(tamContrasenia, '*') << endl; // Mostrar asteriscos
        cout << "-----------------------------" << endl << endl;
    }

    // 4. Cerrar archivo
    archivo.close();
    system("pause");
}
