#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

/*

El programa deberá pedir los datos del cliente, su dirección y los datos de su auto, 
una vez registrados los datos anteriores, el programa deberá de mostrar una pantalla con los
distintos mantenimientos y reparaciones que el taller puede realizar.

Al seleccionar uno o más de ellos el sistema deberá mostrar los recios unitarios y
el total de la reparación.

Una vez que se termine con la selección de los mantenimientos y/o
repataciones, el programa deberá preguntar si se procede con el trabajo o no.
En caso de "NO", solo mostrar en pantalla e resumen y salir. En caso de que "SI", el 
programa deberá de mostrar una fecha de entreha, así como el resumen del trabajo con sus costos,
esto último será guardado en un archivo de texto.
*/


using namespace std;
int main () {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES");
    cout << "Bienvenido a tu centro automotríz favorito.\n" << "Ingrese su nombre completo por favor:"<<endl;
    string nombre;

    getline(cin,nombre);
    cout << "Ingresa tu número telefónico:" <<endl;
    string telefono;
    getline(cin, telefono);
    cout << "Bienvenido "<< nombre << " ¿Qué deseas hacer?:" << endl;
    cout << "\n1.Revisión general."<<endl
    <<      "2.Cambio de aceite."<<endl
    <<      "3.Alineación."<<endl
    <<      "4.Balanceo."<<endl
    <<      "5.Limpieza de motor."<<endl
    <<      "\nPara cotizar un servicio especializado genere una cita."<<endl
    <<      "6.Generar cita.";
    cout << "Teclee su elección:";
    int OPC;
    cin >> OPC;
    getchar();
} 