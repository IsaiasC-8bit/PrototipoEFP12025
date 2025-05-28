#include "MenuGeneral.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"
using namespace std;
bitacora Bitacora;
Empleados mantenimiento;
//codigo realizado por HERSON GIRON

void MenuGeneral()::menu(string usuario)//Metodo de despliegue del menu
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout<<"\n\n\t      Menu General"<<endl;
        cout<<"\t ----------------------"<<endl;
        cout<<"\t | 1. Catalogos:      |"<<endl;
        cout<<"\t | 2. Informes:       |"<<endl;
        cout<<"\t | 3. Seguridad:      |"<<endl;
        cout<<"\t | 4. Salir   :       |"<<endl;
        cout<<"\t |                    |"<<endl;
        cout<<"\t ----------------------"<<endl<<endl;
        cout<<"   Ingrese opcion: ";
        cin>>opciones;
        switch (opciones)
        {
        case 1:
            {
            mantenimiento.menuEmpleados(usuario); //Se llama al metodo menu empleados con el objeto de la clase EMPLEADOS
            //Para mostrar el menu y manipular datos del empleados
            }
            break;
        case 2:
            {
             mantenimiento.mostrarMenuNomina(usuario); //Se llama al metodo mostrar menu nomina de la clase EMPLEADOS para mostrar
             //el menu de procesos de empleados
            }
            break;
        case 3:
            {
            Bitacora.menu(); //Se llama al metodo menu de la clase bitacora para mostrar el menu de la bitacora
            }
            break;
        case 4:
            {
            repetir=false; //Si se ingresa 5 se cierra el programa por completo
            exit(0); //Finaliza el programa de forma inmediata (el 0 signifca que el programa termino correctamente sin errores)
            }
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(repetir);
}
