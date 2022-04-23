#include<iostream>
//#include<GL/gl.h>
//#include<AL/al.h>
#include<GL/glut.h>
#include <cmath>

#include "Viewport.h"


#include <SFML/Audio.hpp>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 540;
const char* WINDOW_TITLE = "SIMULADOR DE TIRO";

 static char label[100]; 

 vector3f CAMERA_POSITION;
 vector3f CAMERA_ROTATION;
 Texture* tex; Texture* tex2; Texture* tex3; Texture* tex1;

 char musicv[]= "Recursos/Audios/GTA.ogg";
 sf::Music musicxv;

void myinit();
void Musicav(char playmusic[]);


//MAIN 

int main(int argc, char ** argv){
											 
											  glutInit(&argc, argv);
											  glutInitWindowPosition(0, 0);
											  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
											  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
                                              
											  //Inicializar	Conexión Serial
											    Arduino::Conexion_Arduino_IN();

												//Archivo::consultar();

											  //INICIALIZAR VENTANA

												glutCreateWindow("MI JUEGO");
												Viewport::ini();

											    //Musica(music);
											    //musicx.play();
											    myinit();

												

												 Camera::position.y=4;
												 Camera::position.z=-60;
												 glutMainLoop();

										return 0;
}

void myinit(){
	                                     
                                       
										Terreno::ini();
										Texture::gen_Textures();
										Mouse::clicksound();
										Dibujar::sound();
										Dibujar::snderror();
										Dibujar::Men_Ent_Snd();
										Dibujar::Men_Save_Snd();
										Dibujar::end_sound();
										Mouse::clicksound2();
										glEnable(GL_DEPTH_TEST);
										glEnable(GL_COLOR_MATERIAL);
										glEnable(GL_LIGHTING);
										glEnable(GL_LIGHT0);
										glEnable(GL_NORMALIZE);
										glShadeModel(GL_SMOOTH);
										glClearColor(0.5f,0.5f,0.5f,1.0f);

}


void drawString (char *s) {
unsigned int H; 
for (H = 0; H < strlen (s); H++) 
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, s[H]);
} 




void Musicav(char playmusic[]){
								
								if (!musicxv.openFromFile(playmusic))
									 return;
								     musicxv.setVolume(20);			
                                     std::cout << std::endl;
}

