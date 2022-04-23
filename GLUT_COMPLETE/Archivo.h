#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

struct registro{
	            int nrr;
                float xcoord;
                float ycoord;
                float zcoord;
                float radio;
                };
                
                struct index{
                             int nrr;
                             int key;
                 };
                 


class Archivo {
                 public:
				 static int modoretornar;   
				 static FILE *data;
				 static FILE *Index;
				 static FILE *aux;
				 static void insertar();
				 static void consultar();
				 static int file_size;
				 static float xc, yc, zc, rd;
};

