#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include <stdbool.h>

/*
El programa deberá pedir los datos del cliente, su dirección y los datos de su auto, 
una vez registrados los datos anteriores, el programa deberá de mostrar una pantalla con los
distintos mantenimientos y reparaciones que el taller puede realizar.

Al seleccionar uno o más de ellos el sistema deberá mostrar los precios unitarios y
el total de la reparación.

Una vez que se termine con la selección de los mantenimientos y/o
repataciones, el programa deberá preguntar si se procede con el trabajo o no.
En caso de "NO", solo mostrar en pantalla e resumen y salir. En caso de que "SI", el 
programa deberá de mostrar una fecha de entreha, así como el resumen del trabajo con sus costos,
esto último será guardado en un archivo de texto.
*/

typedef struct data
{
    char nombre[80];
    char tel[15];
    char Direccion [120];
    //DATOS DEL AUTO
    char Marca[50];
    char Modelo[50];
    int year;

}DATOS;

typedef struct servicios
{
    bool aceite;
    bool acumulador;
    bool suspension;
    bool alineacion;
    bool mofle;
    bool torneado;
    bool clutch;
    bool diferenciales;
    bool engrasado;
    bool rotacion;
    bool frenos;
}SERVICIOS;



DATOS getInfo(DATOS *cliente) {
    system("cls");
    printf("Ingrese su nombre completo en mayusculas: ");
    fflush(stdin);
    gets(cliente->nombre);
    printf("Ingrese su número de teléfono: ");
    fflush(stdin);
    gets(cliente->tel);
    printf("Ingrese la dirección de su domicilio: ");
    fflush(stdin);
    gets(cliente->Direccion);
    printf("Ingrese la marca de su automóvil: ");
    fflush(stdin);
    gets(cliente->Marca); 
    printf("Ingrese el modelo de su automóvil: ");
    fflush(stdin);
    gets(cliente->Modelo);
    printf("Ingrese el año de su automóvil: ");
    fflush(stdin);
    scanf("%d",&cliente->year);
    return *cliente;
}

int listado(SERVICIOS *resumen) {
    int OPCION;
    bool flag = true;
    float subtotal = 0.0;
    while (flag)
    {
        system("cls");
        printf("	        Seleccione un servicio a realizar.:\n");
        printf("--------------------------------------------------------------------\n");
        printf("        SERVICIO                                        IMPORTE\n");
        printf("--------------------------------------------------------------------\n");
		printf("1.-Lubricació y cambio de aceite                        $3,000.0 MXN\n");
		printf("2.-Reemplazo de acumulador                              $2,000.0 MXN\n");
		printf("3.-Suspension                                           $4,000.0 MXN\n");
		printf("4.-Alineacion y Balanceo                                $700.0   MXN\n");
		printf("5.-Mofles                                               $5,000.0 MXN\n");
		printf("6.-Rectificacion y Torneado                             $1,000.0 MXN\n");
		printf("7.-Servicio de clutch                                   $2,000.0 MXN\n");
		printf("8.-Sevicio de diferenciales                             $2,000.0 MXN\n");
		printf("9.-Engrasado                                            $500.0   MXN\n");
		printf("10.-Rotacion                                            $1,000.0 MXN\n");
		printf("11.-Revision,limpieza y ajuste de frenos                $1,000.0 MXN\n");
        printf("--------------------------------------------------------------------\n");
        printf("                                              Subtotal: $%.1f\n",subtotal);
		printf("12 para salir.\n");
        printf("Seleccione: "); scanf("%d",&OPCION);
        fflush(stdin);
        switch (OPCION)
        {
        case 1:
            resumen->aceite = true; subtotal+= 3000.0;
            break;
        case 2:
            resumen->acumulador = true; subtotal+= 2000.0;
            break;
        case 3:
            resumen->suspension = true;subtotal+= 4000.0;
            break;
        case 4:
            resumen->alineacion = true;subtotal+= 700.0;
            break;
        case 5:
            resumen->mofle = true;subtotal+= 5000.0;
            break;
        case 6:
            resumen->torneado = true;subtotal+= 1000.0;
            break;
        case 7:
            resumen->clutch = true;subtotal+= 2000.0;
            break;
        case 8:
            resumen->diferenciales = true;subtotal+= 2000.0;
            break;
        case 9:
            resumen->engrasado = true;subtotal+= 500.0;
            break;
        case 10:
            resumen->rotacion = true; subtotal+= 1000.0;
            break;
        case 11:
            resumen->frenos = true;subtotal+= 1000.0;
            break;
        case 12:
            flag = false;
            system("cls");
        default:
            break;
        }
    }
    
    
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES");
    
    DATOS cliente;
    DATOS *puntero = &cliente;
    SERVICIOS resumen;
    SERVICIOS *respuntero = &resumen;
    resumen.aceite = false;
    resumen.acumulador = false;
    resumen.suspension = false;
    resumen.alineacion = false;
    resumen.mofle = false;
    resumen.torneado = false;
    resumen.clutch = false;
    resumen.diferenciales = false;
    resumen.engrasado = false;
    resumen.rotacion = false;
    resumen.frenos = false;
    printf("Bienvenido al Mexicanico\n");
    printf("************************\n");
    printf("¿Desea realizar alguna cita o consulta?\n  1.Si\n  2.No\n");
    int OPC;
    scanf("%d",&OPC);
    switch (OPC)
    {
    case 1:
        cliente = getInfo(puntero);
        listado(respuntero);
        /*PENDIENTE DE HACER:
            -IMRPIMR UN MENU QUE DIGA SI EL USUARIO QUIERE SEGUIR O NO.
            -HACER EL RESUMEN EN TXT E IMPRESO EN LA CONSOLA. */
        break;
    case 2:
        system("cls");
        printf("¡Vuelva pronto!");
        break;
    default:
        break;
    }

}



