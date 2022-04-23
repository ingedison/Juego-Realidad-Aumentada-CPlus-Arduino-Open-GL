#include "Menu.h"

GLfloat Menu::light0_ambient[] = {0.2, 0.2, 0.2, 1.0};
GLfloat Menu::light0_diffuse[] = {0.0, 0.0, 0.0, 1.0};
GLfloat Menu::light1_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat Menu::light1_position[] ={1.0, 1.0, 1.0, 0.0};
GLfloat Menu::light2_diffuse[] = {0.0, 1.0, 0.0, 1.0};
GLfloat Menu::light2_position[] ={-1.0, -1.0, 1.0, 0.0};
float Menu::s;

void Menu::cargando(void) {
	                       

}

void Menu::salida(GLfloat x, GLfloat y, char *text){
	                                               char *p;
                                                   glPushMatrix();
												   glTranslatef(x, y, 0);
												   for (p = text; *p; p++)
													glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
												   glPopMatrix();
}

