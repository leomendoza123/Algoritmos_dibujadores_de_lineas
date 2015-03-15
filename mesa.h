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

#define H_SIZE 400
#define V_SIZE 400

typedef struct {
  float r;
  float g;
  float b;
} COLOR;

void init ();
void plot ();
void draw ();
void draw_scene ();


