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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

struct datos {
    char Nombre[80];
    char Direccion[100];
    char MarcaAuto[40];
    char ModeloAuto[50];
    int YearAuto;
};
struct datos getInfo(struct datos cliente){
    fflush(stdin);
    printf("Ingrese su nombre completo: ");
    gets(cliente.Nombre);
    system("cls");
    return cliente;
}

int main(){
    //Programa principal
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES");
    printf("Bienvenido al Mexicanico\n");
    printf("************************\n");
    printf("¿Desea realizar alguna cita o consulta?\n  1.Si\n  2.No\n");
    int OPC;
    fflush(stdin);
    scanf("%d",&OPC);
    struct datos Cliente;
    switch (OPC)
    {
        case 1:
            getInfo(Cliente);
            printf("%s",Cliente.Nombre);
            break;
        case 2:
        system("cls");
        printf("¡Vuelva pronto!");
            break;
    }
    
}


