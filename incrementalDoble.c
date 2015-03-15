#include "incrementalDoble.h"

int *algoritmoIncrementalDoble(int X0, int Y0, int X1, int Y1){

	long double x,y,paso_x,paso_y;
	int i, ancho;
	
	ancho = max(abs(X1-X0),abs(Y1-Y0));
	paso_x = (long double)((long double)(X1-X0) / (long double)ancho);
	paso_y = (long double)((long double)(Y1-Y0) / (long double)ancho);
	x= (long double) X0; y= (long double) Y0;
	for(i=0;i<=ancho;i++){
		printPoint(lroundl(x),lroundl(y));
		plot(lroundl(x),lroundl(y));
		x+=(long double)paso_x;
		y+=(long double)paso_y;
		}
	return 1;
	}

