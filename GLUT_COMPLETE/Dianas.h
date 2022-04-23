#pragma once
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "Camera.h"
 #include <sstream> 
#include "Archivo.h"
#define M_PI 3.14159265358979323846
using namespace std;

class Dianas{
             private:
			 public:
		     float clickx;
			 float clicky;
	         float clickz;
			 float rad;

			 static int clicked;
			 static double R_aum;
			 static float xc[200];
			 static double D_Dyn_Radio;
             static GLuint list_dianas;
			 static const int size;
		     static int cont, filesize;
			 static void alta(double Pos_x, double Pos_y, double Pos_z, double r);
			 static void Dib_dianas();
			 static void circle(float x, float y, float z, float r, int segments);
			 static void circle_vect(float x, float y, float z, float r, int segments);
			 static void circle_lined(float x, float y, float z, float r, int segments);
			 static void listar();
			 static int create_scene;
			 static void cargar_desde_archivo();
			 static void getScore(float x, float y, float z, int c);
			 static float gj;
			 static int go_and_back;
			 static void Menu();
			 static void draw_from_file(int l);
			 static int Score;
			 static void Guardar();
			 static int disparos;
			 static int vidas;
};

