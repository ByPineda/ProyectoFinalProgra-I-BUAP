#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include <stdbool.h>

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
    float subtotal;
}SERVICIOS;



DATOS getInfo(DATOS *cliente ) {
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

int listado(SERVICIOS *resumen ) {
    int OPCION;
    bool flag = true;
    resumen->subtotal = 0.0;
    while (flag)
    {
        system("cls");
        printf("	        Seleccione un servicio a realizar.:\n");
        printf("--------------------------------------------------------------------\n");
        printf("        SERVICIO                                          IMPORTE\n");
        printf("--------------------------------------------------------------------\n");
		printf("1.-Lubricación y cambio de aceite                       $3,000.0 MXN\n");
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
        printf("                                              Subtotal: $%.1f\n",resumen->subtotal);
		printf("12 para finalizar.\n");
        printf("Seleccione: "); scanf("%d",&OPCION);
        fflush(stdin);
        switch (OPCION)
        {
        case 1:
            resumen->aceite = true; resumen->subtotal+= 3000.0;
            break;
        case 2:
            resumen->acumulador = true; resumen->subtotal+= 2000.0;
            break;
        case 3:
            resumen->suspension = true;resumen->subtotal+= 4000.0;
            break;
        case 4:
            resumen->alineacion = true;resumen->subtotal+= 700.0;
            break;
        case 5:
            resumen->mofle = true;resumen->subtotal+= 5000.0;
            break;
        case 6:
            resumen->torneado = true;resumen->subtotal+= 1000.0;
            break;
        case 7:
            resumen->clutch = true;resumen->subtotal+= 2000.0;
            break;
        case 8:
            resumen->diferenciales = true;resumen->subtotal+= 2000.0;
            break;
        case 9:
            resumen->engrasado = true;resumen->subtotal+= 500.0;
            break;
        case 10:
            resumen->rotacion = true; resumen->subtotal+= 1000.0;
            break;
        case 11:
            resumen->frenos = true;resumen->subtotal+= 1000.0;
            break;
        case 12:
            flag = false;
            system("cls");
        default:
            break;
        }
    }
    
    
}

int resumenfinal(SERVICIOS *resumen, FILE *fp, DATOS *cliente) {
    
    //ESTA PARTE IMPRIME AL ARCHIVO .txt
    system("cls");
    fprintf(fp,"Mexicanicos S.A de C.V\n");
    fprintf(fp,"*********************************************************************\n");
    fprintf(fp,"Cliente: %s\n",cliente->nombre);
    fprintf(fp,"Teléfono: %s\n",cliente->tel);
    fprintf(fp,"Dirección: %s\n",cliente->Direccion);
    fprintf(fp,"\nAutomóvil\n");
    fprintf(fp,"Marca: %s\n",cliente->Marca);
    fprintf(fp,"Modelo: %s\n",cliente->Modelo);
    fprintf(fp,"Año: %d\n",cliente->year);
    fprintf(fp,"*********************************************************************\n");
    fprintf(fp,"Servicios a realizar: \n");

    //ESTA PARTE IMPRIME A CONSOLA Y A ARCHIVO .txt
    printf("*********************************************************************\n");
    if (resumen->aceite){
       printf("-Lubricación y cambio de aceite                        $3,000.0 MXN\n");
       fprintf(fp,"-Lubricación y cambio de aceite                        $3,000.0 MXN\n");
    }
    if (resumen->acumulador)
    {
       printf("-Reemplazo de acumulador                              $2,000.0 MXN\n");
       fprintf(fp,"-Reemplazo de acumulador                               $2,000.0 MXN\n");
    }
    if (resumen->suspension)
    {
       printf("-Alineacion y Balanceo                                $700.0   MXN\n");
       fprintf(fp,"-Alineacion y Balanceo                                 $700.0   MXN\n");
    }
    if (resumen->clutch)
    {
       printf("-Servicio de clutch                                   $2,000.0 MXN\n");
       fprintf(fp,"-Servicio de clutch                                   $2,000.0 MXN\n");
    }
    if (resumen->mofle)
    {
       printf("-Mofles                                               $5,000.0 MXN\n");
       fprintf(fp,"-Mofles                                                $5,000.0 MXN\n");
    }
    if (resumen->torneado)
    {
       printf("-Rectificacion y Torneado                             $1,000.0 MXN\n");
       fprintf(fp,"-Rectificacion y Torneado                              $1,000.0 MXN\n");
    }
    if (resumen->alineacion)
    {
       printf("-Alineacion y Balanceo                                $700.0   MXN\n");
       fprintf(fp,"-Alineacion y Balanceo                                 $700.0   MXN\n");
    }
    if (resumen->diferenciales)
    {
       printf("-Sevicio de diferenciales                             $2,000.0 MXN\n");
       fprintf(fp,"-Sevicio de diferenciales                              $2,000.0 MXN\n");
    }
    if (resumen->engrasado)
    {
       printf("-Engrasado                                            $500.0   MXN\n");
       fprintf(fp,"-Engrasado                                             $500.0   MXN\n");
    }
    if (resumen->rotacion)
    {
       printf("-Rotacion                                            $1,000.0 MXN\n");
       fprintf(fp,"-Rotacion                                              $1,000.0 MXN\n");
    }
    if (resumen->frenos)
    {
       printf("-Revision,limpieza y ajuste de frenos                $1,000.0 MXN\n");
       fprintf(fp,"-Revision,limpieza y ajuste de frenos                  $1,000.0 MXN\n");
    }
    printf("*********************************************************************\n");
    printf("SUBTOTAL: $%.1f\n",resumen->subtotal);
    printf("\nSu recibo ha sido impreso en un archivo.\n");
    printf("*********************************************************************\n");
    printf("\n¡Gracias por su preferencia!");


    //SOLO IMPRIME A CONSOLA
    fprintf(fp,"*********************************************************************\n");
    fprintf(fp,"SUBTOTAL: $%.1f MXN\n",resumen->subtotal);
    fprintf(fp,"\n¡Gracias por su preferencia!");



    
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES");
    
    FILE *fp;
    fp = fopen("Resumen.txt","w");
    int OPC;
    int OPC2;
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
    scanf("%d",&OPC);
    switch (OPC)
    {
    case 1:
        cliente = getInfo(puntero);
        listado(respuntero);
        printf("¿Desea continuar con la cita?\n1.Si\n2.No");
        scanf("%d",&OPC2);
        switch (OPC2)
        {
        case 1:
            resumenfinal(respuntero,fp,puntero);
            break;
        
        default:
            system("cls");
            printf("¡Vuelva pronto!\nMexicanicos te espera.");
            break;
        }
        break;
    case 2:
        system("cls");
        printf("¡Vuelva pronto!\nMexicanicos te espera.");
        break;
    default:
        break;
    }

}



