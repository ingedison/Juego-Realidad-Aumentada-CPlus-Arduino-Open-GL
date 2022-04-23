#include "Viewport.h"

int Viewport::width=0;
int Viewport::height=0;
int control=0;

const float Viewport::WALKING_SPEED = 3.2; 
void handleSpecialKeyReleased(int key, int x, int y){
										if(key==GLUT_KEY_UP){
											Camera::position.x += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dsin(Camera::rotation.y);
											Camera::position.z += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dcos(Camera::rotation.y);
										}
										if((key==GLUT_KEY_DOWN)){
											Camera::position.x += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dsin(Camera::rotation.y +100);
											Camera::position.z += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dcos(Camera::rotation.y +100);
										}
										if((key==GLUT_KEY_LEFT)){
											Camera::position.x += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dsin(Camera::rotation.y +270);
											Camera::position.z += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dcos(Camera::rotation.y +270);
										}
										if((key==GLUT_KEY_RIGHT)){
											   Camera::position.x += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dsin(Camera::rotation.y +90);
											   Camera::position.z += (Dibujar::WALKING_SPEED*Tiempo::delta)*Math::dcos(Camera::rotation.y +90);
										}
                       }


void Viewport::reshape(int w, int h){
                                     Viewport::height=h;
									 Viewport::width=w;
									 
									 Mouse::h= h;
									 Mouse::w=w;
										
									 glDeleteLists(Dibujar::g_persp,1);
	                                 glDeleteLists(Dibujar::g_ortho,1);
									 glDeleteLists(Dibujar::g_ortho2D,1);
										if (h==0){
												  h=1;
										}	

									  float ratio = (float) w/ h;
										glViewport( 0, 0, w, h);

									    Dibujar::g_persp = glGenLists(1);
	                                    Dibujar::g_ortho = glGenLists(1);
										Dibujar::g_ortho2D = glGenLists(1);
										
	                                   glNewList(Dibujar::g_ortho2D,GL_COMPILE);
									   glMatrixMode(GL_PROJECTION);     
                                       glLoadIdentity();
                                       gluOrtho2D(0.0,200.0,0.0,200.0);
									   glMatrixMode(GL_MODELVIEW);
		                               glLoadIdentity();
									   glEndList();

	                                    glNewList(Dibujar::g_persp,GL_COMPILE);
										glMatrixMode( GL_PROJECTION );
										glLoadIdentity( );
										gluPerspective(45, ratio, 0.01, 1000);
										glMatrixMode( GL_MODELVIEW );
										glLoadIdentity( );
										//gluLookAt( 0, 100, 200, 0, 0, 0, 0, 1, 0 );
										glEndList();

										// generate orthographic display list
	                                    glNewList(Dibujar::g_ortho,GL_COMPILE);
										glMatrixMode(GL_PROJECTION);
										glLoadIdentity();
		                                glOrtho(-0.0, 1024.0, -1000.0, 1000.0, -1000.0, 1000.0);
		                                glMatrixMode(GL_MODELVIEW);
		                                glLoadIdentity();
                                        glEndList(); 

										
}

void Viewport::ini(){
                                                 glutReshapeFunc(Viewport::reshape);
												 glutDisplayFunc(Viewport::show);
												 glutIdleFunc(Viewport::show);
												 glutKeyboardFunc(Keyboard::keyDown);
                                                 glutKeyboardUpFunc(Keyboard::keyUp);
                                                 glutSpecialFunc(handleSpecialKeyReleased);
												 glutMouseFunc(Mouse::mouse);
												 glutMotionFunc(Mouse::move);
												 glutPassiveMotionFunc(Mouse::move);     


}


void Viewport::show(){
							   Dibujar::display();
}


