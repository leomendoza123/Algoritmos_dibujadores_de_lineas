/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: Mesa Example
 * Archivo:  mesa_example.c
 */

#include "mesa.h"
#include "malloc.h"

void test ();

COLOR **buffer;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init ();

    algoritmoIncremental(5, 4, 600, 100);
    algoritmoFuerzaBruta(5, 4, 100, 600);
     algoritmoIncrementalDoble(5, 4, 100, 800);


    draw ();

}

void plot (i,j){

    if (i>=0&&i<H_SIZE  &&   j>=0&&j< V_SIZE ){
        buffer[i][j].r = 1;
        buffer[i][j].g = 1;
        buffer[i][j].b = 1;
    }

}

void test (){
int i,j;
  for (i = 0; i < H_SIZE; i++)
      {
       for (j = 0; j < V_SIZE; j++){

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

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR*));
  for (i = 0; i < H_SIZE; i++)
      {
       buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
      }

  for (i = 0; i < H_SIZE; i++)
      {
       for (j = 0; j < V_SIZE; j++){

            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;

            }
      }

}

void draw (){

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE,V_SIZE);
  glutCreateWindow("Mesa Example");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
  glutDisplayFunc(draw_scene);
  glutMainLoop();
}


void draw_scene() {
  static int last_x = 0;
  int i, j;
  COLOR color;

  for (i = 0; i < last_x; i++)
      {
       for (j = 0; j < V_SIZE; j++)
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }

  for (i = last_x; i < H_SIZE; i++)
      {
       for (j = 0; j < V_SIZE; j++)
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



