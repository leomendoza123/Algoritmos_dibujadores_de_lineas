/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: Mesa Example
 * Archivo:  mesa_example.c
 */

#include "MESA2.h"
#include "malloc.h"
#include <time.h>

void test ();
int asar (void);

COLOR **buffer;

int random_number(int min_num, int max_num);
int h_size, v_size;
void plotCheckerReset();
void plotCheckerON(int x);
void plotChecker(int i, int j);


int main(int argc, char* argv[])
{
    printLabelEncabezado();
    int size =  atoi(argv[1]);
    int times = atoi(argv[2]);
    int lineas = atoi(argv[3]);
    if (argc == 1){
        printLabelError1();
    }
    else if (argc != 3){
        printLabelError2();
        printLabelInfo1();
    }

    printf("Tamaño %i, Repeticiones %i, Lineas %i \n", size, times, lineas);

     h_size =size;
     v_size =size;
    glutInit(&argc, argv);
    init ();
    int n= 0;
    srand(time(NULL));
    plotCheckerON(1);
    int BresemhamTime = 0;
    int IncrementalDobleTime = 0;
    int FuerzaBrutaTime = 0;
    int IncrementalTime = 0;
    int X1, X2, Y1, Y2, tempTimes;
    while (n++<lineas){
        X1 = random_number(0, v_size); X2 = random_number(0, v_size); Y1 = random_number(0, v_size); Y2 = random_number(0, v_size);
        tempTimes = times;
        while (tempTimes-- >0){
            plotCheckerReset();
            printf ("\n Incremental ____________________\n" );
            IncrementalTime += algoritmoIncremental(X1,X2,Y1,Y2);
            plotCheckerReset();
            printf ("\n Fuerza Bruta ____________________\n" );
            FuerzaBrutaTime += algoritmoFuerzaBruta( X1,X2,Y1,Y2);
            plotCheckerReset();
            printf ("\n Doble incremental ____________________\n" );
            IncrementalDobleTime += algoritmoIncrementalDoble( X1,X2,Y1,Y2);
            plotCheckerReset();
            printf ("\nBresemham ____________________\n" );
            BresemhamTime += algoritmoBresemham( X1,X2,Y1,Y2);
        }
        }

    printf (">> \n" );
    printf ("Incremental Doble time %i \n",IncrementalDobleTime );
    printf ("Fuerza Bruta time %i \n",FuerzaBrutaTime );
    printf ("Incremental time %i \n",IncrementalTime );
    printf ("Bresemham time %i \n",BresemhamTime );
    draw ();



}
int asar (){
    srand(time(NULL));
    int r = rand();
}


int Xchecker =0;
int Ychecker = 0;
int checkerBeging =0;
int checkerOn= 0;

void plotCheckerReset(){
    Xchecker = 0;
    Ychecker = 0;
    checkerBeging = 0;
}

void plotCheckerON(int x){
    checkerOn = x;
}

void plotChecker(int i, int j){

    if (checkerOn){

        if (!checkerBeging){
            Xchecker = i;
            Ychecker = j;
            checkerBeging = 1;
        }
        else{
            if (abs(Xchecker-i)>2 || abs(Ychecker-j)>2){
                printf ("posible error en dibujado del punto X:%i, Y:%i al X2:%i, Y2:%i \n",Xchecker, Ychecker, i, j);
            }
            Xchecker = i;
            Ychecker = j;
        }
    }
}

void plot (i,j){

    plotChecker(i,j);

    if (i>=0&&i<h_size  &&   j>=0&&j< v_size ){
        buffer[i][j].r = 1;
        buffer[i][j].g = 1;
        buffer[i][j].b = 1;
    }

}

void test (){
int i,j;
  for (i = 0; i < h_size; i++)
      {
       for (j = 0; j < v_size; j++){

       if (i=j){

            buffer[i][j].r = 1;
            buffer[i][j].g = 1;
            buffer[i][j].b = 1;
            }
            }
      }
}

void init (){
  int i, j;

  buffer = (COLOR **)malloc(h_size * sizeof(COLOR*));
  for (i = 0; i < h_size; i++)
      {
       buffer[i] = (COLOR *)malloc(v_size * sizeof(COLOR));
      }

  for (i = 0; i < h_size; i++)
      {
       for (j = 0; j < v_size; j++){

            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;

            }
      }

}

void draw (){

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(h_size,v_size);
  glutCreateWindow("Mesa Example");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, h_size +0.5, -0.5, v_size + 0.5);
  glutDisplayFunc(draw_scene);
  glutMainLoop();
}


void draw_scene() {
  static int last_x = 0;
  int i, j;
  COLOR color;

  for (i = 0; i < last_x; i++)
      {
       for (j = 0; j < v_size; j++)
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }

  for (i = last_x; i < h_size; i++)
      {
       for (j = 0; j < v_size; j++)
         {
          glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
          glBegin(GL_POINTS);
          glVertex2i(i,j);
          glEnd();
          last_x = i;
         }
      }

  glFlush();
}

int random_number(int min_num, int max_num)
        {
            int result=0,low_num=0,hi_num=0;
            if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }

            result = (rand()%(hi_num-low_num))+low_num;
            return result;
        }



