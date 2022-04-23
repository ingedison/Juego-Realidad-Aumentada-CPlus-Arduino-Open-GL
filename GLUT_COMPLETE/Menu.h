#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>



class Menu{
public:
	   static GLfloat light0_ambient[];
       static GLfloat light0_diffuse[];
		static GLfloat light1_diffuse[];
		static GLfloat light1_position[];
		static GLfloat light2_diffuse[];
		static GLfloat light2_position[];
		static float s;

	static void cargando(void);
	static void salida (GLfloat x, GLfloat y, char *text);

};

