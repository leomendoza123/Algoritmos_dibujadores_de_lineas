#include "incremental.h"

int *algoritmoIncremental(int X0, int Y0, int X1, int Y1){
    clock_t start = clock(), diff;
	long double m,y,x;
	int i;
	//variables para ordenar
	int ordenX0, ordenY0, ordenX1, ordenY1;
	//variables para calcular densidad
	int densidadX, densidadY;

	//calculo de densidades
	densidadX = (abs(X1 - X0));
	densidadY = (abs(Y1 - Y0));


	//caso 1 cuando la densidad de Y es mayor que la de X
	if(densidadX < densidadY){
		//orden basado en Y
		if(Y0 > Y1){//se mantiene el orden Y1 siempre mas grande
		ordenX0 = X0;
		ordenX1 = X1;
		ordenY0 = Y0;
		ordenY1 = Y1;
		X0 = ordenX1;
		Y0 = ordenY1;
		X1 = ordenX0;
		Y1 = ordenY0;
			}

	m = ((long double)(Y1 - Y0) / (long double)(X1 - X0));
	x = (long double)X0;

	for(i=Y0;i<=Y1;i++){
		x += (long double)((long double)1 /(long double) m);
		printPoint(lroundl(x),i);
		plot(lroundl(x),i);
		}
        diff = clock() - start;
        return diff;
	}
	//caso 2 cuando la densidad de X es mayor que la de Y o mayor
	else {

		//Orden basado en X
		if(X0 > X1 ){ //se mantiene el orden X1 siempre mas grande
		ordenX0 = X0;
		ordenX1 = X1;
		ordenY0 = Y0;
		ordenY1 = Y1;
		X0 = ordenX1;
		Y0 = ordenY1;
		X1 = ordenX0;
		Y1 = ordenY0;
			}



	m = ((long double)(Y1 - Y0) / (long double)(X1 - X0));
	y = (long double)Y0;


	for(i=X0;i<=X1;i++){
		printPoint(i,lroundl(y));
		plot(i,lroundl(y));
		y+=m;
		}

		diff = clock() - start;
        return diff;
	}

	   diff = clock() - start;
        return diff;

	}
