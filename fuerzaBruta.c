#include "fuerzaBruta.h"

int *algoritmoFuerzaBruta(int X0, int Y0, int X1, int Y1){
	long double m, b, y, x;
	int i;
	
	//variables para ordenar segun valor de los inputs
	int ordenX0,ordenY0,ordenX1,ordenY1;
	//variables para calcular densidad
	int densidadX, densidadY;
	
	//Caso 0
	//Caso en el cual ambas puntos son iguales X0 = X1 y Y0 = Y1
	if(X0 == X1 && Y0 == Y1){
		printPoint(X0,Y0);
		/*plot(X0,Y0)*/;
		return 1;
		}
		
	//Caso 1
	//Caso en el cual ambas "X" sean iguales X0 = X1
    if(X0 == X1 && Y0 != Y1){
		if(Y0 > Y1){ //se mantiene el orden siempre la Y1 mas grande
			ordenY0 = Y0;
			ordenY1 = Y1;
			Y0 = ordenY1;
			Y1 = ordenY0;
			}
	for(i=Y0; i<=Y1; i++){
		printPoint(X0,i);
		/*plot(X0,i)*/;
		}
	return 1;
	}
		
	//calculo de densidades
	densidadX = (abs(X1 - X0));
	densidadY = (abs(Y1 - Y0));
	
	//caso 3 cuando la densidad de Y es mayor que la de X
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
		
	m = (long double)((long double)(Y1 - Y0) / (long double)(X1 - X0));
	b = (long double) (Y0 - (long double)(m * X0));
	x = (long double)X0;
				
	for(i=Y0;i<=Y1;i++){	 
		x = (long double)((long double)(i - b) / (long double)m);
		printPoint(lroundl(x),i);
		/*plot(i,round(y))*/
		}
					
		return 1;
			
		}
	else{
	//Caso 4 cuando la densidad de X es mayor que la de Y o igual
	m = (long double)((long double)(Y1 - Y0) / (long double)(X1 - X0));
	b = (long double) (Y0 - (long double)(m * X0));
	
	if(X0 > X1 ){ //se mantiene el orden X0 siempre mas grande
	    ordenX0 = X0;
		ordenX1 = X1;
		ordenY0 = Y0;
		ordenY1 = Y1;
		X0 = ordenX1;
		Y0 = ordenY1;
		X1 = ordenX0;
		Y1 = ordenY0;
			}
			
	for(i=X0; i<=X1; i++){
		y = (long double)(((long double)(m * i)) + b);
		printPoint(i,(int) lroundl(y));
		/*plot(i, round(y))*/
		}
		return 1;
	}
	
	}
