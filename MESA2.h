/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: Mesa Example
 * Archivo:  mesa_example.h
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


typedef struct {
  float r;
  float g;
  float b;
} COLOR;

void init ();
void plot ();
void draw ();
void draw_scene ();


