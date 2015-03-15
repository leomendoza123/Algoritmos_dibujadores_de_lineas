#include "p1.h"
	
int main(int argc, char **argv)
{	
	if(argc == 1){
		printLabelEncabezado();
		printLabelError1();
		return 0;
		}
	
	if(!strcmp(argv[1],"h")){
		printLabelEncabezado();
		printLabelInfo1();
		algoritmoIncrementalDoble(5, 4, 23, 11);
		return 0;
		}
		
	if(argc < 4){
		printLabelEncabezado();
		printLabelError2();
		return 0;
		}
	
	}
