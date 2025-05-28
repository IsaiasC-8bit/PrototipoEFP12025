#include <iostream>
#include<fstream>
#include <limits>
#include "MenuGeneral.h"
#include "usuarios.h"
#include "bitacora.h"
#include "seguridad.h"
//Realizado por Isaias Cedillo
using namespace std;
void menuGeneral();
int contrasenia = 147;
int ingreso;
int main()
{
seguridad seguridad1;//Objeto creado de clase sistema
Opciones opciones;//Objeto creado de clases Opciones
    int opcion;

    do {
    // Limpiar la pantalla
    system("cls");

    // Mostrar el men�
    cout << "=======================" << endl;
    cout << "1. Registrar usuario ||" << endl;
    cout << "2. Ingresar          ||" << endl;
    cout << "3. Mostrar usuarios  ||" << endl;
    cout << "4. Salir             ||" << endl;
    cout << "=======================" << endl << endl;

    // Solicitar la opci�n al usuario
    cout << "Ingrese opcion: ";

    try {
        // Verificar si la entrada es un entero v�lido
        if (!(cin >> opcion)) {
            // Lanzar una excepci�n si la entrada no es v�lida
            throw runtime_error("Error de entrada");
        }

        // Verificar si la opci�n est� dentro del rango v�lido
        if (opcion < 1 || opcion > 4) {
            // Lanzar una excepci�n si la opci�n no es v�lida
            throw runtime_error("Opci�n invalida");
        }
    } catch (const exception& e) {
        // Manejar la excepci�n y mostrar un mensaje de error
        cerr << "Ingrese datos validos.." << endl;

        // Limpiar el flag de error y ignorar la entrada inv�lida
        cin.clear();
        cin.ignore(10000, '\n');

        // Pausar el sistema y continuar con el siguiente ciclo
        system("pause");
        continue;
    }

    // Procesar la opci�n seleccionada
    switch (opcion) {
        case 1:
            // Registrar un nuevo usuario
            system("cls");
            cout << "Ingrese contrasenia maestra.." << endl;
            cin >> ingreso;
            if (ingreso == contrasenia) {
                seguridad.registrarUsuario();
            } else {
                cout << "Contrasenia incorrecta..." << endl;
                cout << "Regresando......." << endl;
            }
            break;
        case 2:
            // Ingresar al sistema
            seguridad1.ingresarUsuario();
            break;
        case 3:
            // Mostrar los usuarios registrados
            seguridad1.mostrarUsuarios();
            break;
        case 4:
            // Salir del sistema
            cout << "Saliendo del sistema..." << endl;
            break;
    }

    // Pausar el sistema antes de mostrar el men� nuevamente
    system("pause");
} while (opcion != 4); // Continuar hasta que se seleccione la opci�n de salir
    return 0;
}
