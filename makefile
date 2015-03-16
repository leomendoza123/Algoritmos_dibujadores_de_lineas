OBJECTS= mesa1.o fuerzaBruta.c incremental.c incrementalDoble.c print.c utiles.c bresemham.c
OUTPUT=mesa

CFLAGS=-I/usr/local/Mesa-3.4/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib

$(OUTPUT): $(OBJECTS)
	cc $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDLIBS)

$(OBJECTS): mesa1.h

clean:
	rm -f *.o
	rm -f mesa
