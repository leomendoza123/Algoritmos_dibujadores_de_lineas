#include "incremental.h"

int *algoritmoIncremental(int X0, int Y0, int X1, int Y1){
	long double m,y;
	int i;
	int ordenX0, ordenY0, ordenX1, ordenY1;
	
	//caso 1
	//Caso en el cual ambas puntos son iguales X0 = X1 y Y0 = Y1
	if(X0 == X1 && Y0 == Y1){
		printPoint(X0,Y0);
		/*plot(i, round(y))*/
		return 1;
		}
	//caso 2
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
		/*plot(i, round(y))*/
		}
		return 1;
		}
		
	//caso 3
	m = ((long double)(Y1 - Y0) / (long double)(X1 - X0));
	y = (long double)Y0;
	
	if(X0 > X1 ){ //se mantiene el orden X0 siempre mas grande
		ordenX0 = X0;
		ordenX1 = X1;
		X0 = ordenX1;
		X1 = ordenX0;
			}
			
	for(i=X0;i<=X1;i++){	
		printPoint(i,lroundl(y));
		/*plot(i,round(y))*/
		y+=m;
		}
		
		return 1;
	}
