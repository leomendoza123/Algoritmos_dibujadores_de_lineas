#include "incrementalDoble.h"

int *algoritmoIncrementalDoble(int X0, int Y0, int X1, int Y1){
	
	long double x,y,paso_x,paso_y;
	int i, ancho;
	ancho = max(abs(X1-X0),abs(Y1-Y0));
	paso_x = (X1-X0) / ancho;
	paso_y = (Y1-Y0) / ancho;
	x= X0; y= Y0;
	for(i=0;i<=ancho;i++){
		printPoint(lroundl(x),lroundl(y));
		/*plot(lroundl(x),lroundl(y));*/
		x+=paso_x;
		y+=paso_y;
		}
	return 1;
	}
