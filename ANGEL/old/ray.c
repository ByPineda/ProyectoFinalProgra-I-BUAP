#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nom[50],app[50];
	long tel;
	unsigned char dir[100],mod[100];
	int opc;
	int bandera = 1;
	
	printf("	Taller Mecanico\n");
	printf("Introduzca sus datos\n");
	printf("Nombre\n");
	scanf("%c",&nom);
	printf("Apellido\n");
	scanf("%c",app);
	printf("Telefono o Celular\n");
	scanf("%ld",&tel);
	printf("Direccion\n");
	scanf("%u",&dir);
	printf("Marco y modelo de carro\n");
	scanf("%u",&mod);
	
	
	do{
	
		printf("	Estos son los servicios que el taller proporciona:\n");
		printf("		1.-Lubricacin y cambio de aceite\n");
		printf("		2.-Reemplazo de acumulador\n");
		printf("		3.-Suspension\n");
		printf("		4.-Alineacion y Balanceo\n");
		printf("		5.-Mofles\n");
		printf("		6.-Rectificacion y Torneado\n");
		printf("		7.-Servicio de clutch\n");
		printf("		8.-Sevicio de diferenciales\n");
		printf("		9.-Engrasado\n");
		printf("		10.-Rotacion\n");
		printf("		11.-Revision,limpieza y ajuste de frenos\n");
		printf("		12.-Salir\n");	
	
		printf("		Teclea el numero del servicio que desee: ");
		fflush(stdin);
		scanf("%d",&opc);
		printf("Eligiste el servicio:->%d",opc);
		
	
		switch(opc){
		
					printf("		Menu de los servicios del taller");
			case 1:
					printf("		Lubricacion y cambio de aceite\n");
			case 2:
					printf("		Reemplazo de acumulador\n");
			case 3:
					printf("		Suspension\n");
			case 4:
					printf("		Alineacion y Balanceo\n");
			case 5:
					printf("		Mofles\n");
			case 6:
					printf("		Rectificacion y Torneado\n");
			case 7:
					printf("		Servicio de clutch\n");
			case 8:
					printf("		Sevicio de diferenciales\n");
			case 9:
					printf("		Engrasado\n");
			case 10:
					printf("		Rotacion\n");
			case 11:
					printf("		Revision,limpieza y ajuste de frenos\n");
			
			case 12:
				printf("	Saliste del programa del taller");
                bandera = 0;
			break;
		}
	
	} while (bandera);
	
	
}