#include "print.h"

void *printLabelEncabezado(){
	printf("\nInstituto Tecnologico de Costa Rica");
	printf("\nEscuela de Ingenieria en Computacion");
	printf("\nIntroduccion a los graficos por computadora");
	printf("\nProyecto 1 18/3/2015");
	printf("\nEstudiantes: Jose Carlos Alvarez Umana");
	printf("\nLeonardo Mendoza");
	printf("\n");
	}

void *printLabelError1(){
	printf("\nAtencion: No fueron introducidos parametros");
	printf("\n");
	}

void *printLabelError2(){
	printf("\nAtencion: Cantidad de parametros insuficiente");
	printf("\n");
	}

void *printLabelInfo1(){
	printf("\nIntroducir parametros en el siguiente orden: ");
	printf("\nres #lineas #veces");
	printf("\n");
	}

void *printPoint(int X, int Y){

		printf("%4d-",X);
		printf("%4d",Y);
		printf("//");
	}
